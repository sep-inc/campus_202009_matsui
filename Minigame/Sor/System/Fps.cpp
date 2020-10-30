#include "FPS.h"

Fps* Fps::Instance()
{
	static Fps fps;

	return &fps;
}

//!フレーム時間測定開始関数
void Fps::TimeBaseLoopExecuter()
{
	//周波数取得
	QueryPerformanceFrequency(&mTimeFreq);
	//計測開始時間の初期化
	QueryPerformanceCounter(&mTimeStart);

	FRAME_TIME = 1.0f / FRAME_COUNT;
}

//!フレーム固定関数
void Fps::TimeAdjustment()
{
	// 今の時間を取得
	QueryPerformanceCounter(&mTimeEnd);
	// (今の時間 - 前フレームの時間) / 周波数 = 経過時間(秒単位)
	double frameTime = static_cast<double>(mTimeEnd.QuadPart - mTimeStart.QuadPart) / static_cast<double>(mTimeFreq.QuadPart);
	//処理時間に余裕がある場合はその分待つ
	if (frameTime < FRAME_TIME)
	{
		//Sleepの時間を計算
		DWORD sleepTime = static_cast<DWORD>((FRAME_TIME - frameTime) * 1000);
		timeBeginPeriod(1);

		//寝る
		Sleep(sleepTime);
		timeEndPeriod(1);
	}
}
