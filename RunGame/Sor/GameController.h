#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "Object/Player.h"
#include "Object/Map.h"
#include "Definition.h"

class GameController
{
public:
	GameController() {}
	~GameController() {}


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
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void ObjectUpdate();

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	bool Judgment();

	/**
	 * @brief 解放処理関数
	 */
	void Delete();

	//!各オブジェクトのアドレスのGetter
	Map* GetMapPoint() { return m_map; }
	Player* GetPlayerPoint() { return m_player; }


private:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,       //!初期化
		STEP_UPDATE,  //!先手の番
	}m_step;

	Player* m_player;  //!プレイヤー
	Map* m_map;        //!マップ
};


#endif