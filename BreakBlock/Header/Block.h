#ifndef BLOCK_H_
#define BLOCK_H_
#include "ObjectBase.h"
#include "Collision.h"
#include "World.h"
#include "Drawer.h"

/* Block個数 */
#define BLOCK_NUM_X (((GAME_WIDTH / UNIT_X)) / (BLOCK_WIDTH / UNIT_X))   //フレーム一杯に置けるBlockの数
#define BLOCK_NUM_Y 2                                                    //縦に並べる数

class Block:public ObjectBase
{
public:
	Block() {}
	~Block() {}

	virtual void Init(Vec2 pos_, float speed_, bool eneable_);

	void SetBlockBuufer();  //ワールド座標を描画座標に変換




};

#endif