#ifndef BLOCK_H_
#define BLOCK_H_
#include "ObjectBase.h"
#include "Collision.h"
#include "World.h"
#include "Drawer.h"

/* Block�� */
#define BLOCK_NUM_X (((GAME_WIDTH / UNIT_X)) / (BLOCK_WIDTH / UNIT_X))   //�t���[����t�ɒu����Block�̐�
#define BLOCK_NUM_Y 2                                                    //�c�ɕ��ׂ鐔

class Block:public ObjectBase
{
public:
	Block() {}
	~Block() {}

	virtual void Init(Vec2 pos_, float speed_, bool eneable_);

	void SetBlockBuufer();  //���[���h���W��`����W�ɕϊ�




};

#endif