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
		g_drawer.SetUpBuffer(m_pos, OBJECTKIND::BLOCK, BLOCK_WIDTH);
	}
}



