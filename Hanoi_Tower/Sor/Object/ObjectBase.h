#ifndef OBJECTBASE_H_
#define OBJECTBASE_H_
#include "../Vec.h"
#include "../World.h"

class ObjectBase
{
public:
	ObjectBase() {}
	~ObjectBase() {}

	virtual void Init(Vec pos_, __int8 width, __int8 height);  //‰Šú‰»
	
protected:
	Vec m_pos;          //‰Šú‰»
	__int8 m_width;		//‰¡•
	__int8 m_height;	//c•

};

#endif 