#ifndef SYOUGI_ENEMY_H_
#define SYOUGI_ENEMY_H_
#include "../../../../Utility/Vec2.h"
#include "../../../../Definition.h"
#include "../SyougiPiece.h"
#include "../SyougiBoard.h"
#include "SyougiPlayer.h"

#define RESET_NUM 3  //!移動先を検索できる回数

class SyougiEnemy :public SyougiPlayer
{
public:
	SyougiEnemy(SYOUGI_PLAYER_TYPE player_, SyougiBoard* board_);
	~SyougiEnemy() {}

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
   　* @brief  移動元入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動元を入力する
   　*/
	void MoveSourceSelect();

	/**
　   * @brief  移動先入力関数
	 * @param (bord_) 盤クラス
	 * @detail 移動先を入力する
	 * @return 移動先が決まったかどうか
　   */
	bool NextMoveSelect(SyougiPiece* piece_[]);

	void NextPos();

private:
	Vec2 m_rand_pos;        //!移動先変数
};


#endif