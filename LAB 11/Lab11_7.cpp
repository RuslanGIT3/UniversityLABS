#include <windows.h>
#include <string>
#include <algorithm>
#include<cmath>
constexpr int ID_EDIT1 = 1;
constexpr int ID_EDIT2 = 2;
constexpr int ID_EDIT3 = 3;
constexpr int ID_BUTTON = 4;
constexpr int FirstN = 5;
constexpr int SecondN = 6;
constexpr int ThirdN = 7;
constexpr int Result = 8;
using namespace std;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: {
        CreateWindowEx(0, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            55, 50, 100, 25, hwnd, (HMENU)ID_EDIT1, NULL, NULL);
        CreateWindowEx(0, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
           205, 50, 100, 25, hwnd, (HMENU)ID_EDIT2, NULL, NULL);
        CreateWindowEx(0, "EDIT", "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            355, 50, 100, 25, hwnd, (HMENU)ID_EDIT3, NULL, NULL);

        CreateWindowEx(0, "BUTTON", "Площадь параллелограмма",
            WS_CHILD | WS_VISIBLE,
            150, 90, 200, 30, hwnd, (HMENU)ID_BUTTON, NULL, NULL);

        CreateWindowEx(0, "STATIC", "Первое сторана",
            WS_CHILD | WS_VISIBLE ,
            50, 20, 110, 25, hwnd, (HMENU)FirstN, NULL, NULL);
        CreateWindowEx(0, "STATIC", "Вторая сторона",
            WS_CHILD | WS_VISIBLE ,
            200, 20, 110, 25, hwnd, (HMENU)SecondN, NULL, NULL);
        CreateWindowEx(0, "STATIC", "Угол",
            WS_CHILD | WS_VISIBLE,
            350, 20, 110, 25, hwnd, (HMENU)ThirdN, NULL, NULL);

        CreateWindowEx(0, "STATIC", "",
            WS_CHILD | WS_VISIBLE ,
            150, 140, 200, 70, hwnd, (HMENU)Result, NULL, NULL);
        break;
    }

    case WM_COMMAND: {
        if (LOWORD(wParam) == ID_BUTTON) {
            char text1[256], text2[256], text3[256];
            GetDlgItemText(hwnd, ID_EDIT1, text1, sizeof(text1));
            GetDlgItemText(hwnd, ID_EDIT2, text2, sizeof(text2));
            GetDlgItemText(hwnd, ID_EDIT3, text3, sizeof(text3));
            int number1 = atoi(text1);
            int number2 = atoi(text2);
            double sin1 = atoi(text3);
            double par = number1 * number2 * sin(sin1 * 3.14159265 / 180);
            string message;
            message = to_string(par);
            SetDlgItemText(hwnd, Result, message.c_str());
            
            
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nShowCmd) {
    const char CLASS_NAME[] = " ";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = CreateSolidBrush(RGB(100, 250, 100));

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        " ",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 530, 300,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nShowCmd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}