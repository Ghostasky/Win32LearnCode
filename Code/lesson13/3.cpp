#include <windows.h>
#include <stdio.h>
HANDLE e_event;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    // 等待事件
    WaitForSingleObject(e_event, INFINITE);
    printf("ThreadProc - running ...\n");
    return 0;
}

DWORD WINAPI ThreadProcB(LPVOID lpParameter)
{
    // 等待事件
    WaitForSingleObject(e_event, INFINITE);
    printf("ThreadProcB - running ...\n");
    return 0;
}

int main(int argc, char *argv[])
{
    // 第二个参数，FALSE表示非通知类型通知，也就是互斥；TRUE则表示为通知类型
    // 第三个参数表示初始状态没有信号
    e_event = CreateEvent(NULL, true, FALSE, NULL);

    // 创建2个线程
    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, NULL, ThreadProcB, NULL, 0, NULL);
    //这里他并没有执行ThreadProc和ThreadProcB
    Sleep(1000);

    // 设置事件为已通知，也就是设置为有信号，之后才跑
    SetEvent(e_event);

    // 等待线程执行结束，销毁内核对象
    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(e_event);

    return 0;
}