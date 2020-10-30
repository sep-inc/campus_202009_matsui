#ifndef HANOITOWER_GAMECONTROLLER_H_
#define HANOITOWER_GAMECONTROLLER_H_
#include "../../Definition.h"
#include "../GameControllerBase.h"
#include "Object/HanoiTowerBoxArray.h"
#include "Object/HanoiTowerDiskArray.h"

/**
*@clss   ゲーム管理クラス
*@brief  各オブジェクトの処理を管理する
*/

class HanoiTowerGameController :public GameControllerBase
{
public:
	HanoiTowerGameController();
	virtual ~HanoiTowerGameController();

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
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
	 * @brief  ルール関数
	 * @detail ゲームのルールを表示する
	 */
	virtual void DrawRule()override;

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	virtual void SetUpDrawBuffer()override;

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
     * @brief  インスタンス返還関数
     * @detail 管理クラスのポインタ配列に返す
     */
	static GameControllerBase* InstanceHanoiTower();

private:
	HanoiTowerBoxArray* m_box_array;
	HanoiTowerDiskArray* m_disk_array;

};

#endif