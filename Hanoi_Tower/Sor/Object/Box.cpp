#include "Box.h"
#include "../Typedef.h"

/* ������ */
void Box::Init(Vec pos_, unsigned  __int8 width_, unsigned  __int8 height_)
{
	ObjectBase::Init(pos_, width_, height_);
}

/* �`����W���� */
void Box::SetUpBuffer()
{
	g_drawer.SetUpBuffer(m_pos, m_width, m_height, OBJECT_TYPE::BOX);
}
