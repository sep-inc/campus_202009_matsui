#include "SyougiEnemy.h"
#include "../SyougiPiece_King.h"
#include "../SyougiPiece_Knight.h"
#include "../SyougiPiece_Goldgeneral.h"
#include "../SyougiPiece_Pawn.h"
#include <random>
#include <stdio.h>

//!コンストラクタ
SyougiEnemy::SyougiEnemy(SYOUGI_PLAYER_TYPE player_,SyougiBoard* board_)
{
	m_my_player_type = player_; //!自分が誰かを代入
	m_board = board_;
	m_move = false;  //!移動フラグ
}

void SyougiEnemy::Reset()
{
	m_move = false;  //!移動フラグ
	m_now_pos = Vec2(0, 0);
	m_next_pos = Vec2(0, 0);
	m_piece_type = PIECE_BLANK;
}

//!更新処理
void SyougiEnemy::Update(SyougiPiece* piece_[])
{
	//!移動させる駒を選び直す時用にループする
	while (true)
	{
		//!移動させる駒選択
		MoveSourceSelect();

		//!移動先入力
		if (NextMoveSelect(piece_) == true)
		{
			break;  //!移動先が移動できるならループを抜ける
		}
	}

	//!移動
	Move(m_board);

	m_move = true;

}


//!移動元入力
void SyougiEnemy::MoveSourceSelect()
{
	//!移動させる駒が見つからない場合もう選びなおすためループする
	while (true)
	{
		//!移動させる駒をランダムで決定
		m_piece_type = static_cast<PIECE_TYPE>(rand() % PIECE_NUM);

		_int8 pawn_pos_x = 0; //!同種が複数あるうちから選ぶ用(今回は「歩」)

		 //!同じ駒が複数ある場合、その中からランダムで選ぶ
		if (m_piece_type == PAWN)
		{
			pawn_pos_x = rand() % PAWN_NUM;  //!複数の中から一つ選ぶ
		}

		//!ランダムで選ばれた駒の座標を問い合わせ
		m_now_pos = m_board->SearchPiecePos(m_piece_type, m_my_player_type, pawn_pos_x);

		//!座標が見つかった場合
		if (m_now_pos.x >= 0 && m_now_pos.y >= 0)
		{
			break;
		}
	}

}

//!移動先入力
bool SyougiEnemy::NextMoveSelect(SyougiPiece* piece_[])
{
	__int8 m_reset_counter = 0;   //!移動先変更時用

	while (true)
	{
		NextPos(); //!移動先選択

		m_player_type = m_board->SearchPlayer(m_next_pos);  //!移動先の駒が誰の駒か判別

		//!移動先に自分の駒があった時はもう一度入力させる
		if (m_player_type != m_my_player_type)
		{
			//!駒クラスで移動でpiece.SearchMovきるか判断させる
			if (piece_[m_piece_type]->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
			{
				m_reset_counter = 0;
				return true;    //!移動できるならtrue
			}
		}

		m_reset_counter++;   //!検索できる残り回数を減らす

		//!一定数以上移動先が決まらなかった場合移動させる駒を変更する
		if (m_reset_counter >= RESET_NUM)
		{
			m_reset_counter = 0;
			break;
		}
	}

	return false;
}

//!移動先決定関数
void SyougiEnemy::NextPos()
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
