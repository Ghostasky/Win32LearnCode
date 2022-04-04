
#include <Windows.h>

#include <stdio.h>
HINSTANCE gHinstance;
// 定义子窗口标识
#define CWA_EDIT 0x100
#define CWA_BUTTON_0 0x101
#define CWA_BUTTON_1 0x102
// 窗口函数定义
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // 必须要调用一个默认的消息处理函数，关闭、最小化、最大化都是由默认消息处理函数处理的
    char szOutBuff[0x80];
    sprintf(szOutBuff, "Message: %x - %x \n", (unsigned int)hwnd, uMsg);
    OutputDebugString((LPCTSTR)szOutBuff);

    switch (uMsg)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    case WM_CREATE:
    {
        //编辑框
        CreateWindow(
            "EDIT",                                            // registered class name 注册的类名，使用EDIT则为编辑框
            "",                                                // window name 窗口名称
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE, // window style 子窗口控件样式：子窗口、创建后可以看到、滚动条、自动换行
            0,                                                 // horizontal position of window 在父窗口上的x坐标
            0,                                                 // vertical position of window 在父窗口上的y坐标
            400,                                               // window width 控件宽度
            300,                                               // window height 控件高度
            hwnd,                                              // menu handle or child identifier 父窗口句柄
            (HMENU)CWA_EDIT,                                   // menu handle or child identifier 子窗口标识
            gHinstance,                                        // handle to application instance 模块
            NULL                                               // window-creation data 附加数据
        );
        // 创建"设置"按钮
        CreateWindow(
            TEXT("BUTTON"),        // registered class name 注册的类名，使用BUTTON则为按钮
            TEXT("设置"),          // window name 按钮名称
            WS_CHILD | WS_VISIBLE, // window style 子窗口控件样式：子窗口、创建后可以看到
            450,                   // horizontal position of window 在父窗口上的x坐标
            150,                   // vertical position of window 在父窗口上的y坐标
            80,                    // window width 控件宽度
            20,                    // window height 控件高度
            hwnd,                  // menu handle or child identifier 父窗口句柄
            (HMENU)CWA_BUTTON_0,   // menu handle or child identifier 子窗口标识
            gHinstance,            // handle to application instance 模块
            NULL                   // window-creation data 附加数据
        );

        // 创建"获取"按钮
        CreateWindow(
            TEXT("BUTTON"),        // registered class name 注册的类名，使用BUTTON则为按钮
            TEXT("获取"),          // window name 按钮名称
            WS_CHILD | WS_VISIBLE, // window style 子窗口控件样式：子窗口、创建后可以看到
            450,                   // horizontal position of window 在父窗口上的x坐标
            100,                   // vertical position of window 在父窗口上的y坐标
            80,                    // window width 控件宽度
            20,                    // window height 控件高度
            hwnd,                  // menu handle or child identifier 父窗口句柄
            (HMENU)CWA_BUTTON_1,   // menu handle or child identifier 子窗口标识
            gHinstance,            // handle to application instance 模块
            NULL                   // window-creation data 附加数据
        );

        break;
    }
    // 当按钮点击则处理
    case WM_COMMAND:
    {
        // 宏WM_COMMAND中，wParam参数的低16位中有标识，根据标识我们才能判断哪个按钮和编辑框，使用LOWORD()可以获取低16位
        switch (LOWORD(wParam))
        {
            // 当按钮为设置
        case CWA_BUTTON_0:
        {
            // SetDlgItemText函数修改编辑框内容
            SetDlgItemText(hwnd, (int)CWA_EDIT, TEXT("HACK THE WORLD"));
            break;
        }
        // 当按钮为获取
        case CWA_BUTTON_1:
        {
            // MessageBox弹框输出编辑框内容
            TCHAR szEditBuffer[0x80];
            GetDlgItemText(hwnd, (int)CWA_EDIT, szEditBuffer, 0x80);
            MessageBox(NULL, szEditBuffer, NULL, NULL);
            break;
        }
        }
        break;
    }

    default:
        break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine,
                     int nCmdShow)
{
    gHinstance = hInstance;
    char szOutBuff[0x80];

    // 1. 定义创建的窗口(创建注册窗口类)
    TCHAR className[] = TEXT("My First Window");
    WNDCLASS wndClass = {0};
    // 设置窗口背景色
    wndClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    // 设置类名字
    wndClass.lpszClassName = className;
    // 设置模块地址
    wndClass.hInstance = hInstance;
    // 处理消息的窗口函数
    wndClass.lpfnWndProc = WindowProc; // 不是调用函数，只是告诉操作系统，当前窗口对应的窗口回调函数是什么
    // 注册窗口类
    RegisterClass(&wndClass);

    // 2. 创建并显示窗口
    // 创建窗口
    /*
    CreateWindow 语法格式：
    HWND CreateWindow(
        LPCTSTR lpClassName,  // registered class name 类名字
        LPCTSTR lpWindowName, // window name 窗口名字
        DWORD dwStyle,        // window style 窗口外观的样式
        int x,                // horizontal position of window 相对于父窗口x坐标
        int y,                // vertical position of window 相对于父窗口y坐标
        int nWidth,           // window width 窗口宽度：像素
        int nHeight,          // window height 窗口长度：像素
        HWND hWndParent,      // handle to parent or owner window 父窗口句柄
        HMENU hMenu,          // menu handle or child identifier 菜单句柄
        HINSTANCE hInstance,  // handle to application instance 模块
        LPVOID lpParam        // window-creation data  附加数据
    );
    */
    HWND hWnd = CreateWindow(className, TEXT("窗口"), WS_OVERLAPPEDWINDOW, 10, 10, 600, 300, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL)
    {
        // 如果为NULL则窗口创建失败，输出错误信息
        sprintf(szOutBuff, "Error: %d", GetLastError());
        OutputDebugString((LPCTSTR)szOutBuff);
        return 0;
    }

    // 显示窗口
    /*
    ShowWindow 语法格式：
    BOOL ShowWindow(
        HWND hWnd,     // handle to window 窗口句柄
        int nCmdShow   // show state 显示的形式
    );
    */
    ShowWindow(hWnd, SW_SHOW);

    // 3. 接收消息并处理
    /*
    GetMessage 语法格式：
    BOOL GetMessage(
        LPMSG lpMsg,         // message information OUT类型参数，这是一个指针
        // 后三个参数都是过滤条件
        HWND hWnd,           // handle to window 窗口句柄，如果为NULL则表示该线程中的所有消息都要
        UINT wMsgFilterMin,  // first message 第一条信息
        UINT wMsgFilterMax   // last message 最后一条信息
    );
    */
    MSG msg;
    BOOL bRet;
    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
            sprintf(szOutBuff, "Error: %d", GetLastError());
            OutputDebugString((LPCTSTR)szOutBuff);
            return 0;
        }
        else
        {
            // 转换消息
            TranslateMessage(&msg);
            // 分发消息：就是给系统调用窗口处理函数
            DispatchMessage(&msg);
        }
    }

    return 0;
}