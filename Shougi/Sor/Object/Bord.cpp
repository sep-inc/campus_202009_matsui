#include "Bord.h"
#include "../Entity.h"
#include "Piece_King.h"
#include "Piece_Knight.h"
#include "Piece_Goldgeneral.h"
#include "Piece_Pawn.h"
#include <string.h>
#include <random>

//!初期化関数
void Bord::Init()
{
	//!初期配置コピー用
	BordInfo map[BORD_HEIGHT][BORD_WIDTH] =
	{
	 //!{駒の種類 , プレイヤー}
		{{GOLDGENERAL, SECOND},{KING,  SECOND},{BLANK, NONE  },{KNIGHT,      SECOND}},
		{{PAWN,        SECOND},{PAWN,  SECOND},{PAWN,  SECOND},{PAWN,        SECOND}},
		{{BLANK,       NONE  },{BLANK, NONE  },{BLANK, NONE  },{BLANK,       NONE  }},
		{{PAWN,        FIRST },{PAWN,  FIRST },{PAWN,  FIRST },{PAWN,        FIRST }},
		{{KNIGHT,      FIRST },{BLANK, NONE  },{KING,  FIRST },{GOLDGENERAL, FIRST }}
	};

	//!配列の初期化は宣言と同時にしかできないためコピーで代入する
	memcpy(&m_bord_info, &map, sizeof(map));
	memcpy(&m_bord_clear, &map, sizeof(map));

	m_piece[KING] = new PieceKing;                //!王
	m_piece[KNIGHT] = new PieceKnight;            //!桂
	m_piece[GOLDGENERAL] = new PieceGoldgeneral;  //!金
	m_piece[PAWN] = new PiecePawn;                //!歩

}

//!駒調査関数
PIECE_TYPE Bord::SearchPiece(__int8 x_, __int8 y_)
{
	m_source_pos = Vec(x_, y_);               //!移動させる駒の座標を保存
	return m_bord_info[y_][x_].m_put_piece;   //!指定された場所の駒を返す
}

//!プレイヤー調査関数
PLAYER_TYPE Bord::SearchPlayer(__int8 x_, __int8 y_)
{
	return m_bord_info[y_][x_].m_put_player;   //!指定された場所の駒を返す
}


//!駒移動関数
void Bord::SetPiecePos(Vec next_pos, PIECE_TYPE object_, PLAYER_TYPE player_)
{
	//!移動先が「王の場合」終了フラグをtrueにする
	if (m_bord_info[next_pos.y][next_pos.x].m_put_piece == KING)
	{
		m_winner = m_bord_info[m_source_pos.y][m_source_pos.x].m_put_player; //!勝者を保存
	}

	//!移動元を0にして何もない状態にする
	m_bord_info[m_source_pos.y][m_source_pos.x].m_put_piece = BLANK;  
	m_bord_info[m_source_pos.y][m_source_pos.x].m_put_player = NONE;

	//!駒を移動させる
	m_bord_info[next_pos.y][next_pos.x].m_put_piece = object_;
	m_bord_info[next_pos.y][next_pos.x].m_put_player = player_;
}

//!駒座標調査関数
Vec Bord::SearchPiecePos(PIECE_TYPE object_, PLAYER_TYPE player_)
{
	//!「歩」の場合(複数あるため)
	if (object_ == PAWN)
	{
		__int8 pawn_pos_x = rand() % PAWN_NUM;  //!複数の中から一つ選ぶ

		//!「歩」はX座標が固定なのでY座標で検索する
		for (int y = 0; y < BORD_HEIGHT; y++)
		{
			if (m_bord_info[y][pawn_pos_x].m_put_piece == object_ &&
				m_bord_info[y][pawn_pos_x].m_put_player == player_)
			{
				m_source_pos = Vec(pawn_pos_x, y);   //!移動させる駒の座標を保存
				return Vec(pawn_pos_x, y);           //!座標を返す
			}
		}
	}
	//!「歩」以外
	else
	{
		for (int y = 0; y < BORD_HEIGHT; y++)
		{
			for (int x = 0; x < BORD_WIDTH; x++)
			{
				if (m_bord_info[y][x].m_put_piece == object_ &&
					m_bord_info[y][x].m_put_player == player_)
				{
					m_source_pos = Vec(x, y);  //!移動させる駒の座標を保存
					return Vec(x, y);          //!座標を返す
				}
			}
		}
	}
	
	//!見つからない場合盤上配列以外の数値を返す
	return Vec(-1, -1);
}

//!描画配列代入関数
void Bord::SetUpDrawBuffer()
{
	for (int y = 0; y < BORD_HEIGHT; y++)
	{
		for (int x = 0; x < BORD_WIDTH; x++)
		{
			//!何か駒が置いてある場合
			if (m_bord_info[y][x].m_put_piece != BLANK)
			{
				//!駒の種類分け
				m_piece[m_bord_info[y][x].m_put_piece]->DrawPiece(m_bord_info[y][x].m_put_player, Vec(x, y));
			}
		}
	}
}

//!リセット関数
void Bord::Reset()
{
	memcpy(&m_bord_info, &m_bord_clear, sizeof(m_bord_clear));
	m_winner = NONE;
}

void Bord::Delete()
{
	for (int i = 0; i < PIECE_NUM; i++)
	{
		delete m_piece[i];
	}
}




