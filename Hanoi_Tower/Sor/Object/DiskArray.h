#ifndef DISKARRAY_H_
#define DISKARRAY_H_
#include "Disk.h"

class DiskArray
{
public:
	DiskArray() {}
	~DiskArray() {}

    void StepChange();      //ステップ処理
    void Init();            //初期化 

    void Move();            //移動

    void SetUpDrawBuffer(); //オブジェクトセット関数
    void SetUpBox();        //Boxに代入

private:
    enum Step
    {
        STEP_INIT,
        STEP_MOVE,
        STEP_DRAW
    }m_step;

    Disk m_disk[3];    //disk単体
};

#endif 