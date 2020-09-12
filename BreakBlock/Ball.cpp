#include "Ball.h"
#include "ObjectBase.h"
#include "Definition.h"

/* メンバ変数の初期化 */
void Ball::Init()
{
	Vec2 pos = Vec2(152.0f, 72.0f);  //ワールド座標初期化
	ObjectBase::Init(pos, 16.0f, true);

	m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;
	m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;

	/* あたり判定フラグ初期化 */
	m_collision_type = {
		false,false,false,false,false,false
	};

	m_delete_pos = Vec2(0.0f, 0.0f);

	/* 次のステップへ */
	m_step = Ball::STEP_MOVE;
}

/* ステップ処理 */
void Ball::Update()
{
	switch (m_step)
	{
	case Ball::STEP_INIT:
		Init();
		break;
	case Ball::STEP_MOVE:
		Move();
		break;
	case Ball::STEP_OUT:

		break;
	default:
		break;
	}
}

/* BallのWorld座標を描画座標に変換 */
void Ball::SetDrawBuffer()
{
	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(Vec2(m_pos.X - BALL_RADIUS, m_pos.Y - BALL_RADIUS), OBJECTKIND::BALL, (BALL_RADIUS + BALL_RADIUS));
	}
}

/* Ballの移動までの処理 */
void Ball::Move()
{

	Hit();

	DirectionChange();


	m_pos.X += m_speed * m_direction_vec.X;
	m_pos.Y += m_speed * m_direction_vec.Y;



	m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;
	m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;
}

/* 方向ベクトル変換 */
void Ball::DirectionChange()
{
	if (m_collision_type.m_left_right_wall == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	if (m_collision_type.m_top_under_wall == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	if (m_collision_type.m_left_right_bar == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	else if (m_collision_type.m_top_under_bar == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	if (m_collision_type.m_left_right_block == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	if (m_collision_type.m_top_under_block == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

}

/* 当たり判定まとめ */
void Ball::Hit()
{
	HitWall();  //壁
	HitBar();	//Bar
	HitBlock();
}

/* 壁とのあたり判定 */
void Ball::HitWall()
{
	if (m_pos.X - BALL_RADIUS <= Start_Pos_X || m_pos.X + BALL_RADIUS >= GAME_WIDTH)
	{
		m_collision_type.m_left_right_wall = true;
	}
	else if (m_pos.Y - BALL_RADIUS <= Start_Pos_X || m_pos.Y + BALL_RADIUS >= GAME_HEIGHT)
	{
		m_collision_type.m_top_under_wall = true;
	}
	else
	{
		m_collision_type.m_left_right_wall = false;
		m_collision_type.m_top_under_wall = false;
	}
}

/* Barとのあたり判定 */
void Ball::HitBar()
{
	/* Barとの上下辺のあたり判定 */
	if (Hit_Rect_TopUnder(m_pos, g_bar.GetPos() , BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_top_under_bar = true;
	}
	/* Barとの左右辺のあたり判定 */
	if (Hit_Rect_LeftRight(m_pos, g_bar.GetPos(), BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_left_right_bar = true;
	}
	else
	{
		m_collision_type.m_top_under_bar = false;
		m_collision_type.m_left_right_bar = false;
	}
}

void Ball::HitBlock()
{
	for (int y = FOR_FARST_NUM; y < BLOCK_NUM_Y; y++)
	{
		for (int x = FOR_FARST_NUM; x < BLOCK_NUM_X; x++)
		{
			if (Hit_Rect_TopUnder(m_pos, g_blockarray.GetBlockPos(x,y), BALL_RADIUS, BLOCK_WIDTH, BLOCK_HEIGHT) == true)
			{
				m_collision_type.m_top_under_block = true;
				m_delete_pos.X = static_cast<float>(x);
				m_delete_pos.Y = static_cast<float>(y);
				break;
			}
			/* Barとの左右辺のあたり判定 */
			else if (Hit_Rect_LeftRight(m_pos, g_blockarray.GetBlockPos(x, y), BALL_RADIUS, BLOCK_WIDTH, BLOCK_HEIGHT) == true)
			{
				m_collision_type.m_left_right_block = true;
				m_delete_pos.X = static_cast<float>(x);
				m_delete_pos.Y = static_cast<float>(y);
				break;
			}
			else
			{
				m_collision_type.m_top_under_block = false;
				m_collision_type.m_left_right_block = false;
			}

			if (HitVec(m_next_pos, g_blockarray.GetBlockPos(x, y), BLOCK_WIDTH, BLOCK_HEIGHT) == true)
			{
				m_collision_type.m_top_under_block = true;     //フラグ変更
				m_collision_type.m_left_right_block = true;    //フラグ変更
				m_delete_pos.X = static_cast<float>(x);  //どのBlockにあたったかを知るために保存用変数に代入
				m_delete_pos.Y = static_cast<float>(y);
				break;
			}
		}


		if (m_collision_type.m_top_under_block == true
			|| m_collision_type.m_left_right_block == true)
		{
			break;
		}
	}
	
}
