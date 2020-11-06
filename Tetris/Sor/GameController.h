#ifndef TETRIS_GAMECONTROLLER_H_
#define TETRIS_GAMECONTROLLER_H_
#include "Definition.h"
#include "Object/Stage.h"
#include "Tetris.h"

/**
*@clss   テトリス管理クラス
*@brief  各ゲームの処理を管理する
*/

class Tetris_GameController
{
public:
	Tetris_GameController();
	~Tetris_GameController();

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void Update();

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	bool GameEnd();

	/**
	 * @brief 解放処理関数
	 */
	void Delete();

private:
	Tetris* m_tetris[GAME_NUM];
};

#endif