#include "../Header/Block.h"
#include "../Header/Drawer.h"
#include "../Header/Definition.h"
#include "../Header/BlockArray.h"

/* �����o�ϐ��̏����� */
void Block::Init(Vec2 pos_, float speed_, bool eneable_)
{
	ObjectBase::Init(pos_, speed_, eneable_);
}

/* Block��World���W��`����W�ɕϊ� */
void Block::SetBlockBuufer()
{

	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(Vec2(m_pos.X + START_POS_X, m_pos.Y + START_POS_Y), OBJECTKIND::BLOCK, BLOCK_WIDTH);
	}
}



