#include <stdio.h>

void com_mul(int a, int b);                     // 최소 공배수의 개수를 구하는 함수 원형 정의
void com_fac(int a, int b);                     // 최대 공약수의 개수를 구하는 함수 원형 정의
int gcd = 0;                                    // 최대 공약수를 대입할 정수형 변수 선언

int main() {
    com_fac(250, 135);                       // 정수형 인수 두 개를 매개변수로 하여 함수 com_fac() 호출
    com_mul(250, 135);                       // 정수형 인수 두 개를 매개변수로 하여 함수 com_mul() 호출
}

void com_fac(int a, int b) {                    // 최대 공약수의 개수를 구하는 함수 com_fac()
    int cnt = 0;                                // 공약수의 개수를 구해서 대입할 정수형 변수 선언
    int min = (a >= b) ? b : a;                 // 입력 받은 두 수 중 최소값을 정수형 변수 min에 대입
    for(int i=1; i<=min; i++) {                 // 입력 받은 두 수 중 최소값까지 반복문을 수행
        if(a % i == 0 && b % i == 0) {          // 두 수 모두에게 나누어 떨어지는 수를 정수형 변수 gcd에 대입
            gcd = i;
        }
    }

    for(int i=1; i<=gcd; i++) {                 // 최대 공약수까지 반복문을 수행
        if(gcd % i == 0)                        // 최대 공약수의 약수가 공약수이므로 공약수인지를 확인
            cnt++;                              // 조건에 맞다면 공약수의 개수를 저장하는 변수의 값에 1을 더해서 저장
    }
    printf("%d와 %d의 최대 공약수 : %d, 공약수의 개수 : %d개\n", a, b, gcd, cnt);   // 최대 공약수와 공약수의 개수를 형식에 맞게 출력
}

void com_mul(int a, int b) {                     // 최소 공배수의 개수를 구하는 함수 com_mul()
    // 최소 공배수를 대입할 정수형 변수 lcm 선언
    // a를 최대 공약수로 나눈 몫을 저장하기 위한 정수형 변수 rest1 선언
    // b를 최대 공약수로 나눈 몫을 저장하기 위한 정수형 변수 rest2 선언
    int lcm, rest1, rest2;
    int cnt = 0;                                 // 공배수의 개수를 구해서 대입할 정수형 변수 선언 및 초기화
    rest1 = a / gcd;                             // rest1에 a를 최대 공약수로 나눈 몫을 저장함
    rest2 = b / gcd;                             // rest2에 b를 최대 공약수로 나눈 몫을 저장함
    lcm = gcd * rest1 * rest2;                   // 최소 공배수는 최대 공약수에 rest1과 rest2를 곱한 값임

    int lcms = lcm;                              // 최소 공배수의 개수를 구하기 위해 누적시킬 변수 lcms 선언 및 초기화
    while(lcms <= 1000000) {                     // 공배수가 100만 이하일 때
        lcms += lcm;                             // 공배수를 구함
        cnt++;                                   // 공배수의 개수를 구함
    }
    printf("%d와 %d의 최소 공배수 : %d, 공배수의 개수 : %d개", a, b, lcm, cnt);    // 최소 공배수와 공배수의 개수를 형식에 맞게 출력
}





