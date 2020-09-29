using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    Rigidbody rb;
    [SerializeField]Vector3 force;   //!押し出すベクトル用
    [SerializeField] GameObject bar; //!Bar取得

    public int rife;　　　           //!ライフ数
    
    bool block_deth;                 //!Blockが残っているかどうか用

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();   //!コンポーネント取得

        //!Barの上にくっつくようにする
        gameObject.transform.position = new Vector3(bar.transform.position.x, bar.transform.position.y + bar.transform.localScale.y, bar.transform.position.z);

        //!親子関係設定
        gameObject.transform.parent = bar.transform;

        block_deth = false;
    }

    // Update is called once per frame
    void Update()
    {
        //!リターンキーを押した時
        if (Input.GetKeyDown(KeyCode.Return))
        {
            rb.AddForce(force);                    //!力を加える
            gameObject.transform.parent = null;    //!親子関係を切り離し
        }
    
        //!ライフがなくなった消す
        if (rife <= 0)
        {
            bar.GetComponent<Bar>().CheckBall();  //!Barを止めるフラグをtrueに
            Destroy(gameObject);                  //!削除
        }
        //!Blockが全てなくなった時
        else if(block_deth==true)
        {
            rb.velocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        //!画面下(下のフレームに触れたら死亡)
        if(collision.gameObject.tag=="DethLine")
        {
            rife--;  //!ライフを1つ減らす

            //!動きを止める
            rb.velocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;

            //!STEP.MOVEまでBarの座標にくっつく
            gameObject.transform.position = new Vector3(bar.transform.position.x, bar.transform.position.y + bar.transform.localScale.y, bar.transform.position.z);

            //!再び親子関係設定
            gameObject.transform.parent = bar.transform;
        }
    }

    public void CheckBlock()  //!Blockが無くなったかどうか調べる
    {
        block_deth = true;
    }
}
