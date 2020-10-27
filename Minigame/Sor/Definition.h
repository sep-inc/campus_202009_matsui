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

#define GAME_WIDTH 13    //!全体の横幅
#define GAME_HEIGHT 13   //!全体の縦幅

#define PLAYER_NUM 2   //!プレイヤーの数

#define ENEMY_NUM 3    //!敵の数
#define ITEM_NUM 5 //!アイテムの数

 //1オブジェクトの種類
enum PACMAN_OBJECT_TYPE
{
	MYSELF,       //!自分
	ENEMY,        //!敵
	ITEM,
	WALL,         //!壁
	NONE          //!空
};

/////////////////////////////////////////////////////////



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