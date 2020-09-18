#ifndef BOXARRAY_H_
#define BOXARRAY_H_
#include "Box.h"
#include "../Vec.h"

class BoxArray
{
public:
	BoxArray():m_end(false) {}
	~BoxArray() {}

    void StepChange();        //�X�e�b�v����
    void Init();              //������
    void Search();            //��������
   
    unsigned __int8 SearchBox(unsigned __int8 pos_x_);            //�����pBox��������
    unsigned __int8 SearchPos_X(unsigned __int8 number_);         //���ׂ�Box�̊���W�X�V
    unsigned __int8 SetDiskPos_Y();                               //Box�̒��̈�ԏ�̍��W��Ԃ�

    bool SearchRightBox();                                        //�~�Ղ�3���邩���ׂ鏈��(�I���t���O)

     //Disk�𓮂����邩�ǂ����̃t���O����                                                             
    bool SearchMoveDiskSize(unsigned __int8 disk_width, unsigned __int8 now_number_, unsigned __int8 next_number_);  

    void SetUpDisk(Vec pos, unsigned  __int8 width_, unsigned  __int8 height_);      //disk�𒲍��pbox���W�ɃZ�b�g
    void SetUpDrawBuffer();                                                          //�`��z��ɃI�u�W�F�N�g�Z�b�g

    void ClearBoxBuffer();                                                //�����pbox�̒��g�N���A

    unsigned  __int8 GetNextDiskPos() { return m_now_investigation_pos; } //�ڂ�����pos��Ԃ� 
    unsigned  __int8 GetDiskPos_Y() { return m_pos_y; }                   //Disk��u���鍂����Ԃ�
    bool GetEndFlg() { return m_end; }                   //Disk��u���鍂����Ԃ�


private:
    enum Step
    {
        STEP_INIT,       //������
        STEP_SEARCH     //����
    }m_step;

    Box m_box[3];   //���P��

    unsigned __int8 m_box_buffer[6][19];  //���̒��g�����p
    unsigned __int8 m_pos_y;

    unsigned  __int8 m_disk_counter;            //���̒��g�𒲂ׂ��Ƃ�Disk�̐�
    unsigned  __int8 m_now_investigation_pos;   //�ړ��������p��pos
    unsigned  __int8 m_next_investigation_pos;  //�ړ��撲���p��pos

    bool m_end;   //�I���t���O

};


#endif 