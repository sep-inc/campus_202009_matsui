#include "Tetris.h"
#include "Entity.h"
#include "Player/Myself.h"

//!コンストラクタ
Tetris::Tetris() :
	m_stage(nullptr), m_block(nullptr), m_player(nullptr),
	m_game_over(false)
{
}

//!デストラクタ
Tetris::~Tetris()
{
	Delete(); //!オブジェクトの解放
}

//!ステップ処理関数
void Tetris::Update()
{
	m_block->Update();   //!ブロック
	m_player->Update();  //!プレイヤー
	m_stage->Update();  //!プレイヤー
}

//!初期化関数
void Tetris::Init()
{
	if (m_stage == nullptr) { m_stage = new Tetris_Stage; }             //!ステージ
	if (m_block == nullptr) { m_block = new Tetris_BlockController; }   //!ブロック
	if (m_player == nullptr) { m_player = new Tetris_Myself(m_block); }

	m_stage->Reset();  //!ステージ初期化

	m_block->Rest(m_stage);  //!ブロック初期化
}

//!描画情報代入関数
void Tetris::SetUpDrawBuffer(GAME_TYPE type_)
{
	m_stage->SetUpDrawStageBuffer(type_);  //!ステージ
	m_stage->SetUpDrawBlockBuffer(type_);  //!予測枠
	m_block->SetUpDrawBuffer(type_);       //!ブロック
}

//!ゲームオーバー判定関数
bool Tetris::GameOver()
{
	//!ステージの上にブロックがついた場合
	if (m_stage->GameOver() == true)
	{
		return true;
	}
	return false;
}

//!解放処理
void Tetris::Delete()
{
	delete m_stage;
	m_stage = nullptr;

	delete m_block;
	m_block = nullptr;

	delete m_player;
	m_player = nullptr;
}
