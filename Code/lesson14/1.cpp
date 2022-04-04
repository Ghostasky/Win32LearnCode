#include <windows.h>

int main(int argc, char *argv[])
{
    HWND hWnd; // 窗口句柄
    HDC hDc;   // 设备上下文对象
    HPEN hPen; // 画笔
    // 1. 设备对象，要绘画的位置
    // 设置为NULL则表示在桌面中绘画
    hWnd = (HWND)0x000C058A;

    // 2. 获取设备的上下文对象（DC）
    /*
        语法格式：
        HDC GetDC(
            HWND hWnd   // handle to window
        );
    */
    hDc = GetDC(hWnd);

    // 3. 创建画笔，设置线条的属性
    /*
        语法格式：
        HPEN CreatePen(
            int fnPenStyle,    // pen style
            int nWidth,        // pen width
            COLORREF crColor   // pen color
        );
    */
    hPen = CreatePen(PS_SOLID, 5, RGB(0xFF, 00, 00)); // RGB表示红绿蓝，红绿蓝的组合就可以组成新的一种颜色。

    // 4. 关联
    /*
        语法格式：
        HGDIOBJ SelectObject(
            HDC hdc,          // handle to DC
            HGDIOBJ hgdiobj   // handle to object
        );
    */
    SelectObject(hDc, hPen);

    // 5. 开始画线
    /*
        语法格式：
        BOOL LineTo(
            HDC hdc,    // device context handle
            int nXEnd,  // x-coordinate of ending point
            int nYEnd   // y-coordinate of ending point
        );
    */
    LineTo(hDc, 400, 400);

    // 6. 释放资源
    DeleteObject(hPen);
    ReleaseDC(hWnd, hDc);

    return 0;
}