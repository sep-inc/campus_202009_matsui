#ifndef MYSELF_H_
#define MYSELF_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Cursor.h"
#include "../Object/Board.h"
#include "../Definition.h"
#include "Player.h"

class Myself :public Player
{
public:
	Myself(PLAYER_TYPE player_);
	~Myself() {}

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void Update(Piece* piece_[]);

	/**
   　* @brief  入力関数
　   * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
   　*/
	bool MoveSourceSelect();

	/**
　   * @brief  入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
　   */
	bool NextMoveSelect(Piece* piece_[]);

	/**
	 * @brief  移動駒表示関数
	 * @param (piece_type_) 駒の種類
	 * @detail 現在動かそうとしている駒の表示
	 */
	void NowMovePiece(PIECE_TYPE piece_type_);

private:
	enum STEP
	{
		SelectSorce_Step,
		SelectNext_Step,
		Move_Step
	}m_step;

	bool re_sorce_input;

	
};
#endif