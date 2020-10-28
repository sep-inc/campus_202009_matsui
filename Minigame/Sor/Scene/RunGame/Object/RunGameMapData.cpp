#include "RunGameMapData.h"
#include <string.h>
#include <stdlib.h>

RunGameMapData* RunGameMapData::p_instance = 0;

//!インスタンス化関数
RunGameMapData* RunGameMapData::Instance()
{
	if (p_instance == 0)
	{
		p_instance = new RunGameMapData; //!インスタンス化
	}

	return p_instance;
}

//!マップ配列Set関数(配列丸ごと)
void RunGameMapData::SetCopyMapBuffer(const void* buffer_, int size_)
{
	memcpy(m_map_buffer, buffer_, size_);
}

//!マップ配列Set関数(文字代入)
void RunGameMapData::SetMapBuffer(int x_, int y_, const char* font_)
{
	strcpy_s(m_map_buffer[y_][x_].kind, FONT_BYTE_, font_);
}

//!マップ配列Set関数(マップ更新用)
void RunGameMapData::SetMapPosBuffer(int x_, int y_, MapBufferInfo buffer_)
{
	m_map_buffer[y_][x_] = buffer_;
}

//!指定箇所検索関数
const Vec2 RunGameMapData::GroundPos(Vec2 pos_)
{
	//!指定されたX座標の一番上にある床の座標を返す
	for (int y = 0; y < RUNGAME_HEIGHT; y++)
	{
		if (strcmp(m_map_buffer[y][pos_.x].kind, "■") == 0)
		{
			return Vec2(pos_.x, y);
		}
	}

	return Vec2(pos_.x, RUNGAME_HEIGHT - 1);
}
