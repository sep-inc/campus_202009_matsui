#include "Bar.h"
#include "Definition.h"

/* メンバ変数の初期化 */
void Bar::Init()
{
	Vec2 pos;
	pos.X = UNIT_X + ((GAME_WIDTH / 2) - BAR_WIDTH);    //Game横幅の中央あたり
	pos.Y = UNIT_X + (GAME_HEIGHT / 2);				   //Game縦幅の中央あたり

	float speed = 16.0f;

	ObjectBase::Init(pos, speed, true);

	m_step = Bar::STEP_MOVE;
}

/* ステップ処理 */
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

/* BarのWorld座標を描画座標に変換 */
void Bar::SetUpDrawBuffer()
{
	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(m_pos, OBJECTKIND::BAR, BAR_WIDTH);
	}
}

/* Barの移動までの処理 */
void Bar::Move()
{
	Hit();

	/* 当たっていたら方向ベクトル変更 */
	if (m_hit_wall == true)
	{
		m_direction_X *= -1.0f;
	}

	/* 移動 */
	m_pos.X += m_direction_X * m_speed;
}

/* 当たり判定まとめ */
void Bar::Hit()
{
	/* ワールド座標をフレームを除いて考えてるので右のMax値はUnitはx2 */
	if (m_pos.X <= Start_Pos_X || m_pos.X + BAR_WIDTH >= GAME_WIDTH)
	{
		m_hit_wall = true;
	}
	else
	{
		m_hit_wall = false;
	}
}
