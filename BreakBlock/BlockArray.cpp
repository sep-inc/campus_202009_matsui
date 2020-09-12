#include "BlockArray.h"
#include "Drawer.h"


/* メンバ変数の初期化 */
void BlockArray::Init()
{
	/* Blockをワールド座標で配置 */
	SetUpBlocks();
}

/* ステップ処理 */
void BlockArray::Update()
{
	switch (m_step)
	{
	case BlockArray::STEP_INIT:
		Init();
		break;
	case BlockArray::STEP_RUN:
		
		break;
	case BlockArray::STEP_OUT:

		break;
	default:
		break;
	}
}

/* BlockのWorld座標初期化 */
void BlockArray::SetUpBlocks()
{
	
	Vec2 pos = Vec2(0.0f, 0.0f);  //ワールド座標初期化

	/* 現在のposにBlockの幅を足して次のposを出す用*/
	float block_width = 0.0f;         //横幅
	float block_height = 0.0f;        //縦幅


	/* Blockの数分回す */
	for (int y = FOR_FARST_NUM; y < BLOCK_NUM_Y; y++)
	{
		for (int x = FOR_FARST_NUM; x < BLOCK_NUM_X; x++)
		{
			m_block[y][x].Init(pos, 0.0f, true);

			pos.X += BLOCK_WIDTH;
		}

		pos.X = 0.0f;
		pos.Y += BLOCK_HEIGHT;   //Wallの次のpos(16,16)に
	}

	/* 次のステップへ */
	m_step = BlockArray::STEP_RUN;
}

/* 各BlockのWorld座標を描画座標に変換 */
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
