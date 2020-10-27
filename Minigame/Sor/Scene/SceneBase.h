#ifndef SCENE_BASE_H_
#define SCENE_BASE_H_
#include "../Definition.h"
#include "../Utility/Vec2.h"

/**
*@clss   シーン基底クラス
*/

class SceneBase
{
public:
	SceneBase() {}
	~SceneBase() {}

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	virtual void Reset() = 0;

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	virtual void Update();

	/**
	 * @brief  各ゲーム管理処理関数
	 * @detail 各ゲーム管理クラスの更新処理を行う
	 */
	virtual void GameControllerUpdate() = 0;

	/**
	 * @brief  描画情報送信関数関数
	 * @detail 各ゲーム(または選択シーン)の描画情報を描画クラスに送る
	 */
	virtual void SetUpDrawBuffer()= 0;

	/**
	 * @brief  シーン切り替え判定関数
	 * @detail 各シーンで切り替え判定処理を行う
	 */
	virtual void ChangeState() {}

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲーム(またはプロジェクト)を終了する
	 */
	virtual bool GameEnd() { return false; }

	/**
     * @brief  選択ゲームGetter関数
     * @detail 選択されたゲームの種類を返す(選択シーンで使う)
     */
	GAME_TYPE GetSelectGame() { return m_game_type; }

	/**
	 * @brief  シーン切り替えフラグGetteer関数
	 * @detail シーンが切り替えられたかどうかを返す
	 */
	bool GetNextScene() { return m_next_scene; }


protected:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,    //!初期化
		STEP_UPDATE,  //!更新
	}m_step;

	GAME_TYPE m_game_type;   //!ゲームの種類

	bool m_next_scene;       //!シーン切り替えフラグ
};

#endif