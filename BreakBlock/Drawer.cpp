#include "Drawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 描画用配列初期化 */
void Drawer::Init()
{

	memset(&m_blank_map, OBJECTKIND::BLANK, sizeof(m_blank_map));  //クリア用配列初期

	/* 壁(フレーム)の配置 */
	for (int x = START_UNIT; x < NUM_UNIT_X; x++)
	{
		m_map[START_UNIT][x].m_kind =  OBJECTKIND::WALL ;    //上辺
		m_map[NUM_UNIT_Y - 1][x].m_kind = OBJECTKIND::WALL;  //下辺
	}

	for (int y = START_UNIT; y < NUM_UNIT_Y; y++)
	{	
		m_map[y][START_UNIT].m_kind =  OBJECTKIND::WALL;     //左辺
		m_map[y][NUM_UNIT_X - 1].m_kind = OBJECTKIND::WALL;  //右辺
	}

	memcpy(&m_blank_map, &m_map, sizeof(m_map)); //クリア用配列に壁(不変なObject)をコピー
}

/* 描画 */
void Drawer::Draw()
{

	for (int y = START_UNIT; y < NUM_UNIT_Y; y++)
	{
		for (int x = START_UNIT; x < NUM_UNIT_X; x++)
		{
			if (m_map[y][x].m_kind == OBJECTKIND::WALL)
			{
				printf("□");          //1=外枠
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BLOCK)
			{
				printf("■");          //1=外枠
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BAR)
			{
				printf("■");          //1=外枠
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BALL)
			{
				printf("●");          //1=外枠
			}
			else
			{
				printf("　");          //空白
			}
		}
		printf("\n");
	}
}


/* 描画用配列クリア */
void Drawer::BufferClear()
{
	memcpy(&m_map, &m_blank_map, sizeof(m_blank_map));
}


/* World配列を描画座標に変換(各Objectで行う )*/
void Drawer::SetUpBuffer(Vec2 pos_, OBJECTKIND kind_, int width_)
{
	int x = (pos_.X + UNIT_X) / UNIT_X;
	int y = (pos_.Y + UNIT_Y) / UNIT_Y;

	int num_x = width_ / UNIT_X;

	/* 描画に必要な数分回す */
	for (int x2 = START_UNIT; x2 < num_x; x2++)
	{
		m_map[y][x + x2].m_kind = kind_;
	}
	
}

