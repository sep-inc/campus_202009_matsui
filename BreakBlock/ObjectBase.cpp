#include "ObjectBase.h"


/* メンバ変数の初期化 */
void ObjectBase::Init(Vec2 pos_, float speed_, bool eneable_)
{
	m_pos = pos_;
	m_speed = speed_;
	m_eneable = eneable_;
}
