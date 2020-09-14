#include "../Header/Ball.h"
#include "../Header/ObjectBase.h"
#include "../Header/Definition.h"

/* メンバ変数の初期化 */
void Ball::Init()
{
	Vec2 pos = Vec2(152.0f, 72.0f);  //ワールド座標初期化
	ObjectBase::Init(pos, 16.0f, true);

	m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;
	m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;

	/* あたり判定フラグ初期化 */
	m_collision_type = {
		false,false,false,false,false,false,false,false
	};

	m_first_blocks_pos = Vec2(0.0f, 0.0f);
	m_second_blocks_pos = Vec2(0.0f, 16.0f);

	/* 次のステップへ */
	m_step = Ball::STEP_RUN;
}

/* ステップ処理 */
void Ball::Update()
{
	switch (m_step)
	{
	case Ball::STEP_INIT:  //初期化
		Init(); 
		break;
	case Ball::STEP_RUN:  //移動までの処理
		Move();
		break;
	case Ball::STEP_OUT:  //停止
		Out();
		break;
	default:
		break;
	}
}



/* Ballの移動までの処理 */
void Ball::Move()
{
	switch (m_move_step)
	{
	case Ball::STEP_HIT:
		Hit();
	case Ball::STEP_DIRECTION:
		DirectionChange();
	case Ball::STEP_MOVE:
		/* 下に落ちたとき */
		if (m_collision_type.m_out == true)
		{
			/* 終了処理へ */
			m_step = Ball::STEP_OUT;
			break;
		}

		/* 現在のpos更新 */
		m_pos.X += m_speed * m_direction_vec.X;  
		m_pos.Y += m_speed * m_direction_vec.Y; 

		/* 1フレーム先のpos更新 */
		m_next_pos.X = m_pos.X + m_speed * m_direction_vec.X;  
		m_next_pos.Y = m_pos.Y + m_speed * m_direction_vec.Y;  

		/* 当たり判定ステップへ */
		m_move_step = STEP_HIT;
		break;
	default:
		break;
	}
}

/* 当たり判定まとめ */
void Ball::Hit()
{
	switch (m_hit_step)
	{
	case Ball::STEP_WALL:
		HitWall();  //壁
	case Ball::STEP_BAR:
		HitBar();	//Bar
	case Ball::STEP_BLOCK:
		HitBlocks(); //Block
	default:
		break;
	}

	m_move_step = STEP_DIRECTION;
}

#pragma region 各Objectとの当たり判定
/* 壁とのあたり判定 */
void Ball::HitWall()
{
	/* 当たり判定フラグ初期化 */
	m_collision_type.m_left_right_wall = false; 
	m_collision_type.m_top_under_wall = false;


	/* 上下の壁 */
	if (m_pos.Y - BALL_RADIUS <= Start_Pos_X || m_pos.Y + BALL_RADIUS >= GAME_HEIGHT)
	{
		m_collision_type.m_top_under_wall = true;

		if (m_pos.Y + BALL_RADIUS >= GAME_HEIGHT)
		{
			m_collision_type.m_out = true;
		}
	}
	/* 左右の壁 */
	if (m_pos.X - BALL_RADIUS <= Start_Pos_X || m_pos.X + BALL_RADIUS >= GAME_WIDTH)
	{
		m_collision_type.m_left_right_wall = true;
	}

	/* Barとの当たり判定へ */ 
	m_hit_step = STEP_BAR;
}

/* Barとのあたり判定 */
void Ball::HitBar()
{
	/* Barとの上下辺のあたり判定 */
	if (Hit_Rect_TopUnder(m_pos, g_bar.GetPos() , BALL_RADIUS, BAR_WIDTH, BAR_HEIGHT) == true)
	{
		m_collision_type.m_top_under_bar = true;
		m_next_pos = Vec2(m_pos.X + m_speed * m_direction_vec.X, m_pos.Y + m_speed * -m_direction_vec.Y);
	}
	/* Barとの左右辺のあたり判定 */
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

	/* 1フレーム先のBallposがBarに当たっていて、かつ方向ベクトルを反転させた後の先にもう一度Barがあった時(バグ対策) */
	if (HitVec(m_next_pos, g_bar.GetPos(), BAR_WIDTH, BAR_HEIGHT) == true)
	{
		/* 当たっていた場合方向ベクトルを反転させないようにする */
		m_collision_type.m_during_bar = true;
	}
	else
	{
		m_collision_type.m_during_bar = false;
	}

	/* Blockとの当たり判定へ */
	m_hit_step = STEP_BLOCK;
}

