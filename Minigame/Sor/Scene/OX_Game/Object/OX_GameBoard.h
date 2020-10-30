#ifndef OX_GAME_BORD_H_
#define OX_GAME_BORD_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"

/**
 *@clss   盤クラス
 *@brief  盤情報を持つ
 */
class OX_GameBoard
{
public:
	OX_GameBoard() {}
	~OX_GameBoard() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  更新関数
	 * @detail 更新処理
	 */
	bool Judgment();

	/**
	 * @brief  終了判定関数(勝敗)
	 * @param (object) プレイヤーか敵の駒
	 * @detail 盤上に同じ駒が3つ以上縦横斜めでそろっているかを判定
	 */
	bool EndSearch(__int8 object);

	/**
	 * @brief  終了判定関数(引き分け)
	 * @detail 勝ち負けが決まらず置ける場所があるかを判定
	 */
	bool JudgmentDraw();

	/**
	 * @brief  配置判定関数
	 * @param (input_font) 入力した文字
	 * @param (input_number) 入力した数字
	 * @detail 指定した盤上に置けるかどうか判定する
	 */
	bool PutSearch(__int8 input_font, __int8 input_number);

	/**
	 * @brief  配置番号判定関数
	 * @detail 盤上に置く場所があるかどうか
	 */
	bool SearchNumber();

	/**
	 * @brief  盤上配列駒配置関数
	 * @param (piece_) 駒の座標
	 * @param (object_) 駒の種類
	 * @detail 指定した盤上配列に駒を配置する
	 */
	void SetPiecePos(Vec2 piece_, __int8 object_);

	void DrawResult();

private:
	/* 盤上構造体 */
	struct BordInfo
	{
		__int8 m_put_number;  //!置ける盤上番号
		__int8 m_put_object;  //!置いているObjectの種類

	}m_bord_info[3][3];

	bool m_win;
	bool m_lose;
	bool m_draw;

};

#endif
