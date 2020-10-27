#ifndef PACMAN_GAMECONTROLLER_H_
#define PACMAN_GAMECONTROLLER_H_
#include "../../../Definition.h"
#include "Object/PacManStage.h"
#include "Object/PacManItem.h"
#include "Object/Player/PacManPlayer.h"
#include "../GameControllerBase.h"
/**
*@clss   ゲーム管理クラス
*@brief  各オブジェクトの処理を管理する
*/

class PacManGameController :public GameControllerBase
{
public:
	PacManGameController();
	~PacManGameController();

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	virtual void Init()override;

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void ObjectUpdate()override;

	virtual void DrawRule()override;

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	virtual void SetUpDrawBuffer()override;

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	virtual void GameResult()override;

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	virtual bool GameEnd()override;

	/**
	 * @brief 解放処理関数
	 */
	virtual void Delete()override;

private:
	////!ステップの種類
	//enum STEP
	//{
	//	STEP_INIT,    //!初期化
	//	STEP_START,   //!初期化
	//	STEP_UPDATE,  //!更新
	//	STEP_RESULT,  //!結果
	//}m_step;

	PacManStage* m_stage;
	PacManPlayer* m_player;
	PacManPlayer* m_enemy[ENEMY_NUM];
	PacManItem* m_item;

};

#endif