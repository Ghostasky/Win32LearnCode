#include <windows.h>
#include <stdio.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

    for (int i = 0; i < 10; i++)
    {
        Sleep(50);
        printf("++++++ %d \n", i);
    }

    return 0;
}
DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{

    for (int i = 0; i < 10; i++)
    {
        Sleep(50);
        printf("++++++ %d \n", i);
    }

    return 1;
}
int main(int argc, char *argv[])
{
    HANDLE hd[2];
    DWORD ec, ed;
    hd[0] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    hd[1] = CreateThread(NULL, NULL, ThreadProc1, NULL, 0, NULL);

    WaitForMultipleObjects(2, hd, true, INFINITE);
    GetExitCodeThread(hd[0], &ec);
    GetExitCodeThread(hd[1], &ed);
    SuspendThread(hd);
    printf("end\n%d ,%d", ec, ed);

    CloseHandle(hd[0]);

    CloseHandle(hd[1]);
    return 0;
}