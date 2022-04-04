#include<stdio.h>
#include"MyDLL.h"
#pragma comment(lib, "MyDLL.lib")
int main()
{
	int a = SUB(4, 2);
	int b = ADD(1, 2);

	return 0;
}