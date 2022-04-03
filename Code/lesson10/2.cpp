#include <windows.h>
#include <stdio.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

    for (int i = 0; i < 10; i++)
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

    WaitForSingleObject(hd, INFINITE);
    SuspendThread(hd);
    printf("end\n");

    CloseHandle(hd);
    return 0;
}