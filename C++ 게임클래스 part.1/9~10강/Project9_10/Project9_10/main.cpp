// 9강 게임 규칙 설명만 듣고 완성한 코드입니다.
#include "stdafx.h"

/*
카드 : 1 ~ 12 까지의 숫자 카드
1. 카드 2장이 랜덤하게 선택되고 플레이어에게 보여진다.
   카드 1장은 선택이 되고, 경기 종료까지 오픈되지 않는다.
ex) 7, 10, ?
2. 기본 베팅 금액 : 100원
3. 게임 포기 : 100원만 회수
4. 스탑 : 승부, 추가 베팅 : 카드 추가 오픈
   ㄴ 승부 : 숨겨진 카드가 위에 오픈된 두 숫자 사이의 카드라면 승리  ex ) 숨겨진 카드가 8 or 9일 경우 승리
   ㄴ 추가 배팅 : 배팅 금액이 증가한다. 선택되지 않은 카드 중에 한장이 오픈된다. 추가 배팅 금액량은 따블
*/

int main()
{
    // player의 총 금액, 배팅 금액, 카드 12장(배열), 추가 배팅 횟수 최대 3회, 게임 지속, 3장의 카드
    // 배열의 0, 1 오픈카드 / 2번 카드가 승부 카드 / 4 ~ 6 추가 배팅 시 오픈 카드

    srand(time(NULL));
    rand(); 

    int nPlayerMoney = 1000;//플레이어 금액
    int nPlayerBetting = 0; //배팅 금액
    int nCard[12];          //카드 12장 슬롯 / 오픈카드는 nCard[0], nCard[1] / 선택 카드는 nCard[2] / 추가 배팅 시 nCard[3] ~ nCard[5] 오픈
    int nBetting = 0;       //베팅 횟수
    int nCount;             //카드 오픈 횟수
    int nSelect;            //선택지
    bool bGame = true;
    bool bRule = true;

    while (bGame)
    {
        while (nPlayerMoney > 0 && bRule == true)
        {
            for (int i = 0; i < 12; i++) // 카드에 1 ~ 12 숫자 넣기
            {
                nCard[i] = i + 1;
            }

            for (int i = 0; i < 100; i++) // 셔플
            {
                int nSrc = rand() % 12;
                int nDest = rand() % 12;

                int Temp = nCard[nSrc];
                nCard[nSrc] = nCard[nDest];
                nCard[nDest] = Temp;
            }
            /*
            for (int i = 0; i < 12; i++) // 카드 셔플 확인용
            {
                cout << nCard[i] << endl;
            }
            system("pause");
            */

            bool bRoop = true;
            nPlayerBetting = 100;
            nCount = 0;
            cout << "=======================================" << endl;
            cout << " 현재 금액에서 배팅 금액을 실시간으로" << endl;
            cout << "   차감하지 않으며, 매 판 종료 후" << endl;
            cout << "  베팅 금액만큼 차감 혹은 증가 합니다." << endl;
            cout << "=======================================" << endl;
            cout << "현재 금액      : " << nPlayerMoney << "원" << endl;
            cout << "베팅 금액      : " << nPlayerBetting << "원" << endl;
            cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
            cout << "내 카드        : ?" << endl;
            cout << "추가 배팅 카드 : ? ? ?" << endl;
            cout << "추가 배팅 횟수 : " << nCount << endl;
            cout << "=======================================" << endl;
            cout << "1.추가 배팅, 2.카드 공개, 3.포기 : ";
            cin >> nSelect;

            if (nSelect == 1)
            {
                if (nPlayerMoney >= nPlayerBetting + 100)
                {
                    nPlayerBetting += 100;
                    nCount++;
                    while (nCount > 0 && nCount < 4 && bRoop)
                    {
                        system("cls");

                        if (nCount == 1)
                        {
                            cout << "=======================================" << endl;
                            cout << " 현재 금액에서 배팅 금액을 실시간으로" << endl;
                            cout << "   차감하지 않으며, 매 판 종료 후" << endl;
                            cout << "  베팅 금액만큼 차감 혹은 증가 합니다." << endl;
                            cout << "=======================================" << endl;
                            cout << "현재 금액      : " << nPlayerMoney << "원" << endl;
                            cout << "베팅 금액      : " << nPlayerBetting << "원" << endl;
                            cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
                            cout << "내 카드        : ?" << endl;
                            cout << "추가 배팅 카드 : " << nCard[3] << " ? ?" << endl;
                            cout << "추가 배팅 횟수 : " << nCount << endl;
                            cout << "=======================================" << endl;
                            cout << "1.추가 배팅, 2.카드 공개, 3.포기 : ";
                            cin >> nSelect;
                        }
                        else if (nCount == 2)
                        {
                            cout << "=======================================" << endl;
                            cout << " 현재 금액에서 배팅 금액을 실시간으로" << endl;
                            cout << "   차감하지 않으며, 매 판 종료 후" << endl;
                            cout << "  베팅 금액만큼 차감 혹은 증가 합니다." << endl;
                            cout << "=======================================" << endl;
                            cout << "현재 금액      : " << nPlayerMoney << "원" << endl;
                            cout << "베팅 금액      : " << nPlayerBetting << "원" << endl;
                            cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
                            cout << "내 카드        : ?" << endl;
                            cout << "추가 배팅 카드 : " << nCard[3] << " " << nCard[4] << " ?" << endl;
                            cout << "추가 배팅 횟수 : " << nCount << endl;
                            cout << "=======================================" << endl;
                            cout << "1.추가 배팅, 2.카드 공개, 3.포기 : ";
                            cin >> nSelect;
                        }
                        else if (nCount == 3)
                        {
                            cout << "=======================================" << endl;
                            cout << " 현재 금액에서 배팅 금액을 실시간으로" << endl;
                            cout << "   차감하지 않으며, 매 판 종료 후" << endl;
                            cout << "  베팅 금액만큼 차감 혹은 증가 합니다." << endl;
                            cout << "=======================================" << endl;
                            cout << "현재 금액      : " << nPlayerMoney << "원" << endl;
                            cout << "베팅 금액      : " << nPlayerBetting << "원" << endl;
                            cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
                            cout << "내 카드        : ?" << endl;
                            cout << "추가 배팅 카드 : " << nCard[3] << " " << nCard[4] << " " << nCard[5] << endl;
                            cout << "추가 배팅 횟수 : " << nCount << endl;
                            cout << "=======================================" << endl;
                            cout << "1.추가 배팅, 2.카드 공개, 3.포기 : ";
                            cin >> nSelect;
                        }

                        if (nSelect == 1)
                        {
                            if (nPlayerMoney >= nPlayerBetting + 100)
                            {
                                if (nCount >= 3)
                                {
                                    cout << "더 이상 카드를 공개할 수 없습니다." << endl;
                                    system("pause");
                                }
                                else
                                {
                                    nCount++;
                                    nPlayerBetting += 100;
                                }
                            }
                            else
                            {
                                cout << "금액이 부족합니다." << endl;
                                system("pause");
                            }
                        }
                        else if (nSelect == 2 || nSelect == 3)
                        {
                            bRoop = false;
                        }
                        else if (nSelect != 1 && nSelect != 2 && nSelect != 3 && nSelect != 4)
                        {
                            cout << "=======================================" << endl;
                            cout << "         잘못 입력하였습니다." << endl;
                            cout << "=======================================" << endl;
                            system("pause");
                        }
                    }
                }
                else
                {
                    cout << "금액이 부족합니다." << endl;
                }
            }
            if (nSelect == 2)
            {
                cout << "=======================================" << endl;
                cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
                cout << "내 카드        : " << nCard[2] << endl;
                cout << "=======================================" << endl;

                if (nCard[2] < nCard[1] && nCard[2] > nCard[0] || nCard[2] < nCard[0] && nCard[2] > nCard[1])
                {
                    cout << "승리 + " << nPlayerBetting << "원" << endl;
                    nPlayerMoney = nPlayerMoney + nPlayerBetting;
                }
                else
                {
                    cout << "패배 - " << nPlayerBetting << "원" << endl;
                    nPlayerMoney = nPlayerMoney - nPlayerBetting;
                }
            }
            if (nSelect == 3)
            {
                cout << "=======================================" << endl;
                cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
                cout << "내 카드        : " << nCard[2] << endl;
                cout << "기권 - " << nPlayerBetting - 100 << "원" << endl;
                nPlayerMoney = (nPlayerMoney - nPlayerBetting) + 100;
            }
            else if(nSelect != 1 && nSelect != 2 && nSelect != 3 && nSelect != 4)
            {
                cout << "=======================================" << endl;
                cout << "         잘못 입력하였습니다." << endl;
                cout << "=======================================" << endl;

            }
            system("pause");

            bool bQuest = true;
            char chYN;
            while (bQuest)
            {
                system("cls");
                cout << "=======================================" << endl;
                cout << "      다음 게임 진행하시겠습니까?" << endl;
                cout << "=======================================" << endl;
                cout << "(y , n) : ";
                cin >> chYN;

                if (chYN == 'y' || chYN == 'Y')
                {
                    cout << "=======================================" << endl;
                    cout << "         게임을 이어합니다." << endl;
                    cout << "=======================================" << endl;

                    bQuest = false;
                }
                else if (chYN == 'n' || chYN == 'N')
                {
                    cout << "=======================================" << endl;
                    cout << "         게임을 종료합니다." << endl;
                    cout << "=======================================" << endl;
                    bRule = false;
                    bGame = false;
                    bQuest = false;
                }
                else
                {
                    cout << "=======================================" << endl;
                    cout << "         잘못 입력하였습니다" << endl;
                    cout << "=======================================" << endl;
                }
                system("pause");
                system("cls");
            }
        }
        char chYN;
        cout << "=======================================" << endl;
        cout << "    게임을 다시 시작하시겠습니까?" << endl;
        cout << "=======================================" << endl;
        cout << "(y , n) : ";
        cin >> chYN;

        if (chYN == 'y' || chYN == 'Y')
        {
            cout << "=======================================" << endl;
            cout << "       게임을 재시작 합니다." << endl;
            cout << "=======================================" << endl;
            bGame = true;
            bRule = true;
            system("pause");
            system("cls");
            nPlayerMoney = 1000;
        }
        else if (chYN == 'n' || chYN == 'N')
        {
            cout << "=======================================" << endl;
            cout << "         게임을 종료합니다." << endl;
            cout << "=======================================" << endl;
            bGame = false;
        }
        else
        {
            cout << "=======================================" << endl;
            cout << "         잘못 입력하였습니다" << endl;
            cout << "         게임을 종료합니다." << endl;
            cout << "=======================================" << endl;
            bGame = false;
        }
    }
    system("pause");
    return 0;
}