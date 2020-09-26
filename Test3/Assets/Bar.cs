using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bar : MonoBehaviour
{
    private float MaxMove; //!移動できるx軸の最大値
    private float MinMove; //!移動できるx軸の最小値

    public float Speed;

    GameObject ball;
    GameObject Block;

    // Start is called before the first frame update
    void Start()
    {
        //!初期化
        MaxMove = 7.8f;
        MinMove = -10.0f;

        ball = GameObject.Find("Ball");         //!Ball取得
        Block = GameObject.Find("BlockGroup");  //!BlockGroup取得
    }

    // Update is called once per frame
    void Update()
    {

        if (ball != null && Block != null)  
        {
            //!移動
            Move();
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
}
