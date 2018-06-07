#ifndef __NsDirectXGraphics_h__
#define __NsDirectXGraphics_h__

namespace NsmLib
{
	class NsDirectXGraphics
	{
	private:
		// DX11からIDirect3DDevice91つの管理から、ContextとDeviceの二つで役割が分けられた。
		ID3D11Device*			devive;			// リソース、オブジェクトの生成を行う。DirectX11の中心となる。
		ID3D11DeviceContext*	deviceContext;	// レンダリングを管理

		// DXGI...DirectX Graphics Infrastructure...DirectX描画基盤
		IDXGIAdapter*			giAdapter;		// ディスプレイサブシステム
		IDXGIFactory*			giFactory;		// フルスクリーン切り替えなどで利用する
		IDXGISwapChain*			giSwapChain;	// ウィンドウへの表示、バッファリング等に関するクラス、サンプリング、リフレッシュレート(描画更新速度)なども扱う
		DXGI_SWAP_CHAIN_DESC	giSwapChainDesc;// スワップチェーンを設定したデータを格納する構造体
	};

}

#endif