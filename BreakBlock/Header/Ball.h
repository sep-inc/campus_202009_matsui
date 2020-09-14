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
	Ball() :m_step(STEP::STEP_INIT), m_move_step(STEP_HIT), m_hit_step(STEP_WALL),
		m_direction_vec(Vec2(1.0f, 1.0f)), m_next_pos(Vec2(0.0f, 0.0f)), m_delete_pos(Vec2(0.0f, 0.0f)),
		m_rote_volume(2.0f)
	{}
	~Ball() {}

	void Init();                       //������
	void Update();			           //�X�e�b�v�����֐�
	void SetDrawBuffer();              //���[���h���W��`����W�ɕϊ�
							           
	void Move();                       //�ړ��֐�
	void DirectionChange();         //�����x�N�g���ϊ��֐�
	
	


							      
	void Hit();                   //�����蔻��܂Ƃߊ֐�
	void HitWall();			      //�ǂƂ̓����蔻��
	void HitBar();			      //Bar�Ƃ̓����蔻��
	void HitBlocks();		      //Block�Q�Ƃ̓����蔻��

	void HitBlockUnit(__int8 y_);  //Block�P�̂Ƃ̓����蔻��

	void Out();

	/* �����蔻��̎�� */
	struct CollisionType
	{
		bool m_top_under_wall;     //Wall�̏㉺�̂����蔻��t���O
		bool m_left_right_wall;	   //Wall�̍��E�̂����蔻��t���O
		bool m_top_under_bar;	   //Bar�̏㉺�̂����蔻��t���O
		bool m_left_right_bar;	   //Bar�̏㉺�̂����蔻��t���O
		bool m_top_under_block;    //Block�̏㉺�̂����蔻��t���O
		bool m_left_right_block;   //Block�̏㉺�̂����蔻��t���O

		bool m_during_bar;         //Block�̏㉺�̂����蔻��t���O
		bool m_out;                //Ball�����ɗ������Ƃ�

	}m_collision_type;

	/* ����Block�̍��W�ۑ��p */
	const Vec2 GetDeletePos() { return m_delete_pos; }

	/* Block�������̃t���O */
	const CollisionType GetHiter() { return m_collision_type; }

private:
	//�X�e�b�v�̎��
	enum STEP
	{
		STEP_INIT,     //������
		STEP_RUN,	   //�ړ��܂ł̏���
		STEP_OUT	   //���
	}m_step;

	/* �ړ�����܂ł̏��� */
	enum MOVE_STEP
	{
		STEP_HIT,         //�����蔻��
		STEP_DIRECTION,   //�����x�N�g���ϊ�
		STEP_MOVE,        //�ړ�
	}m_move_step;

	/* �����蔻��̏��� */
	enum HIT_STEP
	{
		STEP_WALL,        //��
		STEP_BAR,         //Bar
		STEP_BLOCK,       //Block
	}m_hit_step;
	 
	Vec2 m_direction_vec;       //�����x�N�g��

	Vec2 m_next_pos;            //1�t���[����̍��W

	Vec2 m_delete_pos;          //Block����pos_x�ۑ��p


	/* ��1���Block��1�Q�ƍl���� */
	Vec2 m_first_blocks_pos;    //1�i�ڂ�Block�Q��pos
	Vec2 m_second_blocks_pos;	//2�i�ڂ�Block�Q��pos

	float m_rote_volume;
};


#endif