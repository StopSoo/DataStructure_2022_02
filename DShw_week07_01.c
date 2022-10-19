#include <stdio.h>              // 기본 입출력 라이브러리
#include <stdlib.h>             // malloc()을 사용하기 위한 헤더 파일 포함

int main(void) {
    // 기본 원소 선언 및 초기화 파트
    int m, n1, n2, p;                                  // 행렬 A와 B의 행의 개수, 열의 개수를 담을 정수형 변수 선언
    printf("행렬 A의 행의 수와 열의 수를 입력하세요. : ");      // 사용자에게 행렬 A의 행, 열의 수를 입력 받기 위한 멘트를 출력
    scanf("%d %d", &m, &n1);                           // 사용자에게 입력 받은 두 정수를 변수 m, n1에 저장
    printf("행렬 B의 행의 수와 열의 수를 입력하세요. : ");      // 사용자에게 행렬 B의 행, 열의 수를 입력 받기 위한 멘트를 출력
    scanf("%d %d", &n2, &p);                           // 사용자에게 입력 받은 두 정수를 변수 n2, p에 저장
    if(n1 != n2) {                                     // 행렬 A의 열의 수와 행렬 B의 행의 수가 같지 않을 경우
        printf("행렬 A의 열의 개수와 행렬 B의 행의 개수는 같아야 합니다.\n");     // 사용자에게 알려주는 멘트를 출력
        printf("프로그램이 종료되었습니다.");                 // 프로그램이 종료되었다는 멘트를 출력
        return 0;                                      // 0을 반환하고 프로그램 종료
    }

    // 행렬 A, B 동적 할당 파트
    int **arr1 = (int **)malloc(sizeof(int)*m);     // 행렬 A를 담기 위해 이중 포인터 arr1 선언 및 변수 m의 크기 만큼 동적 할당
    for(int a=0; a<m; a++) {                             // for문을 m번 수행
        arr1[a] = (int *)malloc(sizeof(int)*n1);    // 일차원 배열 arr1의 원소 당 크기가 n1인 메모리를 할당하여, arr1을 이차원 배열로 만듬
    }
    int **arr2 = (int **)malloc(sizeof(int)*n2);    // 행렬 B를 담기 위해 이중 포인터 arr2 선언 및 변수 n2의 크기 만큼 동적 할당
    for(int b=0; b<n2; b++) {                            // for문을 n2번 수행
        arr2[b] = (int *)malloc(sizeof(int)*p);     // 일차원 배열 arr2의 원소 당 크기가 p인 메모리를 할당하여, arr2를 이차원 배열로 만듬
    }

    // 행렬 A, B 초기화 파트
    printf("행렬 A의 원소를 입력해주세요.\n");      // 행렬 A의 원소를 입력 받기 위해 기본 멘트 출력
    for(int i=0; i<m; i++) {                 // for문을 m번 수행
        for(int j=0; j<n1; j++) {            // i를 한 번 수행할 때마다 n1번의 내부 for문을 수행
            printf("A[%d][%d] = ", i, j);    // 행렬 A의 몇 번째 원소를 입력해야 하는지 알려줌
            scanf("%d", &arr1[i][j]);        // 행렬 A의 원소를 입력 받음
        }
    }
    printf("행렬 B의 원소를 입력해주세요.\n");      // 행렬 B의 원소를 입력 받기 위해 기본 멘트 출력
    for(int i=0; i<n2; i++) {                // for문을 n2번 수행
        for(int j=0; j<p; j++) {             // i를 한 번 수행할 때마다 p번의 내부 for문을 수행
            printf("B[%d][%d] = ", i, j);    // 행렬 B의 몇 번째 원소를 입력해야 하는지 알려줌
            scanf("%d", &arr2[i][j]);        // 행렬 B의 원소를 입력 받음
        }
    }

    // 행렬 C 동적 할당 및 초기화 파트
    int **arr3 = (int **)malloc(sizeof(int)*m);     // 행렬 A와 행렬 B의 곱을 담기 위해 이중 포인터 arr3 선언 및 변수 m의 크기 만큼 동적 할당
    for(int c=0; c<m; c++) {                             // for문을 m번 수행
        arr3[c] = (int *)malloc(sizeof(int)*p);     // 일차원 배열 arr3의 원소 당 크기가 p인 메모리를 할당하여, arr3을 이차원 배열로 만듬
    }
    for(int d=0; d<m; d++) {                             // for문을 m번 수행
        for(int e=0; e<p; e++) {                         // 내부 for문을 p번 수행
            arr3[d][e] = 0;                              // 행렬 C의 원소들을 0으로 초기화
            for(int f=0; f<n1; f++)                      // for문을 n1번 수행
                arr3[d][e] += arr1[d][f] * arr2[f][e];   // 행렬 C의 원소들을 행렬곱의 정의에 맞게 초기화
        }
    }

    // 행렬 C 출력 파트
    printf("행렬 A와 행렬 B의 곱을 저장한 행렬 C : \n");        // 행렬 C를 출력하기 위한 멘트를 출력
    for(int f=0; f<m; f++) {                             // for문을 m번 수행
        for(int g=0; g<p; g++)                           // 내부 for문을 p번 수행
            printf("%d\t", arr3[f][g]);                  // for문을 돌며 arr3의 원소를 차례대로 출력
        printf("\n");                                    // 내부 for문이 종료되면 개행
    }

    // 동적으로 할당 받은 메모리를 해제
    for(int i=0; i<m; i++) {
        free(arr1[i]);                  // for문을 돌면서 배열 arr1의 원소들에 할당되어 있던 메모리를 해제시킴
    }
    free(arr1);                         // arr1 배열 자체에 할당되어 있던 메모리를 해제시킴
    for(int j=0; j<n1; j++) {
        free(arr2[j]);                  // for문을 돌면서 배열 arr2의 원소들에 할당되어 있던 메모리를 해제시킴
    }
    free(arr2);                         // arr2 배열 자체에 할당되어 있던 메모리를 해제시킴
    for(int k=0; k<m; k++) {
        free(arr3[k]);                  // for문을 돌면서 배열 arr3의 원소들에 할당되어 있던 메모리를 해제시킴
    }
    free(arr3);                         // arr3 배열 자체에 할당되어 있던 메모리를 해제시킴
    return 0;                           // 0을 반환하고 프로그램을 종료시킴
}