#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    // char szchar[] = "中国";
    // wchar_t swzStr[] = L"中国";
    char strBuff[] = "A";
    wchar_t strBuff1[] = L"A";
    return 0;
}
int main()
{
    setlocale(LC_ALL, ""); //使用控制台默认编码
    wchar_t wct[] = L"中国";
    wprintf(L"%s\n", wct);
    return 0;
}