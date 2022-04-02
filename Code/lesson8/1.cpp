#include <Windows.h>
#include <stdio.h>
int main()
{
    TCHAR childProcessName[] = TEXT("C:\\Program Files\\Internet Explorer\\iexplore.exe");
    TCHAR childPeocessCmd[] = TEXT("http://www.baidu.com");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    if (CreateProcess(childProcessName,
                      childPeocessCmd,
                      NULL,
                      NULL,
                      FALSE,
                      0, NULL, NULL, &si, &pi))
    {
        printf("create success\nPID:%d, 句柄:%d", pi.dwProcessId, pi.hProcess);
    }
    else
    {
        printf("CreateProcess Error: %d \n", GetLastError());
    }
    system("pause");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}