#include <stdio.h>              // 기본 입출력 라이브러리
#include <math.h>               // sqrt() 함수를 사용하기 위한 math.h 헤더 파일 포함

struct circle {                 // 원에 대한 구조체 변수
    int x,y,radius;             // 원의 x좌표, y좌표, 반지름을 담는 정수형 변수 선언
};

struct point {                  // 점에 대한 구조체 변수
    int x,y;                    // 점의 x좌표, y좌표
};

// 구조체 circle과 point를 매개변수로 받아 원과 점의 위치 관계를 알려주는 함수 checkPos()
void checkPos(struct circle c, struct point p) {
    printf("원의 중심의 좌표를 입력하세요. (ex: x y) : ");   // 원의 중심의 좌표를 입력 받기 위한 멘트를 출력
    scanf("%d %d", &c.x, &c.y);                      // struct circle형의 변수 c의 x와 y에 사용자가 입력한 값을 대입
    printf("원의 반지름의 길이를 입력하세요. : ");           // 원의 반지름의 길이를 입력 받기 위한 멘트를 출력
    scanf("%d", &c.radius);                          // struct circle형의 변수 c의 radius에 사용자가 입력한 값을 대입
    printf("점의 좌표를 입력하세요. (ex: x y) : ");       // 점의 좌표를 입력 받기 위한 멘트를 출력
    scanf("%d %d", &p.x, &p.y);                     // struct point형의 변수 p의 x와 y에 사용자가 입력한 값을 대입

    int distance = sqrt((c.x-p.x)*(c.x-p.x) + (c.y-p.y)*(c.y-p.y));         // 원의 중심 좌표와 점 사이의 거리를 sqrt() 함수를 이용해서 계산한 후 정수형 변수 distance에 대입
    if(distance < c.radius)                 // distance가 원의 반지름의 길이보다 작을 경우
        printf("점은 원 안에 있습니다.");        // 점은 원 안에 있으므로 이에 대한 멘트를 출력
    else if(distance > c.radius)            // distance가 원의 반지름의 길이보다 클 경우
        printf("점은 원 밖에 있습니다.");        // 점은 원 밖에 있으므로 이에 대한 멘트를 출력
    else                                    // distance가 원의 반지름의 길이와 같을 경우
        printf("점은 원 위에 있습니다.");        // 점은 원 위에 있으므로 이에 대한 멘트를 출력
}

int main(void) {
    struct circle circle1;               // struct circle형 circle1을 선언
    struct point po1;                    // struct point형 po1을 선언

    checkPos(circle1, po1);       // circle1과 po1에 대해 함수 checkPos()를 실행

    return 0;                           // 0을 반환하고 프로그램 종료
}