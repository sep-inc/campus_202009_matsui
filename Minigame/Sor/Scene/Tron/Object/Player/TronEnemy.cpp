#include "TronEnemy.h"
#include <random>

//!コンストラクタ(初期化が共通でないものを初期化)
TronEnemy::TronEnemy()
{
	m_player_type = TRON_ENEMY;  //!自分のプレイヤータイプ
	m_draw_font = "□";            //!描画スタイル

	//!移動方向情報
	for (int i = 0; i < DIRECTION_MAX; i++)
	{
		m_direction_array[i] = i;              //!移動方向配列
		m_none_array[i] = DIRECTION_NONE;      //!移動方向比較用配列
	}

	//!移動方向初期化
	m_rand_direction = static_cast<DIRECTION_TYPE>(rand() % DIRECTION_MAX);
}

//!移動方向選択関数
void TronEnemy::SelectDirection()
{
	//!移動できると分かるか移動先が見つからない場合まで回す
	while (true)
	{
		//!何かに衝突しようとするまで移動方向を変えない場合はコメントアウトする
		m_rand_direction = static_cast<DIRECTION_TYPE>(rand() % DIRECTION_MAX);

		//!移動先が移動方向配列に入っているかどうか
		while (SearchDirection() == false)
		{
			//!移動方向をランダムで選択
			m_rand_direction = static_cast<DIRECTION_TYPE>(rand() % DIRECTION_MAX);

			//!全ての移動方向を検索して何かにぶつかってしまう場合
			if (memcmp(m_direction_array, m_none_array, DIRECTION_MAX) == 0)
			{
				m_deth = true;  //!死亡フラグtrue

				//!方向配列を元に戻す
				for (int i = 0; i < DIRECTION_MAX; i++)
				{
					m_direction_array[i] = i;
				}
				break;
			}
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
		if (Collision() != true)
		{
			for (int i = 0; i < DIRECTION_MAX; i++)
			{
				m_direction_array[i] = i;
			}
			break;
		}
		//!当たっていたら
		else if (m_deth == true)
		{
			break;
		}

	}

}

//!移動方向検索関数
bool TronEnemy::SearchDirection()
{
	for (int i = 0; i < DIRECTION_MAX; i++)
	{
		//!見つかったら
		if (m_direction_array[i] == m_rand_direction)
		{
			m_direction_array[m_rand_direction] = DIRECTION_NONE;  //!選択した移動方向はもう一度選ばれないようにする
			return true;
		}
	}
	return false;
}
