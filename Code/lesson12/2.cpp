#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    HANDLE hs = CreateMutex(NULL, true, (LPCWSTR) "���࿪");
    if (hs)
    {
        if (GetLastError() == ERROR_ALREADY_EXISTS)
        {
            printf("�ó����Ѿ������ˣ������ٴο�����");
            getchar();
            CloseHandle(hs);
            return 0;
        }
        else
        {
            WaitForSingleObject(hs, INFINITE);
            // ������Դ
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
