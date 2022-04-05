#include <Windows.h>
#include <stdio.h>
void Fun()
{
    for (int i = 0; i <= 5; i++)
    {
        printf("Fun running... \n");
        Sleep(1000);
    }
}

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    Fun();
    return 0;
}

int main(int argc, char *argv[])
{

    HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    CloseHandle(hThread);

    getchar();
    return 0;
}