/* Block群の当たり判定 */
void Ball::HitBlocks()
{
	/* 当たり判定フラグ初期化 */
	m_collision_type.m_top_under_block = false;
	m_collision_type.m_left_right_block = false;

	/* 2段目のBlock群の当たり判定 */
	if (Hit_Rect_TopUnder(m_pos, m_second_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true
		|| Hit_Rect_LeftRight(m_pos, m_second_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true)
	{
		HitBlockUnit(1);
	}
	/* 1段目のBlock群の当たり判定 */
	if (Hit_Rect_TopUnder(m_pos, m_first_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true
		|| Hit_Rect_LeftRight(m_pos, m_first_blocks_pos, BALL_RADIUS, BLOCK_STAGE_WIDTH, BLOCK_STAGE_HEIGHT) == true)
	{
		HitBlockUnit(0);
	}
	
	/* 最初のステップへ */
	m_hit_step = STEP_WALL;
}

/* Block単体の当たり判定 */
void Ball::HitBlockUnit(float y_)
{
	for (int x = FOR_FARST_NUM; x < BLOCK_NUM_X; x++)
	{
		/* 上下辺のあたり判定 */
		if (Hit_Rect_TopUnder(m_pos, g_blockarray.GetBlockPos(x, y_), BALL_RADIUS, BLOCK_WIDTH, BLOCK_HEIGHT) == true)
		{
			m_collision_type.m_top_under_block = true;
			m_delete_pos.X = static_cast<float>(x);
			m_delete_pos.Y = static_cast<float>(y_);
			break;
		}
		/* 左右辺のあたり判定 */
		else if (Hit_Rect_LeftRight(m_pos, g_blockarray.GetBlockPos(x, y_), BALL_RADIUS, BLOCK_WIDTH, BLOCK_HEIGHT) == true)
		{
			m_collision_type.m_left_right_block = true;
			m_delete_pos.X = static_cast<float>(x);
			m_delete_pos.Y = static_cast<float>(y_);
			break;
		}
		
		/* 1番上の段以外のBlock群との当たり判定 */
		if (y_ != 0)
		{
			/* 斜めの当たり判定 */
			if (HitVec(m_next_pos, g_blockarray.GetBlockPos(x, y_), BLOCK_WIDTH, BLOCK_HEIGHT) == true)
			{
				m_collision_type.m_top_under_block = true;     //フラグ変更
				m_collision_type.m_left_right_block = true;    //フラグ変更
				m_delete_pos.X = static_cast<float>(x);        //どのBlockに当たったかを知るために保存用変数に代入
				m_delete_pos.Y = static_cast<float>(y_);
				break;
			}
		}
		
	}
}
#pragma endregion 

/* 方向ベクトル変換 */
void Ball::DirectionChange()
{
	/* 壁に当たった時 */
	if (m_collision_type.m_left_right_wall == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	if (m_collision_type.m_top_under_wall == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* Barに当たった時 */
	if (m_collision_type.m_left_right_bar == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	else if (m_collision_type.m_top_under_bar == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* Blockに当たった時 */
	if (m_collision_type.m_left_right_block == true)
	{
		m_direction_vec.X *= -1.0f;
	}
	if (m_collision_type.m_top_under_block == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* Barに埋まった時(例外処理) */
	if (m_collision_type.m_during_bar == true)
	{
		m_direction_vec.Y *= -1.0f;
	}

	/* 移動ステップへ */
	m_move_step = STEP_MOVE;
}

/* 終了処理 */
void Ball::Out()
{
	m_speed = 0.0f; //動きを止める
}


/* BallのWorld座標を描画座標に変換 */
void Ball::SetDrawBuffer()
{
	if (m_eneable == true)
	{
		g_drawer.SetUpBuffer(Vec2(m_pos.X - BALL_RADIUS, m_pos.Y - BALL_RADIUS), OBJECTKIND::BALL, (BALL_RADIUS + BALL_RADIUS));
	}
}