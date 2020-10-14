#include "Map.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <random>
#include "../Entity.h"
#include "Player.h"

//!コンストラクタ
Map::Map()
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
	memcpy(&m_map_buffer, &m_frame_buffer, sizeof(m_frame_buffer));

	//!クリア用配列に代入
	g_drawer.SetUpClearBuffer(m_frame_buffer, sizeof(m_frame_buffer));

}

//!初期化関数
void Map::Init()
{
	m_player = g_game_controller.GetPlayerPoint();  //!プレイヤーのアドレスを代入
	m_map_info.m_create_timer = 0;                  //!生成時間測定用変数
	m_map_info.m_rand_time = rand() % LAND_TIME_MAX + LAND_TIME_MIN;        //!生成間隔変数(1～4フレームの間隔)

	m_goal = false; //!ゴールフラグ
}

//!更新関数
void Map::Update()
{
	//!プレイヤーが移動したら
	if (m_player->GetPlayerInfo().m_move == true)
	{
		CreateMap();  //!マップ生成関数

		MoveLoad();	  //!道更新関数

		MoveCount();  //!進行距離カウント関数
	}
}

//!マップ生成関数
void Map::CreateMap()
{
	//!プレイヤーがゴール手前に来ていない場合
	if (m_map_info.m_road_counter <= ROAD_MAX - GAME_WIDTH - m_player->GetPlayerInfo().m_pos.x)
	{
		//!前のフレームで生成した地形をリセット
		for (int y = 0; y <= IMMUTABLE_FLOOR_MAX; y++)
		{
			strcpy_s(m_map_buffer[y][11].kind, FONT_BYTE_, "　");
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
				strcpy_s(m_map_buffer[y][11].kind, FONT_BYTE_, "■");
			}

			//!高さが0の場合穴を作る
			if (m_map_info.m_wall_height == 0)
			{
				for (int y = 0; y <= IMMUTABLE_FLOOR_MAX; y++)
				{
					strcpy_s(m_map_buffer[y][11].kind, FONT_BYTE_, "　");
				}
			}
		}
		//!生成時間を測定中は穴も壁も作らない
		else
		{
			strcpy_s(m_map_buffer[IMMUTABLE_FLOOR_MAX][11].kind, FONT_BYTE_, "■");
		}
	}
	//!プレイヤーがゴールに近づいたら
	else
	{
		//!ゴールから先は消す
		for (int y = 3; y < GAME_HEIGHT; y++)
		{
			strcpy_s(m_map_buffer[y][11].kind, FONT_BYTE_, "　");
		}
	}
	
}
//!道更新関数
void Map::MoveLoad()
{
	//!プレイヤーが生きている間(死んだ場合は止める)
	if (m_player->GetPlayerInfo().m_deth == false)
	{
		//!道を1マスずらす
		for (int y = 0; y < GAME_HEIGHT; y++)
		{
			for (int x = 0; x < GAME_WIDTH - 1; x++)
			{
				m_map_buffer[y][x] = m_map_buffer[y][x + 1];
			}
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
		printf("ゴール！       \n");
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
	printf("結果%dマス進んだ\n", m_map_info.m_road_counter);
}

//!指定箇所検索関数
Vec Map::GroundPos(Vec pos_)
{
	//!指定されたX座標の一番上にある床の座標を返す
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		if (strcmp(m_map_buffer[y][pos_.x].kind,"■") == 0)
		{
			return Vec(pos_.x, y);
		}
	}

	return pos_;
}

//!描画情報代入関数
void Map::SetUpBuffer()
{
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH - 1; j++)
		{
			g_drawer.SetUpBuffer(Vec(j, i), m_map_buffer[i][j].kind);
		}
	}
	
}
