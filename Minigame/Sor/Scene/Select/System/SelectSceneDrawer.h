#ifndef SELECT_SCENE_DRAWER_H_
#define SELECT_SCENE_DRAWER_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../../System/DrawBase.h"
#include <string>
#include <vector>

/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class SelectSceneDrawer :public DrawBase
{
public:
    SelectSceneDrawer() {}
    ~SelectSceneDrawer() {}

    /**
      * @brief  ゲーム文字代入関数
      * @param (font_) 表示文字代入
      * @detail 選択シーン時に表示する文字を文字連結用に代入する
      */
    virtual void SetUpFont(std::string font_)override;

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
    std::vector<std::string> m_draw_font; //!描画用文字
};

#endif