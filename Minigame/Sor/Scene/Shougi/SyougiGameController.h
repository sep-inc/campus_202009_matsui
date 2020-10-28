#ifndef SYOUGI_GAMECONTROLLER_H_
#define SYOUGI_GAMECONTROLLER_H_
#include "Object/Player/SyougiPlayer.h"
#include "Object/SyougiBoard.h"
#include "Object/SyougiPiece.h"
#include "Object/SyougiCursor.h"
#include "../../Utility/Vec2.h"
#include "../GameControllerBase.h"


class SyougiGameController :public GameControllerBase
{
public:
	SyougiGameController();
	~SyougiGameController() {}

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
	virtual bool GameEnd()override;

	/**
	 * @brief 解放処理関数
	 */
	virtual void Delete()override;

	/**
	 * @brief 　オブジェクトポインタ関数
	 * @detail　オブジェクトのアドレスを返す
	 */
	SyougiBoard* GetBoradPoint() { return m_board; }
	SyougiCursor* GetCursorPoint() { return m_cursor; }

public:
	//!ステップの種類
	enum PLAYER_TURN
	{
		FIRST_TURN,  //!先手の番
		SECOND_TURN  //!後手の番
	}m_turn;

	void SetNextTurn(PLAYER_TURN turn_);

private:
	SyougiPlayer* m_player[SYOUGI_PLAYER_NUM];  //!プレイヤー
	SyougiBoard* m_board;                  //!盤
	SyougiPiece* m_piece[PIECE_NUM];     //!各駒
	SyougiCursor* m_cursor;              //!カーソル

};


#endif