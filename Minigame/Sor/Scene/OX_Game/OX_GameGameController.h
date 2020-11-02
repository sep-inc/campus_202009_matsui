#ifndef OX_GAME_GAMECONTROLLER_H_
#define OX_GAME_GAMECONTROLLER_H_
#include "../../Utility/Vec2.h"
#include "../GameControllerBase.h"
#include "Object/OX_GameBoard.h"
#include "Object/OX_GamePlayer.h"
#include "Object/OX_GameEnemy.h"

class OX_GameGameController :public GameControllerBase
{
public:
	OX_GameGameController();
	virtual ~OX_GameGameController();

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
	 * @brief  シーン切り替え判定関数
	 * @detail ESCキーを押された時の処理を行う
	 */
	virtual void ChangeState()override;

	/**
     * @brief  インスタンス返還関数
     * @detail 管理クラスのポインタ配列に返す
     */
	static GameControllerBase* InstanceOX_Game();
private:
	enum TURN
	{
		TURN_PLAYER,  //!プレイヤーのターン
		TURN_ENEMY	  //!敵のターン
	}m_turn;

	OX_GameBoard* m_board;
	OX_GamePlayer* m_player;
	OX_GameEnemy* m_enemy;
};


#endif