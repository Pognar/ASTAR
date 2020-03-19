/* strlen example */
#include <stdio.h>
#include <string>
#include <iostream>

int main ()
{
  char szInput[256];
  printf ("Enter a sentence: ");
  std::cin >> szInput;
  printf ("The sentence entered is %u characters long.\n",(unsigned)strlen(szInput));
  return 0;
}
