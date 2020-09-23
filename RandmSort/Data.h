#ifndef DATA_H_
#define DATA_H_

#define ELEMENT 10

class Data
{
public:
	Data():m_step(STEP_INIT) {}
	~Data() {}

	void StepChange();  //ステップ処理

	void Init();        //初期化

	void Update();      //更新

	void Draw();        //標示

	__int8 RandmNumber(); //乱数代入関数

	__int8 CopyArray(__int8 copy_array_);   //乱数配列コピー関数

	void SortArray();   //ソート配列ソート関数

private:
	/* 整数型構造体 */
	struct IntegerArray
	{
		unsigned __int8 randm;  //乱数保存
		unsigned __int8 sort;   //ソート後保存

	}m_integer_array[ELEMENT];

	enum Step
	{
		STEP_INIT,    //初期化
		STEP_UPDATE,  //更新
		STEP_DRAW     //表示
	}m_step;

	unsigned __int8 transfer_box[100];  //初期化時に乱数を移し替えるよう
};


#endif