#include "Bord.h"
#include "../Entity.h"
#include <string.h>


//!初期化関数
void Bord::Init()
{
	//!初期配置コピー用
	BordInfo map[BORD_HEIGHT][BORD_WIDTH] =
	{
	//!{駒の種類 , プレイヤー}
		{{KIN,  SECOND},{OU,   SECOND},{BLANK,SECOND},{KEIMA,SECOND}},
		{{HU,   SECOND},{HU,   SECOND},{HU,   SECOND},{HU,   SECOND}},
		{{BLANK,NONE  },{BLANK,NONE  },{BLANK,NONE  },{BLANK,NONE  }},
		{{HU,   FIRST },{HU,   FIRST },{HU,   FIRST },{HU,   FIRST }},
		{{KEIMA,FIRST },{BLANK,FIRST },{OU,   FIRST },{KIN,  FIRST }},
	};

	//!配列の初期化は宣言と同時にしかできないためコピーで代入する
	memcpy(&m_bord_info, &map, sizeof(map));

	//!終了フラグ初期化
	m_first_win = false;
	m_second_win = false;

}

//!駒調査関数
OBJECT_TYPE Bord::SearchPiece(__int8 input_font_, __int8 input_number_)
{
	m_source_pos = Vec(input_font_, input_number_);               //!移動させる駒の座標を保存
	return m_bord_info[input_number_][input_font_].m_put_piece;   //!指定された場所の駒を返す
}

//!プレイヤー調査関数
PLAYER_TYPE Bord::SearchPlayer(__int8 input_font_, __int8 input_number_)
{
	return m_bord_info[input_number_][input_font_].m_put_player;   //!指定された場所の駒を返す
}


//!駒移動関数
void Bord::SetPiecePos(Vec next_pos, OBJECT_TYPE object_, PLAYER_TYPE player_)
{

	//!移動元を0にして何もない状態にする
	m_bord_info[m_source_pos.y][m_source_pos.x].m_put_piece = BLANK;  
	m_bord_info[m_source_pos.y][m_source_pos.x].m_put_player = NONE;

	//!移動先が「王の場合」終了フラグをtrueにする
	if (m_bord_info[next_pos.y][next_pos.x].m_put_piece == OU)
	{
		if (m_bord_info[next_pos.y][next_pos.x].m_put_player == FIRST)
		{
			m_first_win = true;   //!先手が勝利
		}
		else
		{
			m_second_win = true;  //!後手が勝利
		}
	}

	//!駒を移動させる
	m_bord_info[next_pos.y][next_pos.x].m_put_piece = object_;
	m_bord_info[next_pos.y][next_pos.x].m_put_player = player_;
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
				switch (m_bord_info[y][x].m_put_piece)
				{
				case OU:
					//!先手なら
					if (m_bord_info[y][x].m_put_player == FIRST)
					{
						g_drawer.SetUpBuffer(Vec(x, y), "王");
					}
					//!後手なら
					else
					{
						g_drawer.SetUpBuffer(Vec(x, y), "玉");
					}
					break;
				case KEIMA:
					//!先手なら
					if (m_bord_info[y][x].m_put_player == FIRST)
					{
						g_drawer.SetUpBuffer(Vec(x, y), "桂");
					}
					//!後手なら
					else
					{
						g_drawer.SetUpBuffer(Vec(x, y), "軽");
					}
					break;
				case KIN:
					//!先手なら
					if (m_bord_info[y][x].m_put_player == FIRST)
					{
						g_drawer.SetUpBuffer(Vec(x, y), "金");
					}
					//!後手なら
					else
					{
						g_drawer.SetUpBuffer(Vec(x, y), "筋");
					}
					break;
				case HU:
					//!先手なら
					if (m_bord_info[y][x].m_put_player == FIRST)
					{
						g_drawer.SetUpBuffer(Vec(x, y), "歩");
					}
					//!後手なら
					else
					{
						g_drawer.SetUpBuffer(Vec(x, y), "ふ");
					}
					break;
				default:
					break;
				}
				
			}
		}
	}
}




