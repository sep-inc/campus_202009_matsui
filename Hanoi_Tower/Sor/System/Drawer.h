#ifndef DRAWER_H_
#define DRAWER_H_
#include "../World.h"
#include "../Vec.h"

#define FRAME_UNIT 1

/* �`��N���X */
class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Init();           //�������֐�
	void Clear();          //�N���A�֐�
	void SetUpBuffer(Vec pos_, __int16 width_, __int16 height_, OBJECT_TYPE kind_);    //�I�u�W�F�N�g�Z�b�g�֐�
	void Draw();           //�`��֐�

private:
	struct Buffer
	{
		OBJECT_TYPE m_kind;
	};

	Buffer m_draw_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];   //�`��p�z��
	Buffer m_clear_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];   //�`��p�z��
};


#endif 