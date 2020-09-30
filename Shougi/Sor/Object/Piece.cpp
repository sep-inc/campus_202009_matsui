#include "Piece.h"
#include "../Definition.h"
#include "../Entity.h"
#include "First.h"
#include "Second.h"
#include <random>

//!ステップ処理関数
void Piece::StepChange()
{
	switch (m_step)
	{
	case Piece::STEP_INIT:         //!初期化
		Init();
		break;
	case Piece::STEP_FIRST_PUT:    //!先手
		Update();
		break;
	case Piece::STEP_SECOND_PUT:   //!後手
		Update();
		break;
	default:
		break;
	}
}

//!初期化関数
void Piece::Init()
{
	m_first = new First;     
	m_second = new Second;

	m_first->Init();     //!先手メンバ変数初期化
	m_second->Init();    //!後手メンバ変数初期化

	InitMove();          //!移動範囲初期化関数

	//!最初に盤上に駒情報を送る
	SetPiece(m_first);
	SetPiece(m_second);

	//!次のステップへ
	m_step = STEP_FIRST_PUT;
}

//!更新関数
void Piece::Update()
{
	Put();               //!移動関数

	DeleteSearchPiece();  //!駒消去関数

	EndGame(m_first, m_second);  //!終了判定

	g_bord.Init();        //!盤上リセット関数

	SetPiece(m_first);    //!盤上配列に先手の駒情報導入
	SetPiece(m_second);   //!盤上配列に後手の駒情報導入
}

//!駒移動範囲初期化関数
void Piece::InitMove()
{
	m_first->InitMove();   //!先手の駒移動範囲初期化
	m_second->InitMove();  //!後手の駒移動範囲初期化
}

//!描画座標代入関数
void Piece::SetUpDrawBuffer()
{
	m_first->SetUpDrawBuffer();   //!先手の駒座標を描画配列に代入
	m_second->SetUpDrawBuffer();  //!後手の駒座標を描画配列に代入

	//!先手の時
	if (m_step == STEP_FIRST_PUT)
	{
		g_drawer.SetUpBuffer(Vec(-1, -1), " 先",true);  //!左上に先手であることを表示
	}
	else
	{
		g_drawer.SetUpBuffer(Vec(-1, -1), " 後",true);  //!左上に後手であることを表示
	}
}



//!駒配置関数
void Piece::Put()
{
	switch (m_step)
	{
	case Piece::STEP_FIRST_PUT:    //!先手
		PutPiece(m_first);         //!配置
		break;
	case Piece::STEP_SECOND_PUT:   //!後手
		PutPiece(m_second);        //!配置
		break;
	default:
		break;
	}
}

//!配置関数
void Piece::PutPiece(Piece* piece_)
{

	g_inputter.InputNumber();      //!移動させる駒を選択

	__int8 piece_type = g_bord.SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());    //!駒の種類判別関数
	__int8 player_type = g_bord.SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!先手の駒か後手の駒か判別関数
	m_hu_number = SearchHuPiece(piece_);   //!「歩」の駒を選んだ場合の「歩」の種類判別関数

	//!もし選んだ場所に駒がなかったら、また選んだ駒が自分の駒でない場合
	while (piece_type == BLANK || player_type != piece_->m_player)
	{
		printf("そこには何もありません。\nもう一度選んでください\n");
		g_inputter.InputNumber();   //!再入力
		m_hu_number = SearchHuPiece(piece_);  //!「歩」の駒を選んだ場合の「歩」の種類判別関数
		piece_type = g_bord.SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!駒の種類判別関数
		player_type = g_bord.SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber()); //!先手の駒か後手の駒か判別関数
	}

	Vec now_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!動かそうとしている駒座標保存変数
	Vec next_pos = Vec(BLANK, BLANK);  //!動かす場所保存変数

	g_drawer.NowMovePiece(piece_type, piece_->m_player);    //!動かそうとしている駒表示

	printf("移動先を選んでください\n");

	g_inputter.InputNumber();    //!移動先入力


	next_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());   //!移動先保存
	player_type = g_bord.SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!移動先の駒が誰の駒か判別

	piece_->m_delete_pos = Vec(-1, -1);  //!毎フレーム消去座標を初期化(前の座標が残っていると勝手に駒が消える恐れがあるため)

	//!自分の駒ではない場合
	if (player_type != piece_->m_player)
	{
		switch (piece_type)
		{
		case OU://!王の時
			if (SearchMove(piece_, piece_->m_piece_info.m_ou_move_center, next_pos, piece_type) == true)
			{
				piece_->m_piece_info.m_ou_pos = next_pos;  //!移動
				piece_->m_delete_pos = next_pos;           //!削除座標保存
			}
			else
				g_drawer.DrawNoMove();  //!表示
			break;
		case KEIMA://!桂の時
			if (SearchMove(piece_, piece_->m_piece_info.m_kei_move_center, next_pos, piece_type) == true)
			{
				piece_->m_piece_info.m_kei_pos = next_pos;  //!移動
				piece_->m_delete_pos = next_pos;            //!削除座標保存
			}
			else
				g_drawer.DrawNoMove();  //!表示
			break;
		case KIN://!金の時
			if (SearchMove(piece_, piece_->m_piece_info.m_kin_move_center, next_pos, piece_type) == true)
			{
				piece_->m_piece_info.m_kin_pos = next_pos;  //!移動
				piece_->m_delete_pos = next_pos;            //!削除座標保存
			}
			else
				g_drawer.DrawNoMove();  //!表示
			break;
		case HU://!歩の時
			if (SearchMove(piece_, piece_->m_piece_info.m_hu_move_center, next_pos, piece_type) == true)
			{
				piece_->m_piece_info.m_hu_pos[m_hu_number] = next_pos;  //!移動
				piece_->m_delete_pos = next_pos;                        //!削除座標保存
			}
			else
				g_drawer.DrawNoMove();  //!表示
			break;
		default:
			break;
		}
		
	}
}

