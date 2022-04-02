#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    HANDLE hProcess;
    hProcess = (HANDLE)0x1b0;
    if (!TerminateProcess(hProcess, 1))
    {
        printf("÷’÷π ß∞‹,%d\n", GetLastError());
    }

    return 0;
}