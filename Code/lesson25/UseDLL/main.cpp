#include<stdio.h>
#include<Windows.h>
#include"MyDLL.h"
//#pragma comment(lib, "MyDLL.lib")
int main()
{/*
	int a = SUB(4, 2);
	int b = ADD(1, 2);*/
    // ��DLL�ļ����Ƶ���ĿĿ¼��

   // ����1�����庯��ָ��,�磺
    typedef int (*lpAdd)(int, int);

    // ����2����������ָ�����,�磺
    lpAdd myAdd;

    // ����3����̬����dll���ڴ���,�磺
    // LoadLibrary�������ȴӵ�ǰĿ¼Ѱ�ң�Ȼ����ϵͳĿ¼Ѱ��
    HINSTANCE hModule = LoadLibrary(TEXT("MyDLL.dll"));

    // ����4����ȡ������ַ,�磺
    myAdd = (lpAdd)GetProcAddress(hModule, "ADD");

    // ����5�����ú���,�磺
    int a = myAdd(10, 2);
    printf("%d\n", a);

    // ����6���ͷŶ�̬���ӿ�,�磺
    FreeLibrary(hModule);
	return 0;
}