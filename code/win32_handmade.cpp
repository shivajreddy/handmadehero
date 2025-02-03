/*
=====================================================================
$File : $
$Date: $
$Revision: $
$Creator: smpl
=====================================================================
*/

#include <windows.h>

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPWSTR lpCmdLine, int nShowCmd) {

  // MB_OK);
  MessageBoxA(0, "This is Handmade Hero", "Handmade Hero",
              MB_OK | MB_ICONINFORMATION);

  // MessageBoxW(NULL, L"WTF Hello there.... wTf, 世界!", L"Unicode Message",

  return 0;
}
