#include <Windows.h>
int main()
{
    /*
    int MessageBox(
        HWND hWnd,          // handle to owner window
        LPCTSTR lpText,     // text in message box
        LPCTSTR lpCaption,  // message box title
        UINT uType          // message box style
    );
    );
    */
    // MessageBox(0, TEXT("hello world"),TEXT("title"), MB_OK);
    // CHAR strTitle[] = "Title";
    // CHAR strContent[] = "Hello World!";
    // MessageBoxA(0, strContent, strTitle, MB_OK);

    // WCHAR strTitle1[] = L"Title";
    // WCHAR strContent1[] = L"Hello World!";
    // MessageBoxW(0, strContent1, strTitle1, MB_OK);

    TCHAR strTitle2[] = TEXT("Title");
    TCHAR strContent2[] = TEXT("Hello World!");
    MessageBox(0, strContent2, strTitle2, MB_OK);
    return 0;
}