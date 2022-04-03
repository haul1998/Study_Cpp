#include "stdafx.h"

/*
push_back(인자값) : 벡터에 자료를 넣는다. 제일 뒤쪽에

pop_back() : 벡터의 마지막 자료를 지운다. 그래서 괄호에 아무것도 안들어간다. 반환해주진 않는다.

size() : 벡터에 들어가있는 자료의 갯수를 반환한다.

begin() : 벡터의 첫번째 값의 주소값
ex) begin() + 3 : 벡터의 첫번째 값으로부터 3칸 뒤의 주소값 (4번째 자료의 주소값)

end() : 벡터의 마지막 값의 다음 주소값
	ㄴ 현재 위치가 7일 경우 8의 주소값을 불러온다.

insert(자료를 넣을 위치 주소값, 넣을 값) : 특정 위치에 값을 넣는다.

insert(자료를 넣을 위치 주소값, 갯수, 넣을 값) : 특정 위치에 지정 개수만큼 값을 넣는다.			// 벡터는 중복되는 데이터가 혀옹된다.

erase(자료를 지울 위치 주소값) : 특정 위치의 값을 지운다.

clear() : 벡터 전체를 지운다.

empty() : 벡터가 비어있는지 확인한다.

// ?? : 벡터는 무한정 슬롯을 만들 수 있는 배열 같은 것인가?
*/

int main()
{
	// 벡터 : 자료를 담는 자료구조
	// vector <담을 자료형> 변수이름;	<- 이런 식으로 선언한다.
	vector<int> vecInt;		// int형 이외에도 구조체, 클래스 등 다른 자료형이 들어갈 수도 있다.

	cout << vecInt.empty() << endl;				// 값이 비어있을 때는 true가 반환되어 1이 출력된다.

	vecInt.push_back(3);	// int형이기 때문에 정수가 들어간다.
							// 맨 뒤에 3이 출력된다.
	vecInt.push_back(2);
	vecInt.push_back(4);
	vecInt.push_back(7);						// 값이 비어있지 않을 때는 false가 반환되어 0이 출력된다.

	// 벡터 이터레이터 : 벡터의 주소값을 임시로 담을 변수
	vector<int>::iterator iter;
	for (iter = vecInt.begin(); iter != vecInt.end(); iter++)
	{
		cout << (*iter) << endl;
	}

	cout << *(vecInt.begin() + 3) << endl;
	//cout << *(vecInt.end()) << endl;			// 할당이 되지 않은 공간을 출력하려해서 오류가 난다.
	cout << *(vecInt.end() - 1) << endl;


	//int nData[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	nData[i];
	//}

	// vecInt[3] => *(vecInt.begin() + 3)

	cout << vecInt.empty() << endl;
	
	vecInt[2] = 10;
	vecInt.insert(vecInt.begin() + 2, 5);
	vecInt.insert(vecInt.begin() + 3, 3, 6);
	// index로 vertor에 접근하는 방식
	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}
	
	vecInt.clear();
	cout << vecInt.empty() << endl;

	system("pause");
	return 0;
}