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
	m_block{ nullptr },   //!ブロック配列
	m_step(STEP_UPDATE),  //!ステップ
	m_block_type(O_BLOCK), m_next_block_type(L_BLOCK)  //!ブロックの種類
{
}

//!初期化関数(繰り返し)
void Tetris_BlockController::Rest(Tetris_Stage* stage_)
{
	//!インスタンス化
	if (m_block[I_BLOCK] == nullptr) { m_block[I_BLOCK] = new Tetris_I_Block(stage_); }
	if (m_block[J_BLOCK] == nullptr) { m_block[J_BLOCK] = new Tetris_J_Block(stage_); }
	if (m_block[L_BLOCK] == nullptr) { m_block[L_BLOCK] = new Tetris_L_Block(stage_); }
	if (m_block[O_BLOCK] == nullptr) { m_block[O_BLOCK] = new Tetris_O_Block(stage_); }
	if (m_block[S_BLOCK] == nullptr) { m_block[S_BLOCK] = new Tetris_S_Block(stage_); }
	if (m_block[T_BLOCK] == nullptr) { m_block[T_BLOCK] = new Tetris_T_Block(stage_); }
	if (m_block[Z_BLOCK] == nullptr) { m_block[Z_BLOCK] = new Tetris_Z_Block(stage_); }

	m_stage = stage_;  //!ステージアドレス

	//!次に降ってくるブロックを予測枠にセット
	m_block[m_next_block_type]->SetBlockAngle(0);
	m_block[m_next_block_type]->SetNextBlockBuffer();

	//!現在降ってくるブロックの形をブロック配列にセット 
	m_block[m_block_type]->SetBlockAngle(0);
}

//!ステップ処理関数
void Tetris_BlockController::Update()
{
	switch (m_step)
	{
	case Tetris_BlockController::STEP_CREATE:     //!生成
		CreateBlock();
		break;
	case Tetris_BlockController::STEP_UPDATE:    //!更新
		BlockUpdate();
		break;
	default:
		break;
	}
}

//!ブロック更新関数
void Tetris_BlockController::BlockUpdate()
{
	m_block[m_block_type]->Update();  //!現在降ってきているブロックの更新

	//!ブロックが固定された場合
	if(m_block[m_block_type]->GetStop() == true)
	{
		m_step = STEP_CREATE;  //!生成ステップへ
	}
}

//!更新関数
void Tetris_BlockController::CreateBlock()
{
	m_block_type = m_next_block_type;   //!現在降ってくるブロックを前に決めたブロックの形で代入

	m_next_block_type = static_cast<BLOCK_TYPE>(rand() % TYPE_NUM);//!ランダム

	while (m_block_type == m_next_block_type)
	{
		m_next_block_type = static_cast<BLOCK_TYPE>(rand() % TYPE_NUM);//!ランダム
	}

	m_stage->NextBlockClear();   //!予測枠クリア

	//!次に降ってくるブロックを予測枠にセット
	m_block[m_next_block_type]->SetBlockAngle(0);  
	m_block[m_next_block_type]->SetNextBlockBuffer();

	//!現在降ってくるブロックをステージ配列にセット 
	m_block[m_block_type]->Reset();
	m_block[m_block_type]->SetBlockAngle(0);


	m_step = STEP_UPDATE;  //!更新ステップへ
}

//!当たり判定関数
bool Tetris_BlockController::Collision()
{
	
	if (m_block[m_block_type]->Collision() == true)
	{
		return true;
	}

	return false;
}

//!ブロック描画情報代入関数
void Tetris_BlockController::SetUpDrawBuffer(GAME_TYPE type_)
{
	m_block[m_block_type]->SetUpDrawBuffer(type_);
}

//!形更新(回転)関数
void Tetris_BlockController::SetBlockAngle(__int8 angle_)
{
	m_block[m_block_type]->SetBlockAngle(angle_);
}

//! 使用ブロック座標更新関数
void Tetris_BlockController::SetBlockPos(float x_, float y_)
{
	m_block[m_block_type]->SetBlockPos(x_, y_);
}
