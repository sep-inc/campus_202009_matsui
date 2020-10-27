#ifndef SCENE_CONTROLLER_H_
#define SCENE_CONTROLLER_H_
#include "SceneBase.h"
/**
*@clss   シーン管理クラス
*@brief  各シーンを管理する
*/

class SceneController
{
public:
	SceneController();
	~SceneController();

	/**
     * @brief  インスタンス化関数
     */
	static SceneController* Instance();

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	void Reset();

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void Update();

	/**
   　* @brief  シーン更新関数
	 * @detail 各シーン更新処理をまとめた関数
   　*/
	void SceneUpdate();

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  シーン切り替え判定関数
	 * @detail 各シーンで切り替え判定を行う
	 */
	void ChangeScene();

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	bool GameEnd();

	/**
	 * @brief  選択ゲームGetter関数
	 * @detail 選択したゲームの種類を返す
	 */
	GAME_TYPE GetSelectGame() { return m_select_game; }

private:
	static SceneController* p_instance; //!インスタンス

	//!ステップの種類
	enum STEP
	{
		STEP_INIT,    //!初期化
		STEP_UPDATE,  //!更新
	};

	STEP m_step;

	//!シーンの種類
	enum SCENE_STEP
	{
		Select,     //!選択シーン
		Game,		//!ゲームシーン
	}m_scene_step;

	SceneBase* m_scene;  //!各シーン格納用

	bool m_next_scene;   //!シーン切り替えフラグ

	GAME_TYPE m_select_game;  //!選択ゲーム保存用
};

#endif