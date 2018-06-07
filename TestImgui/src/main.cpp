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
	//メッセージによって処理を選択
	switch (message) {
	case WM_ACTIVATE:
	{
		// 非アクティブ
		if (LOWORD(wParam) == WA_INACTIVE) {
			m_bWndActive = false;
		}
		// アクティブ
		else {
			m_bWndActive = true;
		}
	}
	break;
	// ホイールスクロール時
	case WM_MOUSEWHEEL:
	{

		S_INPUT.SetMouseWheelValue((short)HIWORD(wParam));
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//不要なメッセージの後始末
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
