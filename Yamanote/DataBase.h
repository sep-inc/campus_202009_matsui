#ifndef DATABASE_H_
#define DATABASE_H_

#define STATION_NUM 29     //駅の数
#define START_STATION 0   //最初の駅


/* 駅の情報 */
struct StationInfo
{
	char station[64];   //駅名     
	__int8 Spin;        //左右駅の移動時間 
};


class DataBase
{
public:
	/* 初期化 */
	DataBase() :m_step(STEP_INPUT), m_start_station(0), m_end_station(0),
		m_right_total_value(0), m_left_total_value(0){}
	~DataBase() {}

	void StepChange();     //ステップ処理
	void Init();           //入力処理
	void Caluculation();   //計算処理
	void SetTotalValue();  //値わたし関数
	

private:
	enum STEP
	{
		STEP_INPUT,         //入力ステップ
		STEP_CALUCULATION,	//計算ステップ
		STEP_SET			//時間保存ステップ
	}m_step;

	char input_start_station[64];   //駅名入力用
	char input_end_station[64];     //駅名入力用

	__int8 m_start_station;         //駅名番号保存用
	__int8 m_end_station;           //駅名番号保存用

	__int8 m_right_total_value;            //右回り合計値
	__int8 m_left_total_value;             //左回り合計値


	char sation[64];
};

#endif