//!盤上配列更新関数まとめ
void Piece::SetPiece(Piece* piece_)
{
	//!王
	g_bord.SetPiecePos(piece_->m_piece_info.m_ou_pos, OU, piece_->m_piece_info.m_ou_display, piece_->m_player);
	//!桂
	g_bord.SetPiecePos(piece_->m_piece_info.m_kei_pos, KEIMA, piece_->m_piece_info.m_kei_display, piece_->m_player);
	//!金
	g_bord.SetPiecePos(piece_->m_piece_info.m_kin_pos, KIN, piece_->m_piece_info.m_kin_display, piece_->m_player);

	for (int i = 0; i < HU_NUM; i++)
	{
		//!歩
		g_bord.SetPiecePos(piece_->m_piece_info.m_hu_pos[i], HU, piece_->m_piece_info.m_hu_display[i], piece_->m_player);  
	}
}

//!置けるかどうか判定関数
bool Piece::SearchMove(Piece* piece_, Vec pos_, Vec input_pos_, __int8 piece_type_)
{
	Vec difference_pos;  //!移動先と駒座標の差分保存用
	Vec move_pos;        //!移動先(盤上)座標を移動範囲配列に直した時の座標

	switch (piece_type_)
	{
	case OU://!王
		//!移動先と駒座標の差分を出す
		difference_pos = Vec(input_pos_.x - piece_->m_piece_info.m_ou_pos.x, input_pos_.y - piece_->m_piece_info.m_ou_pos.y);

		//!移動先(盤上)座標を移動範囲配列に直す
		move_pos = Vec(pos_.x + difference_pos.x, pos_.y + -difference_pos.y);

		//!王の移動範囲に入ってない場合
		if ((move_pos.x < 0 || move_pos.y < 0) || (move_pos.x >= OU_MOVE_MAX_X || move_pos.y >= OU_MOVE_MAX_Y))
		{
			break;
		}
		//!移動範囲に入っていて、移動できる場合
		if (piece_->m_piece_info.m_ou_move[move_pos.y][move_pos.x] == 1)
		{
			return true;
		}

	case KEIMA://!桂
		//!移動先と駒座標の差分を出す
		difference_pos = Vec(input_pos_.x - piece_->m_piece_info.m_kei_pos.x, input_pos_.y - piece_->m_piece_info.m_kei_pos.y);

		//!移動先(盤上)座標を移動範囲配列に直す
		move_pos = Vec(pos_.x + difference_pos.x, pos_.y + difference_pos.y);

		//!桂の移動範囲に入ってない場合
		if ((move_pos.x < 0 || move_pos.y < 0) || (move_pos.x >= KEIMA_MOVE_MAX_X || move_pos.y >= KEIMA_MOVE_MAX_Y))
		{
			break;
		}
		//!移動範囲に入っていて、移動できる場合
		if (piece_->m_piece_info.m_kei_move[move_pos.y][move_pos.x] == 1)
		{
			return true;
		}

	case KIN://!金
		//!移動先と駒座標の差分を出す
		difference_pos = Vec(input_pos_.x - piece_->m_piece_info.m_kin_pos.x, input_pos_.y - piece_->m_piece_info.m_kin_pos.y);

		//!移動先(盤上)座標を移動範囲配列に直す
		move_pos = Vec(pos_.x + difference_pos.x, pos_.y + difference_pos.y);

		//!金の移動範囲に入ってない場合
		if ((move_pos.x < 0 || move_pos.y < 0) || (move_pos.x >= KIN_MOVE_MAX_X || move_pos.y >= KIN_MOVE_MAX_Y))
		{
			break;
		}
		//!移動範囲に入っていて、移動できる場合
		if (piece_->m_piece_info.m_kin_move[move_pos.y][move_pos.x] == 1)
		{
			return true;
		}

	case HU://!歩
		//!移動先と駒座標の差分を出す
		difference_pos = Vec(input_pos_.x - piece_->m_piece_info.m_hu_pos[m_hu_number].x, input_pos_.y - piece_->m_piece_info.m_hu_pos[m_hu_number].y);

		//!移動先(盤上)座標を移動範囲配列に直す
		move_pos = Vec(pos_.x + difference_pos.x, pos_.y + difference_pos.y);

		//!歩の移動範囲に入ってない場合
		if ((move_pos.x != 0 || move_pos.y < 0) || move_pos.y >= HU_MOVE_MAX_Y)
		{
			break;
		}
		//!移動範囲に入っていて、移動できる場合
		if (piece_->m_piece_info.m_hu_move[move_pos.y][move_pos.x] == 1)
		{
			return true;
		}
	default:
		break;
	}

	return false;
}


