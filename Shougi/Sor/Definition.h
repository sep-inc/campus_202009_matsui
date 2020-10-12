#ifndef WORLD_H_
#define WORLD_H_
/**
 * @brief 共通定数、列挙体配置場所
 */

 /* オブジェクトの種類 */
enum PIECE_TYPE
{
    KING,        //!王
    KNIGHT,      //!桂
    GOLDGENERAL, //!金
    PAWN,        //!歩
    PIECE_NUM,   //!駒の種類の数
    BLANK,       //!空
};

//!プレイヤーの種類
enum PLAYER_TYPE
{
    FIRST,         //!先手
    SECOND,        //!後手
    PLAYER_NUM,    //!プレイヤーの人数
    NONE           //!空
};

#define GAME_WIDTH 9   //!全体の横幅
#define GAME_HEIGHT 11   //!全体の縦幅

#define MOVE_MAX_X 3     //!駒の動ける最大範囲範囲
#define MOVE_MAX_Y 4     //!駒の動ける最大範囲範囲

#define MOVE_MIN 0     //!駒の動ける最小範囲範囲
#endif