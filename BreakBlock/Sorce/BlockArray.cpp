#include "../Header/BlockArray.h"
#include "../Header/Drawer.h"
#include "../Header/Definition.h"

/* メンバ変数の初期化 */
void BlockArray::Init()
{
	/* Blockをワールド座標で配置 */
	SetUpBlocks();

	/* 次のステップへ */
	m_step = BlockArray::STEP_RUN;
}

/* ステップ処理 */
void BlockArray::Update()
{
	switch (m_step)
	{
	case BlockArray::STEP_INIT:  //初期化
		Init();
		break;
	case BlockArray::STEP_RUN:  //ブロック消去までの処理
		DeleteBlock();
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

/* Block消去関数 */
void BlockArray::DeleteBlock()
{
	/* BallがBlockに当たった時 */
	if (g_ball.GetHiter().m_top_under_block == true
		|| g_ball.GetHiter().m_left_right_block == true)
	{
		int x = static_cast<__int8>(g_ball.GetDeletePos().X);   //消去する座標(X)
		int y = static_cast<__int8>(g_ball.GetDeletePos().Y);	//消去する座標(Y)

		/* 当たり判定時に座標が残っていると困るので当たらない位置に変える */
		m_block[y][x].Init(Vec2(-30.0f, -30.0f), 0.0f, false);
	}
}
