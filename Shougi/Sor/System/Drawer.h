#ifndef DRAWER_H_
#define DRAWER_H_
#include "../Vec.h"
#include "../Definition.h"

#define BYTE 4

/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/
class Drawer
{
public:
    Drawer() {}
    ~Drawer() {}

    /**
     * @brief  初期化関数
     * @detail メンバ変数の初期化
     */
    void Init();

    /**
    * @brief  Object描画座標変換関数
    * @param (pos_) Objectの座標
    * @param (font_) 表示する形
    * @detail 描画座標にオブジェクト情報代入
    */
    void SetUpBuffer(Vec pos_, const char* font_);

    /**
    * @brief  描画関数
    * @detail 描画
    */
    void Draw();

    /**
     * @brief  描画配列クリア関数
     */
    void Clear();


private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[GAME_HEIGHT][GAME_WIDTH];  //!描画用配列
    DrawBuffer m_clear_buffer[GAME_HEIGHT][GAME_WIDTH]; //!クリア用配列

};

#endif