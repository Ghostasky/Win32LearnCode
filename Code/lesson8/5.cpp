#include <Windows.h>
#include <stdio.h>
int main()
{
    TCHAR childProcessName[] = TEXT("C:/WINDOWS/system32/cmd.exe");
    TCHAR childPeocessCmd[] = TEXT("/c ping www.baidu.com");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    if (CreateProcess(childProcessName,
                      childPeocessCmd,
                      NULL,
                      NULL,
                      FALSE,
                      CREATE_SUSPENDED, NULL, NULL, &si, &pi))
    {
        printf("create success\n");
    }
    else
    {
        printf("CreateProcess Error: %d \n", GetLastError());
    }
    ResumeThread(pi.hThread);
    system("pause");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}