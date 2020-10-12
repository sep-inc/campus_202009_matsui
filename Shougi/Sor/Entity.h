#ifndef ENTITY_H_
#define ENTITY_H_
#include "System/Drawer.h"
#include "System/Inputter.h"
#include "System/FPS.h"
#include "GameController.h"
#include "Object/Piece.h"
#include "Object/Piece_King.h"
#include "Object/Piece_Knight.h"
#include "Object/Piece_Goldgeneral.h"
#include "Object/Piece_Pawn.h"

/**
*@brief 各クラス実体置き場
*/

extern Drawer g_drawer;      //!描画クラス
extern Inputter g_inputter;  //!入力クラス
extern Fps g_fps;
extern GameController g_game_controller;        //!駒クラス


#endif