using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class ShapeCircle : MonoBehaviour
{
    [SerializeField] public float radius = 1;  //!半径
    Vector3 vec_pos_;      //!対象の円の座標までのベクトル               
    float total_radius;    //!半径の合計値

    Vector3 line_start;   //!対象の線分の始点とのベクトル
    Vector3 line_end;     //!対象の線分の終点とのベクトル

    Vector3 line_start_to_end;  //!対象の線分の始点から終点のベクトル

    public float length_line_to_circle;  //!線分の始点との距離

    float line_to_circle_dot;   //!線分との内積

    //!円と円
    public bool HitCircleToCircle(ShapeCircle other)
    {
        //!対象の円の座標までのベクトル
        vec_pos_ = gameObject.transform.position - other.transform.position;

        //!半径の合計値
        total_radius = radius + other.radius;

        //!距離が半径の合計値よりも小さい時
        if (radius+ other.radius>= vec_pos_.magnitude)
        {
            return true;
        }
        return false;
    }

    //!円と線分
    public bool HitCircleToLine(ShapeLine other)
    {
        line_start = gameObject.transform.position - other.line_start.transform.position;   //!線分の始点から円の座標のベクトル
        line_end = gameObject.transform.position - other.line_end.transform.position;       //!線分の終点から円の座標のベクトル

        line_start_to_end = other.line_end.transform.position - other.line_start.transform.position;  //!線分の始点から線分の終点のベクトル

        line_to_circle_dot = Vector3.Dot(line_start_to_end.normalized, line_start);  //!線分と円の内積


        //!線分の始点よりも左側にある場合
        if (line_to_circle_dot < 0)
        {
            length_line_to_circle = line_start.magnitude;
        }
        //!線分の終点よりも右側にある場合
        else if (line_start.magnitude > line_start_to_end.magnitude)
        {
            length_line_to_circle = line_end.magnitude;
        }
        //!線分の範囲にある場合
        else
        {
            length_line_to_circle = Math.Abs(Vector3.Cross(line_start_to_end.normalized, line_start).magnitude);
        }

        //!線分との距離が半径よりも短い場合
        if(length_line_to_circle<=radius)
        {
            return true;
        }

        return false;
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, radius);
    }
}
