#ifndef MYSELF_H_
#define MYSELF_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Bord.h"
#include "../Definition.h"
#include "Player.h"

class Myself :public Player
{
public:
	Myself(PLAYER_TYPE player_);
	~Myself() {}

	/**
   　* @brief  入力関数
　   * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
   　*/
	void MoveSourceSelect(Bord* bord_);

	/**
　   * @brief  入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
　   */
	bool NextMoveSelect(Bord* bord_, Piece* piece_[]);

	/**
	 * @brief  移動駒表示関数
	 * @param (piece_type_) 駒の種類
	 * @detail 現在動かそうとしている駒の表示
	 */
	void NowMovePiece(PIECE_TYPE piece_type_);
};
#endif