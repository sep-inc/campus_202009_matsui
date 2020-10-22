#include "PacManPlayer.h"
#include "../../Entity.h"

//!初期化関数
void PacManPlayer::Init(PacManStage* stage_, PacManItem* item_)
{
	m_stage = stage_;         //!ステージアドレス取得
	m_item = item_;           //!ステージアドレス取得

	m_direction = Vec(0, 0);  //!方向ベクトル
	m_deth = false;           //!死亡フラグ
	m_wall_hit = false;       //!壁当たり判定フラグ
	m_clear = false;

	InitAnother();   //!共通外変数初期化

	//!ステージ情報更新
	m_stage->SetUpStageBuffer(m_pos, m_pos, m_player_type);
}

//!描画情報送信関数
void PacManPlayer::SetUpDrawBuffer()
{
	g_drawer.SetUpBuffer(m_pos, m_draw_font);
}

//!結果表示関数
void PacManPlayer::ResultDraw()
{
	if (m_deth == true)
	{
		printf("ゲームオーバー\n");
	}
	else if (m_clear == true)
	{
		printf("ゲームクリア\n");
	}
}
