﻿#ifndef RUNGAME_MAPDATA_H_
#define RUNGAME_MAPDATA_H_
#include "../../../Definition.h"
#include "../../../Utility/Vec2.h"
/**
*@clss   マップデータクラス
*@brief  マップのデータを管理している
*/

class RunGameMapData
{
public:
	RunGameMapData() {}
	~RunGameMapData() {}

private:
	//!マップ配列情報
	struct MapBufferInfo
	{
		char kind[4];
	};

	MapBufferInfo m_map_buffer[RUNGAME_HEIGHT][RUNGAME_WIDTH];  //!マップ配列

	//static RunGameMapData* p_instance; //!インスタンス

public:
	/**
	 * @brief  インスタンス化関数
	 * @detail メンバ変数の初期化
	 */
	static RunGameMapData* Instance();

	/**
	 * @brief  マップ配列Set関数(配列丸ごと)
	 * @detail 指定した配列をマップ配列にコピーする
	 */
	void SetCopyMapBuffer(const void* buffer_, int size_);

	/**
	 * @brief  マップ配列Set関数(文字代入)
	 * @detail マップ配列の指定要素に文字を代入する
	 */
	void SetMapBuffer(int x_, int y_, const char* font_);

	/**
	 * @brief  マップ配列Set関数(マップ更新用)
	 * @detail マップ配列を1つずらすときに使う
	 */
	void SetMapPosBuffer(int x_, int y_, MapBufferInfo buffer_);

	/**
   　* @brief  指定箇所検索関数
	 * @detail 指定されたX座標の一番上にある床の高さを返す
   　*/
	const Vec2 GroundPos(Vec2 pos_);


	/**
   　* @brief  マップデータGet関数
	 * @detail 指定座標のマップデータを返す
   　*/
	const MapBufferInfo GetMapBuffer(__int8 x_, __int8 y_) { return m_map_buffer[y_][x_]; }


};

#endif