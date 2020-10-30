#include "../Definition.h"
#ifndef GAMECONTROLLER_BASE_H_
#define GAMECONTROLLER_BASE_H_
/**
*@clss   ゲーム管理クラス
*@brief  各オブジェクトの処理を管理する
*/

///////////////////////////////////////////////////
//!基底クラスはまとめられるものはまとめて良いが、//
//上下関係(独立性)がちゃんとある場合に限る       //
///////////////////////////////////////////////////

class GameControllerBase
{
public:
	GameControllerBase() {}
	virtual ~GameControllerBase() {}

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	virtual void Reset() {}

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	virtual void Update() {}

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void ObjectUpdate() {}

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	virtual void SetUpDrawBuffer() {}

	/**
	 * @brief  ルール関数
	 * @detail 各ゲームのルールを表示する
	 */
	virtual void DrawRule() {}

	/**
　　 * @brief  結果表示関数
　　 * @detail 各ゲームの結果を表示する
　　 */
	virtual void GameResult() {}

	/**
	 * @brief  シーン切り替え判定関数
	 * @detail 決定キーを押された時の処理を行う
	 */
	virtual void ChangeState() {}

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	virtual bool GameEnd() { return false; }

	/**
	 * @brief 解放処理関数
	 */
	virtual void Delete() {}

	/**
	 * @brief  結果ステップ移行判定関数
	 * @detail 更新から結果へ行く条件が満たされておるか調べる
	 */
	virtual bool ResultStep() { return false; }

	/**
	 * @brief  シーン切り替えフラグGetteer関数
	 * @detail シーンが切り替えられたかどうかを返す
	 */
	bool GetNextScene() { return m_next_scene; }

	/**
	 * @brief  選択ゲームGetter関数
	 * @detail 選択されたゲームの種類を返す(選択シーンで使う)
	 */
	GAME_TYPE GetSelectGame() { return m_game_type; }

protected:
	//!ステップの種類
	enum CONTROLLER_STEP
	{
		STEP_INIT,    //!初期化
		STEP_START,   //!初期化
		STEP_UPDATE,  //!更新
		STEP_RESULT,  //!結果
	}m_step;



	GAME_TYPE m_game_type;   //!ゲームの種類

	bool m_next_scene;   //!シーン切り替えフラグ
};

#endif