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

      HBRUSH hPurpleBrush = CreateSolidBrush(0x00800080L);  // L for DWORD
      HGDIOBJ holdBrush = SelectObject(DeviceContext, hPurpleBrush);
      PatBlt(DeviceContext, X, Y, Width, Height, PATCOPY);
      SelectObject(DeviceContext, holdBrush);  // restore old brush
      DeleteObject(hPurpleBrush);              // clean up purple brush

      EndPaint(Window, &Paint);
    } break;
    default:
      // Other unhandled Messages will be passed to WindowsOS to handle
      result = DefWindowProc(Window, Message, WParam, LParam);
      break;
  };

  return result;
};

int CALLBACK wWinMain(_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PrevInstance,
                      _In_ LPWSTR CommandLine, _In_ int ShowCommand) {
  // Create Window Class for the main application window
  WNDCLASS WindowClass = {0};
  WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
  WindowClass.lpfnWndProc = MainWindowCallbackProcedure;
  WindowClass.hInstance = Instance;
  WindowClass.lpszClassName =
      "HandmadeHeroWindowClass";  // L prefix for wide string

  // Register the main application window's Window Class
  if (RegisterClass(&WindowClass)) {  // Success
    HWND WindowHandle =
        CreateWindowEx(0, WindowClass.lpszClassName, "Handmade Hero",
                       WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_DEFAULT, CW_DEFAULT,
                       CW_DEFAULT, CW_DEFAULT, 0, 0, Instance, 0);

    if (WindowHandle != NULL) {  //
      MSG Message;
      for (;;) {
        BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
        if (MessageResult > 0) {
          TranslateMessage(&Message);
          DispatchMessage(&Message);
        } else {
          break;
        }
      }
    }

  } else {
    // TODO: Failed to register the MainWindowClass
  }

  return 0;
}
