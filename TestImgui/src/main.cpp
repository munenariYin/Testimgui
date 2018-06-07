#include <windows.h>
#include"main.h"
#include"Input\Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	ImGuiWindowFlags window_flags;
	window_flags = false;
	ImGui::Begin("Stats", nullptr, window_flags);
	ImGui::LabelText("", "FPS:%4.2f (%4.2f ms)", s_Fps);
	//ImGui::LabelText("", "Camera Pos:(%.2f, %.2f, %.2f )", cameraPosition.x, cameraPosition.y, cameraPosition.z);
	ImGui::Spacing();
	ImGui::SetNextTreeNodeOpen(true, ImGuiSetCond_Once);
	if (ImGui::CollapsingHeader("PostEffect"))
	{
		if (ImGui::TreeNode("Tonemap"))
		{
			ImGui::SliderFloat("Gamma", &pfxDesc.Tonemap.Gamma, 0.0f, 4.0f);
			// ...
			ImGui::TreePop();
		}
		// ...
		ImGui::TreePop();
	}
	//...
	ImGui::End();

	ImGui::Render();


	return 0;
}


LRESULT CALLBACK Main::callWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return MAIN.WindowProc(hWnd, message, wParam, lParam);
}

LRESULT Main::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//���b�Z�[�W�ɂ���ď�����I��
	switch (message) {
	case WM_ACTIVATE:
	{
		// ��A�N�e�B�u
		if (LOWORD(wParam) == WA_INACTIVE) {
			m_bWndActive = false;
		}
		// �A�N�e�B�u
		else {
			m_bWndActive = true;
		}
	}
	break;
	// �z�C�[���X�N���[����
	case WM_MOUSEWHEEL:
	{

		S_INPUT.SetMouseWheelValue((short)HIWORD(wParam));
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//�s�v�ȃ��b�Z�[�W�̌�n��
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
