#include <iostream>			// include : 포함하다 / iostream 이라는 라이브러리(데이터)를 추가(정보 불러오기)
using namespace std;		// 전체적으로 namespace 영역을 설정하는 명령어. 이 명령어를 사용해두면 명령어들 앞에 std:: 를 입력하지 않아도 된다.

void main()					// 메인 함수, ()안에 나중에 함수 추가 가능
{
	// std : standard 라이브러리 문법을 사용하겠다 라는 명령어
	cout << "Hello World!!" << endl << "안녕하세요!!" << endl;

	// cout : 출력 명령어
	// << : 명령 구분
	// endl : endline 의 줄임말. 줄바꿈을 해준다.
	// ; : 명령이 끝났음을 알려주는 문자. 없으면 오류가 나고 작동이 되지 않는다.
	std::cout << "Hello World!" << std::endl;
	std::cout << "안녕하세요!" << std::endl;
	
	printf("Good Bye C code!!\n");

	system("pause");
}