#include "stdafx.h"

void Keyboard(bool* playing, int* x, int* y);
void Draw(HANDLE hOP, int x, int y, char* str, WORD color);

int main()
{
    HANDLE hOP;     // 핸들 값 가져오기, 차를 핸들로 운전하듯 전체 프로그램을 관리
    hOP = GetStdHandle(STD_OUTPUT_HANDLE);

    // 커서 숨기기
    CONSOLE_CURSOR_INFO CurInfo;
    CurInfo.bVisible = false;
    CurInfo.dwSize = 1;
    SetConsoleCursorInfo(hOP, &CurInfo);

    bool isPlaying = true;
    int x = 10;
    int y = 10;

    cout << "x좌표 : " << x << endl;
    cout << "y좌표 : " << y << endl;

    Draw(hOP, x, y, (char*)"A", BACKGROUND_RED);

    while (isPlaying)
    {
        if (_kbhit())            // 키 버퍼 확인, 키 입력이 있는 경우 버퍼의 값이 true가 반환된다.
        {
            Keyboard(&isPlaying, &x, &y);       // 키보드 함수 호출
            
            system("cls");
            cout << "x좌표 : " << x << endl;
            cout << "y좌표 : " << y << endl;
            Draw(hOP, x, y, (char*)"A", BACKGROUND_RED);

            while (_kbhit())
            {
                _getch();
                // 키를 한번만 눌러도 버퍼의 값이 계속 남아있게 한다.
                // getch() 함수는 입력된 키보드 값을 변수로 바로 저장할 때도 사용된다.
                // ex) keyValue = getch();
            }
        }
    }

    return 0;
}

void Keyboard(bool* playing, int* x, int* y)
{
    // GetAsyncKeyState : 비동기식 키 입력 상태를 가져오는 함수
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)        // 오른쪽 방향키
    {
        (*x)++;
    }
    else if(GetAsyncKeyState(VK_LEFT) & 0x8000)         // 왼쪽 방향키
    {
        (*x)--;
    }
    else if (GetAsyncKeyState(VK_UP) & 0x8000)          // 위쪽 방향키
    {
        (*y)--;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)        // 아래쪽 방향키
    {
        (*y)++;
    }
    else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)      // esc
    {
        *playing = false;
    }
}

void Draw(HANDLE hOP, int x, int y, char* str, WORD color)
{
    DWORD dwCharsWritten;
    COORD cdFill = { x, y };

    FillConsoleOutputAttribute(hOP, color, strlen(str), cdFill, &dwCharsWritten);       // FillConsoleOutputAttribute : 색상을 칠해준다.
    WriteConsoleOutputCharacter(hOP, str, strlen(str), cdFill, &dwCharsWritten);        // WriteConsoleOutputCharacter : 문자를 적어준다.
}