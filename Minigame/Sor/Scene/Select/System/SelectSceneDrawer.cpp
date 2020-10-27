#include "SelectSceneDrawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

//!クリア関数
void SelectSceneDrawer::SetUpFont(std::string font_)
{
	m_draw_font.push_back(font_);
}

//!描画関数
void SelectSceneDrawer::Draw()
{
	for (unsigned int i = 0; i < m_draw_font.size(); i++)
	{
		printf("%s", m_draw_font[i].c_str());  //!表示
		printf("\n");  //!表示

	}
}

//!描画配列クリア関数
void SelectSceneDrawer::Clear()
{
	m_draw_font.clear();

	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
}

