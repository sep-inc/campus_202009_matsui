#ifndef ENTITY_H_
#define ENTITY_H_
#include "System/Drawer.h"
#include "System/Inputter.h"
#include "GameController.h"


/**
*@brief 各クラス実体置き場
*/

extern Drawer g_drawer;      //!描画クラス
extern Inputter g_inputter;  //!入力クラス
extern GameController g_game_controller;        //!駒クラス


#endif