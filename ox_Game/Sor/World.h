#ifndef WORLD_H_
#define WORLD_H_
/**
 * @brief ���ʒ萔�A�񋓑̔z�u�ꏊ
 */


/* �I�u�W�F�N�g�̎�� */
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