#ifndef ENTITY_H_
#define ENTITY_H_

/**
*@brief 各クラス実体置き場
*/

#include "System/Drawer.h"
#include "System/Inputter.h"
#include "Object/Bord.h"
#include "Object/Piece.h"


extern Drawer g_drawer;      //!描画クラス
extern Inputter g_inputter;  //!入力クラス
extern Bord g_bord;          //!盤クラス
extern Piece g_piece;        //!駒クラス

#endif