#ifndef DATABASE_H_
#define DATABASE_H_

#define STATION_NUM 29     //駅の数
#define START_STATION 0   //最初の駅

#define CENTER_LANE_TIME 12   //中央線のかかる時間

#define CENTER_START_STATION 1 //中央線乗り換え駅(時計回りで見ているため神田が最初)
#define CENTER_END_STATION 14   //中央線乗り換え駅(時計回りで見ているため新宿が最後)


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
	DataBase() :m_start_station(0), m_end_station(0)
	{}
	~DataBase() {}

	void StepChange();     //ステップ処理
	void Input();           //入力処理
	void Caluculation();   //計算処理
	void SearchName();     //駅名検索

	__int8 RightRoteValue(__int8 start_, __int8 end_);  //時計回り計算処理
	__int8 LeftRoteValue(__int8 start_, __int8 end_);   //反時計回り計算処理

	__int8 CenterLaneRoteValue(__int8 station_);        //中央線ありの計算処理

	__int8 Comparison();      //最短時間比較(戻り値:最短時間)

	void SetTotalValue();  //値わたし関数
	

private:
	char input_start_station[64];   //駅名入力用
	char input_end_station[64];     //駅名入力用

	__int8 m_start_station;         //駅名番号保存用
	__int8 m_end_station;           //駅名番号保存用

	struct RoteValue
	{
		__int8 m_right_total_value;            //右回り合計値
		__int8 m_left_total_value;             //左回り合計値

		__int8 m_total_first_yamanote;         //end～中央線までの早い時間を保存
		__int8 m_total_first_value;         //end～中央線までの早い時間を保存

		       
	}m_rotevalue;
	

};

#endif