#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"

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
	void Init();          
	
	/**
	 * @brief  描画座標代入関数
	 * @detail 駒座標を描画座標に代入
	 */
	void SetUpDrawBuffer();
	
	/**
	 * @brief  移動関数まとめ
	 * @detail 駒の移動処理まとめ
	 */
	void Put();         
	
	/**
	 * @brief  プレイヤー移動関数
	 * @detail プレイヤーの移動処理
	 */
	void PlayerPut();         
	
	/**
	 * @brief  敵移動関数
	 * @detail 敵の移動処理
	 */
	void EnemyPut();        


private:
	enum Step
	{
		STEP_INIT,
		STEP_PUT,
		STEP_SET
	}m_step;

	Vec m_player_pos;     //!プレイヤー駒座標
	Vec m_enemy_pos;      //!敵駒座標

	Vec m_randm_number;   //!敵の配置座標
};


#endif