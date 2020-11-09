#include "GameController.h"
#include "Entity.h"

//!コンストラクタ
Tetris_GameController::Tetris_GameController() :
	m_tetris{ nullptr },
	m_step(STEP_INIT)
{

}

//!デストラクタ
Tetris_GameController::~Tetris_GameController()
{
	Delete(); //!各ゲームの解放
}

//!ステップ処理関数
void Tetris_GameController::Update()
{
	switch (m_step)
	{
	case Tetris_GameController::STEP_INIT:     //!初期化
		Init();
		break;
	case Tetris_GameController::STEP_START:    //!開始待ち
		DrawRule();
		//!スタートキーが入力されたら
		if (g_inputter.InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case Tetris_GameController::STEP_UPDATE:   //!更新
		GameUpdate();
		break;
	case Tetris_GameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}

//!初期化関数
void Tetris_GameController::Init()
{
	if (m_tetris[TYPE_A] == nullptr) { m_tetris[TYPE_A] = new Tetris; }     //!テトリスA
	if (m_tetris[TYPE_B] == nullptr) { m_tetris[TYPE_B] = new Tetris; }     //!テトリスB

	for (int i = 0; i < GAME_NUM; i++)
	{
		m_tetris[i]->Init();
	}

	m_step = STEP_START;
}

//!ゲーム更新関数
void Tetris_GameController::GameUpdate()
{
	
	for (int i = 0; i < GAME_NUM; i++)
	{
		m_tetris[i]->Update();

		if (m_tetris[i]->GameOver() == true)
		{
			m_step = STEP_RESULT;
			system("cls");
		}
	}

	printf("操作方法：十字キーで移動(上以外)\n");
	printf("操作方法：Rキーで右回転、Lキーで左回転\n");
}

//!結果出力関数
void Tetris_GameController::GameResult()
{
	if (m_tetris[TYPE_A]->GameOver() == true)
	{
		printf("左手の負け\n");
	}
	else
	{
		printf("右手の負け\n");
	}

	//!続けるかどうか
	if (g_inputter.InputContinue() == true)
	{
		m_step = STEP_INIT;
	}
}

//!ルール描画関数
void Tetris_GameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("操作方法：十字キーで移動(上以外)\n");
	printf("操作方法：Rキーで右回転、Lキーで左回転\n");
	printf("敗北条件：画面上にブロックが当たる\n");
	printf("概要：ブロックを横一列揃えると、その段が消える。\n");
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
	if (g_inputter.GetESCKey() == true)
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
