#include "stdafx.h"

// 반복문
// for 문    : 특정 횟수를 반복하도록 만드는 구문 (특징 O / 정의 X / 무한으로 작동하게도 가능)
// while 문  : 특정 조건이 성립되는 동안 무한으로 반복하는 구문 (특징 O / 정의 X / 특정 조건이 성립이 되도 반복이 끝나게 할 수도 있음)
// break     : 반복문을 빠져나가게 하는 명령어
int main()
{
    srand(time(NULL));
    rand();

    int nA, nB;
    int nPlayer, nCom;
    int nPW = 0;
    int nCW = 0;
    //bool isContinue; // while문에 사용하기 위해 bool 값 선언
    bool isContinue = true;
    /*
    for (int i = 0; i < 5; i++) //i를 쓰는 이유는 interator의 앞글자를 땃다
    {
        // 1. 변수 선언 및 초기화
        // 2. 조건 검사 (조건이 맞지 않으면 for문을 빠져나간다.)
        // 3. 알고리즘 실행
        // 4. 증강값 적용
        // 5. 2 ~ 4번 반복
        //6. 2번의 조건이 맞지 않을 시 for문 탈출

        cout << "A값 : ";
        cin >> nA;
        cout << "B값 : ";
        cin >> nB;

        cout << "덧셈 결과 : " << nA + nB << endl;
    }
    */

    //while (true) // 값이 참일 경우 무한히 반복
    /*
    while(isContinue)
    {
        cout << "a값 : ";
        cin >> nA;
        cout << "b값 : ";
        cin >> nB;

        cout << "덧셈 결과 : " << nA + nB << endl;
        cout << "0.종료, 1.계속 : " ; // 0은 false, 1은 true
        cin >> isContinue;

        if (isContinue == false)
            break;
    }
    */
    
    // 4장에서 사용한 가위바위보를 3판 2선승으로 만들어보기
    while (isContinue)
    {
        cout << "1.가위, 2.바위, 3.보 : ";
        cin >> nPlayer;

        nCom = rand() % 3 + 1; // 이번 강의에서는 컴퓨터의 결과물을 1 2 3 으로 나오게 할 것

        if (nPlayer == 1)
        {
            cout << "플레이어 : 가위 VS ";
            if (nCom == 1)
            {
                cout << "가위 : 컴퓨터" << endl << "무승부" << endl;
            }

            else if (nCom == 2)
            {
                cout << "바위 : 컴퓨터" << endl << "컴퓨터 승!!" << endl;
                nCW++;
            }

            else
            {
                cout << "가위 : 보" << endl << "플레이어 승!!" << endl;
                nPW++;
            }
        }

        else if (nCom == 2)
        {
            cout << "플레이어 : 바위 VS ";
            if (nCom == 1)
            {
                cout << "가위 : 컴퓨터" << endl << "플레이어  승!!" << endl;
                nPW++;
                
            }

            else if (nCom == 2)
            {
                cout << "바위 : 컴퓨터" << endl << "무승부" << endl;
            }

            else
            {
                cout << "가위 : 보" << endl << "컴퓨터 승!!" << endl;
                nCW++;
            }
        }

        else
        {
            cout << "플레이어 : 보 VS ";
            if (nCom == 1)
            {
                cout << "가위 : 컴퓨터" << endl << "컴퓨터 승!!" << endl;
                nCW++;

            }

            else if (nCom == 2)
            {
                cout << "바위 : 컴퓨터" << endl << "플레이어 승!!" << endl;
                nPW++;
            }

            else
            {
                cout << "가위 : 보" << endl << "무승부" << endl;
            }
        }

        cout << "점수 - 플레이어 : " << nPW << " VS " << nCW << " : 컴퓨터" << endl;
        cout << "====================================" << endl;

        if (nPW == 2)
        {
            cout << "플레이어 최종 승리!!";
            break; // isContinue = false; 로 해도 작동됨
        }

        else if (nCW == 2)
        {
            cout << "컴퓨터 최종 승리!!";
            isContinue = false;
        }
    }

    system("pause");
    
    return 0;
}