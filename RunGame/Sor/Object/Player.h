#ifndef PLAYER_H_
#define PLAYER_H_
#include "../Utility/Vec.h"
#include "Map.h"
#include "MapData.h"
/**
*@clss   プレイヤークラス
*/

class Player
{
public:
	Player() {}
	~Player() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void Update();

	/**
   　* @brief  移動関数
	 * @detail 移動までに掛かる時間を計算
   　*/
	void Run();

	/**
   　* @brief  ジャンプ関数
	 * @detail 入力クラスにキーが押されたか問い、押されていたらジャンプする
   　*/
	void Jump();

	/**
   　* @brief  当たり判定関数
	 * @detail 床、もしくは壁に当たっているかを調べる
   　*/
	void Collision();

	/**
　   * @brief  死亡判定関数
     * @detail 壁に当たって至るかどうか調べる
　   */
	void DethJudgment();

	/**
	 * @brief  描画情報代入関数
	 * @detail プレイヤー情報を描画配列に代入
	 */
	void SetUpBuffer();

private:
	//!プレイヤー情報構造体
	struct PlayerInfo
	{
		Vec m_pos;       //!現在座標
		Vec m_body_pos;  //!体座標(表示時に1マス位置が違うため)

		Vec m_next_pos;  //!次の座標

		unsigned __int8 m_speed_counter;           //!移動するまでの時間カウント用
		static const unsigned __int8 m_speed_max;  //!移動までにかかるフレーム数


		static const __int8 m_width;   //!横幅
		static const __int8 m_height;  //!縦幅

		static const __int8 m_jump_power; //!ジャンプ力

		static const __int8 m_gravity;    //!重力

		bool m_move;  //!移動フラグ
		bool m_deth;  //!死亡フラグ
	};
	
	 PlayerInfo m_player_info;

public:
	/**
	 * @brief  プレイヤー情報Getter
	 * @detail プレイヤー情報返す
	 */
	PlayerInfo GetPlayerInfo() { return m_player_info; }

};


#endif