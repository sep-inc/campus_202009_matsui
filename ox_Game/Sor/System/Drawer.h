#ifndef DRAWER_H_
#define DRAWER_H_
#include "../Vec.h"
#include "../World.h"

/**
*@clss   �`��N���X
*@brief  �e�I�u�W�F�N�g�̏������Ƃɕ`�悷��
*/
class Drawer
{
public:
    Drawer() {}
    ~Drawer() {}

    /**
     * @brief  �������֐�
     * @detail �����o�ϐ��̏�����
     */
    void Init();                        
    
     /**
     * @brief  Object�`����W�ϊ��֐�
     * @param (pos_) Object�̍��W
	 * @param (font_) �\������`
     * @detail �`����W�ɃI�u�W�F�N�g�����
     */
    void SetUpBuffer(Vec pos_,const char* font_);   
    
     /**
     * @brief  �`��֐�
     * @detail �`��
     */
    void Draw();               

    void DrawJudgment(JUDGMENT_TYPE type_);


private:
    struct DrawBuffer
    {
        char kind[4];
    };

    DrawBuffer m_draw_buffer[8][8];  //!�`��p�z��
    DrawBuffer m_clear_buffer[8][8]; //!�N���A�p�z��

};

#endif