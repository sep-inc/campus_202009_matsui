#ifndef BORD_H_
#define BORD_H_
#include "../Vec.h"
#include "Piece.h"
#include "../Definition.h"
/**
 *@clss   盤クラス
 *@brief  盤情報を持つ
 */

#define BORD_WIDTH 4     //!盤のサイズ
#define BORD_HEIGHT 5     //!盤のサイズ

class Bord
{
public:
	Bord();
	~Bord() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  駒の種類判定関数
	 * @param (x) 指定X座標
	 * @param (y) 指定Y座標
	 */
	PIECE_TYPE SearchPiece(__int8 x, __int8 y);

	/**
	 * @brief  プレイヤーの種類判定関数
　　 * @param (x) 指定X座標
	 * @param (y) 指定Y座標
	 */
	PLAYER_TYPE SearchPlayer(__int8 x, __int8 y);

	/**
	 * @brief  盤上配列駒配置関数
	 * @param (piece_) 駒の種類
	 * @param (object_) 駒の種類
	 * @detail 指定した盤上配列に駒を配置する
	 */
	void SetPiecePos(Vec piece_, PIECE_TYPE object_, PLAYER_TYPE player_);

	/**
	 * @brief  駒座標調査関数
	 * @param (piece_) 駒の座標
	 * @param (object_) 駒の種類
	 * @detail 指定した駒の座標を返す
	 */
	Vec SearchPiecePos(PIECE_TYPE object_, PLAYER_TYPE player_, __int8 pawn_number);


	/**
	 * @brief  描画配列代入関数
	 * @detail 描画配列に情報を送る
	 */
	void SetUpDrawBuffer(Piece* piece_[]);

	/**
	 * @brief  リセット関数
	 * @detail 盤情報を初期状態に戻す
	 */
	void Reset();

	/**
	 * @brief  勝利フラグGetter
	 * @detail 先手、後手の勝利フラグを返す
	 */
	const PLAYER_TYPE GetWinner() { return m_winner; }

private:
	/* 盤上構造体 */
	struct BordInfo
	{
		PIECE_TYPE m_put_piece;    //!置いている駒の種類
		PLAYER_TYPE m_put_player;  //!置いているプレイヤーの種類(先手か後手か)
	};

	BordInfo m_bord_info[BORD_HEIGHT][BORD_WIDTH];
	BordInfo m_bord_clear[BORD_HEIGHT][BORD_WIDTH];

	Vec m_source_pos;     //!移動元の座標保存用

	PLAYER_TYPE m_winner; //!勝利判定
};

#endif
