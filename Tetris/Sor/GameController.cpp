#include "GameController.h"
#include "Entity.h"

//!コンストラクタ
Tetris_GameController::Tetris_GameController() :
	m_tetris{ nullptr }
{

}

//!デストラクタ
Tetris_GameController::~Tetris_GameController()
{
	Delete(); //!オブジェクトの解放
}

//!ステップ処理関数
void Tetris_GameController::Update()
{
	m_tetris[TYPE_A]->Update();
	m_tetris[TYPE_B]->Update();
}

//!初期化関数
void Tetris_GameController::Init()
{
	if (m_tetris[TYPE_A] == nullptr) { m_tetris[TYPE_A] = new Tetris; }     //!ステージ
	if (m_tetris[TYPE_B] == nullptr) { m_tetris[TYPE_B] = new Tetris; }     //!ステージ
}

//!描画情報代入関数
void Tetris_GameController::SetUpDrawBuffer()
{
	m_tetris[TYPE_A]->SetUpDrawBuffer(TYPE_A);
	m_tetris[TYPE_B]->SetUpDrawBuffer(TYPE_B);
}

//!強制終了関数
bool Tetris_GameController::GameEnd()
{
	//!ESCキーが押されたとき
	if (m_tetris[TYPE_A]->GameEnd() == true || m_tetris[TYPE_A]->GameEnd() == true)
	{
		return true;
	}
	return false;
}

//!解放処理
void Tetris_GameController::Delete()
{
	for (int i = 0; i < GAME_NUM; i++)
	{
		delete m_tetris[i];
		m_tetris[i] = nullptr;
	}
}
