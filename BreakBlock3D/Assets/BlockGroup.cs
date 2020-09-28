using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlockGroup : MonoBehaviour
{
    int count;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        //!BlockPrefabsが無くなった時
        count = transform.childCount;

        if(count<=0)
        {
            Destroy(gameObject);
        }
    }
}
