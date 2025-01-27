#include <winidows.h>

void foo(void) { OutputDebugStringA("THIS IS SOMETHING"); }


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR pCmdLine, int nCmdShow) {
  foo();

}