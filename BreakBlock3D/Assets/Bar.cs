using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices.ComTypes;
using UnityEngine;

public class Bar : MonoBehaviour
{
    private const float MaxMove = 7.8f; //!移動できるx軸の最大値
    private const float MinMove = -10.0f; //!移動できるx軸の最小値

    public float Speed;      //!スピード

    bool ball_deth;    //!Ballが無くなった時用フラグ
    bool block_deth;   //!Blockが無くなった時用フラグ

    // Start is called before the first frame update
    void Start()
    {
        ball_deth = false;
        block_deth = false;
    }

    // Update is called once per frame
    void Update()
    {
         //!移動
         Move();

        //!停止
        if (ball_deth == true || block_deth == true)
        {
            Speed = 0.0f;
        }

    }

    private void Move()
    {
        //!左移動
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            //!左壁に触れていない間
            if (transform.position.x > MinMove)
            {
                transform.Translate(-Speed, 0.0f, 0.0f);
            }
        }
        //!右移動
        else if (Input.GetKey(KeyCode.RightArrow))
        {
            //!右壁に触れていない間
            if (transform.position.x < MaxMove)
            {
                transform.Translate(Speed, 0.0f, 0.0f);
            }
        }
    }
    public void CheckBall()  //!Ballが死んだかどうか
    {
        ball_deth = true;
    }

    public void CheckBlock()   //!Blockが残っているかどうか
    {
        block_deth = true;
    }
}
