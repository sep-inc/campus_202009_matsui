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
	virtual void Reset() {}

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
	virtual bool ResultStep() = 0;
};

#endif