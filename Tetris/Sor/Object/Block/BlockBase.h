#ifndef TETRIS_BLOCKBASE_H_
#define TETRIS_BLOCKBASE_H_
#include "../../Utility/Vec2.h"
#include "../../Definition.h"
#include "../Stage.h"
/**
*@clss   Blockの基底クラス
*/

enum BLOCK_ANGLE_TYPE
{
    ZERO,
    ONE,
    TWO,
    THREE
};

class Tetris_BlockBase
{
public:
    Tetris_BlockBase(Tetris_Stage* stage_);
    ~Tetris_BlockBase() {}

    /**
     * @brief  初期化関数(繰り返し)
     * @detail メンバ変数の初期化
     * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
     */
    void Reset();

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    void Update();

    /**
　   * @brief  移動関数
     * @detail ブロックの移動を行う
　   */
    void Move();

    /**
　   * @brief  当たり判定関数
     * @detail 動いているブロックと壁や固定されたブロックとの当たり判定を行う
　   */
    bool Collision();

    /**
　   * @brief  ステージ更新関数
     * @detail 動いているブロックが固定される時、ステージに何処に固定するかを送る
　   */
    virtual void SetStageBuffer();

    /**
　   * @brief  予測枠更新関数
     * @detail 次に降ってくるブロックの形を表示する枠に情報を送る
　   */
    virtual void SetNextBlockBuffer();

    /**
　   * @brief  ブロック描画情報代入関数
     * @param (type_) 描画位置選択
     * @detail 現在移動しているブロックの描画情報を送る
　   */
    virtual void SetUpDrawBuffer(GAME_TYPE type_);

    /**
　   * @brief  形更新(回転)関数関数
     * @param (angle_) 回転方向(1か-1か)
     * @detail 現在移動しているブロックの形を回転させる
　   */
    virtual void SetBlockAngle(__int8 angle_) {}

    /**
　   * @brief  使用ブロック座標更新関数
     * @detail 移動しているブロックの座標を更新
　   */
    void SetBlockPos(float x_, float y_);

    /**
　   * @brief  ブロック停止(固定)フラグGetter関数
　   */
    bool GetStop() { return m_stop; }

protected:
    Tetris_Stage* m_stage;  //!ステージアドレス保存用

    const char* m_font;     //!描画スタイル

    const __int8(*m_block)[BLOCK_WIDTH]; 	//!ブロック配列ポインタ  

    float m_pos_x;        //!現在X座標(移動時に小数を使うためfloat)
    float m_pos_y;        //!現在Y座標(移動時に小数を使うためfloat)

    float m_next_pos_x;   //!移動後X座標(移動時に小数を使うためfloat)
    float m_next_pos_y;   //!移動後Y座標(移動時に小数を使うためfloat)

    float m_speed;        //!移動スピード

    bool m_stop;          //!停止(固定)フラグ

    __int8 m_angle_type;  //!現在角度保存用
};

#endif