#ifndef TETRIS_PLAYERBASE_H_
#define TETRIS_PLAYERBASE_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
#include "../Object/Block/BlockBase.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_Player_Base
{
public:
    Tetris_Player_Base() {}
    ~Tetris_Player_Base() {}

    virtual void Update() = 0;

    virtual void MoveBlock() {}
    virtual void RoteBlock() {}


protected:

};

#endif