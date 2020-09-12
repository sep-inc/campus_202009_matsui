#include "Bar.h"
#include "Definition.h"

/* �����o�ϐ��̏����� */
void Bar::Init()
{
	Vec2 pos;
	pos.X = UNIT_X + ((GAME_WIDTH / 2) - BAR_WIDTH);    //Game�����̒���������
	pos.Y = UNIT_X + (GAME_HEIGHT / 2);				   //Game�c���̒���������

	float speed = 16.0f;

	ObjectBase::Init(pos, speed, true);

	m_step = Bar::STEP_MOVE;
}

/* �X�e�b�v���� */
void Bar::Update()
{
	switch (m_step)
	{
	case Bar::STEP_INIT:
		Init();
		break;
	case Bar::STEP_MOVE:
		Move();
		break;
	case Bar::STEP_OUT:

		break;
	default:
		break;
	}
}

/* Bar��World���W��`����W�ɕϊ� */
void Bar::SetUpDrawBuffer()
{
	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(m_pos, OBJECTKIND::BAR, BAR_WIDTH);
	}
}

/* Bar�̈ړ��܂ł̏��� */
void Bar::Move()
{
	Hit();

	/* �������Ă���������x�N�g���ύX */
	if (m_hit_wall == true)
	{
		m_direction_X *= -1.0f;
	}

	/* �ړ� */
	m_pos.X += m_direction_X * m_speed;
}

/* �����蔻��܂Ƃ� */
void Bar::Hit()
{
	/* ���[���h���W���t���[���������čl���Ă�̂ŉE��Max�l��Unit��x2 */
	if (m_pos.X <= Start_Pos_X || m_pos.X + BAR_WIDTH >= GAME_WIDTH)
	{
		m_hit_wall = true;
	}
	else
	{
		m_hit_wall = false;
	}
}
