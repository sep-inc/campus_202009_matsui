#ifndef GAMECONTROLLER_BASE_H_
#define GAMECONTROLLER_BASE_H_
/**
*@clss   ゲーム管理クラス
*@brief  各オブジェクトの処理を管理する
*/

class GameControllerBase
{
public:
	GameControllerBase() {}
	~GameControllerBase() {}

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	virtual void Init() {}

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	virtual void Update();

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

	virtual void DrawRule() {}

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	virtual void GameResult() {}

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	virtual bool GameEnd() { return false; }

	/**
	 * @brief 解放処理関数
	 */
	virtual void Delete() {}

protected:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,    //!初期化
		STEP_START,   //!初期化
		STEP_UPDATE,  //!更新
		STEP_RESULT,  //!結果
	}m_step;

};

#endif