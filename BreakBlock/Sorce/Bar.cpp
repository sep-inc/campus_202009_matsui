#include "../Header/Bar.h"
#include "../Header/Definition.h"

/* �����o�ϐ��̏����� */
void Bar::Init()
{
	Vec2 pos;
	pos.X = UNIT_X + ((GAME_WIDTH / 2) - BAR_WIDTH);    //Game�����̒���������
	pos.Y = UNIT_X + (GAME_HEIGHT / 2);				    //Game�c���̒���������

	float speed = 16.0f;

	ObjectBase::Init(pos, speed, true);

	/* ���̃X�e�b�v�� */
	m_step = Bar::STEP_MOVE;
}

/* �X�e�b�v���� */
void Bar::Update()
{
	switch (m_step)
	{
	case Bar::STEP_INIT:  //������
		Init();
		break;
	case Bar::STEP_MOVE:  //�ړ��܂ł̏���
		Move();
		break;
	case Bar::STEP_OUT:   //��~
		Out();
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
		g_drawer.SetUpBuffer(Vec2(m_pos.X + START_POS_X, m_pos.Y + START_POS_Y), OBJECTKIND::BAR, BAR_WIDTH);
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

	if (g_ball.GetHiter().m_out == true)
	{
		m_step = STEP_OUT;
	}
}

/* �����蔻��܂Ƃ� */
void Bar::Hit()
{
	/* ���[���h���W���t���[���������čl���Ă�̂ŉE��Max�l��Unit��x2 */
	if (m_pos.X <= START_POS_X || m_pos.X + BAR_WIDTH >= GAME_WIDTH)
	{
		m_hit_wall = true;
	}
	else
	{
		m_hit_wall = false;
	}
}

/* �I������ */
void Bar::Out()
{
	m_speed = 0.0f; //�������~�߂�
}
