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

    SuspendThread(hd[0]);

    CONTEXT context;
    context.ContextFlags = CONTEXT_INTEGER;
    GetThreadContext(hd[0], &context);

    printf("%x ,%x", context.Rdi, context.Rbx);
    ResumeThread(hd[0]);
    CloseHandle(hd[0]);

    return 0;
}