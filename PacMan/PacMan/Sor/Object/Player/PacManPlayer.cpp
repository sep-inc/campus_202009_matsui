#include "PacManPlayer.h"
#include "../../Entity.h"

//!コンストラクタ
PacManPlayer::PacManPlayer(PacManStage* stage_, PacManItem* item_, OBJECT_TYPE player_type_, const char* m_font_) :
	m_player_type(player_type_),  //!プレイヤーの種類
	m_draw_font(m_font_),   //!描画スタイル
	m_stage(stage_), //!ステージアドレス取得
	m_item(item_)    //!アイテムアドレス取得
{}

//!初期化関数
void PacManPlayer::Reset()
{
	m_direction = Vec(0, 0);  //!方向ベクトル

	m_flg_info = { false,false,false }; //!各フラグ初期化

	ResetAnother();   //!共通外変数初期化

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
	if (m_flg_info.m_deth == true)
	{
		printf("ゲームオーバー\n");
	}
	else if (m_flg_info.m_clear == true)
	{
		printf("ゲームクリア\n");
	}
}
