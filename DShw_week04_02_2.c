#include <stdio.h>

int count = 3;                  // 전역 변수 선언

int func(int n) {               // 수열에서 n번째 수를 얻기 위한 함수 func()
    int arr[n-1];               // 배열에서 n번째 수의 인덱스는 (n-1)이므로 (n-1)의 크기로 선언한 정수형 배열
    arr[0] = 0;                 // 기본값인 배열의 첫 번째 원소 초기화
    arr[1] = 1;                 // 기본값인 배열의 두 번째 원소 초기화
    arr[2] = 2;                 // 기본값인 배열의 세 번째 원소 초기화

    while(count <= n-1) {       // n번째 수에 도달할 때까지 반복문 실행
        arr[count++] = arr[count-3] + arr[count-2] + arr[count-1];  // 배열의 count번째 원소에 직전 세 수의 합을 대입한 후, count를 1 증가시킴
        func(count);         // 증가된 count를 인수로 함수 func() 호출
    }

    int result = arr[n-1];           // 구하려는 값을 정수형 변수 result에 대입
    return result;              // result 반환
}


int main(void) {
    int num;                                // 사용자에게 입력 받은 값을 저장할 정수형 변수 선언
    printf("수열의 몇 번째 값을 출력할까요 ? ");   // 사용자에게 기본 멘트 출력
    scanf("%d", &num);                      // 사용자에게 입력 받은 값을 변수 num에 저장
    printf("수열의 %d번째 값은 %d입니다.", num, func(num));       // 사용자가 원하는 값을 형식에 맞게 출력.

    return 0;                               // 성공하면 0을 반환
}