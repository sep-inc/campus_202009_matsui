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
	I_BLOCK,   //!I型
	J_BLOCK,   //!J型
	L_BLOCK,   //!L型
	O_BLOCK,   //!O型
	S_BLOCK,   //!S型
	T_BLOCK,   //!T型
	Z_BLOCK,   //!Z型
	TYPE_NUM   //!種類の数
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