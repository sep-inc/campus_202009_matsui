#ifndef DRAW_BASE_H_
#define DRAW_BASE_H_
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

#include <string>


class DrawBase
{
public:
    DrawBase() {}
    virtual ~DrawBase() {}

    /**
     * @brief  描画関数
     * @detail 描画
     */
    virtual void Draw() = 0;

    /**
    * @brief  描画配列クリア関数
    */
    virtual void Clear() {}

    /**
     * @brief  ゲーム文字代入関数
     * @param (font_) 表示文字代入
     * @detail 選択シーン時に表示する文字を文字連結用に代入する
     */
    virtual void SetUpFont(std::string font_) {}

    /**
   * @brief  Object描画座標変換関数
   * @param (pos_) Objectの座標
   * @param (font_) 表示する形
   * @detail 描画座標にオブジェクト情報代入
   */
    virtual void SetUpBuffer(Vec2 pos_, const char* font_) {}

    /**
     * @brief  クリア用配列代入関数
     * @param (pos_) Objectの座標
     * @param (font_) 表示する形
     * @detail クリア用配列に不変的なものだけ代入する
     */
    virtual void SetUpClearBuffer(Vec2 pos_, const char* font_) {}
};

#endif