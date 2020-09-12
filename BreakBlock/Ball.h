#ifndef BALL_H_
#define BALL_H_
#include "ObjectBase.h"
#include "Collision.h"
#include "Drawer.h"
#include "BlockArray.h"
#include "World.h"

class Ball : public ObjectBase
{
public:
	Ball() :m_step(STEP::STEP_INIT), m_direction_vec(Vec2(1.0f, 1.0f)), m_next_pos(Vec2(0.0f, 0.0f)) {}
	~Ball() {}

	void Init();               //初期化
	void Update();			   //ステップ処理関数
	void SetDrawBuffer();      //ワールド座標を描画座標に変換

	void Move();               //移動関数
	void DirectionChange();    //方向ベクトル変換関数

	void Hit();                //当たり判定まとめ関数
	void HitWall();			   //壁との当たり判定
	void HitBar();			   //Barとの当たり判定


private:
	//ステップの種類
	enum STEP
	{
		STEP_INIT,     //初期化
		STEP_MOVE,	   //移動までの処理
		STEP_OUT	   //解放
	}m_step;

	/* 当たり判定の種類 */
	struct CollisionType
	{
		bool m_top_under_wall;     //Wallの上下のあたり判定フラグ
		bool m_left_right_wall;	   //Wallの左右のあたり判定フラグ
		bool m_top_under_bar;	   //Barの上下のあたり判定フラグ
		bool m_left_right_bar;	   //Barの上下のあたり判定フラグ

	}m_collision_type;

	 
	Vec2 m_direction_vec;        //方向ベクトル

	Vec2 m_next_pos;             //1フレーム先の座標
};


#endif