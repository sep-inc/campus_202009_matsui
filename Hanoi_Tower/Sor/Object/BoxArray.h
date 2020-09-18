#ifndef BOXARRAY_H_
#define BOXARRAY_H_
#include "Box.h"
#include "../Vec.h"

class BoxArray
{
public:
	BoxArray():m_end(false) {}
	~BoxArray() {}

    void StepChange();        //ステップ処理
    void Init();              //初期化
    void Search();            //検索処理
   
    unsigned __int8 SearchBox(unsigned __int8 pos_x_);            //調査用Box調査処理
    unsigned __int8 SearchPos_X(unsigned __int8 number_);         //調べるBoxの基準座標更新
    unsigned __int8 SetDiskPos_Y();                               //Boxの中の一番上の座標を返す

    bool SearchRightBox();                                        //円盤が3つあるか調べる処理(終了フラグ)

     //Diskを動かせるかどうかのフラグ処理                                                             
    bool SearchMoveDiskSize(unsigned __int8 disk_width, unsigned __int8 now_number_, unsigned __int8 next_number_);  

    void SetUpDisk(Vec pos, unsigned  __int8 width_, unsigned  __int8 height_);      //diskを調査用box座標にセット
    void SetUpDrawBuffer();                                                          //描画配列にオブジェクトセット

    void ClearBoxBuffer();                                                //調査用boxの中身クリア

    unsigned  __int8 GetNextDiskPos() { return m_now_investigation_pos; } //移す箱のposを返す 
    unsigned  __int8 GetDiskPos_Y() { return m_pos_y; }                   //Diskを置ける高さを返す
    bool GetEndFlg() { return m_end; }                   //Diskを置ける高さを返す


private:
    enum Step
    {
        STEP_INIT,       //初期化
        STEP_SEARCH     //検索
    }m_step;

    Box m_box[3];   //箱単体

    unsigned __int8 m_box_buffer[6][19];  //箱の中身検索用
    unsigned __int8 m_pos_y;

    unsigned  __int8 m_disk_counter;            //箱の中身を調べたときDiskの数
    unsigned  __int8 m_now_investigation_pos;   //移動元調査用箱pos
    unsigned  __int8 m_next_investigation_pos;  //移動先調査用箱pos

    bool m_end;   //終了フラグ

};


#endif 