#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

using namespace std;

void error(const char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char const *argv[]) {
  cout << "Server starting..." << endl;

  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) {
    fprintf(stderr, "usage %s port \n", argv[0]);
    exit(1);
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) error("ERROR opening socket");

  bzero((char *)&serv_addr, sizeof(serv_addr));

  portno = atoi(argv[1]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  newsockfd = accept(sockfd, (sockaddr *)&cli_addr, &clilen);
  if (newsockfd < 0) error("ERROR on accept");

  char host[NI_MAXHOST];
  getnameinfo((sockaddr *)&cli_addr, clilen, host, sizeof host, NULL, 0,
              NI_NUMERICHOST);
  printf("server: got connection from %s port %d\n", host,
         ntohs(cli_addr.sin_port));

  send(newsockfd, "Hello, world!\n", 13, 0);

  bzero(buffer, 256);

  n = read(newsockfd, buffer, 255);
  if (n < 0) error("ERROR reading from socket");
  printf("Here is the message: %s\n", buffer);

  close(newsockfd);
  close(sockfd);
  return 0;
}
