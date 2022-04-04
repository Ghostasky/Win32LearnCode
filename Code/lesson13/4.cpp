#include <windows.h>
#include <stdio.h>
// 容器
int container;

// 次数
int count = 10;

HANDLE eventa, eventb;

// 生产者
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < count; i++)
    {

        // 等待互斥体，获取令牌
        WaitForSingleObject(eventa, INFINITE);
        // 获取当前进程ID
        int threadId = GetCurrentThreadId();
        // 生产存放进容器
        container = 1;
        printf("++Thread: %d, Build: %d \n", threadId, container);

        SetEvent(eventb);
    }
    return 0;
}

// 消费者
DWORD WINAPI ThreadProcB(LPVOID lpParameter)
{
    for (int i = 0; i < count; i++)
    {

        // 等待互斥体，获取令牌
        WaitForSingleObject(eventb, INFINITE);
        // 获取当前进程ID
        int threadId = GetCurrentThreadId();
        container = 0;
        printf("--Thread: %d, Consume: %d \n", threadId, container);
        // 消费

        SetEvent(eventa);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    eventa = CreateEvent(NULL, false, true, NULL);
    eventb = CreateEvent(NULL, false, false, NULL);

    // 创建2个线程
    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, NULL, ThreadProcB, NULL, 0, NULL);

    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(eventa);
    CloseHandle(eventb);
    return 0;
}