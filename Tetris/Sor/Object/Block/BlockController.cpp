#include "BlockController.h"
#include "I_Block.h"
#include "J_Block.h"
#include "L_Block.h"
#include "O_Block.h"
#include "S_Block.h"
#include "T_Block.h"
#include "Z_Block.h"
#include <math.h>
#include <random>


//!コンストラクタ
Tetris_BlockController::Tetris_BlockController() :
	m_block{ nullptr },
	m_step(STEP_UPDATE),
	m_block_type(O_BLOCK), m_next_block_type(L_BLOCK)
{
}

//!初期化関数(繰り返し)
void Tetris_BlockController::Rest(Tetris_Stage* stage_)
{
	if (m_block[I_BLOCK] == nullptr) { m_block[I_BLOCK] = new Tetris_I_Block(stage_); }
	if (m_block[J_BLOCK] == nullptr) { m_block[J_BLOCK] = new Tetris_J_Block(stage_); }
	if (m_block[L_BLOCK] == nullptr) { m_block[L_BLOCK] = new Tetris_L_Block(stage_); }
	if (m_block[O_BLOCK] == nullptr) { m_block[O_BLOCK] = new Tetris_O_Block(stage_); }
	if (m_block[S_BLOCK] == nullptr) { m_block[S_BLOCK] = new Tetris_S_Block(stage_); }
	if (m_block[T_BLOCK] == nullptr) { m_block[T_BLOCK] = new Tetris_T_Block(stage_); }
	if (m_block[Z_BLOCK] == nullptr) { m_block[Z_BLOCK] = new Tetris_Z_Block(stage_); }

	m_stage = stage_;

	m_block[m_next_block_type]->SetBlock();
	m_block[m_next_block_type]->SetNextBlockBuffer();

	m_block[m_block_type]->SetBlock();
}

//!ステップ処理関数
void Tetris_BlockController::Update()
{
	switch (m_step)
	{
	case Tetris_BlockController::STEP_CREATE:     //!初期化
		CreateBlock();
		break;
	case Tetris_BlockController::STEP_UPDATE:   //!更新
		BlockUpdate();
		break;
	default:
		break;
	}
}

//!ブロック更新関数
void Tetris_BlockController::BlockUpdate()
{
	m_block[m_block_type]->Update();

	if(m_block[m_block_type]->GetStop() == true)
	{
		m_step = STEP_CREATE;
	}
}

//!更新関数
void Tetris_BlockController::CreateBlock()
{
	m_block_type = m_next_block_type;

	m_next_block_type = static_cast<BLOCK_TYPE>(rand() % TYPE_NUM);//!ランダム

	m_stage->NextBlockClear();

	m_block[m_next_block_type]->SetBlock();
	m_block[m_next_block_type]->SetNextBlockBuffer();


	m_block[m_block_type]->Reset();
	m_block[m_block_type]->SetBlock();


	m_step = STEP_UPDATE;
}

//!ブロック描画情報代入関数
void Tetris_BlockController::SetUpDrawBuffer(GAME_TYPE type_)
{
	m_block[m_block_type]->SetUpDrawBuffer(type_);
}
