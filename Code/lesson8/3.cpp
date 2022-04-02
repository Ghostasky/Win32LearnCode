#include <Windows.h>
#include <stdio.h>
int main()
{
    HANDLE hProcess;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 0x4598);

    if (!TerminateProcess(hProcess, 0))
    {
        printf("终止进程失败：%d \n", GetLastError());
    }
}