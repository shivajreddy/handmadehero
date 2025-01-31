#include <Windows.h>

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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
  return 0;
}
