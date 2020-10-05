#ifndef BORD_H_
#define BORD_H_
#include "../Vec.h"
#include "Piece.h"
#include "../Definition.h"

#define BORD_WIDTH 4     //!盤のサイズ
#define BORD_HEIGHT 5     //!盤のサイズ

/**
 *@clss   盤クラス
 *@brief  盤情報を持つ
 */
class Bord
{
public:
	Bord():m_winner(NONE){}
	~Bord() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  駒の種類判定関数
	 */
	OBJECT_TYPE SearchPiece(__int8 input_font_, __int8 input_number_);

	/**
	 * @brief  プレイヤーの種類判定関数
	 */
	PLAYER_TYPE SearchPlayer(__int8 input_font_, __int8 input_number_);

	/**
	 * @brief  盤上配列駒配置関数
	 * @param (piece_) 駒の座標
	 * @param (object_) 駒の種類
	 * @detail 指定した盤上配列に駒を配置する
	 */
	void SetPiecePos(Vec piece_, OBJECT_TYPE object_, PLAYER_TYPE player_);

	/**
	 * @brief  描画配列代入関数
	 * @detail 描画配列に情報を送る
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  勝利フラグGetter
	 * @detail 先手、後手の勝利フラグを返す
	 */
	const PLAYER_TYPE GetWinner() { return m_winner; }

private:
	/* 盤上構造体 */
	struct BordInfo
	{
		OBJECT_TYPE m_put_piece;   //!置いている駒の種類
		PLAYER_TYPE m_put_player;  //!置いているプレイヤーの種類(先手か後手か)

	}m_bord_info[BORD_HEIGHT][BORD_WIDTH];

	Vec m_source_pos;     //!移動元の座標保存用

	PLAYER_TYPE m_winner; //!勝利判定

};

#endif
