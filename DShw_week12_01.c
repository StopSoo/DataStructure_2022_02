#include <stdio.h>          // 기본 입출력 라이브러리
#include <stdlib.h>         // 랜덤 함수를 사용하기 위한 헤더 파일
#include <time.h>           // 랜덤 함수의 seed 값으로 time을 사용하기 위한 헤더 파일
#define MAX_VERTICES 30     // 정점 개수의 최대값을 정의

typedef struct GraphNode {  // 인접리스트를 구성하는 각 노드를 나타내기 위한 구조체 GraphNode
    int vertex;     // 정점이 가진 값
    struct GraphNode* link;     // 다음 노드로 연결되는 링크
} GraphNode;

typedef struct GraphType {  // 그래프 자체를 나타내기 위한 구조체 GraphType
    int num;        // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];  // MAX_VERTICES의 크기를 갖는 인접리스트
} GraphType;

void initial(GraphType* g) {    // 그래프 초기화 함수
    g->num = 0;     // 그래프의 정점의 개수를 0으로 초기화
    for (int i=0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;  // 인접 리스트의 모든 원소들을 NULL로 초기화
    }
}

void insertVertex(GraphType* g, int v) {    // 정점의 개수를 증가시키는 함수
    if (((g->num) + 1) > MAX_VERTICES) {    // 정점 개수의 최대값을 넘으면
        fprintf(stderr, "정점 개수의 최대값을 초과하였습니다.\n");  // 표준 에러 출력 장치를 통한 에러 메시지 출력
        return;     // 종료시킴
    }
    g->num++;   // 그래프 정점의 개수를 1 증가시킴
}

void insertEdge(GraphType* g, int u, int v) {   // 간선을 추가하는 함수
    GraphNode* node;    // 새로운 노드를 생성
    if (u >= g->num || v >= g->num) {   // 두 인수 중 하나라도 정점의 최대 개수 이상이라면
        fprintf(stderr, "정점 인덱스의 값이 잘못되었습니다.\n");   // 표준 에러 출력 장치를 통한 에러 메시지 출력
        return;     // 종료시킴
    }
    // 정점의 최대 개수를 넘지 않을 경우
    node = (GraphNode*)malloc(sizeof(GraphNode));   // 새로운 노드에 메모리를 할당
    node->vertex = v;   // v를 정점이 가진 값에 대입
    node->link = g->adj_list[u];    // 그래프 인접 리스트의 인덱스 u번째 원소를 새로운 노드의 링크가 가리키게 함
    g->adj_list[u] = node;  // 그래프 인접 리스트의 인덱스 u번째 원소에 생성한 노드를 대입
}

void printAdjList(GraphType* g) {   // 인접 리스트를 출력하는 함수
    for (int i=0; i < g->num; i++) {
        GraphNode* p = g->adj_list[i];  // 포인터 p가 그래프 인접 리스트의 i번째 원소를 가리키게 함
        printf("정점 %d의 인접 리스트", i); // 정점의 이름을 포함한 멘트를 출력
        while (p != NULL) { // 인접 리스트가 NULL이 아니라면 반복
            printf(" -> %d", p->vertex);    // 각 정점에 연결되어 있는 정점들을 출력
            p = p->link;    // 다음 노드로 옮겨감
        }
        printf("\n");   // 한 줄 개행
    }
}

int main(void) {
    int n = 0;  // 배열의 크기 n 선언 및 초기화
    srand((unsigned)time(NULL));    // 랜덤 함수 사용
    printf("정점의 개수 n을 입력하시오 >>>  ");    // 사용자로부터 정점의 개수를수입력 받음
    scanf("%d", &n);
    int arr[n][n];      // 인접 행렬 선언
    for (int i = 0; i < n; i++) {   // 인접 행렬 초기화
        for (int j = 0; j < n; j++) {
            if (i == j) // 주대각선에 있는 원소는 0으로 처리
                arr[i][j] = 0;
            else    // 주대각선에 있는 원소가 아니라면
                arr[i][j] = rand() % 2; // 0 or 1 중 하나로 처리
            printf("%d ", arr[i][j]);   // 인접 행렬 출력
        }
        printf("\n");   // 한 줄 개행
    }

    printf("\n");   // 한 줄 개행

    GraphType *g;   // 새로운 그래프 선언
    g = (GraphType*)malloc(sizeof(GraphType));  // 그래프에 대해 메모리를 할당
    initial(g);     // 그래프를 초기화
    for (int i=0; i < n; i++)
        insertVertex(g, i); // 사용자가 입력한 정점의 크기 대로 그래프를 초기화

    for (int i = 0; i < n; i++) {   // 인접 행렬 초기화
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) // 인접 행렬의 원소가 1이라면
                insertEdge(g, i, j);    // 간선을 추가
        }
    }

    printAdjList(g);    // 인접 리스트 출력하는 함수를 실행
    free(g);    // 그래프에 대한 메모리를 반환

    return 0;   // 0을 반환하고 프로그램 종료
}