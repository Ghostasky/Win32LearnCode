// WindowsProject1.cpp : 定义应用程序的入口点。
//

// #include "framework.h"
// #include "WindowsProject1.h"
#include <stdio.h>
#include <Windows.h>
#define MAX_LOADSTRING 100
#pragma warning(disable : 4996)
int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPWSTR lpCmdLine,
                      int nCmdShow)
{

    DWORD dwAddr = (DWORD)hInstance;

    char szOutBuff[0x80];
    sprintf(szOutBuff, "aaa:%x \n", dwAddr); // 该函数需要包含stdio.h头文件
    OutputDebugString((LPCWSTR)szOutBuff);
    return 0;
}
