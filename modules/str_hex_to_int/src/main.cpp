//ïðîãðàììà ïðåîáðàçóåò ñòðîêó ñ çàïèñàíûì â íåé 16ì ÷èñëîâ â òèï int
//char* "0xFF"
//int res=255;

#include "pch.h"

int convert(char*);

int main()
{
  char* str="ff";

  cout<<convert(str)+1<<endl;
  return 0;
}

int convert(char* data)
{
  char* end;
  int result=strtol(data,&end,16);
  return result;
}