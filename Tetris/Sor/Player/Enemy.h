#ifndef TETRIS_ENEMY_H_
#define TETRIS_ENEMY_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
#include "PlayerBase.h"
#include "AI/AIController.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_Eenmy :public Tetris_Player_Base
{
public:
    Tetris_Eenmy(Tetris_BlockController* block_);
    ~Tetris_Eenmy() {}

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    virtual void Update()override;

    /**
　   * @brief  移動関数
     * @detail 現在落下しているブロックの移動を行う
　   */
    virtual void  MoveBlock()override;

    /**
　   * @brief  回転関数
     * @detail 現在落下しているブロックの回転を行う
　   */
    virtual void  RoteBlock()override;


    void SetDirection();

private:
    Tetris_AIController* m_ai;

    bool m_wall_hit;
};

#endif