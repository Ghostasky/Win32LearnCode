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

int main(int argc, char *argv[])
{
    HANDLE hd[2];
    hd[0] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    hd[1] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    WaitForMultipleObjects(2, hd, true, INFINITE);
    SuspendThread(hd);
    printf("end\n");

    CloseHandle(hd[0]);

    CloseHandle(hd[1]);
    return 0;
}