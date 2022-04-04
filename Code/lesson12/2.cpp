#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    HANDLE hs = CreateMutex(NULL, true, (LPCWSTR) "防多开");
    if (hs)
    {
        if (GetLastError() == ERROR_ALREADY_EXISTS)
        {
            printf("该程序已经开启了，请勿再次开启！");
            getchar();
            CloseHandle(hs);
            return 0;
        }
        else
        {
            WaitForSingleObject(hs, INFINITE);
            // 操作资源
            for (int i = 0; i < 5; i++)
            {
                printf("Process: A Thread: B -- %d \n", i);
                Sleep(1000);
            }
            ReleaseMutex(hs);
        }
    }
    return 0;
}
