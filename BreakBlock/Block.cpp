#include "Block.h"
#include "Drawer.h"
#include "Definition.h"
#include "BlockArray.h"

/* メンバ変数の初期化 */
void Block::Init(Vec2 pos_, float speed_, bool eneable_)
{
	ObjectBase::Init(pos_, speed_, eneable_);
}

/* BlockのWorld座標を描画座標に変換 */
void Block::SetBlockBuufer()
{

	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(m_pos, OBJECTKIND::BLOCK, BLOCK_WIDTH);
	}
}



