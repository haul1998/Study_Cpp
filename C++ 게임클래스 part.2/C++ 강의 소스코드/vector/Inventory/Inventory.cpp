// Inventory.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*
push_back(인자값) : 벡터에 자료를 넣는다. 제일 뒷쪽에
pop_back() : 벡터의 마지막 자료를 지운다.
size() : 백터에 들어가 있는 자료의 갯수를 반환한다.
begin() : 벡터의 첫번째 값의 주소값
ex) begin() + 3 : 벡터의 첫번째 값으로 부터 3칸 뒤의 주소값 (4번째 자료의 주소값)
end() : 벡터의 마지막 값의 다음 주소값
insert(자료를 넣을 위치 주소값, 넣을 값) : 특정 위치에 값을 넣는다.
insert(자료를 넣을 위치 주소값, 갯수, 넣을 값) : 특정 위치에 지정 갯수 만큼 값을 넣는다.
erase(자료를 지울 위치 주소값) : 특정 위치의 값을 지운다.
clear() : 벡터 전체를 지운다.
empty() : 벡터가 비어있는지 확인
*/

int main()
{
	// 벡터 : 자료를 담는 자료구조
	// vector<담을 자료형> 변수이름; 으로 선언을 한다.
	vector<int> vecInt;

	cout << vecInt.empty() << endl;		// true (1)

	vecInt.push_back(3);
	vecInt.push_back(2);
	vecInt.push_back(4);
	vecInt.push_back(7);

	cout << vecInt.empty() << endl;		// false (0)

	// 벡터 이터레이터 : 벡터의 주소값을 임시로 담을 변수
	vector<int>::iterator iter;
	for (iter = vecInt.begin(); iter != vecInt.end(); iter++)
	{
		cout << (*iter) << endl;
	}

	// [begin] 3 [+1] 2 [+2] 4 [+3] 7 [end]

	cout << *(vecInt.begin() + 3) << endl;
	cout << *(vecInt.end() - 1) << endl;

	// vecInt[3] => *(vecInt.begin() + 3)

	vecInt.insert(vecInt.begin() + 2, 10);		// 3 2 10 4 7
	vecInt.insert(vecInt.begin() + 2, 3, 5);	// 3 2 5 5 5 10 4 7

	// 인덱스로 벡터에 접근 하는 방식
	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}
	cout << endl;

	vecInt.clear();

	cout << vecInt.empty() << endl;

	system("pause");

    return 0;
}

