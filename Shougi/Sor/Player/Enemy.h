#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Bord.h"
#include "../Definition.h"
#include "Player.h"

#define RESET_NUM 3  //!移動先を検索できる回数

class Enemy :public Player
{
public:
	Enemy(PLAYER_TYPE player_);
	~Enemy() {}

	/**
   　* @brief  移動元入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元を入力する
   　*/
	void MoveSourceSelect(Bord* bord_);

	/**
　   * @brief  移動先入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先を入力する
　   */
	bool NextMoveSelect(Bord* bord_, Piece* piece_[]);

	void NextPos();

private:
	Vec m_rand_pos;        //!移動先変数
};


#endif