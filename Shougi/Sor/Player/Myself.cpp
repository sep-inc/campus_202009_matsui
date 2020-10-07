#include "Myself.h"
#include "../Definition.h"
#include "../Entity.h"
#include "../Object/Piece_King.h"
#include "../Object/Piece_Knight.h"
#include "../Object/Piece_Goldgeneral.h"
#include "../Object/Piece_Pawn.h"
#include <stdio.h>

//!コンストラクタ
Myself::Myself(PLAYER_TYPE player_)
{
	m_my_player_type = player_;  //!自分が誰かを代入
}

//!入力処理
void Myself::MoveSourceSelect(Bord* bord_)
{
	printf("動かす駒を選んでください。\n");

	g_inputter.InputFont();      //!移動させる駒を選択
	g_inputter.InputNumber();    //!移動させる駒を選択

	SearchBord(bord_);   //!指定箇所問い合わせ

	//!指定した場所に何も無かった場合。または相手の駒だった場合、またはキャンセルボタンが押されたとき																								 //!もし選んだ場所に駒がなかったら、また選んだ駒が自分の駒でない場合
	while (m_piece_type == BLANK || m_player_type != m_my_player_type
		|| g_inputter.GetSelectCancel() == true)
	{
		if (m_piece_type == BLANK)
		{
			printf("そこには何もありません。もう一度選んでください\n");
		}
		else if (g_inputter.GetSelectCancel() == true)
		{
			printf("キャンセルできません。もう一度選んでください\n");
		}
		else if (m_player_type != m_my_player_type)
		{
			printf("それは相手の駒です。もう一度選んでください\n");
		}


		//!再入力
		g_inputter.InputFont();     //!文字
		g_inputter.InputNumber();   //!番号
		SearchBord(bord_); //!盤上検索
	}

	NowMovePiece(m_piece_type);  //!現在動かそうとしている駒の表示

	m_now_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!動かそうとしている駒座標保存変数


	printf("移動先を選んでください\n");
}

//!移動先入力関数
bool Myself::NextMoveSelect(Bord* bord_,Piece* piece_[])
{
	while (true)
	{
		printf("移動させる駒を変更する場合[r]を押してください。\n");

		g_inputter.InputFont();      //!移動先文字番号入力

		//!キャンセルボタンが押されたとき
		if (g_inputter.GetSelectCancel() == true)
		{
			return false;
		}

		g_inputter.InputNumber();    //!移動先数字番号入力

		//!キャンセルボタンが押されたとき
		if (g_inputter.GetSelectCancel() == true)
		{
			return false;
		}

		m_next_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!移動先保存
		m_player_type = bord_->SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!移動先の駒が誰の駒か判別

		//!移動先に自分の駒があった時はもう一度入力させる
		if (m_player_type != m_my_player_type)
		{
			/////////////////////////////////
			//!前にswich文で分けていた箇所//
			////////////////////////////////
			//!駒クラスで移動でpiece.SearchMovきるか判断させる
			if (piece_[m_piece_type]->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
			{
				return true;
			}
		}

		printf("移動できない場所です。もう一度入力してください。\n");
	}

	return false;
}

//!動かそうとしている駒表示関数
void Myself::NowMovePiece(PIECE_TYPE piece_type_)
{
	switch (piece_type_)
	{
	case KING:
		if (m_my_player_type == FIRST)   //!先手の場合
		{
			printf("現在動かそうとしているのは王です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは玉です。\n");
		}
		break;
	case KNIGHT:
		if (m_my_player_type == FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは桂です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは軽です。\n");
		}
		break;
	case GOLDGENERAL:
		if (m_my_player_type == FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは金です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは筋です。\n");
		}
		break;
	case PAWN:
		if (m_my_player_type == FIRST)  //!先手の場合
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

