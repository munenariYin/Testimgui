#ifndef Input_h
#define Input_h

//===========================================================
//
// �L�[�{�[�h��}�E�X�̓��͂Ȃǂ��Ǘ�����
//
//===========================================================
class Input
{
public:
	//===============================
	// ����
	//===============================
	// �萔
	// �}�E�X�{�^���ԍ�
	enum MOUSEBUTTON{
		MOUSE_L = 0,
		MOUSE_R = 1,
		MOUSE_M = 2
	};
	// �L�[�t���O
	enum KEYFLAG{
		KEY_Enter	= 1,		// �������u��
		KEY_Stay	= 2,		// �����Ă���
		KEY_Exit	= 4			// �������u��
	};

//===============================
// �L�[�{�[�h
//===============================
public:
	void UpdateKey();		// ���z�L�[�̏�Ԃ��擾���AKey���X�V�B

	// �L�[�{�[�h����
	// KeyNo	�c ���肷��L�[�R�[�h
	// flag		�c �ǂ̃^�C�~���O�Ŕ��肷�邩
	//   �EKEY_Stay		�c �����Ă����
	//   �EKEY_Enter	�c �������ŏ���1��ڂ̂�
	//   �EKEY_Exit		�c �������ŏ���1��ڂ̂�
	bool KeyCheck(unsigned char KeyNo, KEYFLAG flag = KEY_Stay)
	{
		if(m_Key[KeyNo] & flag)return true;
		return false;
	}

	// �L�[�{�[�h����(�������ŏ���1��ڂ̂�)
	// KeyNo	�c ���肷��L�[�R�[�h
	bool KeyCheck_Enter(unsigned char KeyNo)
	{
		return KeyCheck(KeyNo, KEY_Enter);
	}

	// �L�[�{�[�h����(�������ŏ���1��ڂ̂�)
	// KeyNo	�c ���肷��L�[�R�[�h
	bool KeyCheck_Exit(unsigned char KeyNo)
	{
		return KeyCheck(KeyNo, KEY_Exit);
	}
private:
	BYTE	m_KeyBuffer[256];	// �L�[�o�b�t�@
	DWORD	m_Key[256];			// �L�[�{�[�h�p�t���O


//===============================
// �}�E�X
//===============================
public:
	// FPS�Q�[���p�}�E�X���[�h
	//  �}�E�X��\���A���W�Œ��m_MouseMoveValue(getMouseMoveValue�֐�)�Ɉړ��ʂ�����
	void SetFPSMode(HWND hWnd, bool enable);

	// �}�E�X�f�[�^�X�V
	void UpdateMouseData(HWND hWnd);

	// �}�E�X�{�^������
	// button	�c ���肷��}�E�X�{�^�� MOUSE_? �Ŏw��
	// flag		�c �ǂ̃^�C�~���O�Ŕ��肷�邩
	//   �EKEY_Stay		�c �����Ă����
	//   �EKEY_Enter	�c �������ŏ���1��ڂ̂�
	//   �EKEY_Exit		�c �������ŏ���1��ڂ̂�
	bool MouseCheck(MOUSEBUTTON button, KEYFLAG flag = KEY_Stay)
	{
		BYTE MouseButton[3] = { VK_LBUTTON, VK_RBUTTON, VK_MBUTTON };
		return KeyCheck(MouseButton[button], flag);
	}
	bool MouseCheck_Enter(MOUSEBUTTON button)
	{
		return MouseCheck(button, KEY_Enter);
	}
	bool MouseCheck_Exit(MOUSEBUTTON button)
	{
		return MouseCheck(button, KEY_Exit);
	}

	// �}�E�X�z�C�[���X�N���[���l�ݒ�
	void	SetMouseWheelValue(int Val){m_MouseWheel = Val;}

	// FPS�}�E�X���샂�[�h��ON/OFF�擾
	bool	GetMouseFPSMode() { return m_MouseFPSMode; }
	// �}�E�X���W
	const POINT&	GetMousePos(){return m_MousePos;}
	// �P�O�̃}�E�X���W
	const POINT&	GetMouseOldPos(){return m_MouseOldPos;}
	// �}�E�X���������l(�s�N�Z��)
	const POINT&	GetMouseMoveValue(){return m_MouseMoveValue;}
	// �z�C�[���𓮂������l
	int		GetMouseWheel(){return m_MouseWheel;}

private:
	// Mouse
	POINT	m_MousePos;						// �}�E�X���W
	POINT	m_MouseOldPos;					// �P�O�̃}�E�X���W
	POINT	m_MouseDown[3];					// �}�E�X���������ʒu
	int		m_MouseWheel;					// �z�C�[���𓮂������l
	POINT	m_MouseMoveValue;				// �}�E�X���������l
	bool	m_MouseFPSMode = false;

//------------------------------------------------------------------
// �V���O���g��
private:
	Input();
public:
	static Input& GetInstance()
	{
		static Input instance;
		return instance;
	}
//------------------------------------------------------------------
};

#define S_INPUT Input::GetInstance()

#endif