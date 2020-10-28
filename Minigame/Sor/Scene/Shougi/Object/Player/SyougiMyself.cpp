#include "SyougiMyself.h"
#include "../SyougiPiece_King.h"
#include "../SyougiPiece_Knight.h"
#include "../SyougiPiece_Goldgeneral.h"
#include "../SyougiPiece_Pawn.h"
#include "../../../../System/Inputter.h"
#include <stdio.h>
#include <stdlib.h>


//!コンストラクタ
SyougiMyself::SyougiMyself(SYOUGI_PLAYER_TYPE player_, SyougiBoard* board_,SyougiCursor* cursor_)
{
	m_my_player_type = player_;  //!自分が誰かを代入
	m_board = board_;     //!Boardのアドレスを取得
	m_cursor = cursor_;  //!Cursorのアドレスを取得

	m_move = false;  //!移動フラグ

	m_step = SelectSorce_Step;  //!移動元選択ステップで初期化
}

void SyougiMyself::Reset()
{
	m_move = false;  //!移動フラグ
	m_now_pos = Vec2(0, 0);
	m_next_pos = Vec2(0, 0);
	m_piece_type = BLANK;
}

//!更新処理
void SyougiMyself::Update(SyougiPiece* piece_[])
{
	//!駒の移動までの過程でカーソルの移動もあるのでステップで分ける
	switch (m_step)
	{
	case SyougiMyself::SelectSorce_Step:   //!移動元選択
		m_move = false;  //!移動フラグ
		//!移動させる駒が見つかるかどうか
		if (MoveSourceSelect() == true)
		{
			m_step = SelectNext_Step;  //!移動先選択へ
		}
		break;
	case SyougiMyself::SelectNext_Step: //!移動先選択 
		//!移動先が決まったかどうか
		if (NextMoveSelect(piece_) == true)
		{
			system("cls"); //!文字が残らないように消す

			m_step = Move_Step; //!移動へ　
		}
		//!移動させる駒を変更する場合
		else if (re_sorce_input == true)
		{
			system("cls"); //!文字が残らないように消す

			m_step = SelectSorce_Step; //!移動元選択へ
			re_sorce_input = false;
		}

		break;
	case SyougiMyself::Move_Step:
		//!移動
		Move(m_board);

		m_step = SelectSorce_Step;  //!移動元選択に戻す
		m_move = true;  //!敵の駒移動ターンに移る
		break;
	default:
		break;
	}
}

//!入力処理
bool SyougiMyself::MoveSourceSelect()
{
	printf("動かす駒を選んでください。\n");
	printf("十字キーでカーソル移動\n");
	printf("Spaceで決定\n");

	m_now_pos = m_cursor->Move();   //!カーソル移動

	//!決定ボタンが押されたかどうか
	if (m_cursor->MoveEnd() == true)
	{
		SearchBord(m_board, m_now_pos);   //!指定箇所問い合わせ


		//!指定した場所に何も無かった場合。または相手の駒だった場合、またはキャンセルボタンが押されたとき																								 //!もし選んだ場所に駒がなかったら、また選んだ駒が自分の駒でない場合
		if (m_piece_type == BLANK || m_player_type != m_my_player_type
			|| Inputter::Instance()->GetSelectCancel() == true)
		{

			if (m_piece_type == BLANK)
			{
				printf("そこには何もありません。もう一度選んでください\n");
			}
			else if (Inputter::Instance()->GetSelectCancel() == true)
			{
				printf("キャンセルできません。もう一度選んでください\n");
			}
			else if (m_player_type != m_my_player_type)
			{
				printf("それは相手の駒です。もう一度選んでください\n");
			}

			//!再入力(表示文字を入力待ちで残す)
			m_now_pos = m_cursor->Move();

		}
		else
		{
			return true;
		}
	}

	return false;
}

//!移動先入力関数
bool SyougiMyself::NextMoveSelect(SyougiPiece* piece_[])
{
	NowMovePiece(m_piece_type);  //!現在動かそうとしている駒の表示

	printf("移動先を選んでください\n");
	printf("移動させる駒を変更する場合[r]を押してください。\n");
	printf("十字キーでカーソル移動\n");
	printf("Spaceで決定\n");

	m_next_pos = m_cursor->Move();   //!カーソル移動

	//!キャンセルボタンが押されたとき
	if (Inputter::Instance()->GetSelectCancel() == true)
	{
		re_sorce_input = true;  //!移動させる駒を変更
		return false;
	}

	//!決定ボタンが押されたかどうか
	if (m_cursor->MoveEnd() == true)
	{
		m_player_type = m_board->SearchPlayer(m_next_pos);  //!移動先の駒が誰の駒か判別

		//!移動先に自分の駒があった時はもう一度入力させる
		if (m_player_type != m_my_player_type)
		{
			//!駒クラスで移動でpiece.SearchMovきるか判断させる
			if (piece_[m_piece_type]->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
			{
				return true;
			}
		}
		printf("移動できない場所です。もう一度入力してください。\n");

		//!再入力(表示文字を入力待ちで残す)
		m_next_pos = m_cursor->Move();
	}

	return false;
}

//!動かそうとしている駒表示関数
void SyougiMyself::NowMovePiece(PIECE_TYPE piece_type_)
{
	switch (piece_type_)
	{
	case KING:
		if (m_my_player_type == SYOUGI_FIRST)   //!先手の場合
		{
			printf("現在動かそうとしているのは王です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは玉です。\n");
		}
		break;
	case KNIGHT:
		if (m_my_player_type == SYOUGI_FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは桂です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは軽です。\n");
		}
		break;
	case GOLDGENERAL:
		if (m_my_player_type == SYOUGI_FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは金です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは筋です。\n");
		}
		break;
	case PAWN:
		if (m_my_player_type == SYOUGI_FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは歩です。\n");
		}
		else
		{
			printf("現在動かそうとしているのはふです。\n");
		}
		break;
	default:
		break;
	}
}

