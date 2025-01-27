#include <Windows.h>

#include <iostream>

void foo(void) {
  const char *text = "This is the first thing we have actually printed\n";
  OutputDebugStringA("Line 0 \\Line 1\n");
  OutputDebugStringA(text);
  // WINDOWS: \r\n
  // UNIX: \n
  printf("HELLO THERE");
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
  /*
  int INTEGER;
0x0000007FE0EFF8EC 254 127 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 翾.........
  INTEGER = 10;

  char SmallS;           // 8 bits: 256 unique values [-128, 127]
  char unsigned SmallU;  // 8 bits: 256 unique values [0, 255]

  short MediumS;         // 16 bits: 6536 unique values
  int unsigned MediumU;  // 16 bits: 6536 unique values

  int LargeS;           // 32 bits: ~4 billion values
  int unsigned LargeU;  // 32 bits: ~4 billion values
  */

  char unsigned Test;
  char unsigned *TestPointer;

  TestPointer = &Test;

  Test = 255;
  Test += 1;
  // 0x000000eb6a34fbf4

  foo();
}
// 0x0000007fe0eff694
