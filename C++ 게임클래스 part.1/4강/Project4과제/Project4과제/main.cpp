// 묵찌빠 만들기
// 강의 내용 중에 루프를 존재하지 않기에 묵찌빠가 비겼을 경우 다시 한번 실행하는 코드는 만들지 않음
// 묵찌빠는 1회만 진행하도록 설계
// 가위바위보로 묵찌빠 공격하는 것을 기준으로 묵찌빠 낼 것을 먼저 선택함
// 컴퓨터가 묵찌빠를 먼저 선택한 것을 확인할 수 있도록 결과물에선 묵찌빠 결과물을 보여주게 나올 것

#include <iostream>
#include "stdafx.h"

void main()
{
    srand(time(NULL));
    rand(); // 항상 랜덤값을 가짐

    int nA = rand(); //한번 랜덤 값을 입력했기 때문에 다시 입력하기 전까지 고정값을 가짐
    //cout << rand() << endl << nA << endl << rand() << endl << nA << endl << rand() << endl << nA; // (궁금해서 해본 내용)
    
    int nCom = rand() % 3; // 가위바위보 랜덤하게 선택
    int nPlayer;
    
    cout << "1.가위, 2.바위, 3.보" << endl << "입력 : ";

    cin >> nPlayer;
    nPlayer -= 1; // 1 ~ 3 으로 진행할 예정인데 컴퓨터 입력값은 0 ~ 2 이기 때문에 빼준다.
    
    cout << "=========================" << endl;
    cout << "컴퓨터 : " << nCom << endl << "플레이어 : " << nPlayer << endl;

    if (nCom == nPlayer)
        cout << "무승부" << endl;

    else if ((nCom + 1) % 3 < nPlayer)
    {
        cout << "=========================" << endl;
        cout << "플레이어 선공!!" << endl;
        cout << "컴퓨터 묵찌빠 선택 상황 : ???" << endl; // 상단 주석에 작성했듯이 선공은 플레이어이기에 컴퓨터는 선택 불가능
        cout << "1.묵, 2.찌, 3,빠" << endl << "입력 : ";
        cin >> nPlayer;
        nCom = rand() % 3; // 묵찌빠 중에 랜덤하게 실행
        
        cout << "컴퓨터 : " << nCom << endl << "플레이어 : " << nPlayer << endl; // 묵찌빠 결과

        if (nCom == nPlayer)
            cout << "결과 : 무승부" << endl;

        else if (nCom + 1 % 3 < nPlayer)
            cout << "결과 : 플레이어 승" << endl;

        else
            cout << "결과 : 컴퓨터 승" << endl;
    }

    else
    {
        cout << "=========================" << endl;
        cout << "컴퓨터 선공!!" << endl;
        nCom = rand() % 3;
        cout << "컴퓨터 묵찌빠 선택 상황 : " << nCom << endl; // 상단 주석에 작성했듯이 컴퓨터의 선택 결과물을 표기
        cout << "1.묵, 2.찌, 3,빠" << endl << "입력 : ";
        cin >> nPlayer;
        cout << "=========================" << endl;

        cout << "컴퓨터 : " << nCom << endl << "플레이어 : " << nPlayer << endl;

        if (nCom == nPlayer)
            cout << "결과 : 무승부" << endl;

        else if (nCom + 1 % 3 < nPlayer)
            cout << "결과 : 플레이어 승" << endl;

        else
            cout << "결과 : 컴퓨터 승" << endl;
    }
    system("pause");
}


// cin으로 nPlayer 값을 입력했을 때 가위바위보와 묵찌빠가 글씨로 나오게 하는것을 다중if문이 아닌 case를 써야하는가. 아니면 다른 방법이 있는가.