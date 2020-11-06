#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
 * @brief 共通定数、列挙体配置場所
 */

#define FONT_BYTE_ 4   //!文字サイズ



#define GAME_WIDTH 12    //!全体の横幅
#define GAME_HEIGHT 22   //!全体の縦幅

#define NEXT_BLOCK_WIDTH 7    //!全体の横幅
#define NEXT_BLOCK_HEIGHT 7   //!全体の縦幅

#define BLOCK_WIDTH 5    //!全体の横幅
#define BLOCK_HEIGHT 5   //!全体の縦幅

enum GAME_TYPE
{
	TYPE_A,
	TYPE_B,
	GAME_NUM,
};

 //1オブジェクトの種類
enum OBJECT_TYPE
{
	NONE,         //!空
	FIXED_BLOCK,  //!固定ブロック
	BLOCK,        //!ブロック
	WALL          //!壁
};

enum BLOCK_TYPE
{
	I_BLOCK,
	J_BLOCK,
	L_BLOCK,
	O_BLOCK,
	S_BLOCK,
	T_BLOCK,
	Z_BLOCK,
	TYPE_NUM
};

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