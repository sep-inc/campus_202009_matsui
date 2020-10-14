#ifndef MAP_H_
#define MAP_H_
#include "../Utility/Vec.h"
#include "../Definition.h"

#define ROAD_MAX 300     //!駒の動ける最大範囲範囲

#define LAND_TIME_MAX 5  //!生成間隔の最大
#define LAND_TIME_MIN 1	 //!生成間隔の最大

#define LAND_WALL_HEIGHT_MAX 4 //!壁の高さの最大値

#define IMMUTABLE_FLOOR_MAX 5  //!平地の高さ

class Player;  //!前方宣言

class Map
{
public:
	Map();
	~Map() {}

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
   　* @brief  指定箇所検索関数
	 * @detail 指定されたX座標の一番上にある床の高さを返す
   　*/
	Vec GroundPos(Vec pos_);

	/**
	 * @brief  描画情報代入関数
	 * @detail マップ情報を描画配列に代入
	 */
	void SetUpBuffer();

	/**
     * @brief  ゴールフラグGetter
     */
	bool GetGoal() { return m_goal; }

private:
	Player* m_player;  //!プレイヤーアドレス保存用

	//!マップ配列情報
	struct MapBufferInfo
	{
		char kind[4];
	};

	MapBufferInfo m_map_buffer[GAME_HEIGHT][GAME_WIDTH];  //!マップ配列

	//!マップ情報
	struct MapInfo
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