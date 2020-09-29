using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlockGroup : MonoBehaviour
{
    int block_width_count = 15;   //!Block横群の数
    [SerializeField] GameObject ball;
    [SerializeField] GameObject bar;


    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        //!Block横群が無くなった時
        if (block_width_count <= 0)
        {
            ball.GetComponent<Ball>().CheckBlock();  //!Ballに通知する
            bar.GetComponent<Bar>().CheckBlock();    //!Barに通知する
            Destroy(gameObject);
        }
    }

    public void CheckBlockWidth()
    {
        block_width_count--;
    }
}
