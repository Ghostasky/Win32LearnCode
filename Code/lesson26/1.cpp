#include <Windows.h>
#include <stdio.h>
#pragma comment(lib, "MyDLL.lib")
__declspec(dllimport) int ADD(int a, int b);
__declspec(dllimport) int SUB(int a, int b);
int main()
{
    int a = SUB(2, 1);
    int b = ADD(23, 11);
    return 0;
}