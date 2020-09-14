#include "../Header/Ball.h"
#include "../Header/ObjectBase.h"
#include "../Header/Definition.h"

/* �����o�ϐ��̏����� */
void Ball::Init()
{
	Vec2 pos = Vec2(152.0f, 72.0f);  //���[���h���W������
	ObjectBase::Init(pos, 16.0f, true);

	m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;
	m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;

	/* �����蔻��t���O������ */
	m_collision_type = {
		false,false,false,false,false,false,false,false
	};

	m_first_blocks_pos = Vec2(0.0f, 0.0f);
	m_second_blocks_pos = Vec2(0.0f, 16.0f);

	/* ���̃X�e�b�v�� */
	m_step = Ball::STEP_RUN;
}

/* �X�e�b�v���� */
void Ball::Update()
{
	switch (m_step)
	{
	case Ball::STEP_INIT:  //������
		Init(); 
		break;
	case Ball::STEP_RUN:  //�ړ��܂ł̏���
		Move();
		break;
	case Ball::STEP_OUT:  //��~
		Out();
		break;
	default:
		break;
	}
}



/* Ball�̈ړ��܂ł̏��� */
void Ball::Move()
{
	switch (m_move_step)
	{
	case Ball::STEP_HIT:
		Hit();
	case Ball::STEP_DIRECTION:
		DirectionChange();
	case Ball::STEP_MOVE:
		/* ���ɗ������Ƃ� */
		if (m_collision_type.m_out == true)
		{
			/* �I�������� */
			m_step = Ball::STEP_OUT;
			break;
		}

		/* ���݂�pos�X�V */
		m_pos.X += m_speed * m_direction_vec.X;  
		m_pos.Y += m_speed * m_direction_vec.Y; 

		/* 1�t���[�����pos�X�V */
		m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;  
		m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;  

		/* �����蔻��X�e�b�v�� */
		m_move_step = STEP_HIT;
		break;
	default:
		break;
	}
}

/* �����蔻��܂Ƃ� */
void Ball::Hit()
{
	switch (m_hit_step)
	{
	case Ball::STEP_WALL:
		HitWall();  //��
	case Ball::STEP_BAR:
		HitBar();	//Bar
	case Ball::STEP_BLOCK:
		HitBlocks(); //Block
	default:
		break;
	}

	m_move_step = STEP_DIRECTION;
}

#pragma region �eObject�Ƃ̓����蔻��
/* �ǂƂ̂����蔻�� */
void Ball::HitWall()
{
	/* �����蔻��t���O������ */
	m_collision_type.m_left_right_wall = false; 
	m_collision_type.m_top_under_wall = false;


	/* �㉺�̕� */
	if (m_pos.Y - BALL_RADIUS <= Start_Pos_X || m_pos.Y + BALL_RADIUS >= GAME_HEIGHT)
	{
		m_collision_type.m_top_under_wall = true;

		if (m_pos.Y + BALL_RADIUS >= GAME_HEIGHT)
		{
			m_collision_type.m_out = true;
		}
	}
	/* ���E�̕� */
	if (m_pos.X - BALL_RADIUS <= Start_Pos_X || m_pos.X + BALL_RADIUS >= GAME_WIDTH)
	{
		m_collision_type.m_left_right_wall = true;
	}

	/* Bar�Ƃ̓����蔻��� */ 
	m_hit_step = STEP_BAR;
}

