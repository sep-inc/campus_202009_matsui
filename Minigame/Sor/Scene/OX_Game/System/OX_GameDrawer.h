#ifndef OX_GAME_DRAWER_H_
#define OX_GAME_DRAWER_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../../System/DrawBase.h"

/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/
class OX_GameDrawer :public DrawBase
{
public:
    OX_GameDrawer();
    ~OX_GameDrawer() {}

    /**
  * @brief  Object描画座標変換関数
  * @param (pos_) Objectの座標
  * @param (font_) 表示する形
  * @detail 描画座標にオブジェクト情報代入
  */
    virtual void SetUpBuffer(Vec2 pos_, const char* font_)override;

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
    static DrawBase* InstanceOX_Game();

private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[8][8];  //!描画用配列
    DrawBuffer m_clear_buffer[8][8]; //!クリア用配列

};

#endif