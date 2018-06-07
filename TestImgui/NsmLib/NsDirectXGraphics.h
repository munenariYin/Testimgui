#ifndef __NsDirectXGraphics_h__
#define __NsDirectXGraphics_h__

namespace NsmLib
{
	class NsDirectXGraphics
	{
	private:
		// DX11����IDirect3DDevice91�̊Ǘ�����AContext��Device�̓�Ŗ�����������ꂽ�B
		ID3D11Device*			devive;			// ���\�[�X�A�I�u�W�F�N�g�̐������s���BDirectX11�̒��S�ƂȂ�B
		ID3D11DeviceContext*	deviceContext;	// �����_�����O���Ǘ�

		// DXGI...DirectX Graphics Infrastructure...DirectX�`����
		IDXGIAdapter*			giAdapter;		// �f�B�X�v���C�T�u�V�X�e��
		IDXGIFactory*			giFactory;		// �t���X�N���[���؂�ւ��Ȃǂŗ��p����
		IDXGISwapChain*			giSwapChain;	// �E�B���h�E�ւ̕\���A�o�b�t�@�����O���Ɋւ���N���X�A�T���v�����O�A���t���b�V�����[�g(�`��X�V���x)�Ȃǂ�����
		DXGI_SWAP_CHAIN_DESC	giSwapChainDesc;// �X���b�v�`�F�[����ݒ肵���f�[�^���i�[����\����
	};

}

#endif