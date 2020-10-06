#include "Enemy.h"
#include "../Definition.h"
#include "../Entity.h"
#include "../Object/Piece_King.h"
#include "../Object/Piece_Knight.h"
#include "../Object/Piece_Goldgeneral.h"
#include "../Object/Piece_Pawn.h"
#include <random>
#include <stdio.h>

const PLAYER_TYPE Enemy::m_my_player_type = SECOND;  //!自分自身識別変数初期化

//!初期化
void Enemy::Init()
{
	m_piece[KING] = new PieceKing;                //!王
	m_piece[KNIGHT] = new PieceKnight;            //!桂
	m_piece[GOLDGENERAL] = new PieceGoldgeneral;  //!金
	m_piece[PAWN] = new PiecePawn;  //!金

}

//!更新処理
void Enemy::Update(Bord* bord_)
{
	//!移動先が見つからない場合もう一度移動させる駒を変更するためループする
	while (true)
	{
		//!移動元入力
		MoveSourceSelect(bord_);

		//!移動先入力
		if (NextMoveSelect(bord_) == true)
		{
			break;
		}
	}

	//!移動
	Move(bord_);
}

//!移動元入力
void Enemy::MoveSourceSelect(Bord* bord_)
{
	//!移動させる駒が見つからない場合もう選びなおすためループする
	while (true)
	{
		//!移動させる駒をランダムで決定
		m_piece_type = static_cast<OBJECT_TYPE>(rand() % PIECE_NUM);

		//!ランダムで選ばれた駒の座標を問い合わせ
		m_now_pos = bord_->SearchPiecePos(m_piece_type, m_my_player_type);

		//!座標が見つかった場合
		if (m_now_pos.x >= 0 && m_now_pos.y >= 0)
		{
			break;
		}
	}

}

//!移動先入力
bool Enemy::NextMoveSelect(Bord* bord_)
{
	__int8 m_reset_counter = 0;   //!移動先変更時用

	while (true)
	{
		NextPos(); //!移動先選択

		m_player_type = bord_->SearchPlayer(m_next_pos.x, m_next_pos.y);  //!移動先の駒が誰の駒か判別

		//!移動先に自分の駒があった時はもう一度入力させる
		if (m_player_type != m_my_player_type)
		{

			/////////////////////////////////
			//!前にswich文で分けていた箇所//
			////////////////////////////////

			//!駒クラスで移動でpiece.SearchMovきるか判断させる
			if (m_piece[m_piece_type]->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
			{
				m_reset_counter = 0;
				return true;
			}
		}

		m_reset_counter++;   //!残り検索できる回数を減らす

		//!一定数以上移動先が決まらなかった場合移動させる駒を変更する
		if (m_reset_counter >= RESET_NUM)
		{
			m_reset_counter = 0;
			break;
		}
	}

	return false;
}

void Enemy::Move(Bord* bord_)
{
	//!移動先を盤クラスに送る
	bord_->SetPiecePos(m_next_pos, m_piece_type, m_my_player_type);
}

void Enemy::SearchBord(Bord* bord_)
{
	m_piece_type = bord_->SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());    //!駒の種類判別
	m_player_type = bord_->SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!先手の駒か後手の駒か判別
}

//!勝敗判定
bool Enemy::Judgment(Bord* bord_)
{
	//!盤クラスに移動後の結果(王を取ったか)を返すようにする
	if (bord_->GetWinner() == m_my_player_type)
	{
		//!勝者表示
		printf("後手の勝ちです。\n");

		//!GameControllerに結果を返す
		return true;
	}

	return false;
}

//!解放処理
void Enemy::Delete()
{
	for (int i = 0; i < PIECE_NUM; i++)
	{
		delete m_piece[i];
	}
}

//!移動先決定関数
void Enemy::NextPos()
{
	//!移動先が盤上で収まるまで
	while (true)
	{
		//!移動先決定
		m_next_pos.x = m_now_pos.x + rand() % 3 - 1; //!-1,0,1の範囲で検索したいため-1
		m_next_pos.y = m_now_pos.y + rand() % 4 - 1; //!-1,0,1,2の範囲で検索したいため-1

		//!フレーム外に座標が決まった場合もう一度選びなおす
		if (m_next_pos.x > -1 && m_next_pos.x < BORD_WIDTH &&
			m_next_pos.y > -1 && m_next_pos.y < BORD_HEIGHT)
		{
			break;
		}
	}
}
