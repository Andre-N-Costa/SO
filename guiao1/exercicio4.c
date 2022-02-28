#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fd, char *line, size_t size) {
 int n;
 char c;
 ssize_t nbytes = 0;
 while (c != '\n' && nbytes < size && read(fd,&c,1) > 0){
    line[nbytes] = c;
    nbytes++;
 }
 return nbytes;
}

int main(int argc, char* argv[]){
  if (argc > 2) {
      fprintf(stderr, "ERRO : demasiados argumentos");
      return 1;
  }
  int fd = 0;
  if (argc == 2) {
      fd = open(argv[1], O_RDONLY);
  }
  if (fd == -1) {
      perror(argv[1]);
      return 1;
  }
  char buffer[1024], n_buffer[32];
  int bytes, counter = 1;
  while ((bytes = readln(fd, buffer, 1024)) > 0) {
      sprintf(n_buffer, "%d  ", counter);
      write(1, n_buffer, 2);
      write(1, buffer, bytes);
      write(1, "\n", 1);
      counter++;
  }
  return 0;
}
