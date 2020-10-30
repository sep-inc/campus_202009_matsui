#ifndef RUNGAME_DRAWER_H_
#define RUNGAME_DRAWER_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../../System/DrawBase.h"

/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/
class RunGameDrawer :public DrawBase
{
public:
    RunGameDrawer() {}
    ~RunGameDrawer() {}

    /**
    * @brief  Object描画座標変換関数
    * @param (pos_) Objectの座標
    * @param (font_) 表示する形
    * @detail 描画座標にオブジェクト情報代入
    */
    virtual void SetUpBuffer(Vec2 pos_, const char* font_)override;

    /**
   * @brief クリア配列代入関数
   * @param (kind_) 配列の先頭アドレス
   * @param (size_) 渡すサイズ
   * @detail クリア配列に不変的なものを代入
   */
    void SetUpClearBuffer(Vec2 pos_, const char* font_)override;

    /**
    * @brief  描画関数
    * @detail 描画
    */
    virtual void Draw()override;

    /**
     * @brief  描画配列クリア関数
     */
    virtual void Clear()override;

    /**
     * @brief  インスタンス返還関数
     * @detail 管理クラスのポインタ配列に返す
     */
    static DrawBase* InstanceRunGame();

private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[RUNGAME_HEIGHT][RUNGAME_WIDTH];  //!描画用配列
    DrawBuffer m_clear_buffer[RUNGAME_HEIGHT][RUNGAME_WIDTH]; //!クリア用配列

};

#endif