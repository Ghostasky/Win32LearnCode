#include <windows.h>

#define MapFileName "共享内存"
#define BUF_SIZE 0x1000
HANDLE g_hMapFile;
LPTSTR g_lpBuff;

int main(int argc, char *argv[])
{
    // 内核对象：准备好物理页，无效句柄值-1、物理页可读写、申请一个物理页
    g_hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, BUF_SIZE, (LPCWSTR)MapFileName);
    // 将物理页与线性地址进行映射

    g_lpBuff = (LPTSTR)MapViewOfFile(g_hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);

    // 向物理内存中存储
    *(PDWORD)g_lpBuff = 0x12345678;

    // 关闭映射，关闭映射则表示释放了线形地址，但是物理页还存在
    UnmapViewOfFile(g_lpBuff);
    // 关闭句柄，这样才能释放物理页，但需要等待物理页使用完毕才会真正的释放，这里只是告诉系统我们当前进程不再使用该句柄（物理页）
    CloseHandle(g_hMapFile);
    return 0;
}