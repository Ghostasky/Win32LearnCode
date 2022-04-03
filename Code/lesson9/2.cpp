#include <windows.h>
#include <stdio.h>
// 线程执行的函数有语法要求，参考MSDN Library
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    // 要执行的代码
    int *p = (int *)lpParameter;
    for (int i = 0; i < *p; i++)
    {
        Sleep(500);
        printf("++++++ %d \n", i);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    HANDLE hd;
    int n = 10;
    // 创建线程
    hd = CreateThread(NULL, NULL, ThreadProc, &n, 0, NULL);
    CloseHandle(hd);
    // 要执行的代码
    for (int i = 0; i < 100; i++)
    {
        Sleep(500);
        printf("------ %d \n", i);
    }
    return 0;
}