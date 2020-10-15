#include "Map.h"
#include "../Entity.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <random>

//!初期化関数
void Map::Init()
{
	//!初期状態のマップ
	char m_frame_buffer[GAME_HEIGHT][GAME_WIDTH][FONT_BYTE_] =
	{
	   "　","　","　","　","　","　","　","　","　","　","　","　",
	   "　","　","　","　","　","　","　","　","　","　","　","　",
	   "　","　","　","　","　","　","　","　","　","　","　","　",
	   "　","　","　","　","　","　","　","　","　","　","　","　",
	   "　","　","　","　","　","　","　","　","　","　","　","　",
	   "■","■","■","■","■","■","■","■","■","■","■","■",
	   "■","■","■","■","■","■","■","■","■","■","■","■",
	   "■","■","■","■","■","■","■","■","■","■","■","■",
	   "■","■","■","■","■","■","■","■","■","■","■","■"
	};

	//!マップ配列に初期状態のマップ代入
	MapData::Instance()->SetCopyMapBuffer(m_frame_buffer, sizeof(m_frame_buffer));

	//!クリア用配列に代入
	g_drawer.SetUpClearBuffer(m_frame_buffer, sizeof(m_frame_buffer));

	m_map_info.m_create_timer = 0;                  //!生成時間測定用変数
	m_map_info.m_rand_time = rand() % LAND_TIME_MAX + LAND_TIME_MIN;        //!生成間隔変数(1～4フレームの間隔)
	m_map_info.m_road_counter = 0;


	m_goal = false; //!ゴールフラグ
}

//!更新関数
void Map::Update()
{
	CreateMap();  //!マップ生成関数

	MoveLoad();	  //!道更新関数

	MoveCount();  //!進行距離カウント関数
}

//!マップ生成関数
void Map::CreateMap()
{
	//!プレイヤーがゴール手前に来ていない場合
	if (m_map_info.m_road_counter <= ROAD_MAX - DRAW_RANGE + PLAYER_POS_X)
	{
		//!前のフレームで生成した地形をリセット
		for (int y = 0; y <= IMMUTABLE_FLOOR_MAX; y++)
		{
			MapData::Instance()->SetMapBuffer(11, y, "　");
		}


		m_map_info.m_create_timer++;  //!生成時間測定

		//!生成時間が生成間隔をあけたら
		if (m_map_info.m_create_timer == m_map_info.m_rand_time)
		{
			m_map_info.m_create_timer = 0;  //!測定時間を0に

			m_map_info.m_rand_time = rand() % LAND_TIME_MAX + LAND_TIME_MIN;  //!次のフレームの生成間隔を設定

			m_map_info.m_wall_height = rand() % LAND_WALL_HEIGHT_MAX;    //!生成する床の高さ設定

			//!不変的な床から床の高さ分生成する
			for (int y = IMMUTABLE_FLOOR_MAX; y > IMMUTABLE_FLOOR_MAX - m_map_info.m_wall_height; y--)
			{
				MapData::Instance()->SetMapBuffer(11, y, "■");
			}

			//!高さが0の場合穴を作る
			if (m_map_info.m_wall_height == 0)
			{
				for (int y = 0; y <= IMMUTABLE_FLOOR_MAX; y++)
				{
					MapData::Instance()->SetMapBuffer(11, y, "　");
				}
			}
		}
		//!生成時間を測定中は穴も壁も作らない
		else
		{
			MapData::Instance()->SetMapBuffer(11, IMMUTABLE_FLOOR_MAX, "■");
		}
	}
	//!プレイヤーがゴールに近づいたら
	else
	{
		//!ゴールから先は消す
		for (int y = 3; y < GAME_HEIGHT; y++)
		{
			MapData::Instance()->SetMapBuffer(11, y, "　");
		}
	}
	
}
//!道更新関数
void Map::MoveLoad()
{
	//!道を1マスずらす
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH - 1; x++)
		{
			MapData::Instance()->SetMapPosBuffer(x, y, MapData::Instance()->GetMapBuffer(x + 1, y));
		}
	}
}

//!進行距離カウント関数
void Map::MoveCount()
{
	m_map_info.m_road_counter++;  //!歩数をカウント

	//!ゴールまで走り切ったら
	if (m_map_info.m_road_counter >= ROAD_MAX)
	{
		m_goal = true;
	}
	//!走っている途中
	else
	{
		printf("現在%dマス経過\n", m_map_info.m_road_counter); //!現在の進んだ距離を表示
	}
}

//!結果表示関数
void Map::ResultDraw()
{
	if (m_goal == true)
	{
		printf("ゴール！       \n");
	}
	printf("結果%dマス進んだ\n", m_map_info.m_road_counter);
}

//!描画情報代入関数
void Map::SetUpBuffer()
{
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH - 1; x++)
		{
			g_drawer.SetUpBuffer(Vec(x, y), MapData::Instance()->GetMapBuffer(x, y).kind);
		}
	}
	
}
