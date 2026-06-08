#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc<2)
  {
    printf("Usage: %s -n FILE\n", argv[0]);
    return 1;
  }
  int n;
  char *filename ;
  if (argc ==3 && argv[1][0] == '-')
  {
    n = atoi(argv[1] + 1); // atoi is ASCII to INT,AND the rest is how to get the NUMBER using pointer math
    filename = argv[2];
    if (n < 0)
    {
      printf("Invalid -n!");
      return 1;
    }
  }
  else if (argc==2)
  {
    n = 10;
    filename = argv[1];
  }

  char line[256];
  FILE *file = fopen(filename, "r");

  if (file == NULL)
  {
    printf("FILE %s could NOT be opened!", argv[1]);
    return 1;
  }
  for (int i=0; i <n; i++)
  {
    if (fgets(line, sizeof(line), file)== NULL) //puts the read ones FROM file INTO line
    {
      break;
    }
    printf("%s",line);
  }
  fclose(file);
  return 0;
}
