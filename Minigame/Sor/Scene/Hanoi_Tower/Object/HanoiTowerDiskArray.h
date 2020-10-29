#ifndef HANOITOWER_DISKARRAY_H_
#define HANOITOWER_DISKARRAY_H_
#include "HanoiTowerDisk.h"
#include "HanoiTowerBoxArray.h"

class HanoiTowerDiskArray
{
public:
    HanoiTowerDiskArray() {}
    ~HanoiTowerDiskArray() {}

    void Init(HanoiTowerBoxArray* boxarray_);            //初期化 

    void Move(HanoiTowerBoxArray* boxarray_);            //移動

    void SetUpDrawBuffer(); //オブジェクトセット関数
    void SetUpBox(HanoiTowerBoxArray* boxarray_);        //Boxに代入

private:
    Disk m_disk[3];    //disk単体

    //!数字キー用
    int m_start_number;
    int m_end_number;
};

#endif 