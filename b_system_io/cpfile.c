#include "csapp.h"

#define BUFFER_SIZE MAXBUF

int main(int argc, char **argv) {
  int n;
  rio_t rio;
  char buf[BUFFER_SIZE];

  Rio_readinitb(&rio, STDIN_FILENO);

  while ((n = Rio_readnb(&rio, buf, BUFFER_SIZE)) != 0) {
      Rio_writen(STDOUT_FILENO, buf, n);
  }
}
