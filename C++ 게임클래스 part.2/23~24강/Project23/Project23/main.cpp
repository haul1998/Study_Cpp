#include "stdafx.h"

void Keyboard(bool *playing, int puzzle[5][5], int *x, int *y);
void Draw(HANDLE hOP, int x, int y, char *str, WORD color);

// 게임 함수들
void InitPuzzle(int puzzle[5][5]);      // 퍼즐 초기화 함수
void Print(HANDLE hOP, int puzzle[5][5], int x, int y);     // 화면에 퍼즐을 그려주는 함수
void DrawBlock(HANDLE hOP, int x, int y, char* str, WORD color);        // 퍼즐을 블럭별로 그려주는 함수

void Swap(int* prevBlock, int* currBlock);      // 두 블럭을 교체 해주는 함수
bool Check(int puzzle[5][5]);                   // 게임 클리어 확인

int main()
{
    system("mode con:lines=25 cols=48");       // 콘솔창의 가로 세로 길이 입력
    srand(time(NULL));
    rand();

    HANDLE hOP;
    hOP = GetStdHandle(STD_OUTPUT_HANDLE);


    CONSOLE_CURSOR_INFO CurInfo;
    CurInfo.bVisible = false;
    CurInfo.dwSize = 1;
    SetConsoleCursorInfo(hOP, &CurInfo);

    bool isPlaying = true;
    int nPuzzle[5][5];

    // 처음 빈칸의 index 번호
    int nX = 4;
    int nY = 4;
    
    InitPuzzle(nPuzzle);
    Print(hOP, nPuzzle, nX, nY);

    while (isPlaying)
    {
        if (_kbhit())
        {
            system("cls");

            Keyboard(&isPlaying, nPuzzle, &nX, &nY);
            Print(hOP, nPuzzle, nX, nY);
            isPlaying = !Check(nPuzzle);

            if (isPlaying == false)
            {
                cout << "CLEAR" << endl;
                system("pause");
            }

            while (_kbhit())
            {
                _getch();
            }
        }
    }

    return 0;
}

// 2 * 3 + 6 * 2 - 8 / 4
// (2 * 3) + (6 * 2) - (8 / 4)          <- 가독성이나 불확실성을 확실하게 하기 위해 괄호를 쳐주는게 좋다

void Keyboard(bool* playing, int puzzle[5][5], int* x, int* y)
{
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && *x < 4)
    {
        Swap(&puzzle[*y][*x], &puzzle[*y][*x + 1]);
        (*x)++;
    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && *x > 0)
    {
        Swap(&puzzle[*y][*x], &puzzle[*y][*x - 1]);
        (*x)--;
    }
    else if (GetAsyncKeyState(VK_UP) & 0x8000 && *y > 0)
    {
        Swap(&puzzle[*y][*x], &puzzle[*y - 1][*x]);
        (*y)--;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && *y < 4)
    {
        Swap(&puzzle[*y][*x], &puzzle[*y + 1][*x + 1]);
        (*y)++;
    }
    else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        *playing = false;
    }
}

void Draw(HANDLE hOP, int x, int y, char* str, WORD color)
{
    DWORD dwCharsWritten;
    COORD cdFill = { x, y };

    FillConsoleOutputAttribute(hOP, color, strlen(str), cdFill, &dwCharsWritten);
    WriteConsoleOutputCharacter(hOP, str, strlen(str), cdFill, &dwCharsWritten);
}

void InitPuzzle(int puzzle[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            puzzle[i][j] = i * 5 + j;
        }
    }

    puzzle[0][0] = 24;
    puzzle[4][4] = 0;

    for (int i = 0; i < 999; i++)           // 홀수로 돌리는 이유는 빈칸으로 시작하니 섞는것을 제외하고 전체 횟수를 짝수로 만든다.
    {
        int nDestX = rand() % 5;
        int nDestY = rand() % 5;

        int nSrcX = rand() % 5;
        int nSrcY = rand() % 5;

        if ((nDestX == 4 && nDestY == 4) || (nSrcX == 4 && nSrcY == 4) || (nDestX == nSrcX && nDestY == nSrcY))
        {
            i--;
            continue;       // for문에서 continue를 사용할 경우 아래쪽을 실행하지 않고 위쪽으로 다시 이동한다.
        }

        int nTemp = puzzle[nDestX][nDestY];
        puzzle[nDestX][nDestY] = puzzle[nSrcX][nSrcY];
        puzzle[nSrcX][nSrcY] = nTemp;
    }
}

void Print(HANDLE hOP, int puzzle[5][5], int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // 숫자가 정수형이여서 숫자를 문자로 변환시켜줘야한다.
            char* szTemp = new char;
            // itoa : 정수값을 문자로 변형해주는 함수

            if (j == x && i == y)        // 빈칸 블럭
            {
                DrawBlock(hOP, 10 + j * 6, 5 + i * 3, (char*)"■", BG_YELLOW | FG_BLACK);
            }
            else
            {
                DrawBlock(hOP, 10 + j * 6, 5 + i * 3, itoa(puzzle[i][j], szTemp, 10 /*10진수*/), BG_YELLOW | FG_BLACK);
            }
        }
    }
}

void DrawBlock(HANDLE hOP, int x, int y, char* str, WORD color)
{
    Draw(hOP, x + 0, y + 0, str, color);
    Draw(hOP, x + 2, y + 0, (char*)"■", color);
    Draw(hOP, x + 0, y + 1, (char*)"■", color);
    Draw(hOP, x + 2, y + 1, (char*)"■", color);
}

void Swap(int* prevBlock, int* currBlock)
{
    int Temp = *prevBlock;
    *prevBlock = *currBlock;
    *currBlock = Temp;
}

bool Check(int puzzle[5][5])
{
    bool isComplete = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 4 && j == 4)
            {
                isComplete = true;
            }

            if (puzzle[i][j] != j + 1 + (i * 5))
            {
                break;
            }
        }
    }

    return isComplete;
}