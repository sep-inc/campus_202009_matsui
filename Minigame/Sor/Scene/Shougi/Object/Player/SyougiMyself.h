#ifndef SYOUGI_MYSELF_H_
#define SYOUGI_MYSELF_H_
#include "../../../../Utility/Vec2.h"
#include "../../../../Definition.h"
#include "../SyougiPiece.h"
#include "../SyougiCursor.h"
#include "../SyougiBoard.h"
#include "SyougiPlayer.h"

class SyougiMyself :public SyougiPlayer
{
public:
	SyougiMyself(SYOUGI_PLAYER_TYPE player_, SyougiBoard* board_, SyougiCursor* cursor_);
	~SyougiMyself() {}

	/**
　   * @brief  初期化関数(繰り返し)
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	virtual void Reset()override;

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void Update(SyougiPiece* piece_[])override;

	/**
   　* @brief  入力関数
　   * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
   　*/
	bool MoveSourceSelect();

	/**
　   * @brief  入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元と移動先を入力する
　   */
	bool NextMoveSelect(SyougiPiece* piece_[]);

	/**
	 * @brief  移動駒表示関数
	 * @param (piece_type_) 駒の種類
	 * @detail 現在動かそうとしている駒の表示
	 */
	void NowMovePiece(PIECE_TYPE piece_type_);
private:
	enum STEP
	{
		SelectSorce_Step,
		SelectNext_Step,
		Move_Step
	}m_step;

	bool re_sorce_input;


};
#endif