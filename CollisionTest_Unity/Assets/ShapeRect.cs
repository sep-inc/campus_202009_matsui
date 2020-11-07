using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class ShapeRect : MonoBehaviour
{    
    [SerializeField] private Vector3 size = Vector3.one;
    Vector3 vec_pos_;  //!対象の座標までのベクトル用    

    //!対象のサイズとの合計値
    float total_width;   
    float total_height;  
    float total_depth;  

    struct Vertex
    {
        public Vector3 left_top;      //!左上
        public Vector3 right_top;     //!右上
        public Vector3 left_under;    //!左下
        public Vector3 right_under;   //!右下
    }

    Vertex[] vertex = new Vertex[2];   //!頂点情報([0]が立方体の手前の頂点。[1]が立方体の奥の頂点。)

    public double[] vec = new double[8];  //!各頂点と円とのベクトルの大きさ


    //!矩形と矩形の判定
    public bool HitRectToRect(ShapeRect other)
    {
        vec_pos_= gameObject.transform.position - other.transform.position;  //!対象の座標までのベクトル用 

        //!対象のサイズとの合計値計算
        total_width  = (size.x + other.size.x) / 2;    
        total_height = (size.y + other.size.y) / 2;
        total_depth  = (size.z + other.size.z) / 2;

        //!対象との距離がサイズの合計値よりも小さい場合
        if (Math.Abs(vec_pos_.x) <= total_width&&
            Math.Abs(vec_pos_.y) <= total_height&&
            Math.Abs(vec_pos_.z) <= total_depth)
        {
            return true;
        }

        //!対象の辺と自分の辺が内側か外側かで判定する方法
        //if (gameObject.transform.position.x - (size.x / 2) <= other.transform.position.x + (size.x / 2)&&
        //    gameObject.transform.position.x + (size.x / 2) >= other.transform.position.x - (size.x / 2) &&
        //    gameObject.transform.position.y - (size.y / 2) <= other.transform.position.y + (size.y / 2) &&
        //    gameObject.transform.position.y + (size.y / 2) >= other.transform.position.y - (size.y / 2))
        //{
        //    return true;
        //}

        return false;
    }

    //!矩形(立方体)と円(球)の判定
    public bool HitRectToCircle(ShapeCircle other)
    {
        //!頂点初期化
        //!矩形(立方体)の手前の頂点
        vertex[0].left_top    = new Vector3(gameObject.transform.position.x - (size.x / 2), gameObject.transform.position.y + (size.y / 2), gameObject.transform.position.z - (size.z / 2));
        vertex[0].right_top   = new Vector3(gameObject.transform.position.x + (size.x / 2), gameObject.transform.position.y + (size.y / 2), gameObject.transform.position.z - (size.z / 2));
        vertex[0].left_under  = new Vector3(gameObject.transform.position.x - (size.x / 2), gameObject.transform.position.y - (size.y / 2), gameObject.transform.position.z - (size.z / 2));
        vertex[0].right_under = new Vector3(gameObject.transform.position.x + (size.x / 2), gameObject.transform.position.y - (size.y / 2), gameObject.transform.position.z - (size.z / 2));

        //!矩形(立方体)の奥の頂点
        vertex[1].left_top    = new Vector3(gameObject.transform.position.x - (size.x / 2), gameObject.transform.position.y + (size.y / 2), gameObject.transform.position.z + (size.z / 2));
        vertex[1].right_top   = new Vector3(gameObject.transform.position.x + (size.x / 2), gameObject.transform.position.y + (size.y / 2), gameObject.transform.position.z + (size.z / 2));
        vertex[1].left_under  = new Vector3(gameObject.transform.position.x - (size.x / 2), gameObject.transform.position.y - (size.y / 2), gameObject.transform.position.z + (size.z / 2));
        vertex[1].right_under = new Vector3(gameObject.transform.position.x + (size.x / 2), gameObject.transform.position.y - (size.y / 2), gameObject.transform.position.z + (size.z / 2));

        //!矩形(立方体)の手前の頂点から円(球)までのベクトル
        vec[0] = Math.Pow(vertex[0].left_top.x    - other.transform.position.x, 2) + Math.Pow(vertex[0].left_top.y    - other.transform.position.y, 2) + Math.Pow(vertex[0].left_top.z    - other.transform.position.z, 2);
        vec[1] = Math.Pow(vertex[0].right_top.x   - other.transform.position.x, 2) + Math.Pow(vertex[0].right_top.y   - other.transform.position.y, 2) + Math.Pow(vertex[0].right_top.z   - other.transform.position.z, 2);
        vec[2] = Math.Pow(vertex[0].left_under.x  - other.transform.position.x, 2) + Math.Pow(vertex[0].left_under.y  - other.transform.position.y, 2) + Math.Pow(vertex[0].left_under.z  - other.transform.position.z, 2);
        vec[3] = Math.Pow(vertex[0].right_under.x - other.transform.position.x, 2) + Math.Pow(vertex[0].right_under.y - other.transform.position.y, 2) + Math.Pow(vertex[0].right_under.z - other.transform.position.z, 2);

        //!矩形(立方体)の奥の頂点から円(球)までのベクトル
        vec[4] = Math.Pow(vertex[1].left_top.x    - other.transform.position.x, 2) + Math.Pow(vertex[1].left_top.y    - other.transform.position.y, 2) + Math.Pow(vertex[1].left_top.z    - other.transform.position.z, 2);
        vec[5] = Math.Pow(vertex[1].right_top.x   - other.transform.position.x, 2) + Math.Pow(vertex[1].right_top.y   - other.transform.position.y, 2) + Math.Pow(vertex[1].right_top.z   - other.transform.position.z, 2);
        vec[6] = Math.Pow(vertex[1].left_under.x  - other.transform.position.x, 2) + Math.Pow(vertex[1].left_under.y  - other.transform.position.y, 2) + Math.Pow(vertex[1].left_under.z  - other.transform.position.z, 2);
        vec[7] = Math.Pow(vertex[1].right_under.x - other.transform.position.x, 2) + Math.Pow(vertex[1].right_under.y - other.transform.position.y, 2) + Math.Pow(vertex[1].right_under.z - other.transform.position.z, 2);

        //!各辺(面)の内側にあるかどうか
        //!Y軸
        if (gameObject.transform.position.x - (size.x / 2) <= other.transform.position.x &&
            gameObject.transform.position.x + (size.x / 2) >= other.transform.position.x &&
            gameObject.transform.position.y - (size.y / 2) <= other.transform.position.y + other.radius &&
            gameObject.transform.position.y + (size.y / 2) >= other.transform.position.y - other.radius &&
            gameObject.transform.position.z - (size.z / 2) <= other.transform.position.z &&
            gameObject.transform.position.z + (size.z / 2) >= other.transform.position.z)
        {
            return true;
        }
        //!X軸
        else if (gameObject.transform.position.x - (size.x / 2) <= other.transform.position.x + other.radius &&
                 gameObject.transform.position.x + (size.x / 2) >= other.transform.position.x - other.radius &&
                 gameObject.transform.position.y - (size.y / 2) <= other.transform.position.y &&
                 gameObject.transform.position.y + (size.y / 2) >= other.transform.position.y &&
                 gameObject.transform.position.z - (size.z / 2) <= other.transform.position.z &&
                 gameObject.transform.position.z + (size.z / 2) >= other.transform.position.z)
        {
            return true;
        }
        //!Z軸
        else if (gameObject.transform.position.x - (size.x / 2) <= other.transform.position.x &&
                 gameObject.transform.position.x + (size.x / 2) >= other.transform.position.x &&
                 gameObject.transform.position.y - (size.y / 2) <= other.transform.position.y &&
                 gameObject.transform.position.y + (size.y / 2) >= other.transform.position.y &&
                 gameObject.transform.position.z - (size.z / 2) <= other.transform.position.z + other.radius &&
                 gameObject.transform.position.z + (size.z / 2) >= other.transform.position.z - other.radius)
        {
            return true;
        }
        //!頂点からの距離が半径よりも小さい時
        else if (vec[0] <= Math.Pow(other.radius, 2) ||
            vec[1] <= Math.Pow(other.radius, 2) ||
            vec[2] <= Math.Pow(other.radius, 2) ||
            vec[3] <= Math.Pow(other.radius, 2) ||
            vec[4] <= Math.Pow(other.radius, 2) ||
            vec[5] <= Math.Pow(other.radius, 2) ||
            vec[6] <= Math.Pow(other.radius, 2) ||
            vec[7] <= Math.Pow(other.radius, 2))
        {
            return true;
        }

            return false;
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireCube(transform.position, size);
    }

}
