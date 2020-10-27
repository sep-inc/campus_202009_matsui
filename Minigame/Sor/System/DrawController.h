#ifndef DRAW_CONTROLLER_H_
#define DRAW_CONTROLLER_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
#include "DrawBase.h"
#include <map>
/**
*@clss   描画管理クラス
*@brief  各オブジェクトの描画クラスを管理する
*/

class DrawController
{
public:
    DrawController();
    ~DrawController() {}

    /**
     * @brief  インスタンス化関数
     */
    static DrawController* Instance();

    /**
     * @brief  描画関数
     * @detail 描画
     */
    void Draw();

    /**
    * @brief  描画配列クリア関数
    */
    void Clear();

    /**
     * @brief  ゲーム文字代入関数
     * @param (font_) 表示文字代入
     * @detail 選択シーン時に表示する文字を文字連結用に代入する
     */
    void SetUpFont(std::string font_);

    /**
     * @brief  Object描画座標変換関数
     * @param (pos_) Objectの座標
     * @param (font_) 表示する形
     * @detail 描画座標にオブジェクト情報代入
     */
    void SetUpBuffer(Vec2 pos_, const char* font_);

    /**
     * @brief  クリア用配列代入関数
     * @param (pos_) Objectの座標
     * @param (font_) 表示する形
     * @detail クリア用配列に不変的なものだけ代入する
     */
    void SetUpClearBuffer(Vec2 pos_, const char* font_);

    /**
    * @brief  描画ゲーム判定関数
    * @param (game_type_) ゲームの種類
    * @detail 表示に使う描画クラスを判断する
    */
    void SetNowGameDraw(GAME_TYPE game_type_);

private:
    static DrawController* p_instance; //!インスタンス

    DrawBase* m_drawer;

    GAME_TYPE m_game_type;
};

#endif