#ifndef PLAYER_H_
#define PLAYER_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Bord.h"
#include "../Definition.h"
class Player
{
public:
	Player() {}
	~Player() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init() = 0;

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void Update(Bord* bord_) = 0;

	/**
	* @brief  勝敗判定関数
	* @detail 盤クラスからの結果をもとにGameControllerにフラグを返す
	*/
	virtual bool Judgment(Bord* bord_) = 0;

	/**
	* @brief  解放関数
	*/
	virtual void Delete() = 0;

protected:
	Piece* m_piece[PIECE_NUM];    //!各駒

	PIECE_TYPE m_piece_type;    //!駒の種類保存用
	PLAYER_TYPE m_player_type;   //!プレイヤーの種類保存用

	Vec m_now_pos;    //!動かす駒の座標保存用
	Vec m_next_pos;   //!動かす場所保存用
};


#endif