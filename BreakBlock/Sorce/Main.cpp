#include "../Header/Definition.h"


int main()
{	
	/* 描画用クラスのみここで初期化 */
	g_drawer.Init();

	while (true)
	{
		/* 各オブジェクトStepChange */
		g_bar.Update();
		g_ball .Update();
		g_blockarray.Update();


		//* Bufferの中身をクリア */
		g_drawer.BufferClear();

		/* Drawer処理 */
		g_blockarray.SetUpDrawBuufer();   //Blockを追加
		g_bar.SetUpDrawBuffer();          //Barを追加
		g_ball.SetDrawBuffer();           //Ballを追加


		/* 表示 */
		g_drawer.Draw();

		getchar();

		/* Ballが下に落ちたとき終了(現在動作確認中のため止まらない) */
		if (g_ball.GetHiter().m_out == true)
		{
			break;
		}

		/* 毎回表示が下に行かないようにしている */
		system("cls");
	}
	return 0;
}