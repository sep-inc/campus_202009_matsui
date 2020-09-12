#include "../Header/Block.h"
#include "../Header/Drawer.h"
#include "../Header/Definition.h"
#include "../Header/BlockArray.h"

/* ƒƒ“ƒo•Ï”‚Ì‰Šú‰» */
void Block::Init(Vec2 pos_, float speed_, bool eneable_)
{
	ObjectBase::Init(pos_, speed_, eneable_);
}

/* Block‚ÌWorldÀ•W‚ğ•`‰æÀ•W‚É•ÏŠ· */
void Block::SetBlockBuufer()
{

	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(m_pos, OBJECTKIND::BLOCK, BLOCK_WIDTH);
	}
}



