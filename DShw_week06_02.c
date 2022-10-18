#include <stdio.h>		// 기본 입출력 라이브러리
#include <conio.h> 		// 함수 _getch()를 사용하기 위해 conio.h 포함

int main(void) {
    int size = 0;		// 사용자가 입력한 문자열의 길이를 저장할 정수형 변수 size
    char arr[100] = { 0 };    // 사용자에게 입력 받은 문자열을 저장할 문자 배열 arr을 선언
    printf("100글자 이하의 문자열을 입력해주세요 : "); // 사용자에게 문자열을 입력 받기 위한 멘트를 출력
    for (int i = 0; i < 100; i++) {	// 100번의 for문을 수행
        char key = _getch();	// 한 문자를 입력 받아 char형 변수 key에 대입
        putchar(key);		// key를 출력함
        arr[i] = key;		// 그 key를 배열 arr의 인덱스 i번째 원소에 대입
        if (key == '\r') {	// 사용자가 입력한 문자가 엔터키일 경우
            arr[i] = '\0';	// 배열 arr의 인덱스 i번째 원소에 널문자를 대입
            size = i+1;	// 이 때 (i +1) 값을 size에 대입 (입력한 문자열의 크기를 구함)
            break;		// 반복문 종료
        }
    }

    printf("\n타자 연습 : ");	// 타자 연습이 시작되는 것을 알리는 멘트 출력
    for (int j = 0; j < size; j++) {	// 문자열의 길이 만큼 for문을 수행
        char key = _getch();	// 사용자로부터 문자를 입력 받음
        if (key != arr[j]) {	// 사용자가 입력한 값과 해당 위치의 문자가 같지 않을 경우
            printf("\a");	// 경고음 출력
            j--;		// j값을 1 감소시킴
        }
        else			// 사용자가 입력한 값과 해당 위치의 문자가 같을 경우
            putchar(key);	// key를 출력
    }
    return 0;			// 0을 반환하고 프로그램 종료
}
