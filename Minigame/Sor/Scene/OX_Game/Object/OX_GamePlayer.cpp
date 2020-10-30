#include "OX_GamePlayer.h"
#include "../../../System/DrawController.h"
#include "../../../System/Inputter.h"


//!初期化関数
void OX_GamePlayer::Init()
{
	m_pos = Vec2(-5, -5);  //!表示されないよう見えない位置に初期化
}

//!描画座標代入関数
void OX_GamePlayer::SetUpDrawBuffer()
{
	DrawController::Instance()->SetUpBuffer(m_pos, "●");
}

//!配置
void OX_GamePlayer::Put(OX_GameBoard* board_)
{

	Inputter::Instance()->InputNumber();    //!配置場所入力

	//!選択した場所が置けるかどうか調べる
	if (board_->PutSearch(Inputter::Instance()->GetSelectFont(), Inputter::Instance()->GetSelectNumber()) == true)
	{
		m_pos = Vec2(Inputter::Instance()->GetSelectFont(), Inputter::Instance()->GetSelectNumber());  //座標更新
	}
	//!置けない場合はもう一度選択
	else
	{
		while (board_->PutSearch(Inputter::Instance()->GetSelectFont(), Inputter::Instance()->GetSelectNumber()) == false)
		{
			Inputter::Instance()->InputNumber();    //!配置場所再入力
		}

		m_pos = Vec2(Inputter::Instance()->GetSelectFont(), Inputter::Instance()->GetSelectNumber());  //座標更新
	}

	board_->SetPiecePos(m_pos, OX_GAME_OBJECT_TYPE::OX_GAME_PLAYER_PIECE);   //盤配列に座標代入
}
