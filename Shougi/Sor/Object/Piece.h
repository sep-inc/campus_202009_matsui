#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"
#include "../Definition.h"

/**
 *@clss   駒クラス
 *@brief  プレイヤー、敵の駒情報を持つ
 */

#define HU_NUM 4 //!1プレイヤーの持つ歩の数

 //!移動範囲配列
#pragma region 先手の駒の移動範囲
const __int8 ou_move[3][3]=
{
	1,1,1,
	1,0,1,
	1,1,1
};  //!王

const __int8 first_kei_move[3][3]=
{
	1,0,1,
	0,0,0,
	0,0,0
}; //!桂

const __int8 first_kin_move[3][3]=
{
	1,1,1,
	1,0,1,
	0,1,0
}; //!金

const __int8 first_hu_move[3][3]=
{
	0,1,0,
	0,0,0,
	0,0,0
};  //!歩
#pragma endregion

#pragma region 先手の駒の移動範囲
const __int8 second_kei_move[3][3] =
{
	0,0,0,
	0,0,0,
	1,0,1
}; //!桂

const __int8 second_kin_move[3][3] =
{
	0,1,0,
	1,0,1,
	1,1,1
}; //!金

const __int8 second_hu_move[3][3] =
{
	0,0,0,
	0,0,0,
	0,1,0
};  //!歩
#pragma endregion


//!移動範囲配列の基準座標
const Vec move_center = Vec(1, 1);  //!王と金と歩

//!桂馬
const Vec first_kei_center = Vec(1, 2);
const Vec second_kei_center = Vec(1, 0);

class Piece
{
public:
	Piece(){}
	~Piece() {}
	
	/**
	 * @brief  移動判定
     * @param (center_pos_) 駒の移動範囲配列の基準座標
	 * @param (input_pos_) 移動先の座標
	 * @param (piece_type_) 駒の種類
	 * @param (player_type_) 先手か後手
	 * @detail 先手、後手の選んだ駒が移動できるか判定
	 */
	bool SearchMove(Vec center_pos_, Vec input_pos_, OBJECT_TYPE piece_type_, PLAYER_TYPE player_type_);
};


#endif