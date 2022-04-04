#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    HANDLE hs = CreateMutex(NULL, true, "xyz");
    WaitForSingleObject(hs, INFINITE);

    for (int i = 0; i < 10; i++)
    {
        Sleep(1000);
        printf("%d\n", i);
    }
    ReleaseMutex(hs);

    return 0;
}