//!「歩」の種類判別関数
int Piece::SearchHuPiece(Piece* piece_)
{
	for (int i = 0; i < HU_NUM; i++)
	{
		if (piece_->m_piece_info.m_hu_pos[i].x == g_inputter.GetSelectFont() &&
			piece_->m_piece_info.m_hu_pos[i].y == g_inputter.GetSelectNumber())
		{
			return i;
		}
	}

	return -1;
}

//!駒消去関数まとめ
void Piece::DeleteSearchPiece()
{
	switch (m_step)
	{
	case Piece::STEP_FIRST_PUT:  //!先手
		DeleteSearchPiece(m_first, m_second);
		m_step = STEP_SECOND_PUT;
		break;
	case Piece::STEP_SECOND_PUT: //!後手
		DeleteSearchPiece(m_second, m_first);
		m_step = STEP_FIRST_PUT;
		break;
	default:
		break;
	}
}

//!駒消去関数
void Piece::DeleteSearchPiece(Piece* piece_, Piece* piece2_)
{
	__int8 hu_number = SearchHuPiece(piece2_);  //!削除する歩の種類(歩でない場合-1を返す)
	__int8 piece_type = 0;   //!駒の種類保存変数

	piece_type = g_bord.SearchPiece(piece_->m_delete_pos.x, piece_->m_delete_pos.y); //!移動先の駒の種類判別関数


	if (piece_type == OU) { piece2_->m_piece_info.m_ou_display = false; }                  //!王
	else if (piece_type == KEIMA) { piece2_->m_piece_info.m_kei_display = false; }			  //!桂
	else if (piece_type == KIN) { piece2_->m_piece_info.m_kin_display = false; }			  //!金
	else if (piece_type == HU) { piece2_->m_piece_info.m_hu_display[hu_number] = false; }  //!歩
}

//!終了判定
void Piece::EndGame(Piece* piece_, Piece* piece2_)
{
	if (piece_->m_piece_info.m_ou_display == false)
	{
		m_win_second = true;
	}
	else if (piece2_->m_piece_info.m_ou_display == false)
	{
		m_win_first = true;
	}
}

//!駒情報リセット関数
void Piece::ResetPiece()
{
	m_first->Init();     //!先手メンバ変数初期化
	m_second->Init();    //!後手メンバ変数初期化

	//!最初に盤上に駒情報を送る
	SetPiece(m_first);
	SetPiece(m_second);

	m_win_first = false;
	m_win_second = false;

	//!次のステップへ
	m_step = STEP_INIT;
}



