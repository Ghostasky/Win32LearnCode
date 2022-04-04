#include <Windows.h>
#include <stdio.h>
int main()
{
    LPVOID p;
    p = VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);
    VirtualFree(p, 0x1000, MEM_DECOMMIT); // 虚拟地址仍然保留，物理页不保留
    // VirtualFree(p, 0, MEM_RESERVE);//// 虚拟地址不保留
    return 0;
}