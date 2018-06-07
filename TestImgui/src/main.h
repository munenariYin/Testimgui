#ifndef __MAIN_H__
#define __MAIN_H__

#include"..\ImguiLib\imgui.h"

class Main
{
private:
	Main()
	{
		m_hInst = nullptr;
		m_hWnd = nullptr;
		m_FrameCnt = 0;
		m_bWndActive = false;
	}
	// ウィンドウ関数
	static LRESULT CALLBACK callWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


public:
	static Main& GetInstance()
	{
		static Main instance;
		return instance;
	}
private:
	//=================================================
	// ウィンドウ関係
	//=================================================
	HINSTANCE		m_hInst;			// アプリケーションのインスタンスハンドル
	HWND			m_hWnd;				// ウィンドウハンドル
	DWORD			m_FrameCnt;			// 現在のフレーム値
	bool			m_bWndActive;		// ウィンドウがアクティブか？
};
#define MAIN Main::GetInstance()


#endif