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
	// �E�B���h�E�֐�
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
	// �E�B���h�E�֌W
	//=================================================
	HINSTANCE		m_hInst;			// �A�v���P�[�V�����̃C���X�^���X�n���h��
	HWND			m_hWnd;				// �E�B���h�E�n���h��
	DWORD			m_FrameCnt;			// ���݂̃t���[���l
	bool			m_bWndActive;		// �E�B���h�E���A�N�e�B�u���H
};
#define MAIN Main::GetInstance()


#endif