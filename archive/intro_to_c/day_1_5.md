/*
void foo(void) {
  const char* text = "This is the first thing we have actually printed\n";
  OutputDebugStringA("Line 0 \\Line 1\n");
  OutputDebugStringA(text);
  // WINDOWS: \r\n
  // UNIX: \n
  printf("HELLO THERE");
}

struct Projectile {
  char unsigned IsThisOnFire;  // 1 if it's on fire, 0 if it's not
  int Damage;                  // this is how much damage it does on impact
  int ParticlePerSecond;       // For special efects
  short HowManyCooks;          // Too many cooks?
};
*/

/*
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                  PWSTR pCmdLine, int nCmdShow) {
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

/*
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

69420
1 0000 1111 0010 1100
- --------- ---------

6  3 1 0 0 0 0 0 0  0 0 0 0 0 0 0 0
5  2 6 8 4 2 1 0 0  0 0 0 0 0 0 0 0
5  7 3 1 0 0 0 5 2  1 0 0 0 0 0 0 0
3  6 8 9 9 4 2 1 5  2 6 3 1 0 0 0 0
6  8 4 2 6 8 4 2 6  8 4 2 6 8 4 2 1

-  ---------------  ---------------
1  0 0 0 0 1 1 1 1  0 0 1 0 1 1 0 0
1       15               44
-  ---------------  ---------------

65536 2048+1024+512+256 32+8+4
65536 3840              44
44 15 1
2C 0F 01

1  0 0 0 0 1 1 1 1  0 0 1 0 1 1 0 0
*/

/*
byte x;
x = 0x0a; // assigning in hexadecimal
x = 0b1010;  // assigning in binary

value       = 10
hexadecimal = 0a
binary      = 1010

int value   = 10

bits        = 00000000 00000000 00000000 00000000
bits        = 00001010 00000000 00000000 00000000

bytes(u_int)=  0 0 0 0
bytes(u_int)= 10 0 0 0

bytes(hex)  = 00 00 00 00
bytes(hex)  = 0a 00 00 00

x << 1
bytes(hex)  = 14 00 00 00

0000 0000     00
0000 1010     10
0001 0100     20
0010 1000     40
0101 0000     80
1010 0000     160
1010 0000     320
0000 0001 0100 0000
0100 0000     64
*/

/*
struct Empty {};

struct Person {
  char a;
  int b;
};


  Empty empty;
  size_t size_of_Empty = sizeof(Empty);  // garbage
  size_t size_of_empty = sizeof(empty);  // garbage

  Person person;
  person.a = 97;
  person.b = 220;

  size_t size_of_Person = sizeof(Person);
  size_t size_of_person = sizeof(person);

  int x;
  x = 0b0000 ^ 0b0100;

*/
