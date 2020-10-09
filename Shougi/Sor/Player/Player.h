#ifndef PLAYER_H_
#define PLAYER_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Board.h"
#include "../Object/Cursor.h"
#include "../Definition.h"
class Player
{
public:
	Player() {}
	~Player() {}

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void Update(Piece* piece_[]) = 0;

	/**
   　* @brief  移動関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先をもとに駒を移動させる
   　*/
	void Move(Board* bord_);

	/**
	 * @brief  指定箇所調査
	 * @param (bord_) 盤クラス
	 * @detail 指定した場所の盤情報を受け取る関数
	 */
	void SearchBord(Board* bord_, Vec2 pos_);

	/**
	* @brief  勝敗判定関数
	* @detail 盤クラスからの結果をもとにGameControllerにフラグを返す
	*/
	bool Judgment(Board* bord_);

protected:
	PLAYER_TYPE m_my_player_type;   //!プレイヤーの種類保存用

	PIECE_TYPE m_piece_type;     //!駒の種類保存用
	PLAYER_TYPE m_player_type;   //!プレイヤーの種類保存用

	Vec2 m_now_pos;    //!動かす駒の座標保存用
	Vec2 m_next_pos;   //!動かす場所保存用

	Cursor* m_cursor;
	Board* m_board;  //!プレイヤー
};


#endif