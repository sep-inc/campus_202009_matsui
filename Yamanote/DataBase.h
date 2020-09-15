#ifndef DATABASE_H_
#define DATABASE_H_

#define STATION_NUM 29     //�w�̐�
#define START_STATION 0   //�ŏ��̉w


/* �w�̏�� */
struct StationInfo
{
	char station[64];   //�w��     
	__int8 Spin;        //���E�w�̈ړ����� 
};


class DataBase
{
public:
	/* ������ */
	DataBase() :m_step(STEP_INPUT), m_start_station(0), m_end_station(0),
		m_right_total_value(0), m_left_total_value(0){}
	~DataBase() {}

	void StepChange();     //�X�e�b�v����
	void Init();           //���͏���
	void Caluculation();   //�v�Z����
	void SetTotalValue();  //�l�킽���֐�
	

private:
	enum STEP
	{
		STEP_INPUT,         //���̓X�e�b�v
		STEP_CALUCULATION,	//�v�Z�X�e�b�v
		STEP_SET			//���ԕۑ��X�e�b�v
	}m_step;

	char input_start_station[64];   //�w�����͗p
	char input_end_station[64];     //�w�����͗p

	__int8 m_start_station;         //�w���ԍ��ۑ��p
	__int8 m_end_station;           //�w���ԍ��ۑ��p

	__int8 m_right_total_value;            //�E��荇�v�l
	__int8 m_left_total_value;             //����荇�v�l


	char sation[64];
};

#endif