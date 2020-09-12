#ifndef BLOCKCARRAY_H_
#define BLOCKCARRAY_H_
#include "Block.h"
#include "Drawer.h"
#include "World.h"

class BlockArray
{
public:
	BlockArray() :m_step(STEP::STEP_INIT) {}
	~BlockArray() {}

	void Init();              //初期化
	void Update();            //ステップ処理関数 

	void SetUpBlocks();       //Block初期化
	void SetUpDrawBuufer();   //ワールド座標を描画座標に変換

	void DeleteBlock();

	const Vec2 GetBlockPos(__int8 x_, __int8 y_) { return m_block[y_][x_].GetPos(); }
	//const Block(&GetBlock())[BLOCK_NUM_Y][BLOCK_NUM_X]{ return m_block; }
private:
	enum STEP
	{
		STEP_INIT,    //初期化
		STEP_RUN,     //処理
		STEP_OUT	  //解放
	}m_step;


	Block m_block[BLOCK_NUM_Y][BLOCK_NUM_X];
};

#endif