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
	Enemy(PLAYER_TYPE player_) :m_my_player_type(player_) {}
	~Enemy() {}

	/**
     * @brief  初期化関数
     * @detail メンバ変数の初期化
     */
	virtual void Init()override;

	/**
   　* @brief  更新関数
	 * @param (bord_) 盤クラス
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void Update(Bord* bord_)override;

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
	bool NextMoveSelect(Bord* bord_);

	/**
   　* @brief  移動関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先をもとに駒を移動させる
   　*/
	void Move(Bord* bord_);

	/**
	 * @brief  指定箇所調査
	 * @param (bord_) 盤クラス
	 * @detail 指定した場所の盤情報を受け取る関数
	 */
	void SearchBord(Bord* bord_);

	/**
	 * @brief  勝敗判定関数
	 * @param (bord_) 盤クラス
	 * @detail 盤クラスからの結果をもとにGameControllerにフラグを返す
	 */
	virtual bool Judgment(Bord* bord_)override;

	/**
	* @brief  解放関数
	*/
	virtual void Delete()override;

	void NextPos();

private:
	const PLAYER_TYPE m_my_player_type;   //!自分自身識別変数

	Vec m_rand_pos;        //!移動先変数

};


#endif