#ifndef SCENE_CONTROLLER_H_
#define SCENE_CONTROLLER_H_
#include "GameControllerBase.h"
/**
*@clss   シーン管理クラス
*@brief  各シーンを管理する
*/

class SceneController
{
public:
	SceneController() {}
	~SceneController() {}

	/**
	 * @brief  インスタンス化関数
	 */
	static SceneController* Instance();

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void Update();

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

	/**
	 * @brief 解放処理関数
	 */
	void Delete();

	/**
	 * @brief  各ゲーム管理クラスアドレス配列
	 * @detail 配列に指定したゲームを入れるとそのゲームの管理クラスのnewが返ってくる
	 */
	static GameControllerBase* (*s_controller_array[static_cast<int>(GAME_TYPE::Game_Num)])();

private:
	static SceneController* p_instance; //!インスタンス

	GameControllerBase* m_gamecontroller;  //!各ゲームの管理クラス格納用

	GAME_TYPE m_game_type;   //!ゲームの種類

	GAME_TYPE m_select_game;  //!選択ゲーム保存用
};

#endif