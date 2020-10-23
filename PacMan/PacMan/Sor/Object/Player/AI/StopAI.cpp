#include "StopAI.h"

//!コンストラクタ
StopAI::StopAI() :
	m_direction(Vec(0, 0)) //!方向ベクトル
{}

//!移動方向選択関数
Vec StopAI::SelectDirection()
{
	return m_direction;
}
