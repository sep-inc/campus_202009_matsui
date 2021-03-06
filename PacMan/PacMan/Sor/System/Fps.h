﻿#ifndef FPS_H_
#define FPS_H_
#include <fstream>
#include <sstream>
#include <windows.h>
#include <timeapi.h>
#pragma comment(lib,"winmm.lib")

#define FRAME_COUNT 60 //!1フレームで回る回数

class Fps
{
public:
	Fps() {}
	~Fps() {}

	/**
	 * @brief  フレーム時間測定開始関数
	 * @detail 1フレームの始まりを設定
	 */
	void TimeBaseLoopExecuter();

	/**
	 * @brief  フレーム固定関数
	 * @detail 1フレームの時間を測りFPSを固定する
	 */
	void TimeAdjustment();

private:
	double FRAME_TIME = 0.0;
	//計測開始時間
	LARGE_INTEGER mTimeStart;
	//計測終了時間
	LARGE_INTEGER mTimeEnd;
	//計測周波数
	LARGE_INTEGER mTimeFreq;
};

#endif