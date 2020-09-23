#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"

/**
 *@clss   ��N���X
 *@brief  �v���C���[�A�G�̋��������
 */
class Piece
{
public:
	Piece() :m_step(STEP_INIT) {}
	~Piece() {}

	/**
     * @brief  �X�e�b�v�����֐�
     * @detail �X�e�b�v�ύX����
     */
	void StepChange();   
	
    /**
	 * @brief  �������֐�
	 * @detail �����o�ϐ��̏�����
	 */
	void Init();          
	
	/**
	 * @brief  �X�V�֐�
	 * @detail �X�V����
	 */
	void Update();        
	
	/**
	 * @brief  �`����W����֐�
	 * @detail ����W��`����W�ɑ��
	 */
	void SetUpDrawBuffer();
	
	/**
	 * @brief  �ړ��֐��܂Ƃ�
	 * @detail ��̈ړ������܂Ƃ�
	 */
	void Put();         
	
	/**
	 * @brief  �v���C���[�ړ��֐�
	 * @detail �v���C���[�̈ړ�����
	 */
	void PlayerPut();         
	
	/**
	 * @brief  �G�ړ��֐�
	 * @detail �G�̈ړ�����
	 */
	void EnemyPut();        


private:
	enum Step
	{
		STEP_INIT,
		STEP_UPDATE,
		STEP_SET
	}m_step;

	Vec m_player_pos;     //!�v���C���[����W
	Vec m_enemy_pos;      //!�G����W

	Vec m_randm_number;   //!�G�̔z�u���W
};


#endif