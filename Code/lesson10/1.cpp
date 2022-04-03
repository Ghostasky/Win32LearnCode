#include <windows.h>
#include <stdio.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

    for (int i = 0; i < 100; i++)
    {
        Sleep(500);
        printf("++++++ %d \n", i);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    HANDLE hd;
    hd = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    Sleep(3000);
    SuspendThread(hd);
    Sleep(3000);
    ResumeThread(hd);
    CloseHandle(hd);
    return 0;
}