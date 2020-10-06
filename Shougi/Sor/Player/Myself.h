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
	//!現在2人とも手入力のためメンバイニシャライザで初期化
	//!後々普通のイニシャライザで初期化
	Myself() {}
	~Myself() {}

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
   　* @brief  入力関数
　   * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
   　*/
	void Input(Bord* bord_);

	/**
　   * @brief  入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
　   */
	bool NextMoveInput(Bord* bord_);

	/**
   　* @brief  移動関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先をもとに駒を移動させる
   　*/
	void Move(Bord* bord_);

	/**
	 * @brief  移動駒表示関数
	 * @param (piece_type_) 駒の種類
	 * @detail 現在動かそうとしている駒の表示
	 */
	void NowMovePiece(OBJECT_TYPE piece_type_);

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

private:
	static const PLAYER_TYPE m_my_player_type;   //!プレイヤーの種類保存用

};
#endif