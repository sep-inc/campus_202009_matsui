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
	Syougi,
	Tron,
	SelectMode,
	Game_Num,

};

#define FONT_BYTE_ 4   //!文字サイズ


///////////////////////////////////////////////////////////
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


/////////////////////////////////////////////////////////
#define RUNGAME_WIDTH 12    //!全体の横幅
#define RUNGAME_HEIGHT 9   //!全体の縦幅

#define RUNGAME_PLAYER_POS_X 1  //!プレイヤーのX座標の位置(マップと相互参照が起こらないようにするため)

#define RUNGAME_WALL_SIZE_X 1  //!1マスの横幅
#define RUNGAME_WALL_SIZE_Y 1  //!1マスの縦幅
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
#define TRON_GAME_WIDTH 19    //!全体の横幅
#define TRON_GAME_HEIGHT 12   //!全体の縦幅

#define TRON_PLAYER_MAX 2   //!プレイヤーの数

//1オブジェクトの種類
enum TRON_OBJECT_TYPE
{
	TRON_MYSELF,       //!自分
	TRON_ENEMY,        //!敵
	TRON_WALL,         //!壁
	TRON_NONE          //!空
};

/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
/* オブジェクトの種類 */
enum PIECE_TYPE
{
	KING,        //!王
	KNIGHT,      //!桂
	GOLDGENERAL, //!金
	PAWN,        //!歩
	PIECE_NUM,   //!駒の種類の数
	PIECE_BLANK,       //!空
};

//!プレイヤーの種類
enum SYOUGI_PLAYER_TYPE
{
	SYOUGI_FIRST,         //!先手
	SYOUGI_SECOND,        //!後手
	SYOUGI_PLAYER_NUM,    //!プレイヤーの人数
	SYOUGI_NONE           //!空
};

#define SYOUGI_GAME_WIDTH 9   //!全体の横幅
#define SYOUGI_GAME_HEIGHT 11   //!全体の縦幅

#define PIECE_MOVE_MAX_X 3     //!駒の動ける最大範囲範囲
#define PIECE_MOVE_MAX_Y 4     //!駒の動ける最大範囲範囲

#define PIECE_MOVE_MIN 0     //!駒の動ける最小範囲範囲

/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
enum HANOITOWER_OBJECT_TYPE
{
	BOX,
	DISK
};

#define START_UNIT 0        //最初の要素数

#define BUFFER_WIDTH 19       //Bufferの横幅
#define BUFFER_HEIGHT 6       //Bufferの縦幅

#define BOX_NUM 3            //箱の数
#define BOX_WIDTH 5          //箱の横幅
#define BOX_HEIGHT 3         //箱の縦幅

#define BUFFER_BOX_POS_Y 2         //箱の縦幅

#define DISK_NUM 3           //円盤の数
#define SMALL_DISK_WIDTH 1   //小円盤の横幅
#define NOMAL_DISK_WIDTH 3   //中盤の横幅
#define BIG_DISK_WIDTH 5     //大盤の横幅
#define DISK_HEIGHT 1        //円盤の縦幅

#define DISK_MAX_WIDTH 6        //円盤の縦幅
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