#include "Player.h"
#include "Definition.h"
#include "Entity.h"
#include "Object/Piece.h"
#include <stdio.h>

//!初期化
void Player::Init()
{
	m_piece = new Piece;
}

//!更新処理
void Player::Update(PLAYER_TYPE player_type_)
{
	Move(player_type_);
}

//!入力処理
void Player::Input(PLAYER_TYPE player_type_)
{
	g_inputter.InputNumber();      //!移動させる駒を選択

	m_piece_type = g_bord.SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());    //!駒の種類判別関数
	m_player_type = g_bord.SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!先手の駒か後手の駒か判別関数
	
																										 //!もし選んだ場所に駒がなかったら、また選んだ駒が自分の駒でない場合
	while (m_piece_type == BLANK || m_player_type != player_type_)
	{
		printf("そこには何もありません。\nもう一度選んでください\n");
		g_inputter.InputNumber();   //!再入力
		m_piece_type = g_bord.SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!駒の種類判別関数
		m_player_type = g_bord.SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber()); //!先手の駒か後手の駒か判別関数
	}

	NowMovePiece(m_piece_type, m_player_type);

	m_now_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!動かそうとしている駒座標保存変数
	m_next_pos = Vec(BLANK, BLANK);  //!動かす場所保存変数

	printf("移動先を選んでください\n");

	g_inputter.InputNumber();    //!移動先入力

	m_next_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!移動先保存
	m_player_type = g_bord.SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!移動先の駒が誰の駒か判別
}

//!移動処理
void Player::Move(PLAYER_TYPE player_type_)
{
	//!入力
	Input(player_type_);

	//!移動先に自分の駒があった時は移動させない
	if (m_player_type != player_type_)
	{
		//!駒クラスで移動できるか判断させる
		if (m_piece->SearchMove(m_now_pos, m_next_pos, m_piece_type, player_type_) == true)
		{
			//!移動先を盤クラスに送る
			g_bord.SetPiecePos(m_next_pos, m_piece_type, player_type_);
		}
	}
}

//!動かそうとしている駒表示関数
void Player::NowMovePiece(OBJECT_TYPE piece_type_, PLAYER_TYPE player_type_)
{
	switch (piece_type_)
	{
	case OU:
		if (player_type_ == FIRST)   //!先手の場合
		{
			printf("現在動かそうとしているのは王です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは玉です。\n");
		}
		break;
	case KEIMA:
		if (player_type_ == FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは桂です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは軽です。\n");
		}
		break;
	case KIN:
		if (player_type_ == FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは金です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは筋です。\n");
		}
		break;
	case HU:
		if (player_type_ == FIRST)  //!先手の場合
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

//!勝敗判定
bool Player::Judgment()
{
	//!盤クラスに移動後の結果(王を取ったか)を返すようにする
	if (g_bord.GetFirstWin() == true || g_bord.GetSecondWin() == true)
	{
		//!勝者表示
		if (g_bord.GetFirstWin() == true)
		{
			printf("先手の勝ちです。\n");
		}
		else if (g_bord.GetSecondWin() == true)
		{
			printf("後手の勝ちです。\n");
		} 
		
		//!GameControllerに結果を返す
		return true;
	}

	return false;
}

//!解放処理
void Player::Delete()
{
	delete m_piece;
}
