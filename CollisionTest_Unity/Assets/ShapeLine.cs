using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeLine : MonoBehaviour
{
    [SerializeField] public GameObject line_start = null; //!始点
    [SerializeField] public GameObject line_end = null;   //!終点

    Vector3 my_start_to_my_end;        //!自分の始点から自分の終点までのベクトル
    Vector3 my_start_to_other_start;   //!自分の始点から相手の始点までのベクトル
    Vector3 my_start_to_other_end;     //!自分の始点から相手の終点までのベクトル

    Vector3 other_start_to_other_end;  //!相手の始点から相手の終点までのベクトル
    Vector3 other_start_to_my_start;   //!相手の始点から自分の始点までのベクトル
    Vector3 other_start_to_my_end;     //!相手の始点から自分の終点までのベクトル

    //!外積用(自分)
    public Vector3 Cross_1;
    public Vector3 Cross_2;

    //!外積用(相手)
    public Vector3 Cross_3;
    public Vector3 Cross_4;

    //!線分の中心点計算関数
    public Vector3 GetCenterPos()
    {
        Vector3 half_start_to_end = (line_end.transform.position - line_start.transform.position) / 2;

        return line_start.transform.position + half_start_to_end;
    }

    public bool HitLineToLine(ShapeLine other)
    {
        
        my_start_to_my_end = line_end.transform.position - line_start.transform.position;               //!自分の始点から自分の終点までのベクトル
        my_start_to_other_start = other.line_start.transform.position - line_start.transform.position;  //!自分の始点から相手の始点までのベクトル
        my_start_to_other_end = other.line_end.transform.position - line_start.transform.position;      //!自分の始点から相手の終点までのベクトル

        other_start_to_other_end = other.line_end.transform.position - other.line_start.transform.position;   //!相手の始点から相手の終点までのベクトル
        other_start_to_my_start = line_start.transform.position - other.line_start.transform.position;        //!相手の始点から自分の始点までのベクトル
        other_start_to_my_end = line_end.transform.position - other.line_start.transform.position;            //!相手の始点から自分の終点までのベクトル

        //!外積計算(自分)
        Cross_1 = Vector3.Cross(my_start_to_my_end.normalized, my_start_to_other_start);
        Cross_2 = Vector3.Cross(my_start_to_my_end.normalized, my_start_to_other_end);

        //!外積計算(相手)
        Cross_3 = Vector3.Cross(other_start_to_other_end.normalized, other_start_to_my_start);
        Cross_4 = Vector3.Cross(other_start_to_other_end.normalized, other_start_to_my_end);

        //!交差している時
        if (Cross_1.z * Cross_2.z < 0.0f && Cross_3.z * Cross_4.z < 0.0f) 
        {
            return true;
        }

        return false;
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawLine(line_start.transform.position, line_end.transform.position);
    }
}
