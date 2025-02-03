#include <Windows.h>

#include <iostream>
#include <string>

void foo(void) {
  const char* text = "This is the first thing we have actually printed\n";
  OutputDebugStringA("Line 0 \\Line 1\n");
  OutputDebugStringA(text);
  // WINDOWS: \r\n
  // UNIX: \n
  printf("HELLO THERE");
}

<<<<<<< HEAD:day_1-4/main.cpp
struct Projectile {
  char unsigned IsThisOnFire;  // 1 if it's on fire, 0 if it's not
  int Damage;                  // this is how much damage it does on impact
  int ParticlePerSecond;       // For special efects
  short HowManyCooks;          // Too many cooks?
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
=======
int WINAPI wWinMain_day4(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                         PWSTR pCmdLine, int nCmdShow) {
>>>>>>> refs/remotes/origin/main:archive/intro_to_c/main.cpp
  /*
  int INTEGER;
  INTEGER = 10;

  char SmallS;           // 8 bits: 256 unique values [-128, 127]
  char unsigned SmallU;  // 8 bits: 256 unique values [0, 255]

  short MediumS;         // 16 bits: 6536 unique values
  int unsigned MediumU;  // 16 bits: 6536 unique values

  int LargeS;           // 32 bits: ~4 billion values
  int unsigned LargeU;  // 32 bits: ~4 billion values
  */

  /*
  char unsigned Test;
  char unsigned *TestPointer;

  TestPointer = &Test;

  Test = 255;
  Test += 1;

  foo();
  */

  unsigned int Test;
  Test = 88;

  int INTEGER;
  // INTEGER = 21;
  INTEGER = 69420;

  unsigned long long LONG;
  LONG = 69420;

  std::string TEXT;
  TEXT = "HELLO THERE MAN";
  OutputDebugStringA("size of TEXT: ");
  OutputDebugStringA(std::to_string(sizeof(TEXT)).c_str());
  OutputDebugStringA("\n");

  OutputDebugStringA("size of long: ");
  OutputDebugStringA(std::to_string(sizeof(long long)).c_str());
  OutputDebugStringA("\n");

  int x;
  x = 21;

  Projectile TestProjectile;

  TestProjectile.IsThisOnFire = 1;
  TestProjectile.Damage = 2;
  TestProjectile.ParticlePerSecond = 3;
  TestProjectile.HowManyCooks = 4;

  short* test_pointer = (short*)&TestProjectile;
  *test_pointer = 300;

  // 1 1111 0100
  // 0000 0001 1111 0100

  return 0;
}

// 69420
// 1 0000 1111 0010 1100
// - --------- ---------

// 6  3 1 0 0 0 0 0 0  0 0 0 0 0 0 0 0
// 5  2 6 8 4 2 1 0 0  0 0 0 0 0 0 0 0
// 5  7 3 1 0 0 0 5 2  1 0 0 0 0 0 0 0
// 3  6 8 9 9 4 2 1 5  2 6 3 1 0 0 0 0
// 6  8 4 2 6 8 4 2 6  8 4 2 6 8 4 2 1

// -  ---------------  ---------------
// 1  0 0 0 0 1 1 1 1  0 0 1 0 1 1 0 0
// 1       15               44
// -  ---------------  ---------------

// 65536 2048+1024+512+256 32+8+4
// 65536 3840              44
// 44 15 1
// 2C 0F 01

// 1  0 0 0 0 1 1 1 1  0 0 1 0 1 1 0 0
