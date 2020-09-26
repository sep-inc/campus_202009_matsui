using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    Rigidbody rb;    
    Vector3 force;   //!押し出すベクトル用

    public int rife;
    [SerializeField] GameObject bar;
    GameObject block;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();   //!コンポーネント取得

        force = new Vector3(500.0f, 500.0f, 0.0f);  //!初期化

        bar = GameObject.Find("Bar");           //!Bar取得
        block = GameObject.Find("BlockGroup");  //!BlockGroup取得
    }

    // Update is called once per frame
    void Update()
    {
        //!リターンキーで押し出す
        if (Input.GetKeyDown(KeyCode.Return))
        {
            rb.AddForce(force);  //!力を加える
            bar = null;          //!Barを切り離す
        }
        else if (bar != null) 
        {
            //!Ballを押し出すまでBarの座標にくっつく
            gameObject.transform.position = new Vector3(bar.transform.position.x, bar.transform.position.y + 2.0f, bar.transform.position.z) ;
        }

        //!ライフがなくなった消す
        if (rife <= 0) 
        {
            Destroy(gameObject);   //!削除
        }
        //!Blockがなくなった時
        else if(block==null)
        {
            //!動きを止める
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
            transform.position = new Vector3(0.0f, -10.0f, 9.5f);   //!画面中央に配置

            //!動きを止める
            rb.velocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;

            //!Barの座標を受け取るために再びBarを見つける
            bar = GameObject.Find("Bar");
        }
    }

}
