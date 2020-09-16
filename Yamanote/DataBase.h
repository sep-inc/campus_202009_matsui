#ifndef DATABASE_H_
#define DATABASE_H_

#define STATION_NUM 29     //�w�̐�
#define START_STATION 0   //�ŏ��̉w

#define CENTER_LANE_TIME 12   //�������̂����鎞��

#define CENTER_START_STATION 1 //��������芷���w(���v���Ō��Ă��邽�ߐ_�c���ŏ�)
#define CENTER_END_STATION 14   //��������芷���w(���v���Ō��Ă��邽�ߐV�h���Ō�)


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
	DataBase() :m_start_station(0), m_end_station(0)
	{}
	~DataBase() {}

	void StepChange();     //�X�e�b�v����
	void Input();           //���͏���
	void Caluculation();   //�v�Z����
	void SearchName();     //�w������

	__int8 RightRoteValue(__int8 start_, __int8 end_);  //���v���v�Z����
	__int8 LeftRoteValue(__int8 start_, __int8 end_);   //�����v���v�Z����

	__int8 CenterLaneRoteValue(__int8 station_);        //����������̌v�Z����

	__int8 Comparison();      //�ŒZ���Ԕ�r(�߂�l:�ŒZ����)

	void SetTotalValue();  //�l�킽���֐�
	

private:
	char input_start_station[64];   //�w�����͗p
	char input_end_station[64];     //�w�����͗p

	__int8 m_start_station;         //�w���ԍ��ۑ��p
	__int8 m_end_station;           //�w���ԍ��ۑ��p

	struct RoteValue
	{
		__int8 m_right_total_value;            //�E��荇�v�l
		__int8 m_left_total_value;             //����荇�v�l

		__int8 m_total_first_yamanote;         //end�`�������܂ł̑������Ԃ�ۑ�
		__int8 m_total_first_value;         //end�`�������܂ł̑������Ԃ�ۑ�

		       
	}m_rotevalue;
	

};

#endif