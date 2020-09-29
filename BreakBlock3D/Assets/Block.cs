using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Block : MonoBehaviour
{
    [SerializeField]GameObject blockwidth;

    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnCollisionEnter(Collision collision)
    {
       blockwidth.GetComponent<BlockWidth>().CheckBlock();   //!Blockが消えたときにBlockwidthに通知する
       Destroy(gameObject);   //!Ballにあたると削除
    }

   
}
