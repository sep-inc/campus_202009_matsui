#include "Player.h"
#include "../Definition.h"
#include "../Entity.h"
#include <stdio.h>

//!初期化
void Player::Init()
{
	m_piece_ou = new PieceOu;       //!王
	m_piece_keima = new PieceKeima; //!桂
	m_piece_kin = new PieceKin;     //!金
	m_piece_hu = new PieceHu;       //!歩
}

//!更新処理
void Player::Update(Bord* bord_)
{

	while (true)
	{
		//!移動元入力
		Input(bord_);

		//!移動先入力
		if (NextMoveInput(bord_) == true)
		{
			break;
		}

		printf("\n");
	}

	//!移動
	Move(bord_);
}

//!入力処理
void Player::Input(Bord* bord_)
{
	printf("動かす駒を選んでください。\n");

	g_inputter.InputFont();      //!移動させる駒を選択
	g_inputter.InputNumber();      //!移動させる駒を選択

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
		SearchBord(bord_);
	}

	NowMovePiece(m_piece_type);  //!現在動かそうとしている駒の表示

	m_now_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!動かそうとしている駒座標保存変数

	printf("移動先を選んでください\n");
}

//!移動先入力関数
bool Player::NextMoveInput(Bord* bord_)
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


	while (true)
	{
		//!移動先に自分の駒があった時はもう一度入力させる
		if (m_player_type != m_my_player_type)
		{
			//!駒クラスの基底クラスで行う場合
			/*if (g_piece.SearchMove(m_now_pos, m_next_pos, m_piece_type, m_my_player_type) == true)
			{
				return true;
			}*/

			//!駒クラスで移動でpiece.SearchMovきるか判断させる
			//!各駒クラスで行う場合
			switch (m_piece_type)
			{
			case OU:  //!王
				if (m_piece_ou->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
				{
					return true;
				}
				break;
			case KEIMA: //!桂
				if (m_piece_keima->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
				{
					return true;
				}
				break;
			case KIN: //!金
				if (m_piece_kin->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
				{
					return true;
				}
				break;
			case HU: //!歩
				if (m_piece_hu->SearchMove(m_now_pos, m_next_pos, m_my_player_type) == true)
				{
					return true;
				}
				break;
			default:
				break;
			}
		}

		printf("移動できない場所です。もう一度入力してください。\n");
		NextMoveInput(bord_);//!再入力
	}
}

//!移動処理
void Player::Move(Bord* bord_)
{
	//!移動先を盤クラスに送る
	bord_->SetPiecePos(m_next_pos, m_piece_type, m_my_player_type);
}

//!動かそうとしている駒表示関数
void Player::NowMovePiece(OBJECT_TYPE piece_type_)
{
	switch (piece_type_)
	{
	case OU:
		if (m_my_player_type == FIRST)   //!先手の場合
		{
			printf("現在動かそうとしているのは王です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは玉です。\n");
		}
		break;
	case KEIMA:
		if (m_my_player_type == FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは桂です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは軽です。\n");
		}
		break;
	case KIN:
		if (m_my_player_type == FIRST)  //!先手の場合
		{
			printf("現在動かそうとしているのは金です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは筋です。\n");
		}
		break;
	case HU:
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

//!指定した場所の盤情報を受け取る関数
void Player::SearchBord(Bord* bord_)
{
	m_piece_type = bord_->SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());    //!駒の種類判別関数
	m_player_type = bord_->SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!先手の駒か後手の駒か判別関数
}

//!勝敗判定
bool Player::Judgment(Bord* bord_)
{
	//!盤クラスに移動後の結果(王を取ったか)を返すようにする
	if (bord_->GetWinner() == m_my_player_type)
	{
		//!勝者表示
		if (m_my_player_type == FIRST)
		{
			printf("先手の勝ちです。\n");
		}
		else if (m_my_player_type == SECOND)
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
	delete m_piece_ou;
	delete m_piece_keima;
	delete m_piece_kin;
	delete m_piece_hu;
}
