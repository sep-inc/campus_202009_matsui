#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"
#include "../Definition.h"
/**
 *@clss   駒の基底クラス
 */

///////////////////////////////////////////////////////////////////////////////////////////
//!今後描画やデータの持ち方によって変わってくる可能性があるため、データが少なくても分ける//
///////////////////////////////////////////////////////////////////////////////////////////

#define MOVE_POSSIBLE 1 //!移動可能数値


class Piece
{
public:
	Piece(){}
	~Piece() {}

	/**
	 * @brief  移動判定
     * @param (center_pos_) 駒の移動範囲配列の基準座標
	 * @param (input_pos_) 移動先の座標
	 * @param (player_type_) 先手か後手
	 * @detail 先手、後手の選んだ駒が移動できるか判定
	 */
	bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_);

	/**
　　 * @brief  移動判定
　　 * @param (player_type_) 先手か後手
　　 * @param (pos) 座標
　　 * @detail 描画配列に駒の情報を送る
　　 */
	void DrawPiece(PLAYER_TYPE player_type_, Vec pos);

protected:
	const __int8(*m_move)[MOVE_MAX_X]; 	//!移動範囲配列ポインタ

    //!移動範囲配列の基準座標
	static const Vec move_center;  //!駒の移動範囲の基準座標(配列で言う2の箇所)

	const char* m_first_draw_font;   //!先手が表示する駒の文字用
	const char* m_second_draw_font;  //!後手が表示する駒の文字用

};
#endif