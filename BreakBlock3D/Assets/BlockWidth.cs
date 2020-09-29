using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlockWidth : MonoBehaviour
{
    int block_count = 20;  //!Blockの横に並んでいる数

    [SerializeField]GameObject blockgroup;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        //!BlockPrefabsが無くなった時
        if(Input.GetKeyDown(KeyCode.R))
        {
            block_count = 0;
        }

       if (block_count <= 0)
       {
           blockgroup.GetComponent<BlockGroup>().CheckBlockWidth();  //!BlockGroupに通知する
           Destroy(gameObject);
       }
    }

    public void CheckBlock()
    {
        block_count--;
    }
}
