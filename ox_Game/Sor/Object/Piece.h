#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"

class Player;
class Enemy;

/**
 *@clss   駒クラス
 *@brief  プレイヤー、敵の駒情報を持つ
 */
class Piece
{
public:
	Piece() :m_step(STEP_INIT) {}
	~Piece() {}

	/**
     * @brief  ステップ処理関数
     * @detail ステップ変更処理
     */
	void StepChange();   
	
    /**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init();         
	
	/**
	 * @brief  描画座標代入関数
	 * @detail 駒座標を描画座標に代入
	 */
	virtual void SetUpDrawBuffer();
	
	/**
	 * @brief  移動関数まとめ
	 * @detail 駒の移動処理まとめ
	 */
	virtual void Put();
	
	/**
	 * @brief  解放関数
	 * @detail プレイヤーと敵の駒の解放
	 */
	void Delete();

	/**
	 * @brief  コンティニュー関数
	 * @detail ステップを初期化に戻す
	 */
	void Continue();


private:
	enum Step
	{
		STEP_INIT,    //!初期化
		STEP_PLAYER,  //!プレイヤーのターン
		STEP_ENEMY	  //!敵のターン
	}m_step;

	Piece* m_player;  //!プレイヤーの駒
	Piece* m_enemy;   //!敵の駒

protected:
	Vec m_pos;
};


#endif