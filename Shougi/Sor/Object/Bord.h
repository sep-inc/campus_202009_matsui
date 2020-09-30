#ifndef BORD_H_
#define BORD_H_
#include "../Vec.h"
#include "Piece.h"

#define BORD_WIDTH 4     //!盤のサイズ
#define BORD_HEIGHT 5     //!盤のサイズ

/**
 *@clss   盤クラス
 *@brief  盤情報を持つ
 */
class Bord
{
public:
	Bord() {}
	~Bord() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  駒の種類判定関数
	 */
	__int8 SearchPiece(__int8 input_font_, __int8 input_number_);

	/**
	 * @brief  プレイヤーの種類判定関数
	 */
	__int8 SearchPlayer(__int8 input_font_, __int8 input_number_);

	/**
	 * @brief  盤上配列駒配置関数
	 * @param (piece_) 駒の座標
	 * @param (object_) 駒の種類
	 * @detail 指定した盤上配列に駒を配置する
	 */
	void SetPiecePos(Vec piece_, __int8 object_, bool display_, __int8 player_);

private:
	/* 盤上構造体 */
	struct BordInfo
	{
		__int8 m_put_object;  //!置いているObjectの種類
		__int8 m_put_player;  //!置いているプレイヤーの種類(先手か後手か)

	}m_bord_info[BORD_HEIGHT][BORD_WIDTH];

};

#endif
