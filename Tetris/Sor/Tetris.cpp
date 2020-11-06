#include "Tetris.h"
#include "Entity.h"

//!コンストラクタ
Tetris::Tetris() :
	m_stage(nullptr), m_block(nullptr)
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
	switch (m_step)
	{
	case Tetris::STEP_INIT:     //!初期化
		Init();
		break;
	case Tetris::STEP_START:    //!開始待ち
		//!スタートキーが入力されたら
		if (g_inputter.InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case Tetris::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	case Tetris::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}

//!初期化関数
void Tetris::Init()
{
	if (m_stage == nullptr) { m_stage = new Tetris_Stage; }             //!ステージ
	if (m_block == nullptr) { m_block = new Tetris_BlockController; }   //!ステージ

	m_block->Rest(m_stage);

	//!次のステップへ
	m_step = STEP_START;
}

//!更新処理関数
void Tetris::ObjectUpdate()
{
	m_block->Update();

	//m_step = STEP_RESULT;
}

//!描画情報代入関数
void Tetris::SetUpDrawBuffer(GAME_TYPE type_)
{
	m_stage->SetUpDrawStageBuffer(type_);
	m_stage->SetUpDrawBlockBuffer(type_);
	m_block->SetUpDrawBuffer(type_);
}

//!終了判定関数
void Tetris::GameResult()
{


	//!続けるかどうか
	if (g_inputter.InputContinue() == true)
	{
		m_step = STEP_INIT;
	}
}

//!強制終了関数
bool Tetris::GameEnd()
{
	//!ESCキーが押されたとき
	if (g_inputter.GetESCKey() == true)
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
}
