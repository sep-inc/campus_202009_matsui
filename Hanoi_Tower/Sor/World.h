#ifndef WORLD_H_
#define WORLD_H_

enum OBJECT_TYPE
{
    BLANK,
    BOX,
    DISK
};

#define START_UNIT 0        //�ŏ��̗v�f��

#define BUFFER_WIDTH 19       //Buffer�̉���
#define BUFFER_HEIGHT 6       //Buffer�̏c��

#define BOX_NUM 3            //���̐�
#define BOX_WIDTH 5          //���̉���
#define BOX_HEIGHT 3         //���̏c��

#define BUFFER_BOX_POS_Y 2         //���̏c��
	 
#define DISK_NUM 3           //�~�Ղ̐�
#define SMALL_DISK_WIDTH 1   //���~�Ղ̉���
#define NOMAL_DISK_WIDTH 3   //���Ղ̉���
#define BIG_DISK_WIDTH 5     //��Ղ̉���
#define DISK_HEIGHT 1        //�~�Ղ̏c��

#define DISK_MAX_WIDTH 6        //�~�Ղ̏c��


#endif 