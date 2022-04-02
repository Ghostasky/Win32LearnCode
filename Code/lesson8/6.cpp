#include <Windows.h>
#include <stdio.h>
int main()
{
    char strModule[256];
    GetModuleFileName(NULL, (LPWSTR)strModule, 256);
    char strWork[1000];
    GetCurrentDirectory(1000, (LPWSTR)strWork); // 获取当前工作目录

    printf("模块目录：%ws \n工作目录：%ws \n", strModule, strWork);
    return 0;
}