#include <Windows.h>
#include <stdio.h>
int main()
{
    // 将DLL文件复制到项目目录下

    // 步骤1：定义函数指针,如：
    typedef int (*lpAdd)(int, int);

    // 步骤2：声明函数指针变量,如：
    lpAdd myAdd;

    // 步骤3：动态加载dll到内存中,如：
    // LoadLibrary函数会先从当前目录寻找，然后在系统目录寻找
    HINSTANCE hModule = LoadLibrary(TEXT("MyDLL.dll"));

    // 步骤4：获取函数地址,如：
    myAdd = (lpAdd)GetProcAddress(hModule, "ADD");

    // 步骤5：调用函数,如：
    int a = myAdd(10, 2);
    printf("%d\n", a);

    // 步骤6：释放动态链接库,如：
    FreeLibrary(hModule);
    return 0;
}