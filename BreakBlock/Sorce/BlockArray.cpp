#include "../Header/BlockArray.h"
#include "../Header/Drawer.h"
#include "../Header/Definition.h"

/* �����o�ϐ��̏����� */
void BlockArray::Init()
{
	/* Block�����[���h���W�Ŕz�u */
	SetUpBlocks();
}

/* �X�e�b�v���� */
void BlockArray::Update()
{
	switch (m_step)
	{
	case BlockArray::STEP_INIT:
		Init();
		break;
	case BlockArray::STEP_RUN:
		DeleteBlock();
		break;
	case BlockArray::STEP_OUT:

		break;
	default:
		break;
	}
}

/* Block��World���W������ */
void BlockArray::SetUpBlocks()
{
	
	Vec2 pos = Vec2(0.0f, 0.0f);  //���[���h���W������

	/* ���݂�pos��Block�̕��𑫂��Ď���pos���o���p*/
	float block_width = 0.0f;         //����
	float block_height = 0.0f;        //�c��


	/* Block�̐����� */
	for (int y = FOR_FARST_NUM; y < BLOCK_NUM_Y; y++)
	{
		for (int x = FOR_FARST_NUM; x < BLOCK_NUM_X; x++)
		{
			m_block[y][x].Init(pos, 0.0f, true);

			pos.X += BLOCK_WIDTH;
		}

		pos.X = 0.0f;
		pos.Y += BLOCK_HEIGHT;   //Wall�̎���pos(16,16)��
	}

	/* ���̃X�e�b�v�� */
	m_step = BlockArray::STEP_RUN;
}

/* �eBlock��World���W��`����W�ɕϊ� */
void BlockArray::SetUpDrawBuufer()
{
	for (int y = FOR_FARST_NUM; y < BLOCK_NUM_Y; y++)
	{
		for (int x = FOR_FARST_NUM; x < BLOCK_NUM_X; x++)
		{
			m_block[y][x].SetBlockBuufer();
		}
	}
}

void BlockArray::DeleteBlock()
{
	if (g_ball.GetHitBlock().m_top_under_block == true
		|| g_ball.GetHitBlock().m_left_right_block == true)
	{
		int x = static_cast<__int8>(g_ball.GetDeletePos().X);
		int y = static_cast<__int8>(g_ball.GetDeletePos().Y);

		m_block[y][x].Init(Vec2(-10.0f, -10.0f), 0.0f, false);
	}
}
