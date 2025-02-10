#include <corecrt_wstdlib.h>
#include <float.h>
#include <windows.h>
#include <wingdi.h>
#include <winuser.h>

#include <cstdlib>

// Defining more meaningful aliases for 'static'
#define LOCAL_PERSIST static
#define INTERNAL_FN static
#define GLOBAL_VAR static

//-------------------------------------------------------------------
// GLOBAL VARIABLES
//-------------------------------------------------------------------
HINSTANCE global_hInstance;
char win_title[100];
char win_class[100];

GLOBAL_VAR bool IsRunning = false;

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

  IsRunning = true;

  // 3. Main message loop
  // (our WindowProc fn will handle these disptched messages)
  MSG Message;
  HACCEL hAccelTable = LoadAccelerators(Instance, MAKEINTRESOURCE(109));
  OutputDebugStringA("hello once\n");
  while (IsRunning) {
    BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
    if (MessageResult > 0) {
      TranslateMessage(&Message);  // basically converts messages into proper
                                   // keyboard messages
      DispatchMessage(&Message);
    } else {
      break;
    }
  }

  return EXIT_SUCCESS;
}

// 2.1: Saves instance handle and creates main window
BOOL InitializeWindowInstance(HINSTANCE Instance, int ShowCommand) {
  global_hInstance = Instance;  // store in global variable

  // Create a main window, and get the handle to this window
  HWND WindowHandle = CreateWindowEx(
      0, win_class, win_title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);

  // FAILED TO CREATE THE MAIN WINDOW
  // will fail if window class name is not same as Instances classname
  if (!WindowHandle) return FALSE;

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

void do_paint(HWND *);

void ResizeDBISection(int width, int height) {}

// 1.2 (requires gdi32.lib at linking)
LRESULT CALLBACK MainWindowCallbackProcedure(HWND Window, UINT Message,
                                             WPARAM WParam, LPARAM LParam) {
  LRESULT result = 0;
  // Handle all the messages that Windows Sends to the window
  switch (Message) {
    case WM_SIZE: {
      // Get the new size
      RECT ClientRect;
      GetClientRect(Window, &ClientRect);
      int width = ClientRect.right - ClientRect.left;
      int height = ClientRect.top - ClientRect.bottom;

      ResizeDBISection(width, height);
      OutputDebugStringA("WM_SIZE");
    } break;
    case WM_DESTROY: {    // this is force close
      IsRunning = false;  // TODO: Handle this with a message to the user?
      // OutputDebugStringA("WM_DESTROY");
    } break;
    case WM_CLOSE: {
      IsRunning = false;  // TODO: Handle this as an error, recreate the window
      // OutputDebugStringA("WM_CLOSE");
      //  DestroyWindow(Window);
      //  exit(0);
    } break;
    case WM_ACTIVATEAPP: {
      OutputDebugStringA("WM_ACTIVATEAPP");
    } break;
    case WM_PAINT: {
      do_paint(&Window);
    } break;
    default: {
      // Other unhandled Messages will be passed to WindowsOS to handle
      result = DefWindowProc(Window, Message, WParam, LParam);
    } break;
  };

  return result;
};

void do_paint(HWND *Wind) {
  HWND Window = *Wind;
  PAINTSTRUCT Paint;
  HDC DeviceContext = BeginPaint(Window, &Paint);
  int X = Paint.rcPaint.left;
  int Y = Paint.rcPaint.top;
  LONG Width = Paint.rcPaint.right - Paint.rcPaint.left;
  LONG Height = Paint.rcPaint.bottom - Paint.rcPaint.top;

  static DWORD Operation = WHITENESS;
  PatBlt(DeviceContext, X, Y, Width, Height, Operation);
  Operation = Operation == WHITENESS ? BLACKNESS : WHITENESS;

  /*
  HBRUSH hPurpleBrush = CreateSolidBrush(0x00800080L);  // L for DWORD
  HGDIOBJ holdBrush = SelectObject(DeviceContext, hPurpleBrush);
  PatBlt(DeviceContext, X, Y, Width, Height, PATCOPY);
  SelectObject(DeviceContext, holdBrush);  // restore old brush
  DeleteObject(hPurpleBrush);              // clean up purple brush
  */

  EndPaint(Window, &Paint);
}
