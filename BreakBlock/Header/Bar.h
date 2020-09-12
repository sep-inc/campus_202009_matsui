#ifndef BAR_H_
#define BAR_H_
#include "ObjectBase.h"
#include "Drawer.h"
#include "World.h"                     

class Bar :public ObjectBase
{
public:
	Bar() :m_step(STEP::STEP_INIT), m_hit_wall(false), m_direction_X(1.0f)   //thisのメンバ変数はメンバイニシャライザで初期化
	{}
	~Bar() {}

	virtual void Init();      //初期化
	virtual void Update();    //ステップ処理関数

	void SetUpDrawBuffer();   //ワールド座標を描画座標に変換
	void Move();              //移動関数
	void Hit();               //あたり判定関数

private:
	//ステップの種類
	enum STEP
	{
		STEP_INIT,        //初期化
		STEP_MOVE,        //移動までの処理
		STEP_OUT		  //解放
	}m_step;

	bool m_hit_wall;        //フレームに当たったかフラグ
	float m_direction_X;    //方向ベクトル(左右にしか移動しないのでX軸だけ)


};

#endif