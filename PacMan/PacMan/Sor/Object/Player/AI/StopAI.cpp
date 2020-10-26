#include "StopAI.h"

//!初期化関数
void StopAI::Reset()
{
	m_direction = Vec(0, 0); //!方向ベクトル
}

//!移動方向選択関数
Vec StopAI::SelectDirection(Vec pos_)
{
	return m_direction;
}
