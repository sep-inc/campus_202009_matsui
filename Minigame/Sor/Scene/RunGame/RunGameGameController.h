#ifndef RUNGAME_GAMECONTROLLER_H_
#define RUNGAME_GAMECONTROLLER_H_
#include "Object/RunGamePlayer.h"
#include "Object/RunGameMapManager.h"
#include "../GameControllerBase.h"
#include "../../Definition.h"


class RunGameGameController :public GameControllerBase
{
public:
	RunGameGameController();
	virtual ~RunGameGameController();


	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Reset()override;

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	virtual void Update()override;

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	virtual void ObjectUpdate()override;

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	virtual void SetUpDrawBuffer()override;

	/**
	 * @brief  ルール関数
	 * @detail ゲームのルールを表示する
	 */
	virtual void DrawRule()override;

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	virtual void GameResult()override;

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	//virtual bool GameEnd()override;

	/**
	 * @brief  シーン切り替え判定関数
	 * @detail ESCキーを押された時の処理を行う
	 */
	virtual void ChangeState()override;

	/**
	 * @brief 解放処理関数
	 */
	virtual void Delete()override;

	/**
     * @brief  インスタンス返還関数
     * @detail 管理クラスのポインタ配列に返す
     */
	static GameControllerBase* InstanceRunGame();
private:
	RunGamePlayer* m_player;  //!プレイヤー
	RunGameMapManager* m_map;        //!マップ
};


#endif