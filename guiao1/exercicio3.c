#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

ssize_t readln(int fd, char *line, size_t size) {
 int n;
 char c;
 ssize_t nbytes = 0;
 while (c != '\n' && nbytes < size && read(fd,&c,1) > 0){
    line[nbytes] = c;
    nbytes++;
 }
   write(1,line,strlen(line));
 return nbytes;
}

int main(int argc, char* argv[]){
  char line[1024];
  int sfd = open(argv[1],O_RDONLY);
  readln(sfd,line,1024);
}
