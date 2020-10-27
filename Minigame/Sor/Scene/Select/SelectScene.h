#ifndef SELECT_SCENE_H_
#define SELECT_SCENE_H_
#include "../SceneBase.h"
#include <string>
/**
*@clss   選択シーンクラス
*@brief  選択シーンでの処理を行う
*/

class SelectScene :public SceneBase
{
public:
	SelectScene();
	~SelectScene() {}

	/**
	 * @brief  初期化関数(繰り返し)
	 * @detail メンバ変数の初期化
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	 */
	virtual void Reset()override;

	/**
	 * @brief  各ゲーム管理処理関数
	 * @detail 各ゲーム管理クラスの更新処理を行う
	 */
	virtual void GameControllerUpdate()override;

	/**
	 * @brief  描画情報送信関数関数
	 * @detail 各ゲーム(または選択シーン)の描画情報を描画クラスに送る
	 */
	virtual void SetUpDrawBuffer()override;

	/**
   　* @brief  矢印更新関数
	 * @detail 矢印キー移動の処理
   　*/
	void ArrowUpdate();

	/**
     * @brief  シーン切り替え判定関数
     * @detail 決定キーを押された時の処理を行う
     */
	virtual void ChangeState()override;

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲーム(またはプロジェクト)を終了する
	 */
	virtual bool GameEnd()override;


private:
	Vec2 m_select_arrow;   //!矢印座標

	__int8 m_now_select;   //!現在矢印が示すゲームの位置用

	std::string m_select_font;  //!矢印
	std::string m_none_font;    //!空白

	std::string m_game_nmae[Game_Num];  //!各ゲーム名

	std::string m_draw_font;   //!文字連結用
};

#endif