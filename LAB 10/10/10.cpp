#include <windows.h>
#include <vector>

struct RectData {
    int x;
    int y;
};

std::vector<RectData> ellipse; 

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
   
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L" ";
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 

    RegisterClass(&wc);

   
    HWND hwnd = CreateWindowEx(
        0,                            
        L" ",      
        L" ",        
        WS_OVERLAPPEDWINDOW,          
        CW_USEDEFAULT, CW_USEDEFAULT, 
        600, 400,                     
        nullptr,                    
        nullptr,                   
        hInstance,                  
        nullptr                       
    );

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow); 
    UpdateWindow(hwnd);         
   
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_LBUTTONDOWN:
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);
        ellipse.push_back({ x, y });
        InvalidateRect(hwnd, nullptr, TRUE);
        return 0;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        if (hdc) {
            
            for (const auto& rect : ellipse) {
               
                HPEN hBorderPen = CreatePen(PS_DOT, 1, RGB(128, 0, 128)); 
                HBRUSH hFillBrush = CreateHatchBrush(HS_VERTICAL, RGB(255,0,0));

              
                HGDIOBJ hOldPen = SelectObject(hdc, hBorderPen);
                HGDIOBJ hOldBrush = SelectObject(hdc, hFillBrush);

               
                ::Ellipse(hdc, rect.x - 100, rect.y - 50, rect.x + 100, rect.y + 50);

               
                SelectObject(hdc, hOldPen);
                SelectObject(hdc, hOldBrush);

                
                DeleteObject(hBorderPen);
                DeleteObject(hFillBrush);
            }

            EndPaint(hwnd, &ps);
        }
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}