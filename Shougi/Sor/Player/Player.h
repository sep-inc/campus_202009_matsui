#ifndef PLAYER_H_
#define PLAYER_H_
#include "../Vec.h"
#include "../Object/Piece.h"
#include "../Object/Piece_Ou.h"
#include "../Object/Piece_Keima.h"
#include "../Object/Piece_Kin.h"
#include "../Object/Piece_Hu.h"
#include "../Object/Bord.h"
#include "../Definition.h"
class Player
{
public:
	Player(PLAYER_TYPE player_type_):m_my_player_type(player_type_){}
	~Player() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init();

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void Update(Bord* bord_);

	/**
   　* @brief  入力関数
	 * @detail 移動元と移動先を入力する
   　*/
	void Input(Bord* bord_);


	/**
　   * @brief  入力関数
     * @detail 移動元と移動先を入力する
　   */
	bool NextMoveInput(Bord* bord_);

	/**
   　* @brief  移動関数
	 * @detail 移動先をもとに駒を移動させる
   　*/
	void Move(Bord* bord_);

	/**
	 * @brief  移動駒表示関数
	 * @param (piece_) 先手か後手
	 * @param (piece_type_) 駒の種類
	 * @detail 現在動かそうとしている駒の表示
	 */
	void NowMovePiece(OBJECT_TYPE piece_type_);

	void SearchBord(Bord* bord_);

	/**
	* @brief  勝敗判定関数
	* @detail 盤クラスからの結果をもとにGameControllerにフラグを返す
	*/
	bool Judgment(Bord* bord_);

	/**
	* @brief  解放関数
	*/
	void Delete();
protected:
	const PLAYER_TYPE m_my_player_type;   //!プレイヤーの種類保存用

	PieceOu* m_piece_ou;
	PieceKeima* m_piece_keima;
	PieceKin* m_piece_kin;
	PieceHu* m_piece_hu;


	OBJECT_TYPE m_piece_type;    //!駒の種類保存用
	PLAYER_TYPE m_player_type;   //!プレイヤーの種類保存用

	Vec m_now_pos;    //!動かす駒の座標保存用
	Vec m_next_pos;   //!動かす場所保存用
};


#endif