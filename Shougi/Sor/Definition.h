#ifndef WORLD_H_
#define WORLD_H_
/**
 * @brief 共通定数、列挙体配置場所
 */

 /* オブジェクトの種類 */
enum OBJECT_TYPE
{
    BLANK,  //!空
    OU,     //!王
    KEIMA,  //!桂
    KIN,    //!金
    HU      //!歩
};

//!プレイヤーの種類
enum PLAYER_TYPE
{
    NONE,  //!空
    FIRST, //!先手
    SECOND //!後手
};

#define GAME_WIDTH 10    //!全体の横幅
#define GAME_HEIGHT 12   //!全体の縦幅

#define MOVE_MAX 3     //!駒の動ける最大範囲範囲
#define MOVE_MIN 0     //!駒の動ける最小範囲範囲

#endif