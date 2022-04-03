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
    hd[0] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    /* hd[1] = CreateThread(NULL, NULL, ThreadProc1, NULL, 0, NULL);*/

    SuspendThread(hd[0]);

    CONTEXT context;
    context.ContextFlags = CONTEXT_INTEGER;
    context.Eax = 0x123;
    SetThreadContext(hd[0], &context);

    CONTEXT c;
    c.ContextFlags = CONTEXT_INTEGER;
    GetThreadContext(hd[0], &c);

    printf("%x ,%x", c.Eax, c.Ebp);
    getchar();
    ResumeThread(hd[0]);
    CloseHandle(hd[0]);

    return 0;
}