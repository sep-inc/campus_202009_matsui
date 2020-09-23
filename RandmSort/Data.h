#ifndef DATA_H_
#define DATA_H_

#define ELEMENT 10

class Data
{
public:
	Data():m_step(STEP_INIT) {}
	~Data() {}

	void StepChange();  //�X�e�b�v����

	void Init();        //������

	void Update();      //�X�V

	void Draw();        //�W��

	__int8 RandmNumber(); //��������֐�

	__int8 CopyArray(__int8 copy_array_);   //�����z��R�s�[�֐�

	void SortArray();   //�\�[�g�z��\�[�g�֐�

private:
	/* �����^�\���� */
	struct IntegerArray
	{
		unsigned __int8 randm;  //�����ۑ�
		unsigned __int8 sort;   //�\�[�g��ۑ�

	}m_integer_array[ELEMENT];

	enum Step
	{
		STEP_INIT,    //������
		STEP_UPDATE,  //�X�V
		STEP_DRAW     //�\��
	}m_step;

	unsigned __int8 transfer_box[100];  //���������ɗ������ڂ��ւ���悤
};


#endif