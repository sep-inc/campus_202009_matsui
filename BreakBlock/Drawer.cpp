#include "Drawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* `ζpzρϊ» */
void Drawer::Init()
{

	memset(&m_blank_map, OBJECTKIND::BLANK, sizeof(m_blank_map));  //NApzρϊ

	/* Η(t[)Μzu */
	for (int x = START_UNIT; x < NUM_UNIT_X; x++)
	{
		m_map[START_UNIT][x].m_kind =  OBJECTKIND::WALL ;    //γΣ
		m_map[NUM_UNIT_Y - 1][x].m_kind = OBJECTKIND::WALL;  //ΊΣ
	}

	for (int y = START_UNIT; y < NUM_UNIT_Y; y++)
	{	
		m_map[y][START_UNIT].m_kind =  OBJECTKIND::WALL;     //ΆΣ
		m_map[y][NUM_UNIT_X - 1].m_kind = OBJECTKIND::WALL;  //EΣ
	}

	memcpy(&m_blank_map, &m_map, sizeof(m_map)); //NApzρΙΗ(sΟΘObject)πRs[
}

/* `ζ */
void Drawer::Draw()
{

	for (int y = START_UNIT; y < NUM_UNIT_Y; y++)
	{
		for (int x = START_UNIT; x < NUM_UNIT_X; x++)
		{
			if (m_map[y][x].m_kind == OBJECTKIND::WALL)
			{
				printf(" ");          //1=Og
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BLOCK)
			{
				printf("‘");          //1=Og
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BAR)
			{
				printf("‘");          //1=Og
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BALL)
			{
				printf("");          //1=Og
			}
			else
			{
				printf("@");          //σ
			}
		}
		printf("\n");
	}
}


/* `ζpzρNA */
void Drawer::BufferClear()
{
	memcpy(&m_map, &m_blank_map, sizeof(m_blank_map));
}


/* Worldzρπ`ζΐWΙΟ·(eObjectΕs€ )*/
void Drawer::SetUpBuffer(Vec2 pos_, OBJECTKIND kind_, int width_)
{
	int x = (pos_.X + UNIT_X) / UNIT_X;
	int y = (pos_.Y + UNIT_Y) / UNIT_Y;

	int num_x = width_ / UNIT_X;

	/* `ζΙKvΘͺρ· */
	for (int x2 = START_UNIT; x2 < num_x; x2++)
	{
		m_map[y][x + x2].m_kind = kind_;
	}

	m_map[0][0].m_kind = WALL;
}

