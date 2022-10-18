#include <stdio.h>                      // 기본 입출력 라이브러리
#include <string.h>                     // 함수 strlen()을 사용하기 위한 라이브러리

int countExChar(const char *str);       // char형 포인터를 매개변수로 하여, 공백을 제외한 문자의 개수를 반환하는 함수 countExChar()
int countInChar(const char *str);       // char형 포인터를 매개변수로 하여, 공백을 포함한 문자의 개수를 반환하는 함수 countInChar()

int main(void) {
    char line1[100];                    // 파일의 이름을 입력 받는 문자 배열 line1 선언
    char line2[1000] = {0};             // 파일의 내용을 담을 문자 배열 line2 선언 및 초기화
    int includeSpace=0, excludeSpace=0, countLine=1;

    FILE *fp;           // 파일 포인터 fp
    printf("파일의 경로를 입력하세요. : ");   // 사용자에게 파일의 경로를 입력 받기 위한 멘트 출력
    scanf("%s", line1); // 문자열을 입력 받고 line1에 대입
    fp = fopen(line1, "r"); // line1에 저장된 문자열의 이름을 가진 파일을 읽기 모드로 염
    if(fp) {            // 파일 포인터 fp가 참일 때
        fread(line2, sizeof(line2), 1, fp);     // fp 스트림에 저장된 데이터 블록을 읽어오는 fread() 함수 실행
        printf("텍스트 파일의 내용 :\n%s\n", line2);    // 배열 line2에 저장된 텍스트 파일의 내용을 출력
        printf("\n");   // 한 줄 개행
    }

    excludeSpace = countExChar(line2);         // 함수 countExChar()을 실행하여 나온 반환값을 변수 excludeSpace에 저장
    printf("문자 수(공백 제외) : %d\n", excludeSpace); // 멘트와 함께 excludeSpace 값을 출력

    includeSpace = countInChar(line2);         // 함수 countInChar()을 실행하여 나온 반환값을 변수 includeSpace에 저장
    printf("문자 수(공백 포함) : %d\n", includeSpace); // 멘트와 함께 includeSpace 값을 출력

    for(int k=0; k<sizeof(line2); k++) {           // line2 배열 크기 만큼 for문 수행
        if(line2[k] == '\n')            // 배열의 원소가 개행 문자일 경우
            countLine++;                // 변수 countLine의 값을 1 증가시킴
        else if(line2[k] == '\0')       // 배열의 원소가 널 문자일 경우
            break;                      // 반복문을 중단
    }
    printf("줄 수 : %d", countLine);     // 멘트와 함께 countLine 값을 출력
    fclose(fp);     // 열었던 파일을 닫음
    return 0;       // 0을 반환하고 프로그램을 종료시킴
}

int countExChar(const char *str) {      // char형 포인터를 매개변수로 하여, 공백을 제외한 문자의 개수를 반환하는 함수 countExChar()
    int size = strlen(str);          // 정수형 변수 size에 문자 배열의 길이를 계산해 대입
    int count = 0;      // 공백 문자를 제외한 문자의 개수를 담을 정수형 변수 count를 선언하고 0으로 초기화
    for(int i=0; i<size; i++) {         // size 값 만큼 for문을 수행
        // 배열의 원소가 알파벳일 경우
        if (65 <= str[i] && str[i] <= 90 || 97 <= str[i] && str[i] <= 122)
            count++;        // count를 1 증가시킴
        // 배열의 원소가 숫자일 경우
        else if (48 <= str[i] && str[i] <= 57)
            count++;        // count를 1 증가시킴
        // 배열의 원소가 특수 문자일 경우
        else if (58 <= str[i] && str[i] <= 64 || 91 <= str[i] && str[i] <= 96 || 123 <= str[i] && str[i] <= 126)
            count++;        // count를 1 증가시킴
        // 배열의 원소가 개행 문자일 경우
        else if(str[i] == '\n')
            count++;        // count를 1 증가시킴
        // 배열의 원소가 한글일 경우
        else if(str[i] > 128)
            count++;        // count를 1 증가시킴
    }
    return count;           // count를 반환
}

int countInChar(const char *str) {      // char형 포인터를 매개변수로 하여 공백을 포함한 문자의 개수를 반환하는 함수 countInChar()
    int size = strlen(str);          // 정수형 변수 size에 문자 배열의 길이를 계산해 대입
    int count = 0;      // 공백 문자를 제외한 문자의 개수를 담을 정수형 변수 count를 선언하고 0으로 초기화
    for(int i=0; i<size; i++) {         // size 값 만큼 for문을 수행
        // 배열의 원소가 알파벳일 경우
        if(65 <= str[i] && str[i] <= 90 || 97 <= str[i] && str[i] <= 122)
            count++;        // count를 1 증가시킴
        // 배열의 원소가 숫자일 경우
        else if(48 <= str[i] && str[i] <= 57)
            count++;        // count를 1 증가시킴
        // 배열의 원소가 공백 문자이거나 개행 문자일 경우
        else if(str[i] == 32 || str[i] == '\n')
            count++;        // count를 1 증가시킴
        // 배열의 원소가 특수 문자일 경우
        else if(58 <= str[i] && str[i] <= 64 || 91 <= str[i] && str[i] <= 96 || 123 <= str[i] && str[i] <= 126)
            count++;        // count를 1 증가시킴
        // 배열의 원소가 한글일 경우
        else if(str[i] > 128)
            count++;        // count를 1 증가시킴
    }
    return count;           // count를 반환
}