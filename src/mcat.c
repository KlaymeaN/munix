#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>

int main(int argc , char* argv[])
{
  if (argc<2)
  {
    printf("Usage: %s FILE\n", argv[0]);
  }

  int fd = open(argv[1], O_RDONLY); //FILE descriptor 

  if (fd == -1)
  {
    printf("File %s could NOT be opened!", argv[1]);
    return 1;
  }
  char buffer[4096]; //we dont want to load the WHOLE file into memory 
  ssize_t bytes_read; //ssize_t is an INTEGER type that is commonly used with read() & write()

  while((bytes_read = read(fd, buffer, sizeof(buffer)))> 0) //read MAX size of buffer at a time (4096)
  {
    write(STDOUT_FILENO, buffer, bytes_read); //STDOUT_FILENO is the std output file descriptor ( the terminal here)
                                              //we are saying: write to the TERMINAL
  }
  if (bytes_read == -1)
  {
    printf("Read ERROR\n");
    close(fd);
    return 1;
  }
  close(fd);
  return 0;
}





// SIMPLE VERSION 


//#include <stdio.h>
//
//int main(int argc, char *argv[])
//{
//  // we have to first check IF the user passed a filename
//  // C will not protect us automatically against this 
//  if (argc < 2)
//  {
//    printf("Usage: %s FILE\n", argv[0]);
//    return 1;
//  }
//  char *path = argv[1];
//  FILE *file = fopen(path, "r");
//  if (file == NULL)
//  {
//    printf("file %s NOT found!",path);
//    //now we must terminate the program 
//    return 1;
//  }
//
//  char line[256];
//  while (fgets(line, sizeof(line), file))
//  {
//    //printf(line); ==> printf is dangerous IF the file has characters like:
//    // %s or things like that, so we do :
//    printf("%s", line); //we can also use fputs here, but its fine for now
//  }
//  fclose(file);
//
//  return 0;
//  
//}
