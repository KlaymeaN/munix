#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

long long bytes(char *argv);
int lines(char *argv); 
int words(char *argv);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s FILE\n", argv[0]);
  }
  long long total_bytes = bytes(argv[1]);
  //printf("%lld\n", total_bytes);
  int total_lines = lines(argv[1]);
  int total_words = words(argv[1]);
  printf("%i %i %lld %s \n", total_lines, total_words, total_bytes, argv[1]);
  //printf("%i\n", total_lines);
  return 0;
  
}

int words(char *filename)
{
  char line[256];
  int word_count = 0;
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Could NOT open file %s \n", filename);
    return -1;
  }
  int in_word = 0;
  while (fgets(line, sizeof(line), file))
  {
    for (int i=0; line[i]!='\0'; i++)
    {
      if (isspace((unsigned char)line[i])) // this checks ALL of : \n, \t, etc. 
                                           // unsigned char is to be safe that it is not negative
      {
        in_word = 0;
      }
      else if(in_word == 0)
      {
        word_count ++;
        in_word = 1;
      }

    }
  }
  fclose(file);
  return word_count;
  
}
int lines(char *filename)
{
  char line[256];
  int line_count = 0;
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("could NOT open file %s \n", filename);
    return -1;
  }
  while (fgets(line, sizeof(line), file))
  {
    for (int i = 0; line[i] !='\0'; i++) // strings END with the NULL byte
    {
      if ( line[i]=='\n') // NOTE: '\n' is ONE character, "\n" is one STRING
      {
        line_count ++;
      }
    }
  }
  fclose(file);
  return line_count;
}

long long bytes(char *filename)
{
  int fd = open(filename, O_RDONLY);
  if (fd ==-1)
  {
    printf("Could NOT open FILE %s", filename);
    return 1;
  }
  char buffer[4096];
  ssize_t bytes_read; 
  long long total_bytes=0;
  while((bytes_read = read(fd, buffer, sizeof(buffer)))>0)
  {
    total_bytes +=bytes_read;
  }
  if (bytes_read == -1)
  {
    printf("Read Error\n");
    close(fd);
    return 1;
  }
  close(fd);

  //printf("%lld\n", total_bytes);
  return total_bytes;


}
