#include "Ball.h"
#include "ObjectBase.h"
#include "Definition.h"

/* �����o�ϐ��̏����� */
void Ball::Init()
{
	Vec2 pos = Vec2(152.0f, 72.0f);  //���[���h���W������
	ObjectBase::Init(pos, 16.0f, true);

	m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;
	m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;

	/* �����蔻��t���O������ */
	m_collision_type = {
		false,false,false,false
	};

	/* ���̃X�e�b�v�� */
	m_step = Ball::STEP_MOVE;
}

/* �X�e�b�v���� */
void Ball::Update()
{
	switch (m_step)
	{
	case Ball::STEP_INIT:
		Init();
		break;
	case Ball::STEP_MOVE:
		Move();
		break;
	case Ball::STEP_OUT:

		break;
	default:
		break;
	}
}

/* Ball��World���W��`����W�ɕϊ� */
void Ball::SetDrawBuffer()
{
	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(Vec2(m_pos.X + BALL_RADIUS, m_pos.Y + BALL_RADIUS), OBJECTKIND::BALL, (BALL_RADIUS + BALL_RADIUS));
	}
}

/* Ball�̈ړ��܂ł̏��� */
void Ball::Move()
{

	Hit();

	DirectionChange();


	m_pos.X += m_speed * m_direction_vec.X;
	m_pos.Y += m_speed * m_direction_vec.Y;



	m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;
	m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;
}

/* �����x�N�g���ϊ� */
void Ball::DirectionChange()
{
	if (m_collision_type.m_left_right_wall == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	else if (m_collision_type.m_top_under_wall == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	if (m_collision_type.m_left_right_bar == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	else if (m_collision_type.m_top_under_bar == true)
	{
		m_direction_vec.Y *= -1.0f;
	}
}

/* �����蔻��܂Ƃ� */
void Ball::Hit()
{
	HitWall();  //��
	HitBar();	//Bar
}

/* �ǂƂ̂����蔻�� */
void Ball::HitWall()
{
	if (m_pos.X <= Start_Pos_X || m_pos.X + BALL_RADIUS >= GAME_WIDTH)
	{
		m_collision_type.m_left_right_wall = true;
	}
	else if (m_pos.Y <= Start_Pos_X || m_pos.Y + BALL_RADIUS >= GAME_HEIGHT)
	{
		m_collision_type.m_top_under_wall = true;
	}
	else
	{
		m_collision_type.m_left_right_wall = false;
		m_collision_type.m_top_under_wall = false;
	}
}

/* Bar�Ƃ̂����蔻�� */
void Ball::HitBar()
{
	/* Bar�Ƃ̏㉺�ӂ̂����蔻�� */
	if (Hit_Rect_TopUnder(m_pos, g_bar.GetPos() , BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_top_under_bar = true;
	}
	/* Bar�Ƃ̍��E�ӂ̂����蔻�� */
	else if (Hit_Rect_LeftRight(m_pos, g_bar.GetPos(), BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_left_right_bar = true;
	}
	else
	{
		m_collision_type.m_top_under_bar = false;
		m_collision_type.m_left_right_bar = false;
	}
}