/* Bar�Ƃ̂����蔻�� */
void Ball::HitBar()
{
	/* Bar�Ƃ̏㉺�ӂ̂����蔻�� */
	if (Hit_Rect_TopUnder(m_pos, g_bar.GetPos() , BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_top_under_bar = true;
		m_next_pos = Vec2(m_pos.X + m_speed * m_direction_vec.X, m_pos.Y + m_speed * -m_direction_vec.Y);
	}
	/* Bar�Ƃ̍��E�ӂ̂����蔻�� */
	else if (Hit_Rect_LeftRight(m_pos, g_bar.GetPos(), BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_left_right_bar = true;
		m_next_pos = Vec2(m_pos.X + m_speed * -m_direction_vec.X, m_pos.Y + m_speed * m_direction_vec.Y);
	}
	else
	{
		m_collision_type.m_top_under_bar = false;
		m_collision_type.m_left_right_bar = false;
	}

	/* 1�t���[�����Ballpos��Bar�ɓ������Ă��āA�������x�N�g���𔽓]��������̐�ɂ�����xBar����������(�o�O�΍�) */
	if (HitVec(m_next_pos, g_bar.GetPos(), BAR_WIDTH, BAR_HEIGHT) == true)
	{
		/* �������Ă����ꍇ�����x�N�g���𔽓]�����Ȃ��悤�ɂ��� */
		m_collision_type.m_during_bar = true;
	}
	else
	{
		m_collision_type.m_during_bar = false;
	}

	/* Block�Ƃ̓����蔻��� */
	m_hit_step = STEP_BLOCK;
}

/* Block�Q�̓����蔻�� */
void Ball::HitBlocks()
{
	/* �����蔻��t���O������ */
	m_collision_type.m_top_under_block = false;
	m_collision_type.m_left_right_block = false;

	/* 2�i�ڂ�Block�Q�̓����蔻�� */
	if (Hit_Rect_TopUnder(m_pos, m_second_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true
		|| Hit_Rect_LeftRight(m_pos, m_second_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true)
	{
		HitBlockUnit(1);
	}
	/* 1�i�ڂ�Block�Q�̓����蔻�� */
	if (Hit_Rect_TopUnder(m_pos, m_first_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true
		|| Hit_Rect_LeftRight(m_pos, m_first_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true)
	{
		HitBlockUnit(0);
	}
	
	/* �ŏ��̃X�e�b�v�� */
	m_hit_step = STEP_WALL;
}

/* Block�P�̂̓����蔻�� */
void Ball::HitBlockUnit(float y_)
{
	for (int x = FOR_FARST_NUM; x < BLOCK_NUM_X; x++)
	{
		/* �㉺�ӂ̂����蔻�� */
		if (Hit_Rect_TopUnder(m_pos, g_blockarray.GetBlockPos(x, y_), BALL_RADIUS, BLOCK_WIDTH, BLOCK_HEIGHT) == true)
		{
			m_collision_type.m_top_under_block = true;
			m_delete_pos.X = static_cast<float>(x);
			m_delete_pos.Y = static_cast<float>(y_);
			break;
		}
		/* ���E�ӂ̂����蔻�� */
		else if (Hit_Rect_LeftRight(m_pos, g_blockarray.GetBlockPos(x, y_), BALL_RADIUS, BLOCK_WIDTH, BLOCK_HEIGHT) == true)
		{
			m_collision_type.m_left_right_block = true;
			m_delete_pos.X = static_cast<float>(x);
			m_delete_pos.Y = static_cast<float>(y_);
			break;
		}
		
		/* 1�ԏ�̒i�ȊO��Block�Q�Ƃ̓����蔻�� */
		if (y_ != 0)
		{
			/* �΂߂̓����蔻�� */
			if (HitVec(m_next_pos, g_blockarray.GetBlockPos(x, y_), BLOCK_WIDTH, BLOCK_HEIGHT) == true)
			{
				m_collision_type.m_top_under_block = true;     //�t���O�ύX
				m_collision_type.m_left_right_block = true;    //�t���O�ύX
				m_delete_pos.X = static_cast<float>(x);        //�ǂ�Block�ɓ�����������m�邽�߂ɕۑ��p�ϐ��ɑ��
				m_delete_pos.Y = static_cast<float>(y_);
				break;
			}
		}
		
	}
}
#pragma endregion 

/* �����x�N�g���ϊ� */
void Ball::DirectionChange()
{
	/* �ǂɓ��������� */
	if (m_collision_type.m_left_right_wall == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	if (m_collision_type.m_top_under_wall == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* Bar�ɓ��������� */
	if (m_collision_type.m_left_right_bar == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	else if (m_collision_type.m_top_under_bar == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* Block�ɓ��������� */
	if (m_collision_type.m_left_right_block == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	if (m_collision_type.m_top_under_block == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* Bar�ɖ��܂�����(��O����) */
	if (m_collision_type.m_during_bar == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* �ړ��X�e�b�v�� */
	m_move_step = STEP_MOVE;
}

/* �I������ */
void Ball::Out()
{
	m_speed = 0.0f; //�������~�߂�
}


/* Ball��World���W��`����W�ɕϊ� */
void Ball::SetDrawBuffer()
{
	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(Vec2(m_pos.X - BALL_RADIUS, m_pos.Y - BALL_RADIUS), OBJECTKIND::BALL, (BALL_RADIUS + BALL_RADIUS));
	}
}