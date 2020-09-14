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
	Ball() :m_step(STEP::STEP_INIT), m_move_step(STEP_HIT), m_hit_step(STEP_WALL),
		m_direction_vec(Vec2(1.0f, 1.0f)), m_next_pos(Vec2(0.0f, 0.0f)), m_delete_pos(Vec2(0.0f, 0.0f)),
		m_rote_volume(2.0f)
	{}
	~Ball() {}

	void Init();                       //初期化
	void Update();			           //ステップ処理関数
	void SetDrawBuffer();              //ワールド座標を描画座標に変換
							           
	void Move();                       //移動関数
	void DirectionChange();         //方向ベクトル変換関数
	
	


							      
	void Hit();                   //当たり判定まとめ関数
	void HitWall();			      //壁との当たり判定
	void HitBar();			      //Barとの当たり判定
	void HitBlocks();		      //Block群との当たり判定

	void HitBlockUnit(__int8 y_);  //Block単体との当たり判定

	void Out();

	/* 当たり判定の種類 */
	struct CollisionType
	{
		bool m_top_under_wall;     //Wallの上下のあたり判定フラグ
		bool m_left_right_wall;	   //Wallの左右のあたり判定フラグ
		bool m_top_under_bar;	   //Barの上下のあたり判定フラグ
		bool m_left_right_bar;	   //Barの上下のあたり判定フラグ
		bool m_top_under_block;    //Blockの上下のあたり判定フラグ
		bool m_left_right_block;   //Blockの上下のあたり判定フラグ

		bool m_during_bar;         //Blockの上下のあたり判定フラグ
		bool m_out;                //Ballが下に落ちたとき

	}m_collision_type;

	/* 消去Blockの座標保存用 */
	const Vec2 GetDeletePos() { return m_delete_pos; }

	/* Block消去時のフラグ */
	const CollisionType GetHiter() { return m_collision_type; }

private:
	//ステップの種類
	enum STEP
	{
		STEP_INIT,     //初期化
		STEP_RUN,	   //移動までの処理
		STEP_OUT	   //解放
	}m_step;

	/* 移動するまでの処理 */
	enum MOVE_STEP
	{
		STEP_HIT,         //当たり判定
		STEP_DIRECTION,   //方向ベクトル変換
		STEP_MOVE,        //移動
	}m_move_step;

	/* 当たり判定の処理 */
	enum HIT_STEP
	{
		STEP_WALL,        //壁
		STEP_BAR,         //Bar
		STEP_BLOCK,       //Block
	}m_hit_step;
	 
	Vec2 m_direction_vec;       //方向ベクトル

	Vec2 m_next_pos;            //1フレーム先の座標

	Vec2 m_delete_pos;          //Block消去pos_x保存用


	/* 横1列のBlockを1群と考える */
	Vec2 m_first_blocks_pos;    //1段目のBlock群のpos
	Vec2 m_second_blocks_pos;	//2段目のBlock群のpos

	float m_rote_volume;
};


#endif