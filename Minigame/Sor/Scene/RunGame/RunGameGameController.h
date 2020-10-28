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
	~RunGameGameController();


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
	virtual bool GameEnd()override;

	/**
	 * @brief 解放処理関数
	 */
	virtual void Delete()override;

	//!各オブジェクトのアドレスのGetter
	RunGameMapManager* GetMapPoint() { return m_map; }
	Player* GetPlayerPoint() { return m_player; }



private:
	Player* m_player;  //!プレイヤー
	RunGameMapManager* m_map;        //!マップ
};


#endif