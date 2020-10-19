#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
 * @brief 共通定数、列挙体配置場所
 */

#define FONT_BYTE_ 4   //!文字サイズ

#define GAME_WIDTH 19    //!全体の横幅
#define GAME_HEIGHT 12   //!全体の縦幅

#define PLAYER_MAX 2   //!プレイヤーの数

//1オブジェクトの種類
enum OBJECT_TYPE
{
	MYSELF,       //!自分
	ENEMY,        //!敵
	WALL,         //!壁
	NONE          //!空
};

#endif