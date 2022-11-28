#include <stdio.h>      // 기본 입출력 라이브러리

int num = 6;    // 그래프 정점의 개수 num 선언 및 초기화
int INF = 10000000; // 거리가 양수 무한대임을 나타내는 변수 INF 선언 및 초기화
int distance[6];    // 거리를 체크

int getMinimumIndex() { // 가장 최소 거리를 가지는 정점을 반환하는 getMinimumIndex()
    int min = INF;  // 최소 거리를 담을 변수 min 선언 및 INF로 초기화
    int index = 0;  // 최소 거리를 가지는 정점의 인덱스를 담을 변수 index 선언 및 초기화
    for (int i = 0; i < num - 1; i++) { // 인덱스 0인 원소부터 인덱스 5인 원소까지 돌면서 v0으로부터 최단 거리에 있는 정점 체크
        if (distance[i+1] < distance[i]) {  // 배열 distance의 인덱스 i번째 원소보다 (i+1)번째 원소가 더 크다면
            min = distance[i+1];    // 변수 min에 배열 distance의 인덱스 (i+1)번째 원소를 저장
            index = i+1;    // 변수 index에 i+1 값을 저장
        }
    }
    return index;   // for문이 끝나면 index를 반환
}

void dijkstra(int arr[6][6], int first) {       // 다익스트라 알고리즘을 사용해서 최단거리를 계산하는 dijkstra()
    for (int i = 0; i < num; i++) {     // for문을 돌면서 distance 배열의 원소들을 초기화
        distance[i] = arr[first][i];
    }

    for (int i = 0; i < num - 2; i++) { // 정점 v0과 연결된 v1, v2, v3 중 가장 최단 거리를 가진 정점을 탐색
        int current = getMinimumIndex();    // getMinimumIndex() 함수를 실행하여 반환 인덱스를 변수 current에 저장
        for (int j = 0; j < 6; j++) {
            // 현재 distance 배열에 저장된 거리보다 더 최단 거리가 있다면, 그 값을 distance 배열의 원소로 바꿈
            if (distance[current] + arr[current][j] < distance[j]) {
                distance[j] = distance[current] + arr[current][j];
            }
        }
    }
}

int main() {
    int array[6][6] = {     // 그래프를 배열로 선언 및 초기화
            {0, INF, 25, 15, INF, INF},
            {15, 0, INF, INF, 10, INF},
            {10, 50, 0, INF, 65, INF},
            {INF, 20, INF, 0, 35, INF},
            {INF, INF, INF, 30, 0, INF},
            {INF, INF, INF, 3, INF, 0}
    };

    dijkstra(array, 0); // 배열 array에 대해 인덱스 0번째부터 dijkstra 함수 실행
    for (int i = 0; i < num-1; i++) {   // 최단 거리 출력
        if (distance[i+1] != INF)   // 계산된 최단 거리가 INF가 아니라면 정상 출력
            printf("정점 v0부터 v%d까지의 최단 거리 : %d\n", (i+1), distance[i+1]);
        else    // 계산된 최단 거리가 INF라면 찾을 수 없다고 출력
            printf("정점 v0부터 v%d까지의 최단 거리 : 찾을 수 없습니다.\n", (i+1));
    }

    return 0;   // 0을 반환하고 프로그램 종료
}