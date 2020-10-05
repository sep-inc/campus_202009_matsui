#ifndef ENTITY_H_
#define ENTITY_H_

/**
*@brief 各クラス実体置き場
*/

#include "System/Drawer.h"
#include "System/Inputter.h"
#include "GameController.h"

extern Drawer g_drawer;      //!描画クラス
extern Inputter g_inputter;  //!入力クラス
extern GameController g_game_controller;        //!駒クラス


#endif