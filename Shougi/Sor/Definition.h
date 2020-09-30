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


#define GAME_WIDTH 10    //!全体の横幅
#define GAME_HEIGHT 12   //!全体の縦幅

#define FIRST_PLAYER 1   //!先手
#define SECOND_PLAYER 2  //!後手

#define OU_MOVE_MAX_X 3     //!王のX軸の動ける最大範囲範囲
#define OU_MOVE_MAX_Y 3     //!王のY軸の動ける最大範囲範囲

#define KEIMA_MOVE_MAX_X 3    //!桂のX軸の動ける最大範囲範囲
#define KEIMA_MOVE_MAX_Y 3    //!桂のY軸の動ける最大範囲範囲

#define KIN_MOVE_MAX_X 3    //!金のX軸の動ける最大範囲範囲
#define KIN_MOVE_MAX_Y 3    //!金のY軸の動ける最大範囲範囲

#define HU_MOVE_MAX_X 1     //!歩のX軸の動ける最大範囲範囲
#define HU_MOVE_MAX_Y 2     //!歩のY軸の動ける最大範囲範囲



#endif