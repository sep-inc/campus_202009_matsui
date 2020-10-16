#ifndef MAP_H_
#define MAP_H_
#include "../Utility/Vec.h"
/**
*@clss   マップクラス
*/

#define ROAD_MAX 300     //!駒の動ける最大範囲範囲

#define LAND_TIME_MAX 5  //!生成間隔の最大値
#define LAND_TIME_MIN 1	 //!生成間隔の最小値

#define LAND_WALL_HEIGHT_MAX 4 //!壁の高さの最大値

#define IMMUTABLE_FLOOR_MAX 5  //!平地の高さ

#define DRAW_RANGE (GAME_WIDTH - 1) //!描画時に見えるマップの範囲


class MapManager
{
public:
	MapManager() {}
	~MapManager() {}

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
   　* @brief  マップ生成関数
	 * @detail 次のフレームで出てくるマップの床や壁を生成
   　*/
	void CreateMap();

	/**
   　* @brief  道更新関数
	 * @detail 生成したマップから1マス左にずらす
   　*/
	void MoveLoad();

	/**
　   * @brief  進行距離カウント関数
	 * @detail 現在進んだ距離を数える
　   */
	void MoveCount();

	/**
　   * @brief  結果表示関数
　   */
	void ResultDraw();

	/**
	 * @brief  描画情報代入関数
	 * @detail マップ情報を描画配列に代入
	 */
	void SetUpBuffer();

	/**
     * @brief  ゴールフラグGetter
     */
	bool GetGoal() { return m_goal; }

	

protected:
	//!マップ更新時に必要な変数
	struct MapManagerInfo
	{
		__int8 m_wall_width;   //!壁(1マス)の横幅
		__int8 m_wall_height;  //!壁(1マス)の縦幅

		unsigned __int8 m_create_timer;  //!生成時間測定用変数
		unsigned __int8 m_rand_time;     //!生成間隔変数

		unsigned __int16 m_road_counter;  //!進んだ歩数

	}m_map_info;
	
	bool m_goal;  //!ゴールフラグ

};

#endif