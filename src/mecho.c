#include <stdio.h>
//#include <string.h>

int main(int argc, char *argv[])
{
  //printf(argv);
  for (int i=1; i<argc; i++) //argv[argc] is NULL
  {
    //printf(argv[i]); ==> THIS can crash based on user input!
    printf("%s", argv[i]);
    if (i < argc -1) //so we dont print AN EXTRA space at the end
    {
    printf(" ");
    }
  }
  printf("\n");
  return 0; //always 
}
