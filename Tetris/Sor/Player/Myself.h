#ifndef TETRIS_MYSELF_H_
#define TETRIS_MYSELF_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
#include "PlayerBase.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_Myself :public Tetris_Player_Base
{
public:
    Tetris_Myself();
    ~Tetris_Myself() {}

    virtual void Update()override;

    virtual void  MoveBlock()override;
    virtual void  RoteBlock()override;


};

#endif