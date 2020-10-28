#ifndef DRAWER_H_
#define DRAWER_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../../System/DrawBase.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class PacManDrawer :public DrawBase
{
public:
    PacManDrawer() {}
    ~PacManDrawer() {}

    /**
    * @brief  Object描画座標変換関数
    * @param (pos_) Objectの座標
    * @param (font_) 表示する形
    * @detail 描画座標にオブジェクト情報代入
    */
    virtual void SetUpBuffer(Vec2 pos_, const char* font_)override;

    /**
     * @brief  クリア用配列代入関数
     * @param (pos_) Objectの座標
     * @param (font_) 表示する形
     * @detail クリア用配列に不変的なものだけ代入する
     */
    virtual void SetUpClearBuffer(Vec2 pos_, const char* font_)override;

    /**
     * @brief  描画関数
     * @detail 描画
     */
    virtual void Draw()override;

    /**
    * @brief  描画配列クリア関数
    */
    virtual void Clear()override;

private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[PACMAN_GAME_HEIGHT][PACMAN_GAME_WIDTH];  //!描画用配列
    DrawBuffer m_clear_buffer[PACMAN_GAME_HEIGHT][PACMAN_GAME_WIDTH];  //!描画用配列
};

#endif