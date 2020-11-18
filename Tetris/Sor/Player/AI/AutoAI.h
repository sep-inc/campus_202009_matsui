#ifndef TETRIS_AUTOAI_H_
#define TETRIS_AUTOAI_H_
#include "../../Utility/Vec2.h"
#include "../../Definition.h"
#include "../PlayerBase.h"
#include "AIBase.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_Auto_AI :public Tetris_AIBase
{
public:
    Tetris_Auto_AI();
    ~Tetris_Auto_AI() {}

    /**
　   * @brief  初期化関数
     * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
    virtual void Reset();

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    virtual void Update()override;

  
    virtual void SearchFixedPos()override;

};

#endif