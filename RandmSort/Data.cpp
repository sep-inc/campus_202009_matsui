#include "Data.h"
#include <string.h>
#include <stdio.h>
#include <random>
#include <time.h>

/* ステップ処理 */
void Data::StepChange()
{
	switch (m_step)
	{
	case STEP_INIT:       //初期化
		Init();
	case STEP_UPDATE:    //更新
		Update();
	case STEP_DRAW:      //描画
		Draw();
	default:
		break;
	}
}

/* 初期化 */
void Data::Init()
{
	/* 配列の中身を0初期化 */
	memset(&m_integer_array, 0, sizeof(m_integer_array));

	/* 乱数抽出配列初期化 */
	for (int i = 0; i < 100; i++)
	{
		transfer_box[i] = i;   //0～99
	}

	/* テーブル初期化 */
	srand((unsigned)time(NULL));

	/* 次のステップへ */
	m_step = STEP_UPDATE;
}

/* 更新 */
void Data::Update()
{
	for (__int8 i = 0; i < ELEMENT; i++)
	{
		m_integer_array[i].randm = RandmNumber();                        //乱数代入
		m_integer_array[i].sort = CopyArray(m_integer_array[i].randm);   //乱数配列をソート用配列にコピー
	}
	
	SortArray();      //ソート配列を昇順で並び替える

	/* 次のステップへ */
	m_step = STEP_DRAW;
}

/* 乱数代入関数 */
__int8 Data::RandmNumber()
{

	__int8 array_ = 0;  //保存用

	/* 乱数を代入 */
	array_ = rand() % 100;

	for (int i = 0; i < 100; i++)
	{
		/* 同じ数が見つかればその数を返す */
		if (transfer_box[i] == array_)
		{
			transfer_box[i] = -1;   //取り出した数は被らないように-1にする
			return array_;
		}
	}
}


/* 乱数配列コピー関数 */
__int8 Data::CopyArray(__int8 copy_array_)
{
	__int8 array_ = 0;    //保存用

	/* 乱数配列をソート用配列にコピー */
	array_ = copy_array_;

	return array_;
}

/* ソート配列ソート関数 */
void Data::SortArray()
{
	__int8 save_number = 0;  //入れ替え保存用

	for (__int8 i = 0; i < ELEMENT; i++)
	{
		for (__int8 j = i + 1; j < ELEMENT; j++)
		{
			/* 現在の要素の中身が次の要素の数より小さい場合 */
			if (m_integer_array[i].sort < m_integer_array[j].sort)
			{
				/* 入れ替え */
				save_number = m_integer_array[i].sort;
				m_integer_array[i].sort = m_integer_array[j].sort;
				m_integer_array[j].sort = save_number;
			}
		}
	}

}

/* 表示 */
void Data::Draw()
{
	printf("乱数表示\n");
	for (__int8 i = 0; i < ELEMENT; i++)
	{	
		printf("%d,", m_integer_array[i].randm);
	}

	getchar();

	printf("ソート後\n");

	for (__int8 i = 0; i < ELEMENT; i++)
	{
		printf("%d,", m_integer_array[i].sort);
	}
	printf("\n\n");
	
}
