#ifndef BALL_H_
#define BALL_H_
#include "ObjectBase.h"
#include "Collision.h"
#include "Drawer.h"
#include "BlockArray.h"
#include "World.h"



class Ball : public ObjectBase
{
public:
	Ball() :m_step(STEP::STEP_INIT), m_direction_vec(Vec2(1.0f, 1.0f)), m_next_pos(Vec2(0.0f, 0.0f)) {}
	~Ball() {}

	void Init();               //������
	void Update();			   //�X�e�b�v�����֐�
	void SetDrawBuffer();      //���[���h���W��`����W�ɕϊ�

	void Move();               //�ړ��֐�
	void DirectionChange();    //�����x�N�g���ϊ��֐�

	void Hit();                //�����蔻��܂Ƃߊ֐�
	void HitWall();			   //�ǂƂ̓����蔻��
	void HitBar();			   //Bar�Ƃ̓����蔻��
	void HitBlock();			   //Bar�Ƃ̓����蔻��

	/* �����蔻��̎�� */
	struct CollisionType
	{
		bool m_top_under_wall;     //Wall�̏㉺�̂����蔻��t���O
		bool m_left_right_wall;	   //Wall�̍��E�̂����蔻��t���O
		bool m_top_under_bar;	   //Bar�̏㉺�̂����蔻��t���O
		bool m_left_right_bar;	   //Bar�̏㉺�̂����蔻��t���O
		bool m_top_under_block;   //Block�̏㉺�̂����蔻��t���O
		bool m_left_right_block;   //Block�̏㉺�̂����蔻��t���O
	}m_collision_type;

	const Vec2 GetDeletePos() { return m_delete_pos; }

	const CollisionType GetHitBlock() { return m_collision_type; }

private:
	//�X�e�b�v�̎��
	enum STEP
	{
		STEP_INIT,     //������
		STEP_MOVE,	   //�ړ��܂ł̏���
		STEP_OUT	   //���
	}m_step;

	

	 
	Vec2 m_direction_vec;        //�����x�N�g��

	Vec2 m_next_pos;             //1�t���[����̍��W

	Vec2 m_delete_pos;  //Block����pos_x�ۑ��p
	__int8 m_delete_pos_y;  //Block����pos_y�ۑ��p
};


#endif