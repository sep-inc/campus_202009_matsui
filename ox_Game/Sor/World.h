#ifndef WORLD_H_
#define WORLD_H_
/**
 * @brief 共通定数、列挙体配置場所
 */


/* オブジェクトの種類 */
enum OBJECT_TYPE
{
    BLANK,
    PLAYER_PIECE,
    ENEMY_PIECE,
};

enum JUDGMENT_TYPE
{
    WIN,
    LOSE,
    DRAW
};

#define GAME_WIDTH 8    //!全体の横幅
#define GAME_HEIGHT 8   //!全体の縦幅

#define BORD_SIZE 3     //!盤のサイズ


#endif