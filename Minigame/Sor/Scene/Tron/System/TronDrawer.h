#ifndef TRON_DRAWER_H_
#define TRON_DRAWER_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../../System/DrawBase.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/
class TronDrawer :public DrawBase
{
public:
    TronDrawer() {}
    ~TronDrawer() {}

    /**
     * @brief  Object描画座標変換関数
     * @param (pos_) Objectの座標
     * @param (font_) 表示する形
     * @detail 描画座標にオブジェクト情報代入
     */
    void SetUpBuffer(Vec2 pos_, const char* font_);

    /**
     * @brief  描画関数
     * @detail 描画
     */
    void Draw();

    /**
     * @brief  インスタンス返還関数
     * @detail 管理クラスのポインタ配列に返す
     */
    static DrawBase* InstanceTron();

private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[TRON_GAME_HEIGHT][TRON_GAME_WIDTH];  //!描画用配列

};

#endif