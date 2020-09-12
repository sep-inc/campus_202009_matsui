#ifndef BAR_H_
#define BAR_H_
#include "ObjectBase.h"
#include "Drawer.h"
#include "World.h"                     

class Bar :public ObjectBase
{
public:
	Bar() :m_step(STEP::STEP_INIT), m_hit_wall(false), m_direction_X(1.0f)   //this�̃����o�ϐ��̓����o�C�j�V�����C�U�ŏ�����
	{}
	~Bar() {}

	virtual void Init();      //������
	virtual void Update();    //�X�e�b�v�����֐�

	void SetUpDrawBuffer();   //���[���h���W��`����W�ɕϊ�
	void Move();              //�ړ��֐�
	void Hit();               //�����蔻��֐�

private:
	//�X�e�b�v�̎��
	enum STEP
	{
		STEP_INIT,        //������
		STEP_MOVE,        //�ړ��܂ł̏���
		STEP_OUT		  //���
	}m_step;

	bool m_hit_wall;        //�t���[���ɓ����������t���O
	float m_direction_X;    //�����x�N�g��(���E�ɂ����ړ����Ȃ��̂�X������)


};

#endif