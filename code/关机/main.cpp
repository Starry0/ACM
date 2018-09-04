#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void){
  char* p = "我是猪";
  char str[100];
  while(gets(str) > 0 && strcmp(str, p) != 0) {
    printf("You are wrong!!!\n");
    system("start shutdown -t 0");
    exit(0);
  }
  printf("You are right!!!\n");
  printf("请记录下来\n\t^-^\n");
  system("start notepad");
  return 0;
}
