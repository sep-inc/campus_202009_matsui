#ifndef DRAWMAP_H_
#define DRAWMAP_H_
#include "Vec2.h"
#include "World.h"


#define UNIT_X 16           //配列1つのWorldサイズ(int)
#define UNIT_Y 16           //配列1つのWorldサイズ(int)

#define WALL_FRAME 1        //Wall(フレーム)サイズ(int)

//配列数(Worldサイズに対する描画サイズ)
#define NUM_UNIT_X (GAME_WIDTH/UNIT_X) + (WALL_FRAME + WALL_FRAME)   
#define NUM_UNIT_Y (GAME_HEIGHT/UNIT_Y) + (WALL_FRAME + WALL_FRAME)  

#define START_UNIT 0       //forを回すときの初期定数(int)

/* Objectの種類 */
enum OBJECTKIND
{
	BLANK = 0,   
	WALL = 1,	 
	BLOCK = 2,	 
	BAR = 3,	 
	BALL = 4	 
};

//Map(描画用)
class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Init();           //初期化
	void Draw();           //描画

	void BufferClear();    //フレームのみのbufferを描画用配列に代入する関数

	void SetUpBuffer(Vec2 pos_, OBJECTKIND kind_, int width_);  //Blockをbrankbufferに追加する関数

private:
	struct DrawParm
	{
		OBJECTKIND m_kind;    
	};

	DrawParm m_map[NUM_UNIT_Y][NUM_UNIT_X];        //描画用

	DrawParm m_blank_map[NUM_UNIT_Y][NUM_UNIT_X];  //各オブジェクト追加用
};

#endif