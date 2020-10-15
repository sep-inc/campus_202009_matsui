#ifndef DRAWER_H_
#define DRAWER_H_
#include "../Utility/Vec.h"
#include "../Definition.h"
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
    * @brief  Object描画座標変換関数
    * @param (pos_) Objectの座標
    * @param (font_) 表示する形
    * @detail 描画座標にオブジェクト情報代入
    */
    void SetUpBuffer(Vec pos_, const char* font_);

    /**
   * @brief クリア配列代入関数
   * @param (kind_) 配列の先頭アドレス
   * @param (size_) 渡すサイズ
   * @detail クリア配列に不変的なものを代入
   */
    void SetUpClearBuffer(const void* kind_, int size_);

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