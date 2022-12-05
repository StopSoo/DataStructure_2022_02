#include <stdio.h>      // 기본 입출력 라이브러리
#include <stdlib.h>     // 랜덤 함수를 사용하기 위한 헤더 파일
#include <time.h>       // 랜덤 함수의 seed 값을 time으로 설정하기 위한 헤더파일
#define MAX_SIZE 10     // 배열의 크기를 기호 상수로 설정
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))  // SWAP 함수 정의

// Bubble Sort - 버블 정렬 구현을 위한 함수
void bubble_sort(int list[], int size) {
    int temp;   // 두 값의 교환을 위한 임시 변수 선언
    for (int k=0; k < MAX_SIZE; k++) {  // 랜덤 값으로 생성된 배열 list를 출력
        printf("%d ", list[k]);
    }
    printf("\n");   // 한 줄 개행
    // 정렬 과정
    for (int i = size-1; i > 0; i--) {  // 배열의 마지막 원소부터 기준으로 잡고
        for (int j = 0; j < i; j++) {   // 모든 원소들을 순회하면서
            if (list[j] > list[j+1]) {  // 앞에 있는 원소의 값이 더 클 경우 두 값을 교환함
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
        for (int k=0; k < MAX_SIZE; k++) {  // 한 차례 정렬이 되면 정렬된 배열 list를 출력
            printf("%d ", list[k]);
        }
        printf("\n");   // 한 줄 개행
    }
}
// Insertion Sort - 삽입 정렬 구현을 위한 함수
void insertion_sort (int list[], int size) {
    int next;   // 삽입하려는 값을 담는 변수 next 선언
    int i, j;   // 제어 변수 i, j 선언
    for (int k=0; k < MAX_SIZE; k++) {  // 랜덤 값으로 생성된 배열 list를 출력
        printf("%d ", list[k]);
    }
    printf("\n");   // 한 줄 개행
    for (i = 1; i < size; i++) {
        next = list[i];     // 삽입하려는 list의 인덱스 i번째 원소를 변수 next에 대입
        for (j = i-1; j >= 0 && next < list[j]; j--) {  // 조건에 해당할 경우
            list[j+1] = list[j];    // list[j] 값을 list[j+1]에 대입
        }
        list[j+1] = next;   // next 값을 list[j+1]에 대입
        for (int k=0; k < MAX_SIZE; k++) {  // 한 차례 정렬이 되면 정렬된 배열 list를 출력
            printf("%d ", list[k]);
        }
        printf("\n");   // 한 줄 개행
    }
}
// Quick Sort - 부분 리스트 구현을 위한 함수
int partition (int list[], int left, int right) {
    int pivot, temp;    // 피봇 값, 임시 값을 넣을 변수 선언
    int low, high;      // 양 끝값을 넣을 변수 선언

    low = left;         // 왼쪽 끝 값을 low에 대입
    high = right + 1;   // high 값 초기화
    pivot = list[left]; // 배열의 인덱스 left번째 값을 pivot으로 설정
    // low와 high가 교차할 때까지 이를 반복
    do {
        for (int i=0; i < MAX_SIZE; i++) {  // 랜덤 값으로 생성된 배열 list를 출력
            printf("%d ", list[i]);
        }
        printf("\n");   // 한 줄 개행
        // list[low]가 pivot보다 작으면 low를 증가시킴
        do {
            low++;  // low는 left+1에서 시작 --> left는 pivot !
        } while (low <= right && list[low] < pivot);
        // list[high]가 pivot보다 크면 high를 감소시킴
        do {
            high--; // high는 right에서 시작 --> high의 초기값은 right + 1
        } while (high >= left && list[high] > pivot);
        // low와 high가 교차되지 않았다면 교환시킴
        if (low < high)
            SWAP(list[low], list[high], temp);
    } while (low < high);

    SWAP(list[left], list[high], temp);     // 교환을 통해 pivot을 제 위치에 놓음
    return high;    // 피벗의 위치를 반환
}
// Quick Sort - 분할정복을 통해 정렬
void quick_sort (int list[], int left, int right) {
    if (left < right) { // 정렬할 배열의 원소가 2개 이상이라면
        int q = partition(list, left, right);   // 피벗을 기준으로 리스트를 분할 --> q는 피벗의 위치
        quick_sort(list, left, q-1);   // 피벗보다 작은 값들을 정렬
        quick_sort(list, q+1, right);   // 피벗보다 큰 값들을 정렬
    }
}
// Merge Sort - 합병 정렬 구현을 위한 함수
void merge (int list[], int left, int middle, int right) {
    int i = left;  // i : 정렬된 왼쪽 리스트에 대한 인덱스
    int j = middle + 1;  // j : 정렬된 오른쪽 리스트에  대한 인덱스
    int k = left;  // k : 정렬될 리스트에 대한 인덱스
    int sorted[MAX_SIZE];   // 정렬된 리스트를 담을 배열 sorted 선언
    // 분할되어 정렬된 리스트를 배열 sorted에 합병
    while (i <= middle && j <= right) {
        if (list[i] <= list[j])     // 왼쪽 리스트 정렬
            sorted[k++] = list[i++];
        else    // 오른쪽 리스트 정렬
            sorted[k++] = list[j++];
    }
    while (i <= middle) sorted[k++] = list[i++];    // 왼쪽 리스트 원소들을 배열 sorted에 복사
    while (j <= right) sorted[k++] = list[j++];     // 오른쪽 리스트 원소들을 배열 sorted에 복사
    for (int a = left; a <= right; a++) list[a] = sorted[a];    // 정렬된 리스트가 저장되어 있는 배열 sorted의 원소들을 list에 차례대로 복사
}
// Merge Sort - 합병 정렬 구현을 위한 함수
void merge_sort (int list[], int left, int right) {
    int middle; // 중간 값의 인덱스를 담을 변수 middle 선언
    if (left < right) { // left 값이 right 값보다 작을 때
        middle = (left + right) / 2;    // middle 값을 설정
        merge_sort(list, left, middle);     // 앞쪽 리스트를 정렬
        merge_sort(list, middle+1, right);   // 뒤쪽 리스트를 정렬
        merge(list, left, middle, right);   // 정렬된 2개의 부분 배열을 합병
    }
    printf("\n");   // 한 줄 개행
    for (int i=0; i < MAX_SIZE; i++) {  // 한 차례 정렬이 되면 정렬된 배열 list를 출력
        printf("%d ", list[i]);
    }
}

int main(void) {
    int choice; // 사용자가 선택할 정렬 방식의 번호를 담을 변수 choice 선언
    srand((unsigned)time(NULL));    // 랜덤 값을 사용하기 위해 seed 값을 time으로 설정
    int n = MAX_SIZE;   // 배열의 크기 n을 선언하고 그 값을 MAX_SIZE로 초기화
    int list[n];    // n 값의 크기를 가진 배열 list를 선언
    for (int i=0; i < MAX_SIZE; i++) {  // 배열 list의 원소들을 랜덤 값으로 설정
        list[i] = rand() % 101;
    }
    printf("랜덤으로 구성된 배열 : ");
    for (int i=0; i < MAX_SIZE; i++) {  // 랜덤한 값으로 구성된 배열 출력
        printf("%d ", list[i]);
    }
    printf("입니다.\n\n");
    printf("1.Bubble-Sort\n2.Insertion-Sort\n3.Quick-Sort\n4.Merge-Sort\n");    // 정렬 방식 보기를 출력
    printf("정렬 방식을 선택하세요 : ");
    scanf("%d", &choice);   // 사용자의 입력을 변수 choice에 저장
    printf("\n");
    switch (choice) {   // choice의 값에 따라 다른 함수를 실행
        case 1: // bubble-sort
            printf("* Bubble-Sort\n");
            bubble_sort(list, n);
            break;
        case 2: // insertion-sort
            printf("* Insertion-Sort\n");
            insertion_sort(list, n);
            break;
        case 3: // quick-sort
            printf("* Quick-Sort\n");
            quick_sort(list, 0, n-1);
            break;
        case 4: // merge-sort
            printf("* Merge-Sort\n");
            merge_sort(list, 0, n-1);
            break;
    }

    return 0;   // 0을 반환하고 프로그램 종료
}