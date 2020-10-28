#ifndef SYOUGI_PLAYER_H_
#define SYOUGI_PLAYER_H_
#include "../../../../Utility/Vec2.h"
#include "../../../../Definition.h"
#include "../SyougiPiece.h"
#include "../SyougiBoard.h"
#include "../SyougiCursor.h"

class SyougiPlayer
{
public:
	SyougiPlayer() {}
	~SyougiPlayer() {}

	/**
　   * @brief  初期化関数(繰り返し)
	 * @param (stage_) ステージのアドレス
　　 * @param (item_) アイテムのアドレス
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	virtual void Reset() = 0;

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void Update(SyougiPiece* piece_[]) = 0;

	/**
   　* @brief  移動関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先をもとに駒を移動させる
   　*/
	void Move(SyougiBoard* bord_);

	/**
	 * @brief  指定箇所調査
	 * @param (bord_) 盤クラス
	 * @detail 指定した場所の盤情報を受け取る関数
	 */
	void SearchBord(SyougiBoard* bord_, Vec2 pos_);

	/**
	* @brief  勝敗判定関数
	* @detail 盤クラスからの結果をもとにGameControllerにフラグを返す
	*/
	bool Judgment(SyougiBoard* bord_);

	bool GetMove() { return m_move; }

protected:
	SYOUGI_PLAYER_TYPE m_my_player_type;   //!プレイヤーの種類保存用

	PIECE_TYPE m_piece_type;     //!駒の種類保存用
	SYOUGI_PLAYER_TYPE m_player_type;   //!プレイヤーの種類保存用

	Vec2 m_now_pos;    //!動かす駒の座標保存用
	Vec2 m_next_pos;   //!動かす場所保存用

	SyougiCursor* m_cursor;
	SyougiBoard* m_board;  //!プレイヤー

	bool m_move;
};


#endif