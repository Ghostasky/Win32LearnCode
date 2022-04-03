#include <windows.h>
#include <stdio.h>

CRITICAL_SECTION cs;
int tickNUM = 10;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

    while (1)
    {
        EnterCriticalSection(&cs);
        if (tickNUM > 0)
        {
            printf("现在有%d张 ", tickNUM);
            tickNUM--;
            printf("还有%d 张\n", tickNUM);
        }
        else
        {
            LeaveCriticalSection(&cs);
            break;
        }
        LeaveCriticalSection(&cs);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    InitializeCriticalSection(&cs);
    HANDLE hd, hd1;
    hd = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
    hd1 = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

    // getchar();

    return 0;
}
