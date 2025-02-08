/* APP ENTRY POINT
=====================================================================
$File : $
$Date: $
$Revision: $
$Creator: smpl
=====================================================================
*/

#include <float.h>
#include <windows.h>
#include <wingdi.h>
#include <winuser.h>

//-------------------------------------------------------------------
// GLOBAL VARIABLES
//-------------------------------------------------------------------
HINSTANCE global_hInstance;
// CHAR szTitle[MAX_LOADSTRING];       // The title bar text
// CHAR szWindowClass[MAX_LOADSTRING]; // The main window class name
char win_title[100];
char win_class[100];

//-------------------------------------------------------------------
// FORWARD DECLARATIONS
//-------------------------------------------------------------------
ATOM RegisterHandmadeHeroWindowClass(HINSTANCE);
LRESULT CALLBACK MainWindowCallbackProcedure(HWND, UINT, WPARAM, LPARAM);
BOOL InitializeWindowInstance(HINSTANCE, int);

//-------------------------------------------------------------------
// APP ENTRY POINT
//-------------------------------------------------------------------
int APIENTRY wWinMain(_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PrevInstance,
                      _In_ LPWSTR CommandLine, _In_ int ShowCommand) {
  // 0. Initialize Global Variables
  // must use same class & same title, for registering & creating new windows
  strcpy_s(win_title, "HandMadeHero");
  strcpy_s(win_class, "HandMadeHero");

  // 1. Register the Window Class
  RegisterHandmadeHeroWindowClass(Instance);

  // 2. Create the main Window
  if (!InitializeWindowInstance(Instance, ShowCommand)) {
    return FALSE;
  }

  // 3. Main message loop:
  MSG Message;
  HACCEL hAccelTable = LoadAccelerators(Instance, MAKEINTRESOURCE(109));
  OutputDebugStringA("hello once\n");
  while (GetMessage(&Message, 0, 0, 0)) {
    if (!TranslateAccelerator(Message.hwnd, hAccelTable, &Message)) {
      OutputDebugStringA("hello twice\n");
      TranslateMessage(&Message);
      DispatchMessage(&Message);
    }
  }

  return 0;
}

//----------------------------------------------------------------------
//   2.1:
//   FUNCTION: InitInstance(HINSTANCE, int)
//   PURPOSE: Saves instance handle and creates main window
//   COMMENTS:
//        - In this fn, we save the instance handle in a global variable
//        - create and display the main program window.
//----------------------------------------------------------------------
BOOL InitializeWindowInstance(HINSTANCE Instance, int ShowCommand) {
  global_hInstance = Instance; // store in global variable

  // Create a main window, and get the handle to this window
  // HWND WindowHandle = CreateWindowEx(
  //    0, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
  //    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0,
  //    Instance, 0);
  HWND WindowHandle = CreateWindowEx(
      0, win_class, win_title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);

  /*
  HWND WindowHandle = CreateWindowExA(
      0, "asdfjk", "asldfjk", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
  CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0,
  Instance, 0);
  // HWND WindowHandle = CreateWindow( "askdfja", "asldfjk",
  WS_OVERLAPPEDWINDOW
  // | WS_VISIBLE, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr,
  // Instance, nullptr);
  */

  if (!WindowHandle) {
    DWORD error = GetLastError();
    char errorMsg[256];
    wsprintf(errorMsg, "CreateWindowEx failed with error: %lu\n", error);
    OutputDebugStringA(errorMsg);
    return FALSE;
  }

  ////  added new, but we using WS_VISIBLE so it should be fine
  // ShowWindow(WindowHandle, ShowCommand);
  //  UpdateWindow(WindowHandle);

  return TRUE;
}

// 1.1
ATOM RegisterHandmadeHeroWindowClass(HINSTANCE hInst) {
  // Window class for the main window
  // WNDCLASSEXW WindowClass = {0};  // for WNDCLASSEXW
  WNDCLASS WindowClass = {0};
  WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
  WindowClass.lpfnWndProc = MainWindowCallbackProcedure;
  WindowClass.hInstance = hInst;
  // WindowClass.lpszClassName = L"HandmadeHeroWindowClass";  // for WNDCLASSEXW
  WindowClass.lpszClassName = win_class;
  // WindowClass.lpszClassName = "HandmadeHeroWindowClass";

  // return RegisterClassExW(&WindowClass);  // for WNDCLASSEXW
  return RegisterClass(&WindowClass);
}

// 1.2
LRESULT CALLBACK MainWindowCallbackProcedure(HWND Window, UINT Message,
                                             WPARAM WParam, LPARAM LParam) {
  LRESULT result = 0;
  // Handle all the messages that Windows Sends to the window
  switch (Message) {
  case WM_SIZE: {
    OutputDebugStringA("WM_SIZE");
  } break;
  case WM_DESTROY: {
    OutputDebugStringA("WM_DESTROY");
  } break;
  case WM_CLOSE: {
    OutputDebugStringA("WM_CLOSE");
    DestroyWindow(Window);
    exit(0);
  } break;
  case WM_ACTIVATEAPP: {
    OutputDebugStringA("WM_ACTIVATEAPP");
  } break;
  case WM_PAINT: {
    PAINTSTRUCT Paint;
    HDC DeviceContext = BeginPaint(Window, &Paint);
    int X = Paint.rcPaint.left;
    int Y = Paint.rcPaint.top;
    LONG Width = Paint.rcPaint.right - Paint.rcPaint.left;
    LONG Height = Paint.rcPaint.bottom - Paint.rcPaint.top;

    // PatBlt(DeviceContext, X, Y, Width, Height, WHITENESS);

    HBRUSH hPurpleBrush = CreateSolidBrush(0x00800080L); // L for DWORD
    HGDIOBJ holdBrush = SelectObject(DeviceContext, hPurpleBrush);
    PatBlt(DeviceContext, X, Y, Width, Height, PATCOPY);
    SelectObject(DeviceContext, holdBrush); // restore old brush
    DeleteObject(hPurpleBrush);             // clean up purple brush

    EndPaint(Window, &Paint);
  } break;
  default: {
    // Other unhandled Messages will be passed to WindowsOS to handle
    result = DefWindowProc(Window, Message, WParam, LParam);
  } break;
  };

  return result;
};
