﻿// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#pragma once
#include "framework.h"
#include "Editor_Window.h"
#include "..\\SO_SOURCE\soApplication.h"

#include "..\\SO_SOURCE\\Resources.h"
#include "..\\SO_SOURCE\\Texture.h"
#include "..\\SO_SOURCE\\SceneManager.h"

#include "..\\SOEngine_Window\\LoadScene.h"
#include "..\\SOEngine_Window\\LoadResources.h"
#include "..\\SOEngine_Window\\ToolScene.h"

//#pragma comment(lib,"..\\x64\\Debug\\SOEngine_Window.lib")
#define MAX_LOADSTRING 100
so::Application app;
ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;
#define MAX_LOADSTRING 100


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK    WndTileProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(251);
    // TODO: 여기에 코드를 입력합니다.
    //깃허브 테스트
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance, szWindowClass, WndProc);
    MyRegisterClass(hInstance, L"TILEWINDOW", WndTileProc);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;
    //GetMessage
    // 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
    // 메세지큐에 아무것도 없으면 아무 메세지도 가져오지 않는다.
    // 
    // PeekMessage : 메세지큐에 메세지 유무에 상관없이 함수가 리턴된다.
    //               리턴 값이 true인 경우 메세지가 있고 false인 경우는 메세지가 없다라고 가르켜준다.
    // 
    // 
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else {
            //메세지가 없을 경우 여기서 처리
            //게임 로직이 들어가면 된다.
            app.Run();
        }
    }
    // 기본 메시지 루프입니다:
 /*   while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/




    Gdiplus::GdiplusShutdown(gpToken);
    app.Release();
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = proc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = name;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
 /*  const UINT width = 1032;
   const UINT height = 404.0f;*/
   const UINT width = 672;
   const UINT height = 846;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);

   HWND ToolhWnd = CreateWindowW(L"TILEWINDOW", L"TileWindow", WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);

   app.Initialize(hWnd, width, height);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   //ShowWindow(ToolhWnd, nCmdShow);
   //UpdateWindow(ToolhWnd);

   Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);
   //load Scene
   so::LoadResources();
   so::LoadScene();

   int a = 0;
   srand((unsigned int)(&a));

   so::Scene* activeScene = so::SceneManager::GetActiveScene();

   std::wstring name = activeScene->GetName();
   if (name == L"ToolScene") {
       //Tile윈도운 크기 조정
       so::graphics::Texture* texture
           = so::Resources::Find<so::graphics::Texture>(L"SpringFloor");

       RECT rect = { 0,0,texture->GetWidth(), texture->GetHeight() };
       AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

       UINT toolWidth = rect.right - rect.left;
       UINT toolHeight = rect.bottom - rect.top;

       SetWindowPos(ToolhWnd, nullptr, 0, 0, toolWidth, toolHeight, 0);
       ShowWindow(ToolhWnd, true);
       UpdateWindow(ToolhWnd);
   }

 

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
//메세지 함수 처리 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //DC란 화면에 출력에 필요한 모든 정보를 가지는 데이터 구조체이며
            // //gui모듈에 의해서 관리된다.
            // 어떤 폰트를 사용할건가? 어떤 선의 굵기를 정해줄건가...
            // 화면출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업을 진행할 수 있다.
            // 
           /* HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
            Rectangle(hdc, 100, 100, 200, 200);
            (HBRUSH)SelectObject(hdc, oldBrush);
            Ellipse(hdc, 200, 200, 300, 300);
            DeleteObject(brush);*/

            //기본적으로 자주사용되는 GDI오브젝트를 미리 DC안에 만들어두었는데
            //그 오브젝트들을 스톡 오브젝트라고 한다.


            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
//LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_COMMAND:
//    {
//        int wmId = LOWORD(wParam);
//        // 메뉴 선택을 구문 분석합니다:
//        switch (wmId)
//        {
//        case IDM_ABOUT:
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//            break;
//        case IDM_EXIT:
//            DestroyWindow(hWnd);
//            break;
//        default:
//            return DefWindowProc(hWnd, message, wParam, lParam);
//        }
//    }
//    break;
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hWnd, &ps);
//
//        EndPaint(hWnd, &ps);
//    }
//    break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
