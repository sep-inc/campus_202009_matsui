#ifndef SYOUGI_DRAWER_H_
#define SYOUGI_DRAWER_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../../System/DrawBase.h"

#define SYOUGI_FRAME_X 2 //!フレームが盤上をとるサイズ
#define SYOUGI_FRAME_Y 2 //!フレームが盤上をとるサイズ

/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/
class SyougiDrawer :public DrawBase
{
public:
    SyougiDrawer() {}
    ~SyougiDrawer() {}

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

    /**
     * @brief  インスタンス返還関数
     * @detail 管理クラスのポインタ配列に返す
     */
    static DrawBase* InstanceSyougi();

private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[SYOUGI_GAME_HEIGHT][SYOUGI_GAME_WIDTH];  //!描画用配列
    DrawBuffer m_clear_buffer[SYOUGI_GAME_HEIGHT][SYOUGI_GAME_WIDTH]; //!クリア用配列

};

#endif