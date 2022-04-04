#include <Windows.h>
#include <stdio.h>

int main()
{
    // CreateDirectory(TEXT("E:\\A"), NULL);
    // RemoveDirectory(TEXT("E:\\A"));
    // MoveFile(TEXT("E:\\A"), TEXT("E:\\B"));

    TCHAR dwOutDirectory[200];
    GetCurrentDirectory(200, dwOutDirectory);
    return 0;
}