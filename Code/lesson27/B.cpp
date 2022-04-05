#include <Windows.h>
#include <stdio.h>
BOOL MyCreateRemoteThread(DWORD dwProcessId, DWORD dwProcessAddr)
{
    DWORD dwThreadId;
    HANDLE hProcess;
    HANDLE hThread;
    // 1. 获取进程句柄
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
    // 判断OpenProcess是否执行成功
    if (hProcess == NULL)
    {
        OutputDebugString(TEXT("OpenProcess failed! \n"));
        return FALSE;
    }
    // 2. 创建远程线程
    hThread = CreateRemoteThread(
        hProcess,                              // handle to process
        NULL,                                  // SD
        0,                                     // initial stack size
        (LPTHREAD_START_ROUTINE)dwProcessAddr, // thread function
        NULL,                                  // thread argument
        0,                                     // creation option
        &dwThreadId                            // thread identifier
    );
    // 判断CreateRemoteThread是否执行成功
    if (hThread == NULL)
    {
        OutputDebugString(TEXT("CreateRemoteThread failed! \n"));
        CloseHandle(hProcess);
        return FALSE;
    }

    // 3. 关闭
    CloseHandle(hThread);
    CloseHandle(hProcess);

    // 返回
    return TRUE;
}
int main()
{
    MyCreateRemoteThread(20500, 0x00007ff7d9e017d0);
    return 0;
}