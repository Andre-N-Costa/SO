#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]){
  char buffer[MAX_BUFFER];
  int bytes_read;

  while((bytes_read = read(0, buffer, MAX_BUFFER)) > 0){
    write(1,buffer,bytes_read);
  }
  close(bytes_read);
  printf("terminei\n");

  return 0;
}
