#include "ChaseAI.h"
#include <stdlib.h>

//!コンストラクタ
ChaseAI::ChaseAI(PacManStage* stage_) :
	m_rand_direction(UP)  //!選択用移動方向ベクトル
{
	m_stage = stage_; //!ステージアドレス取得
}

//! 初期化関数
void ChaseAI::Reset()
{
	m_direction = Vec2(0, 0);  //!方向ベクトル

	m_rand_direction = static_cast<DIRECTION_TYPE>(rand() % DIRECTION_MAX);//!選択用移動方向ベクトル

	//!移動可能方向配列初期化
	for (int i = 0; i < DIRECTION_MAX; i++)
	{
		m_direction_array[i] = i;
	}

	m_direction_array[m_rand_direction] = DIRECTION_NONE;

	m_param_change = false;  //!敵のパラメーター(スピード変更フラグ)
}


//!移動方向選択関数
Vec2 ChaseAI::SelectDirection(Vec2 pos_)
{
	//!追跡範囲にプレイヤーがいる場合
	if (SearchPlayer(pos_) == true)
	{
		//!プレイヤーまでのベクトルを出す
		m_direction.x -= pos_.x;
		m_direction.y -= pos_.y;

		//!方向ベクトルを出す
		if (m_direction.x != 0)
		{
			m_direction.x /= abs(m_direction.x);
		}
		if (m_direction.y != 0)
		{
			m_direction.y /= abs(m_direction.y);
		}

		//!後退更新
		SetDirection(m_direction);

		m_param_change = true;//!追跡フラグtrue

		return m_direction;

	}
	//!プレイヤーが見つかっていない場合
	else
	{
		m_param_change = false;

		return RandDirection(pos_);
	}

	return Vec2(0, 0);
}



//!プレイヤー捜索関数
bool ChaseAI::SearchPlayer(Vec2 pos_)
{
	Vec2 enemy_pos = pos_;  //!敵の座標保存

	//!敵の座標から壁までの上方向にプレイヤーがいるか調べる
	for (int y = pos_.y; y > 0; y--)
	{
		enemy_pos.y = y;

		//!見つけた場合プレイヤーの座標を方向ベクトルに保存(正規化は後で行う)
		if (m_stage->SearchObject(enemy_pos) == PACMAN_MYSELF)
		{
			m_direction = enemy_pos;
			return true;
		}
		//!壁がある場合調べるのをやめる
		else if (m_stage->SearchObject(enemy_pos) == PACMAN_WALL)
		{
			break;
		}
	}

	//!敵の座標から壁までの下方向にプレイヤーがいるか調べる
	for (int y = pos_.y; y < PACMAN_GAME_HEIGHT; y++)
	{
		enemy_pos.y = y;

		//!見つけた場合プレイヤーの座標を方向ベクトルに保存(正規化は後で行う)
		if (m_stage->SearchObject(enemy_pos) == PACMAN_MYSELF)
		{
			m_direction = enemy_pos;
			return true;
		}
		//!壁がある場合調べるのをやめる
		else if (m_stage->SearchObject(enemy_pos) == PACMAN_WALL)
		{
			break;
		}
	}

	enemy_pos = pos_; //!X軸を調べるために座標リセット

	//!敵の座標から壁までの左方向にプレイヤーがいるか調べる
	for (int x = pos_.x; x > 0; x--)
	{
		enemy_pos.x = x;

		//!見つけた場合プレイヤーの座標を方向ベクトルに保存(正規化は後で行う)
		if (m_stage->SearchObject(enemy_pos) == PACMAN_MYSELF)
		{
			m_direction = enemy_pos;
			return true;
		}
		//!壁がある場合調べるのをやめる
		else if (m_stage->SearchObject(enemy_pos) == PACMAN_WALL)
		{
			break;
		}
	}

	//!敵の座標から壁までの右方向にプレイヤーがいるか調べる
	for (int x = pos_.x; x < PACMAN_GAME_WIDTH; x++)
	{
		enemy_pos.x = x;

		//!見つけた場合プレイヤーの座標を方向ベクトルに保存(正規化は後で行う)
		if (m_stage->SearchObject(enemy_pos) == PACMAN_MYSELF)
		{
			m_direction = enemy_pos;
			return true;
		}
		//!壁がある場合調べるのをやめる
		else if (m_stage->SearchObject(enemy_pos) == PACMAN_WALL)
		{
			break;
		}
	}

	return false;
}

//!ランダム方向選択関数
Vec2 ChaseAI::RandDirection(Vec2 pos_)
{
	//!移動できると分かるか移動先が見つからない場合まで回す
	while (true)
	{
		//!何かに衝突しようとするまで移動方向を変えない場合はコメントアウトする
		m_rand_direction = static_cast<DIRECTION_TYPE>(rand() % DIRECTION_MAX);

		//!移動先が移動方向配列に入っているかどうか
		while (SearchDirection() == false)
		{
			m_rand_direction = static_cast<DIRECTION_TYPE>(rand() % DIRECTION_MAX);
		}

		//!方向の場合分け
		switch (m_rand_direction)
		{
		case UP://!上
			m_direction = Vec2(0, -1);
			break;
		case DOWN://!下
			m_direction = Vec2(0, 1);
			break;
		case LEFT://!左
			m_direction = Vec2(-1, 0);
			break;
		case RIGHT://!右
			m_direction = Vec2(1, 0);
			break;
		default:
			break;
		}

		//!もしも当たっていなかったら方向配列をもとに戻しbreak
		if (CollisionWall(pos_, m_direction) != true)
		{
			SetDirection(m_direction);
			break;
		}
	}

	return m_direction;
}

//!当たり判定関数(壁)
bool ChaseAI::CollisionWall(Vec2 pos_, Vec2 direction_)
{
	Vec2 pos = pos_;   //!座標保存用
	pos.x += direction_.x;
	pos.y += direction_.y;

	//!移動先で何かにぶつかっているかどうか
	if (m_stage->SearchObject(pos) == PACMAN_WALL)
	{
		return true;
	}

	return false;
}

//!移動方向検索関数
bool ChaseAI::SearchDirection()
{
	for (int i = 0; i < DIRECTION_MAX; i++)
	{
		//!見つかったら
		if (m_direction_array[i] == m_rand_direction)
		{
			return true;
		}
	}
	return false;
}

//!後退消去関数
void ChaseAI::SetDirection(Vec2 vec_)
{
	//!移動可能配列を一度初期化
	for (int i = 0; i < DIRECTION_MAX; i++)
	{
		m_direction_array[i] = i;
	}

	//!現在動いている方向の反対(後退)方向に動かないようにする

	//!現在右方向に動いている場合
	if (vec_.x == 1 && vec_.y == 0)
	{
		m_direction_array[LEFT] = DIRECTION_NONE; //!左方向が選ばれないようにする
	}
	//!現在左方向に動いている場合
	else if (vec_.x == -1 && vec_.y == 0)
	{
		m_direction_array[RIGHT] = DIRECTION_NONE; //!右方向が選ばれないようにする
	}
	//!現在下方向に動いている場合
	else if (vec_.x == 0 && vec_.y == 1)
	{
		m_direction_array[UP] = DIRECTION_NONE;    //!上方向が選ばれないようにする
	}
	//!現在上方向に動いている場合
	else if (vec_.x == 0 && vec_.y == -1)
	{
		m_direction_array[DOWN] = DIRECTION_NONE;  //!下方向が選ばれないようにする
	}
}
