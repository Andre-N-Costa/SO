#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

ssize_t readlnplus(FILE *fd, char *line, size_t size) {
 char c[1024];
 ssize_t nbytes = 0;
 fgets(c,1024,fd);
 write(1,c,strlen(c));
 return nbytes;
}

int main(int argc, char* argv[]){
  char line[1024];
  FILE *file = fopen(argv[1],"r");
  readlnplus(file,line,1024);
}
