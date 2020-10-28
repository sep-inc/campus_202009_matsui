#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
 * @brief 共通定数、列挙体配置場所
 */

 //!ゲームの種類
enum GAME_TYPE
{
	Hanoi_Tower,
	OX_Game,
	PacMan,
	RunGame,
	Shougi,
	Tron,
	SelectMode,
	Game_Num,

};

#define FONT_BYTE_ 4   //!文字サイズ


//////////////////////////////////////////////////////////
//!パックマン

#define PACMAN_GAME_WIDTH 13    //!全体の横幅
#define PACMAN_GAME_HEIGHT 13   //!全体の縦幅

#define PACMAN_PLAYER_NUM 2   //!プレイヤーの数

#define PACMAN_ENEMY_NUM 3    //!敵の数
#define PACMAN_ITEM_NUM 5 //!アイテムの数

 //1オブジェクトの種類
enum PACMAN_OBJECT_TYPE
{
	PACMAN_MYSELF,       //!自分
	PACMAN_ENEMY,        //!敵
	PACMAN_ITEM,
	PACMAN_WALL,         //!壁
	PACMAN_NONE          //!空
};

/////////////////////////////////////////////////////////


#define GAME_WIDTH 12    //!全体の横幅
#define GAME_HEIGHT 9   //!全体の縦幅

#define PLAYER_POS_X 1  //!プレイヤーのX座標の位置(マップと相互参照が起こらないようにするため)

#define WALL_SIZE_X 1  //!1マスの横幅
#define WALL_SIZE_Y 1  //!1マスの縦幅

//!移動方向の種類
enum DIRECTION_TYPE
{
	UP,                //!上
	DOWN,			   //!下
	LEFT,			   //!左
	RIGHT,			   //!右
	DIRECTION_MAX,	   //!方向の数
	DIRECTION_NONE,	   //!無し
};

#endif