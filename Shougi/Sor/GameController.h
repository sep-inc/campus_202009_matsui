#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "Vec.h"
#include "Player/Player.h"
#include "Object/Board.h"
#include "Object/Piece.h"
#include "Object/Cursor.h"

class GameController
{
public:
	GameController() :m_step(STEP_INIT), m_turn(FIRST_TURN){}
	~GameController() {}

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void Update();

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init();

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void ObjectUpdate();

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	virtual void SetUpDrawBuffer();

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	bool Judgment();

	/**
	 * @brief  解放関数
	 */
	void Delete();

	/**
     * @brief 　オブジェクトポインタ関数
	 * @detail　オブジェクトのアドレスを返す
     */
	Board* GetBoradPoint() { return m_board; }
	Cursor* GetCursorPoint() { return m_cursor; }

public:
	//!ステップの種類
	enum PLAYER_TURN
	{
		FIRST_TURN,  //!先手の番
		SECOND_TURN  //!後手の番
	}m_turn;

	void SetNextTurn(PLAYER_TURN turn_);

private:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,       //!初期化
		STEP_UPDATE,  //!先手の番
	}m_step;

	

	Player* m_player[PLAYER_NUM];  //!プレイヤー
	Board* m_board;                  //!盤
	Piece* m_piece[PIECE_NUM];     //!各駒
	Cursor* m_cursor;              //!カーソル



};


#endif