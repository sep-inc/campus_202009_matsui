#ifndef DISKARRAY_H_
#define DISKARRAY_H_
#include "Disk.h"

class DiskArray
{
public:
	DiskArray() {}
	~DiskArray() {}

    void StepChange();      //�X�e�b�v����
    void Init();            //������ 

    void Move();            //�ړ�

    void SetUpDrawBuffer(); //�I�u�W�F�N�g�Z�b�g�֐�
    void SetUpBox();        //Box�ɑ��

private:
    enum Step
    {
        STEP_INIT,
        STEP_MOVE,
        STEP_DRAW
    }m_step;

    Disk m_disk[3];    //disk�P��
};

#endif 