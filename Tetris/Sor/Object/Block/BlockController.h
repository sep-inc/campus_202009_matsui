#ifndef TETRIS_BLOCKCONTROLLER_H_
#define TETRIS_BLOCKCONTROLLER_H_
#include "../../Utility/Vec2.h"
#include "../../Definition.h"
#include "BlockBase.h"
#include "../Stage.h"
/**
*@clss   Block管理クラス
*/


class Tetris_BlockController
{
public:
    Tetris_BlockController();
    ~Tetris_BlockController() {}

    /**
    * @brief  初期化関数(繰り返し)
    * @detail メンバ変数の初期化
    * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
    */
    void Rest(Tetris_Stage* stage_);

    /**
     * @brief  ステップ処理関数
     * @detail ステップ変更処理
     */
    void Update();

    /**
　   * @brief  ブロック更新関数
     * @detail ブロックの各更新処理をまとめた関数
　   */
    void BlockUpdate();

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    void CreateBlock();

    /**
　   * @brief  ブロック描画情報代入関数
     * @param (type_) 描画位置選択
     * @detail 現在移動しているブロックの描画情報を送る
　   */
    void SetUpDrawBuffer(GAME_TYPE type_);

private:
    //!ステップの種類
    enum STEP
    {
        STEP_CREATE,  //!生成
        STEP_UPDATE,  //!更新
    }m_step;

    BLOCK_TYPE m_block_type;       //!現在のブロックの種類 
    BLOCK_TYPE m_next_block_type;  //!次のブロックの種類


    Tetris_Stage* m_stage;                //!ステージアドレス保存用
    Tetris_BlockBase* m_block[TYPE_NUM];  //!各ブロック
};

#endif