#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"
/**
 *@clss   駒クラス
 *@brief  プレイヤー、敵の駒情報を持つ
 */

#define HU_NUM 4 //!1プレイヤーの持つ歩の数

class Piece
{
public:
	Piece() :m_step(STEP_INIT), m_win_first(false), m_win_second(false) {}
	~Piece() {}

	/**
     * @brief  ステップ処理関数
     * @detail ステップ変更処理
     */
	void StepChange();   
	
    /**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init();  

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void Update();

	/**
	* @brief  移動範囲初期化関数
	* @detail 移動範囲配列の初期化
	*/
	virtual void InitMove();

	
	/**
	 * @brief  描画座標代入関数
	 * @detail 駒座標を描画座標に代入
	 */
	virtual void SetUpDrawBuffer();
	
	/**
	 * @brief  配置関数まとめ
	 * @detail 先手、後手の配置処理をステップで分ける
	 */
	void Put();         

	/**
	 * @brief  配置関数
	 * @param (piece_) 先手か後手
	 */
	void PutPiece(Piece* piece_);

	/**
	 * @brief 「歩」の検索関数
	 * @param (piece_) 先手か後手
	 * @detail 盤にある「歩」の中から選んだものを検索する関数
	 */
	int SearchHuPiece(Piece* piece_);

	/**
	 * @brief  盤上配列更新関数まとめ
	 * @param (piece_) 先手か後手
	 * @detail 先手、後手の駒情報を盤上配列に送る
	 */
	void SetPiece(Piece* piece_);
	
	/**
	 * @brief  駒消去検索関数まとめ
	 */
	void DeleteSearchPiece();


	/**
	 * @brief  駒消去検索関数
	 * @param (piece_) 先手が動かす番なら先手が入る
	 * @param (piece_) 先手が動かす番なら後手が入る
	 * @detail 消去する駒を検索する
	 */
	void DeleteSearchPiece(Piece* piece_, Piece* piece2_);

	/**
	 * @brief  移動判定
	 * @param (piece_) 先手か後手
	 * @param (pos) 駒の移動範囲配列の基準座標
	 * @param (input_pos_) 移動先の座標
	 * @param (piece_type_) 駒の種類
	 * @detail 先手、後手の選んだ駒が移動できるか判定
	 */
	bool SearchMove(Piece* piece_, Vec pos, Vec input_pos_, __int8 piece_type_);

	

	/**
	 * @brief  移動駒表示関数
	 * @param (first_) 先手
	 * @param (second_) 後手
	 * @detail 王がとられているかどうか
	 */
	void EndGame(Piece* first_, Piece* second_);

	/**
	 * @brief  駒情報リセット関数
	 * @detail ゲームを続ける場合駒情報を初期化する関数
	 */
	void ResetPiece();
	
	bool GetFirstWin() { return m_win_first; }
	bool GetSecondWin() { return m_win_second; }

protected:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,
		STEP_FIRST_PUT,
		STEP_SECOND_PUT
	}m_step;

	//!駒情報
	struct PieceInfo
	{
		//!座標
		Vec m_ou_pos;     //!王
		Vec m_kei_pos;	  //!桂
		Vec m_kin_pos;	  //!金
		Vec m_hu_pos[4];  //!歩

		//!表示フラグ
		bool m_ou_display;       //!王
		bool m_kei_display;		 //!桂
		bool m_kin_display;		 //!金
		bool m_hu_display[4];	 //!歩

		//!移動範囲配列
		__int8 m_ou_move[3][3];  //!王
		__int8 m_kei_move[3][3]; //!桂
		__int8 m_kin_move[3][3]; //!金
		__int8 m_hu_move[2][1];	 //!歩

		//!移動範囲配列の基準座標
		Vec m_ou_move_center;    //!王
		Vec m_kei_move_center;	 //!桂
		Vec m_kin_move_center;	 //!金
		Vec m_hu_move_center;	 //!歩
	};

	PieceInfo m_piece_info; 

	Piece* m_first;   //!先手
	Piece* m_second;  //!後手

	__int8 m_player;  //!プレイヤー判別用変数(先手は0,後手は1)

	__int8 m_hu_number;  //!「歩」の種類判別用

	Vec m_next_pos;      //!移動先座標保存用
	Vec m_delete_pos;    //!消去座標保存用

	bool m_win_first; //!先手勝利フラグ
	bool m_win_second; //!後手勝利フラグ
public:
	PieceInfo* GetPieceInfo() { return &m_piece_info; }
};


#endif