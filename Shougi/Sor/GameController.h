#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "Vec.h"
#include "Player.h"
class GameController
{
public:
	GameController() :m_step(STEP_INIT) {}
	~GameController() {}

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void StepChange();

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init();

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void Update(PLAYER_TYPE player_type_);

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	virtual void SetUpDrawBuffer();

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	bool Judgment();

	/**
	 * @brief  解放関数
	 */
	void Delete();

protected:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,       //!初期化
		STEP_FIRST_PUT,  //!先手の番
		STEP_SECOND_PUT  //!後手の番
	}m_step;

	Player* m_player;  //!プレイヤー
};


#endif