#ifndef TETRIS_STAGE_H_
#define TETRIS_STAGE_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
/**
*@clss   ステージクラス
*/

#define WALL_SIZE 1  //!壁(フレーム)のサイズ(描画や当たり判定時に使う)

class Tetris_Stage
{
public:
    Tetris_Stage();
    ~Tetris_Stage() {}

    /**
　   * @brief  ステージ描画情報代入関数
     * @param (type_) 描画位置選択
     * @detail 現在のステージの壁と固定されたブロックの描画情報を送る
　   */
    void SetUpDrawStageBuffer(GAME_TYPE type_);

    /**
　   * @brief  予測枠描画情報代入関数
     * @param (type_) 描画位置選択
     * @detail 予測枠の描画情報を送る
　   */
    void SetUpDrawBlockBuffer(GAME_TYPE type_);

    /**
     * @brief  ブロック固定関数
     * @detail ステージにブロックを固定する
     */
    void SetUpBlock(Vec2 pos_, OBJECT_TYPE obj_);

    /**
     * @brief  予測枠更新関数
     * @param (pos_) 描画座標
     * @param (obj_) 代入するオブジェクト
     * @detail 次に降ってくるブロックの形を更新する
     */
    void SetUpNextBlock(Vec2 pos_, OBJECT_TYPE obj_);

    /**
     * @brief  予測枠クリア関数
     * @detail 予測枠を空にする
     * @detail 予測枠を更新する際に使う
     */
    void NextBlockClear();

    /**
     * @brief  初期化関数(繰り返し)
     * @detail メンバ変数の初期化
     * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
     */
    OBJECT_TYPE SearchStage(Vec2 pos_);

private:
    //!ステージ情報
    struct StageInfo
    {
        OBJECT_TYPE m_obj;  //!オブジェクトの種類
    };

    StageInfo m_stage[GAME_HEIGHT][GAME_WIDTH];  //!ステージ配列

    StageInfo m_next_block[7][7];        //!予測枠配列
    StageInfo m_next_block_clear[7][7];  //!予測枠クリア用配列

};

#endif