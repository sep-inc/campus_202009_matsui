#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_
#include "../SceneBase.h"
#include "GameControllerBase.h"
/**
*@clss   ゲームシーンクラス
*@brief  ゲームシーンでの処理を行う
*/

class GameScene :public SceneBase
{
public:
	GameScene();
	~GameScene() {}

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	virtual void Reset()override;

	/**
	 * @brief  各ゲーム管理処理関数
	 * @detail 各ゲーム管理クラスの更新処理を行う
	 */
	virtual void GameControllerUpdate()override;
	/**
	 * @brief  描画情報送信関数関数
	 * @detail 各ゲーム(または選択シーン)の描画情報を描画クラスに送る
	 */
	virtual void SetUpDrawBuffer()override;

	/**
     * @brief  シーン切り替え判定関数
     * @detail 各シーンで切り替え判定処理を行う
     */
	virtual void ChangeState()override;

private:
	GameControllerBase* m_gamecontroller[Game_Num];  //!各ゲームの管理クラス格納用

};

#endif