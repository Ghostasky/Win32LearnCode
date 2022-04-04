#include <Windows.h>
#include <stdio.h>

int main()
{
    CreateFile(
        TEXT("E:\\A.txt"),
        GENERIC_READ | GENERIC_WRITE,
        0,                     //共享模式，如果为0则是排他性，就是目前在使用时其他人是无法使用的
        NULL,                  // SD
        CREATE_ALWAYS,         //如何创建，可以打开一个已经存在的文件
        FILE_ATTRIBUTE_HIDDEN, //文件属性，可以创建隐藏文件
        NULL                   //创建文件的句柄
    );
    return 0;
}