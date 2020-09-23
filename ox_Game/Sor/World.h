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

#define GAME_Width 19
#define GAME_Height 6


#endif