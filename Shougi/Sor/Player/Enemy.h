#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Board.h"
#include "../Definition.h"
#include "Player.h"

#define RESET_NUM 3  //!移動先を検索できる回数

class Enemy :public Player
{
public:
	Enemy(PLAYER_TYPE player_);
	~Enemy() {}

	/**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
	virtual void Update(Piece* piece_[]);

	/**
   　* @brief  移動元入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元を入力する
   　*/
	void MoveSourceSelect();

	/**
　   * @brief  移動先入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先を入力する
	 * @return 移動先が決まったかどうか
　   */
	bool NextMoveSelect(Piece* piece_[]);

	void NextPos();

private:
	Vec2 m_rand_pos;        //!移動先変数
};


#endif