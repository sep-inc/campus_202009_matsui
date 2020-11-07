using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeCapsule : MonoBehaviour
{
    [SerializeField] private GameObject capsule_start = null;  //!カプセルを形成する始点
    [SerializeField] private GameObject capsule_end = null;    //!カプセルを形成する終点

    [SerializeField] private float radius = 0;  //!半径

    //!線分情報
    struct Line_Info
    {
        public Vector3 start_pos;    //!カプセルの始点
        public Vector3 end_pos;      //!カプセルの終点

        public Vector3 direction_1;  //!90度用
        public Vector3 direction_2;  //!-90度用
    }

    Line_Info[] line_Info = new Line_Info[2];  //!カプセル描画用([0]が始点、[1]が終点の情報)

    Vector3 angles = new Vector3(0, 0, 90);     //!回転角度(2D用)
    Vector3 angles2 = new Vector3(0, 0, -90);   //!回転角度(2D用)

    struct CapsuleVec_Info
    {
        public Vector3 my_start_my_end;    //!カプセルAの始点からカプセルAの終点までのベクトル
        public Vector3 my_end_my_start;    //!カプセルAの終点からカプセルAの始点までのベクトル

        public Vector3 my_start_other_start;  //!カプセルAの始点からカプセルBの始点までのベクトル
        public Vector3 my_end_other_start;    //!カプセルAの終点からカプセルBの始点までのベクトル

        public Vector3 my_end_other_end;     //!カプセルAの終点からカプセルBの終点までのベクトル
        public Vector3 my_start_other_end;   //!カプセルAの始点からカプセルBの終点までのベクトル
    }

    CapsuleVec_Info[] vec_Info = new CapsuleVec_Info[2];   //!ベクトル構造体([0]が自分から相手のベクトル。[1]が相手から自分のベクトル)

    double[] length_ = new double[8];  //!ベクトルの距離保存用

    float[] dot = new float[8];  //!内積による角度保存用

    public float Closs;   //!カプセルAの始点からカプセルBの始点の外積の結果保存用
    public float Closs2;  //!カプセルAの終点からカプセルBの終点の外積の結果保存用

    public float Closs3;   //!カプセルAの始点からカプセルBの始点の外積の結果保存用
    public float Closs4;  //!カプセルAの終点からカプセルBの終点の外積の結果保存用

    float value_radius;  //!半径の合計値

    Vector3 my_start_circle;  //!カプセルの始点から球までのベクトル
    Vector3 my_end_circle;    //!カプセルの終点から球までのベクトル

    float capsule_circle_dot;   //!線分との内積
    public float length_capsule_circle;  //!線分の始点との距離

    //!カプセルの中心点計算関数
    public Vector3 GetCenterPos()
    {
        Vector3 half_start_to_end = (capsule_end.transform.position - capsule_start.transform.position) / 2;

        return capsule_start.transform.position + half_start_to_end;
    }

    //!カプセルとカプセル
    public bool HitCapsuleToCapsule(ShapeCapsule other)
    {
        vec_Info[0].my_start_my_end = capsule_end.transform.position - capsule_start.transform.position;   //!自分のStart～End
        vec_Info[0].my_end_my_start = capsule_start.transform.position - capsule_end.transform.position;   //!自分のEnd～Start

        vec_Info[0].my_start_other_start = other.capsule_start.transform.position - capsule_start.transform.position;  //!自分のStart～相手のStart
        vec_Info[0].my_end_other_start = other.capsule_start.transform.position - capsule_end.transform.position;      //!自分のEnd～相手のStart

        vec_Info[0].my_end_other_end = other.capsule_end.transform.position - capsule_end.transform.position;          //!自分のEnd～相手のEnd
        vec_Info[0].my_start_other_end = other.capsule_end.transform.position - capsule_start.transform.position;      //!自分のStart～相手のEnd

        //!外積計算
        Closs = Math.Abs(Vector3.Cross(vec_Info[0].my_start_my_end.normalized, vec_Info[0].my_start_other_start).magnitude);
        Closs2= Math.Abs(Vector3.Cross(vec_Info[0].my_end_my_start.normalized, vec_Info[0].my_end_other_end).magnitude);


        vec_Info[1].my_start_my_end = other.capsule_end.transform.position - other.capsule_start.transform.position;   //!自分のStart～End
        vec_Info[1].my_end_my_start = other.capsule_start.transform.position - other.capsule_end.transform.position;   //!自分のEnd～Start

        vec_Info[1].my_start_other_start = capsule_start.transform.position - other.capsule_start.transform.position;  //!自分のStart～相手のStart
        vec_Info[1].my_end_other_start = capsule_start.transform.position - other.capsule_end.transform.position;      //!自分のEnd～相手のStart

        vec_Info[1].my_end_other_end = capsule_end.transform.position - other.capsule_end.transform.position;          //!自分のEnd～相手のEnd
        vec_Info[1].my_start_other_end = capsule_end.transform.position - other.capsule_start.transform.position;      //!自分のStart～相手のEnd

        //!外積計算
        Closs3 = Math.Abs(Vector3.Cross(vec_Info[1].my_start_my_end.normalized, vec_Info[1].my_start_other_start).magnitude);
        Closs4 = Math.Abs(Vector3.Cross(vec_Info[1].my_end_my_start.normalized, vec_Info[1].my_end_other_end).magnitude);

        value_radius = radius + other.radius;  //!半径の合計値

        //!カプセルとの最短距離が半径の合計より小さい時
        if (Math.Abs(Closs) <= value_radius)
        {
            //!内積計算
            dot[0] = Vector3.Dot(vec_Info[0].my_start_other_start, vec_Info[0].my_start_my_end);
            dot[1] = Vector3.Dot(vec_Info[0].my_end_other_start, vec_Info[0].my_start_my_end);

            //!交差している場合
            if (dot[0] * dot[1] <= 0.0f)
            {
                return true;
            }
            //!始点(A)から始点(B)、もしくは終点(A)から始点(B)の距離が半径の合計よりも小さい時
            else if (vec_Info[0].my_start_other_start.magnitude < value_radius ||
                     vec_Info[0].my_end_other_start.magnitude < value_radius)
            {
                return true;
            }
        }
        if (Math.Abs(Closs2) <= value_radius)
        {
            //!内積計算
            dot[2] = Vector3.Dot(vec_Info[0].my_end_other_end, vec_Info[0].my_end_my_start);
            dot[3] = Vector3.Dot(vec_Info[0].my_start_other_end, vec_Info[0].my_end_my_start);

            //!交差している場合
            if (dot[2] * dot[3] <= 0.0f)
            {
                return true;
            }
            //!終点(A)から終点(B)、もしくは始点(A)から終点(B)の距離が半径の合計よりも小さい時
            else if (vec_Info[0].my_end_other_end.magnitude < value_radius ||
                     vec_Info[0].my_start_other_end.magnitude < value_radius)
            {
                return true;
            }
        }

        //!カプセルとの最短距離が半径の合計より小さい時
        if (Math.Abs(Closs3) <= value_radius)
        {
            //!内積計算
            dot[4] = Vector3.Dot(vec_Info[1].my_start_other_start, vec_Info[1].my_start_my_end);
            dot[5] = Vector3.Dot(vec_Info[1].my_end_other_start, vec_Info[1].my_start_my_end);

            //!交差している場合
            if (dot[4] * dot[5] <= 0.0f)
            {
                return true;
            }
            //!始点(B)から始点(A)、もしくは終点(B)から始点(A)の距離が半径の合計よりも小さい時
            else if (vec_Info[1].my_start_other_start.magnitude < value_radius ||
                     vec_Info[1].my_end_other_start.magnitude < value_radius)
            {
                return true;
            }
        }
        if (Math.Abs(Closs4) <= value_radius)
        {
            //!内積計算
            dot[6] = Vector3.Dot(vec_Info[1].my_end_other_end, vec_Info[1].my_end_my_start);
            dot[7] = Vector3.Dot(vec_Info[1].my_start_other_end, vec_Info[1].my_end_my_start);

            //!交差している場合
            if (dot[6] * dot[7] <= 0.0f)
            {
                return true;
            }
            //!終点(B)から終点(A)、もしくは始点(B)から終点(A)の距離が半径の合計よりも小さい時
            else if (vec_Info[1].my_end_other_end.magnitude < value_radius ||
                     vec_Info[1].my_start_other_end.magnitude < value_radius)
            {
                return true;
            }
        }

        return false;
    }

    //!カプセルと円
    public bool HitCapsuleToCircle(ShapeCircle other)
    {
        vec_Info[0].my_start_my_end = capsule_end.transform.position - capsule_start.transform.position;   //!自分のStart～End
        value_radius = radius + other.radius;  //!半径の合計値

        my_start_circle = other.transform.position - capsule_start.transform.position;
        my_end_circle = other.transform.position - capsule_end.transform.position;

        capsule_circle_dot = Vector3.Dot(vec_Info[0].my_start_my_end.normalized, my_start_circle);  //!線分と円の内積


        //!線分の始点よりも左側にある場合
        if (capsule_circle_dot < 0)
        {
            length_capsule_circle = my_start_circle.magnitude;
        }
        //!線分の終点よりも右側にある場合
        else if (my_start_circle.magnitude > vec_Info[0].my_start_my_end.magnitude)
        {
            length_capsule_circle = my_end_circle.magnitude;
        }
        //!線分の範囲にある場合
        else
        {
            length_capsule_circle = Math.Abs(Vector3.Cross(vec_Info[0].my_start_my_end.normalized, my_start_circle).magnitude);
        }

        //!線分との距離が半径よりも短い場合
        if (length_capsule_circle <= value_radius)
        {
            return true;
        }

        return false;
    }

    private void OnDrawGizmos()
    {
        line_Info[0].direction_1 = capsule_end.transform.position - capsule_start.transform.position;  //!始点から終点までのベクトル方向
        line_Info[1].direction_1 = capsule_start.transform.position - capsule_end.transform.position;  //!終点から始点までのベクトル方向

        line_Info[0].direction_1 = radius * line_Info[0].direction_1.normalized;            //!始点から終点までの方向で半径分の座標をだす 
        line_Info[0].direction_2 = Quaternion.Euler(angles2) * line_Info[0].direction_1;    //!上の座標を-90度回転した座標
        line_Info[0].direction_1 = Quaternion.Euler(angles) * line_Info[0].direction_1;     //!上の座標を90度回転した座標


        line_Info[1].direction_1 = radius * line_Info[1].direction_1.normalized;            //!終点から始点までの方向で半径分の座標をだす
        line_Info[1].direction_2 = Quaternion.Euler(angles) * line_Info[1].direction_1;     //!上の座標を90度回転した座標
        line_Info[1].direction_1 = Quaternion.Euler(angles2) * line_Info[1].direction_1;    //!上の座標を-90度回転した座標

        line_Info[0].start_pos = capsule_start.transform.position + line_Info[0].direction_1;  
        line_Info[1].start_pos = capsule_start.transform.position + line_Info[0].direction_2;  

        line_Info[0].end_pos = capsule_end.transform.position + line_Info[1].direction_1;
        line_Info[1].end_pos = capsule_end.transform.position + line_Info[1].direction_2;


        Gizmos.DrawLine(capsule_start.transform.position, capsule_end.transform.position);  //!カプセルの中央線

        Gizmos.DrawWireSphere(capsule_start.transform.position, radius);   //!カプセルの中央線から半径分ずらしたベクトル(2D用)
        Gizmos.DrawWireSphere(capsule_end.transform.position, radius);   //!カプセルの中央線から半径分ずらしたベクトル(2D用)

        Gizmos.DrawLine(line_Info[0].start_pos, line_Info[0].end_pos);   //!カプセルの中央線から半径分ずらしたベクトル(2D用)
        Gizmos.DrawLine(line_Info[1].start_pos, line_Info[1].end_pos);   //!カプセルの中央線から半径分ずらしたベクトル(2D用)

    }
}
