#include <stdio.h>          // 기본 입출력 라이브러리
#include <stdlib.h>         // abs() 함수를 사용하기 위한 라이브러리 포함
#include <math.h>           // sqrt() 함수를 사용하기 위한 라이브러리 포함

struct circle {             // 원을 구조체 circle로 정의
    int x,y,r;              // 원의 x좌표, y좌표, 반지름을 담는 정수형 변수 x, y, r
};

// 구조체 circle형 변수 두 개를 매개 변수로 받아 두 원 각각의 위치 상태를 체크하고, 위치 관계를 확인해 출력하는 함수 checkPos()
void checkPos(struct circle c1, struct circle c2) {
    printf("첫 번째 원의 중심의 좌표를 입력하세요. (ex: x y) : ");      // 첫 번째 원의 중심의 좌표를 입력 받기 위한 멘트 출력
    scanf("%d %d", &c1.x, &c1.y);       // 사용자로부터 첫 번째 원의 x좌표와 y좌표를 입력 받음
    printf("첫 번째 원의 반지름을 입력하세요. : ");         // 첫 번째 원의 반지름을 입력 받기 위한 멘트 출력
    scanf("%d", &c1.r);                 // 사용자로부터 첫 번째 원의 반지름의 길이를 입력 받음
    printf("두 번째 원의 중심의 좌표를 입력하세요. (ex: x y) : ");      // 두 번째 원의 중심의 좌표를 입력 받기 위한 멘트 출력
    scanf("%d %d", &c2.x, &c2.y);       // 사용자로부터 두 번째 원의 x좌표 y좌표를 입력 받음
    printf("두 번째 원의 반지름을 입력하세요. : ");         // 두 번째 원의 반지름을 입력 받기 위한 멘트 출력
    scanf("%d", &c2.r);                 // 사용자로부터 두 번째 원의 반지름의 길이를 입력 받음

    int distance = sqrt((c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y));     // 두 원의 중심 좌표 사이의 거리를 sqrt() 함수를 이용해 계산 후 정수형 변수 distance에 대입
    int twice = c1.r + c2.r;        // 두 원의 반지름의 길이를 더한 값을 정수형 변수 twice에 대입
    int sub = c1.r - c2.r;          // 두 원의 반지름의 길이의 차를 계산해 정수형 변수 sub에 대입

    // 중심 좌표 사이의 거리가 두 원의 반지름의 길이를 더한 값보다 작고, 두 원의 반지름의 길이의 차가 중심 좌표 사이의 거리보다 작을 때
    if(distance < twice && abs(sub) < distance)
        printf("두 원은 두 점에서 만납니다.");     // 두 원은 두 점에서 만나므로 이에 대한 멘트를 출력
    // 중심 좌표 사이의 거리가 두 원의 반지름의 길이를 더한 값보다 크거나, 두 원의 반지름의 길이의 차가 중심 좌표 사이의 거리보다 클 때
    else if (distance > twice || abs(sub) > distance)
        printf("두 원은 만나지 않습니다.");       // 두 원은 만나지 않으므로 이에 대한 멘트를 출력
    // 중심 좌표 사이의 거리가 두 원의 반지름의 길이를 더한 값과 같을 때
    else if(distance == twice || (abs(sub) == distance && abs(sub) != 0))
        printf("두 원은 한 점에서 만납니다.");    // 두 원은 한 점에서 만나므로(외접) 이에 대한 멘트를 출력
    // 두 원의 반지름의 길이의 차가 0이 아니면서 중심 좌표 사이의 거리와 같을 때
    else if(abs(sub) > distance)
        if(sub > 0)         // 두 원의 반지름의 길이의 차가 양수이면
            printf("원 A 안에 원 B가 있습니다.");// 원 A가 원 B보다 크므로 이에 대한 멘트를 출력
        else                // 두 원의 반지름의 길이의 차가 음수이면
            printf("원 B 안에 원 A가 있습니다.");// 원 B가 원 A보다 크므로 이에 대한 멘트를 출력
    // 모든 경우에 해당하지 않을 때
    else
        printf("두 원은 일치합니다.");          // 두 원은 일치하므로 이에 대한 멘트를 출력
}

int main(void) {
    struct circle circle1, circle2;        // 구조체 circle형 변수 circle1과 circle2를 선언

    checkPos(circle1, circle2);    // circle1과 circle2를 인수로 하여 함수 checkPos() 실행

    return 0;       // 0을 반환하고 프로그램 종료
}