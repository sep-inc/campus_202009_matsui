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

	void Init();              //������
	void Update();            //�X�e�b�v�����֐� 

	void SetUpBlocks();       //Block������
	void SetUpDrawBuufer();   //���[���h���W��`����W�ɕϊ�

	void DeleteBlock();

	const Vec2 GetBlockPos(__int8 x_, __int8 y_) { return m_block[y_][x_].GetPos(); }
	//const Block(&GetBlock())[BLOCK_NUM_Y][BLOCK_NUM_X]{ return m_block; }
private:
	enum STEP
	{
		STEP_INIT,    //������
		STEP_RUN,     //����
		STEP_OUT	  //���
	}m_step;


	Block m_block[BLOCK_NUM_Y][BLOCK_NUM_X];
};

#endif