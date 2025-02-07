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

#define MAX_LOADSTRING 100

//-------------------------------------------------------------------
// GLOBAL VARIABLES
//-------------------------------------------------------------------
HINSTANCE global_hInstance;
CHAR szTitle[MAX_LOADSTRING];       // The title bar text
CHAR szWindowClass[MAX_LOADSTRING]; // The main window class name
// WCHAR szTitle[MAX_LOADSTRING];  // The title bar text
//  WCHAR szWindowClass[MAX_LOADSTRING];  // The main window class name

//-------------------------------------------------------------------
// FORWARD DECLARATIONS
//-------------------------------------------------------------------
ATOM RegisterHandmadeHeroWindowClass(HINSTANCE);
BOOL InitializeWindowInstance(HINSTANCE, int);
LRESULT CALLBACK MainWindowCallbackProcedure(HWND, UINT, WPARAM, LPARAM);

//-------------------------------------------------------------------
// APP ENTRY POINT
//-------------------------------------------------------------------
int APIENTRY wWinMain(_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PrevInstance,
                      _In_ LPWSTR CommandLine, _In_ int ShowCommand) {
  // Initialize Global Strings
  LoadString(Instance, 103, szWindowClass, MAX_LOADSTRING);
  LoadString(Instance, 109, szWindowClass, MAX_LOADSTRING);

  RegisterHandmadeHeroWindowClass(Instance);

  // Perform Application Initialization
  if (!InitializeWindowInstance(Instance, ShowCommand))
    return FALSE;

  // Main message loop:
  MSG Message;
  HACCEL hAccelTable = LoadAccelerators(Instance, MAKEINTRESOURCE(109));
  OutputDebugStringA("hello once\n");
  while (GetMessage(&Message, nullptr, 0, 0)) {
    if (!TranslateAccelerator(Message.hwnd, hAccelTable, &Message)) {
      OutputDebugStringA("hello twice\n");
      TranslateMessage(&Message);
      DispatchMessage(&Message);
    }
  }

  return 0;
}

ATOM RegisterHandmadeHeroWindowClass(HINSTANCE hInst) {
  // Window class for the main window
  // WNDCLASSEXW WindowClass = {0};  // for WNDCLASSEXW
  WNDCLASS WindowClass = {0};
  WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
  WindowClass.lpfnWndProc = MainWindowCallbackProcedure;
  WindowClass.hInstance = hInst;
  // WindowClass.lpszClassName = L"HandmadeHeroWindowClass";  // for WNDCLASSEXW
  WindowClass.lpszClassName = szWindowClass;
  // WindowClass.lpszClassName = "HandmadeHeroWindowClass";

  // return RegisterClassExW(&WindowClass);  // for WNDCLASSEXW
  return RegisterClass(&WindowClass);
}

//----------------------------------------------------------------------
//   FUNCTION: InitInstance(HINSTANCE, int)
//   PURPOSE: Saves instance handle and creates main window
//   COMMENTS:
//        - In this fn, we save the instance handle in a global variable
//        - create and display the main program window.
//----------------------------------------------------------------------
BOOL InitializeWindowInstance(HINSTANCE Instance, int ShowCommand) {
  global_hInstance = Instance; // store in global variable

  HWND WindowHandle = CreateWindowExA(
      0, "asdfjk", "asldfjk", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);
  // HWND WindowHandle = CreateWindow( "askdfja", "asldfjk", WS_OVERLAPPEDWINDOW
  // | WS_VISIBLE, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr,
  // Instance, nullptr);

  if (!WindowHandle) {
    return FALSE;
  }

  ShowWindow(WindowHandle, ShowCommand);
  UpdateWindow(WindowHandle);

  return TRUE;
}

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
  default:
    // Other unhandled Messages will be passed to WindowsOS to handle
    result = DefWindowProc(Window, Message, WParam, LParam);
    break;
  };

  return result;
};
