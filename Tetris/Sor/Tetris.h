#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "Definition.h"
#include "Object/Stage.h"
#include "Object/Block/BlockController.h"
#include "Player/PlayerBase.h"

/**
*@clss   ゲームクラス
*@brief  各オブジェクトの処理を管理する
*/

class Tetris
{
public:
	Tetris();
	~Tetris();

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void Update();

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void ObjectUpdate();

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	void SetUpDrawBuffer(GAME_TYPE type_);

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	void GameResult();

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	bool GameEnd();

	/**
	 * @brief 解放処理関数
	 */
	void Delete();

private:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,    //!初期化
		STEP_START,   //!初期化
		STEP_UPDATE,  //!更新
		STEP_RESULT,  //!結果
	}m_step;

	Tetris_Stage* m_stage;             //!ステージ
	Tetris_BlockController* m_block;   //!ブロック
	Tetris_Player_Base* m_player;
};

#endif