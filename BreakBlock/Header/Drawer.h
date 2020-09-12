#ifndef DRAWMAP_H_
#define DRAWMAP_H_
#include "Vec2.h"
#include "World.h"


#define UNIT_X 16           //�z��1��World�T�C�Y(int)
#define UNIT_Y 16           //�z��1��World�T�C�Y(int)

#define WALL_FRAME 1        //Wall(�t���[��)�T�C�Y(int)

//�z��(World�T�C�Y�ɑ΂���`��T�C�Y)
#define NUM_UNIT_X (GAME_WIDTH/UNIT_X) + (WALL_FRAME + WALL_FRAME)   
#define NUM_UNIT_Y (GAME_HEIGHT/UNIT_Y) + (WALL_FRAME + WALL_FRAME)  

#define START_UNIT 0       //for���񂷂Ƃ��̏����萔(int)

/* Object�̎�� */
enum OBJECTKIND
{
	BLANK = 0,   
	WALL = 1,	 
	BLOCK = 2,	 
	BAR = 3,	 
	BALL = 4	 
};

//Map(�`��p)
class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Init();           //������
	void Draw();           //�`��

	void BufferClear();    //�t���[���݂̂�buffer��`��p�z��ɑ������֐�

	void SetUpBuffer(Vec2 pos_, OBJECTKIND kind_, int width_);  //Block��brankbuffer�ɒǉ�����֐�

private:
	struct DrawParm
	{
		OBJECTKIND m_kind;    
	};

	DrawParm m_map[NUM_UNIT_Y][NUM_UNIT_X];        //�`��p

	DrawParm m_blank_map[NUM_UNIT_Y][NUM_UNIT_X];  //�e�I�u�W�F�N�g�ǉ��p
};

#endif