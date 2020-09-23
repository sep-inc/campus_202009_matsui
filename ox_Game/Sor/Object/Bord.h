#ifndef BORD_H_
#define BORD_H_
#include "../Vec.h"

/**
 *@clss   �ՃN���X
 *@brief  �Տ�������
 */
class Bord
{
public:
	Bord()  {}
	~Bord() {}

	/**
	 * @brief  �������֐�
	 * @detail �����o�ϐ��̏�����
	 */
	void Init();          
	
	/**
	 * @brief  �X�V�֐�
	 * @detail �X�V����
	 */
	bool Search();        

	/**
	 * @brief  �I������֐�(���s)
	 * @param (object) �v���C���[���G�̋�
	 * @detail �Տ�ɓ����3�ȏ�c���΂߂ł�����Ă��邩�𔻒�
	 */
	bool EndSearch(__int8 object);	 

	/**
	 * @brief  �I������֐�(��������)
	 * @detail �������������܂炸�u����ꏊ�����邩�𔻒�
	 */
	bool DrawSearch();

	
	/**
	 * @brief  �z�u����֐�
	 * @param (input_font) ���͂�������
	 * @param (input_number) ���͂�������
	 * @detail �w�肵���Տ�ɒu���邩�ǂ������肷��
	 */
	bool PutSearch(__int8 input_font, __int8 input_number);	

	/**
	 * @brief  �z�u�ԍ�����֐�
	 * @detail �Տ�ɒu���ꏊ�����邩�ǂ���
	 */
	bool SearchNumber();


	/**
	 * @brief  �Տ�z���z�u�֐�
	 * @param (piece_) ��̍��W
	 * @param (object_) ��̎��
	 * @detail �w�肵���Տ�z��ɋ��z�u����
	 */
	void SetPiecePos(Vec piece_, __int8 object_);

private:
	/* �Տ�\���� */
	struct BordInfo
	{
		 __int8 m_put_number;  //!�u����Տ�ԍ�
		 __int8 m_put_object;  //!�u���Ă���Object�̎��

	}m_bord_info[3][3];

};

#endif
