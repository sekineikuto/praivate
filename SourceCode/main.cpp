//*************************************************************************************************************
//
// �E�B���h�E�\������[man.icpp]
// Author:Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define CLASS_NAME		"WindowClass"								// �E�B���h�E�N���X�̖��O
#define WINDOW_NAME		"CyoTotu Mousin"			// �L���v�V����

//-------------------------------------------------------------------------------------------------------------
// �v���g�^�C�v�錾
//-------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void MeasurProcesTime(CManager *g_pManager, DWORD &dwCurrentTime, DWORD &dwFPSLastTime, DWORD &dwFrameCount);
void DispConsol();

//-------------------------------------------------------------------------------------------------------------
// �O���[�o���ϐ�
//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
//
// ���C���֐�
//
//-------------------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR lpCmdLine, int nCmdShow)
{
	// rand���V���b�t��
	srand((unsigned int)time(NULL));

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	//_CrtSetBreakAlloc(375);
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),				// WNDCLASSEX�̃������T�C�Y�̎w��
		CS_CLASSDC,						// �\������E�B���h�E�̃X�^�C����ݒ�
		WindowProc,						// �E�B���h�E�v���V�[�W���̃A�h���X�i�֐����j���w��
		0,								// �ʏ�͎g�p�͎g�p���Ȃ��̂�0�w��
		0,								// �ʏ�͎g�p�͎g�p���Ȃ��̂�0�w��
		hInstance,						// Windows�̈����̉@�X�^���h�n���h���w��
		LoadIcon(NULL,IDI_APPLICATION),	// �^�X�N�o�[�Ɏg�p����A�C�R���w��
		LoadCursor(NULL,IDC_ARROW),		// �g�p����}�E�X�J�[�\���w��
		(HBRUSH)(COLOR_WINDOW + 1),		// �E�B���h�E�N���C�A���g�̈�̐F�w��
		NULL,							// ���j���[���w��
		CLASS_NAME,						// �E�B���h�E�N���X�̖��O
		LoadIcon(NULL,IDI_APPLICATION)	// �������A�C�R���w��
	};

	// �R���\�[����ʂ̕\��
	DispConsol();

	HWND hWnd;							// �E�B���h�E�n���h���i���ʎq�j
	MSG  msg;							// ���b�Z�[�W���i�[����ϐ�
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	// �E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	// �w�肵���N���C�A���g�̈���m�ۂ��邽�߂ɕK�v�ȃE�B���h�E���W���v�Z
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);


	// �E�C���h�E���쐬
	hWnd = CreateWindowEx(0,		// �g���E�B���h�E�X�^�C��
		CLASS_NAME,					// �E�B���h�E�N���X��
		WINDOW_NAME,				// �E�B���h�E�̖��O
		WS_OVERLAPPEDWINDOW,		// �E�B���h�E�X�^�C��
		CW_USEDEFAULT,				// �E�B���h�E����X���W
		CW_USEDEFAULT,				// �E�B���h�E����Y���W
		(rect.right - rect.left),	// �E�B���h�E�̕�
		(rect.bottom - rect.top),	// �E�B���h�E�̍���
		NULL,						// �e�E�B���h�E�̃n���h��
		NULL,						// ���j���[�������͎q�E�B���h�E�̃n���h��
		hInstance,					// �C���X�^���X�n���h��
		NULL);						// �E�B���h�E�쐬�f�[�^

	DWORD dwCurrentTime = NULL;		// ���ݎ���
	DWORD dwExecLastTime = NULL;	// �Ō�ɏ�����������	
	DWORD dwFrameCount = NULL;		// �v���p����
	DWORD dwFPSLastTime = NULL;		// �ۑ��p����

	CManager *pManager = NULL;
	pManager = new CManager;

	// �����������i�E�B���h�E�̐�����ɍs���j
	if (FAILED(pManager->Init(hInstance, hWnd, TRUE)))
	{
		return -1;
	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);			// �w�肳�ꂽ�E�B���h�E�̕\���ݒ�
	UpdateWindow(hWnd);					// �E�B���h�E�̃N���C�A���g�̍X�V

	// ����\��ݒ�
	timeBeginPeriod(1);

	dwCurrentTime = 0;
	dwExecLastTime = timeGetTime();		// �V�X�e���������~���b�P�ʂŎ擾

	dwFrameCount = 0;
	dwFPSLastTime = timeGetTime();		// �V�X�e���������~���b�P�ʂŎ擾

	// ���b�Z�[�W���[�v�i���b�Z�[�W�h�L���[���烁�b�Z�[�W�h���擾
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)// ���b�Z�[�W���擾�����ꍇ��Ԃ�
		{// Window����
			if (msg.message == WM_QUIT)
			{//WM_QUIT���b�Z�[�W������ꂽ��I��
				break;
			}
			else
			{// ���b�Z�[�W�̖|��𑗏o
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{// DirectX�̏���
			// �V�X�e�����Ԃ̎擾����
			dwCurrentTime = timeGetTime();

			// �������Ԃ̌v��
			MeasurProcesTime(pManager, dwCurrentTime, dwFPSLastTime, dwFrameCount);

			// �������x�̐���
			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{
				// ��������������ۑ�
				dwExecLastTime = dwCurrentTime;

				// �X�V����
				pManager->Update();

				// �`�揈��
				pManager->Draw();

				// �t���[���J�E���g�̍X�V����
				dwFrameCount++;
			}
		}
	}
	// �I������
	pManager->Uninit();
	delete pManager;
	// �E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	// ����\��߂�
	timeEndPeriod(1);
	_CrtDumpMemoryLeaks();
	return (int)msg.wParam;
}

//-------------------------------------------------------------------------------------------------------------
// �E�B���h�E�v���V�[�W���֐�
//-------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:						// �E�B���h�E�j�����b�Z�[�W
		PostQuitMessage(0);					// ���b�Z�[�W��Ԃ�
		break;

	case WM_KEYDOWN:						//�L�[�������ꂽ�ۂ̃��b�Z�[�W
		// [ESC]�L�[�������ꂽ
		if (wParam == VK_ESCAPE) {
			//�E�B���h�E�̔j���iWM_DESTROY�𔭐��j
			DestroyWindow(hWnd);
		}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);	// ����̏������
}

//-------------------------------------------------------------------------------------------------------------
// �������x�̌v��
//-------------------------------------------------------------------------------------------------------------
void MeasurProcesTime(CManager * g_pManager, DWORD & dwCurrentTime, DWORD & dwFPSLastTime, DWORD & dwFrameCount)
{
	// �������Ԃ̌v��
	if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5�b���ƂɎ��s
	{
#ifdef _DEBUG
		// FPS�𑪒�
		g_pManager->SetFPS((dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime));
#endif
		dwFPSLastTime = dwCurrentTime;			// FPS�𑪒肵��������ۑ�
		dwFrameCount = 0;						// �J�E���g���N���A
	}
}

//-------------------------------------------------------------------------------------------------------------
// �R���\�[����ʂ̕\��
//-------------------------------------------------------------------------------------------------------------
void DispConsol()
{
#ifdef _DEBUG
	AllocConsole();

	FILE *fp = NULL;

	freopen_s(&fp, "CONOUT$", "w", stdout);

	std::cout << std::fixed;
#endif
}
