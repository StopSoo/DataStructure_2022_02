#include <stdio.h>

void print_arr(int *arr, int nSize) {       // 함수의 매개변수로 정수형 배열을 받을 정수형 포인터와 배열의 크기를 받을 정수형 변수를 선언한다.
    for(int i = 0; i < nSize; i++) {        // 배열의 크기 만큼 반복문을 수행하며 배열의 원소를 출력한다.
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int array[] = {1,2,3,4,5, 6, 7, 8, 9, 10};     // 정수형 배열을 하나 선언한 후 초기화한다.
    print_arr(array, 10);          // 배열의 원소를 출력하는 함수를 실행한다.

    return 0;                                // 0을 반환한다.
}