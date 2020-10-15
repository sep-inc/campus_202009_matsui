#include "Collision.h"

EdgeInfo Collision::m_edge_info[2];

//!辺と辺の当たり判定
bool Collision::EdgeCollision(Vec player_pos_, Vec rect_pos_, __int8 player_height_, __int8 player_width_, __int8 rect_height_, __int8 rect_width_, EdgeType type)
{
	//!選んだ辺の当たり判定を行う
	switch (type)
	{
	case TOP:   //!上辺
		m_edge_info[0].top = player_pos_.y;
		m_edge_info[1].bottom = rect_pos_.y + rect_height_;

		if (m_edge_info[0].top <= m_edge_info[1].bottom)
		{
			return true;
		}
		break;
	case BOTTOM: //!下辺
		m_edge_info[0].bottom = player_pos_.y + player_height_;
		m_edge_info[1].top = rect_pos_.y;

		if (m_edge_info[0].bottom >= m_edge_info[1].top)
		{
			return true;
		}

		break;
	case LEFT: //!左辺
		m_edge_info[0].left = player_pos_.x;
		m_edge_info[1].right = rect_pos_.x + rect_width_;

		if (m_edge_info[0].left <= m_edge_info[1].right)
		{
			return true;
		}

		break;
	case RIGHT: //!右辺
		m_edge_info[0].right = player_pos_.x + player_width_;
		m_edge_info[1].left = rect_pos_.x;

		if (m_edge_info[0].right >= m_edge_info[1].left)
		{
			return true;
		}

		break;
	default:
		break;
	}
	return false;
}
