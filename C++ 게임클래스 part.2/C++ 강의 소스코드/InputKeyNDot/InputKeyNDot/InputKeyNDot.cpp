// InputKeyNDot.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//void Keyboard(bool *playing, int *x, int *y);
//void Draw(HANDLE hOP, int x, int y, char *str, WORD color);
//
//int main()
//{
//	HANDLE hOP;	// 핸들 값 가져오기
//	hOP = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// 커서 숨기기
//	CONSOLE_CURSOR_INFO curInfo;
//	curInfo.bVisible = false;
//	curInfo.dwSize = 1;
//	SetConsoleCursorInfo(hOP, &curInfo);
//
//	bool isPlaying = true;
//	int x = 10, y = 10;
//
//	cout << "x좌표 : " << x << endl;
//	cout << "y좌표 : " << y << endl;
//	Draw(hOP, x * 2, y, (char*)"A", BACKGROUND_RED);
//
//	while (isPlaying)
//	{
//		if (_kbhit())		// 키 버퍼 확인 : 키 입력이 있는 경우 버퍼에 값이 생겨서 true 가 반환 된다.
//		{
//			Keyboard(&isPlaying, &x, &y); // 키보드 함수 호출
//
//			system("cls");
//			cout << "x좌표 : " << x << endl;
//			cout << "y좌표 : " << y << endl;
//			Draw(hOP, x * 2, y, (char*)"A", FOREGROUND_INTENSITY);
//			while (_kbhit()) _getch();	// 키를 한번만 눌러도 버퍼에 값이 계속 남아 있게 되서 그 값들을 getch() 함수를 이용해서 비워줌.
//										// getch() 함수는 입력 된 키보드 값을 변수로 바로 저장 할 때도 사용 됨 ex) keyValue = getch();
//		}
//	}
//
//    return 0;
//}
//
//void Keyboard(bool *playing, int *x, int *y)
//{
//	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)		// 오른쪽 방향키
//		(*x)++;
//	else if (GetAsyncKeyState(VK_LEFT) & 0x8000)	// 왼쪽 방향키
//		(*x)--;
//	else if (GetAsyncKeyState(VK_UP) & 0x8000)		// 위쪽 방향키
//		(*y)--;
//	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)	// 아래쪽 방향키
//		(*y)++;
//	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)	// ESC
//		*playing = false;
//}
//
//void Draw(HANDLE hOP, int x, int y, char *str, WORD color)
//{
//	DWORD dwCharsWritten;
//	COORD cdFill = { x, y };
//
//	FillConsoleOutputAttribute(hOP, color, strlen(str), cdFill, &dwCharsWritten);
//	WriteConsoleOutputCharacter(hOP, str, strlen(str), cdFill, &dwCharsWritten);
//}

void Keyboard(bool* playing, int* x, int* y);
void Draw(HANDLE hOP, int x, int y, const char* str, WORD color);

int main()
{

	HANDLE hOP; // 핸들 값(차를 핸들로 운전하듯 전체 프로그램을 관리) 가져오기
	hOP = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 숨기기
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = false;
	curInfo.dwSize = 1;
	SetConsoleCursorInfo(hOP, &curInfo);


	bool isPlaying = true;
	int x = 10, y = 10;


	while (isPlaying)
	{
		if (_kbhit()) // 키 버퍼 확인 : 키입력이있는경우 버퍼에 값이 생겨서 true반환
		{
			Keyboard(&isPlaying, &x, &y); // 키보드 함수 호출

			system("cls");

			cout << "x좌표 : " << x << endl;
			cout << "y좌표 : " << y << endl;
			Draw(hOP, x * 2, y, (char*)"A", FOREGROUND_INTENSITY);
			while (_kbhit()) _getch(); // 키를 한번만 눌러도 버퍼에 값이 계속 남아있게 됨
									 // getch()함수는 입력된 키보드 값을 변수 바로 저장할때 사용
									 // ex) keyValue = getch();
		}
	}
	return 0;
}

void Keyboard(bool* playing, int* x, int* y)
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 오른쪽 방향키
		(*x)++;
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 왼쪽 방향키
		(*x)--;
	else if (GetAsyncKeyState(VK_UP) & 0x8000) // 위쪽 방향키
		(*y)--;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래쪽 방향키
		(*y)++;
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // ESC 방향키
		*playing = false;
}

void Draw(HANDLE hOP, int x, int y, const char* str, WORD color)
{
	DWORD dwCharsWritten;
	COORD cdFill = { x,y };

	FillConsoleOutputAttribute(hOP, color, strlen(str), cdFill, &dwCharsWritten); // Color
	WriteConsoleOutputCharacter(hOP, str, strlen(str), cdFill, &dwCharsWritten);
}