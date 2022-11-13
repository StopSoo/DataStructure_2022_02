#include <stdio.h>              // 기본 입출력 라이브러리
#include <string.h>             // strcpy() 함수를 사용하기 위한 헤더 파일
#define MAX 100                 // 배열의 크기를 기호 상수로 정의

typedef struct Info Student;    // 학생의 정보를 구조체로 선언 후 typedef를 사용하여 이름을 변경
struct Info {                   // 학생의 정보를 담는 구조체 Info
    char name[10];              // 학생의 이름을 담는 문자 배열 name
    int score;                  // 학생의 성적을 담는 정수형 변수 score
};
typedef struct Node Node;       // 노드를 구조체로 선언 후 typedef를 사용하여 이름을 변경
struct Node {                   // 노드 포인터를 나타내는 구조체 Node
    Student student;            // 학생의 정보를 담을 구조체 Student형 변수 student
    Node *l_list;               // 노드의 왼쪽 링크를 나타내는 l_list
    Node *r_list;               // 노드의 오른쪽 링크를 나타내는 r_list
} node[MAX];                    // 구조체 Node의 정의 선언 및 크기 100을 가지는 배열 node 선언

int arr_index;                  // 배열의 인덱스를 담을 정수형 변수 arr_index
Node *head, *tail;              // 이중 연결 리스트의 첫 노드와 마지막 노드를 생성
Node *myAlloc() {               // 배열 node의 주소를 반환하는 함수 myAlloc()
    return &node[arr_index++];  // 반환 후 배열의 인덱스 값을 1 증가시킴
}

/*--- 함수 원형 정의 영역 ---*/
char stName[10];                // 사용자로부터 학생의 이름을 입력 받아 저장할 문자 배열 변수 stName
int stScore;                    // 사용자로부터 학생의 성적을 입력 받아 저장할 정수형 변수 stScore
void initial();                 // 이중 연결 리스트를 초기화하는 함수 initial()
int choiceUser();               // 4개의 선택지 중 사용자의 선택을 받는 함수 choiceUser()
void getNameScore();            // 사용자로부터 학생의 이름과 성적을 받는 함수 getNameScore()
void getName();                 // 사용자로부터 학생의 이름만 받는 함수 getName()
void addInfo();                 // 노드를 생성하여 학생의 정보를 추가하는 함수 addInfo()
void delInfo();                 // 학생의 이름만을 이용하여 학생의 정보를 삭제하는 함수 delInfo()
void searchInfo();              // 학생의 이름만을 이용하여 학생의 정보를 검색하고, 성적과 등수를 알려주는 함수 searchInfo()
void printInfo();               // 누적된 학생의 정보를 출력하는 함수 printInfo()
void exitProgram();             // 프로그램을 종료하기 위해 멘트를 출력하는 함수 exitProgram()

int main(void) {
    initial();                  // 이중 연결 리스트 초기화
    while(1) {                  // 무한 반복문
        switch(choiceUser()) {  // 사용자의 선택을 받고 그 경우에 따라 case문으로 들어감
            case 1:             // 1. 입력
                getNameScore(); // 사용자로부터 학생의 이름과 성적을 입력 받고 전역 변수에 대입
                addInfo();      // 노드를 생성하여 학생의 정보를 입력함
                break;          // switch문 종료
            case 2:             // 2. 삭제
                getName();      // 사용자로부터 학생의 이름만 입력 받음
                delInfo();      // 학생의 이름에 해당하는 정보를 삭제함
                break;          // switch문 종료
            case 3:             // 3. 검색
                getName();      // 사용자로부터 학생의 이름만 입력 받음
                searchInfo();   // 학생의 이름에 해당하는 정보를 검색하여, 성적과 등수를 출력함
                break;          // switch문 종료
            case 4:             // 4. 종료
                exitProgram();  // 프로그램 종료 멘트를 출력함
                return 0;       // 프로그램 종료
        }
        printInfo();            // switch문이 종료되면, 누적된 학생 정보를 출력함
        printf("\n");           // 한 줄 개행
    }
}

/*--- 함수 정의 영역 ---*/
void initial() {                // 이중 연결 리스트를 초기화하는 함수 initial()
    arr_index = 0;              // 노드 배열의 인덱스를 0으로 초기화
    head = myAlloc();           // head를 노드 배열의 0번째 원소를 가리키게 함
    tail = myAlloc();           // tail을 노드 배열의 1번째 원소를 가리키게 함
    head->r_list = tail;        // head와 tail이 서로가 서로를 가리키게 함
    tail->l_list = head;
}

int choiceUser() {              // 사용자의 선택을 입력 받는 함수 choiceUser()
    int choice;                 // 사용자의 선택을 담을 정수형 변수 choice
    printf("*---<학생 성적 관리 프로그램>---*\n");    // 멘트 출력
    printf("아래 메뉴 중 하나를 선택하시오.\n");       // 멘트 출력
    printf("1. 입력  2. 제거  3. 검색  4. 종료\n"); // 보기 출력
    printf(">>> ");             // 멘트 출력
    scanf("%d", &choice);       // 사용자로부터 입력을 받아 변수 choice에 저장
    return choice;              // choice를 반환함
}

void getNameScore() {           // 사용자로부터 학생의 이름과 성적을 입력 받는 함수 getNameScore()
    printf("학생의 이름을 입력 : ");// 멘트 출력
    scanf("%s", &stName);       // 이름을 입력 받아 전역 변수 stName에 저장
    printf("학생의 성적을 입력 : ");// 멘트 출력
    scanf("%d", &stScore);      // 성적을 입력 받아 전역 변수 stScore에 저장
}

void addInfo() {                // 새 노드를 생성하여 학생의 정보를 입력하는 함수 addInfo()
    Node *temp = myAlloc();     // 새로운 노드를 생성
    strcpy(temp->student.name, stName);     // 학생 정보 중 이름 입력
    temp->student.score = stScore;          // 학생 정보 중 성적 입력
    temp->r_list = head->r_list;            // 원래 head의 오른쪽 링크가 가리키고 있던 요소를 temp의 오른쪽 링크가 가리키게 함 --> head의 다음 요소로 temp를 넣음
    head->r_list = temp;                    // head의 오른쪽 링크는 temp를 가리키게 함
    temp->l_list = temp->r_list->l_list;    // temp의 오른쪽 링크에 연결되어있던 요소의 왼쪽 링크에 연결되어 있던 요소는 temp의 왼쪽 링크가 가리키게 함
    temp->r_list->l_list = temp;            // temp의 오른쪽 링크에 연결되어 있던 요소의 왼쪽 링크에는 temp가 연결되게 함
    printf("값이 추가되었습니다! --> 이름 : %s, 성적 : %d\n", temp->student.name, temp->student.score);      // 값이 추가되었음을 알리고, 입력된 값들을 함께 출력함
}

void getName() {                // 사용자로부터 학생의 이름만 받음
    printf("학생의 이름을 입력 : ");// 멘트 출력
    scanf("%s", &stName);       // 이름을 입력 받아 전역 변수 stName에 저장
}

void delInfo() {                // 학생의 이름만을 이용하여 학생의 정보를 삭제하는 함수 delInfo()
    // 새로운 노드 temp를 생성하여 head의 오른쪽 링크가 가리키게 한 다음, 마지막 요소가 될 때까지 차례대로 요소를 하나씩 옮기면서 반복
    for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {
        if(strcmp(temp->student.name, stName) == 0) {   // 만약 temp의 구조체 student의 멤버 name과 사용자가 입력한 stName이 일치한다면
            temp->r_list->l_list = temp->l_list;        // temp의 왼쪽 링크에 연결된 요소를 temp의 오른쪽 링크에 연결된 요소의 왼쪽 링크에 연결되게 함
            temp->l_list->r_list = temp->r_list;        // temp의 오른쪽 링크에 연결된 요소를 temp의 왼쪽 링크에 연결된 요소의 오른쪽 링크에 연결되게 함 --> 요소 삭제
            break;      // for문 종료
        }
    }
}

void printInfo() {              // 누적된 학생의 정보를 출력하는 함수 printInfo()
    // 새로운 노드 temp를 생성하여 head의 오른쪽 링크가 가리키게 한 다음, 마지막 요소가 될 때까지 차례대로 요소를 하나씩 옮기면서 반복
    for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {
        printf("[%s: %d] ", temp->student.name, temp->student.score);     // 학생의 이름과 성적을 출력
    }
    printf("\n");               // 한 줄 개행
}

void searchInfo() {             // 학생의 이름만을 이용하여 학생의 정보를 검색하고, 성적과 등수를 알려주는 함수 searchInfo()
    int rank = 1;               // 학생의 등수를 담을 정수형 변수 rank 선언 및 1로 초기화
    int fScore;                 // 찾고자 하는 학생의 점수를 저장할 fScore
    // 새로운 노드 temp를 생성하여 head의 오른쪽 링크가 가리키게 한 다음, 마지막 요소가 될 때까지 차례대로 요소를 하나씩 옮기면서 반복
    for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {
        if(strcmp(temp->student.name, stName) == 0) {       // 만약 temp의 구조체 student의 멤버 name과 사용자가 입력한 stName이 일치한다면
            fScore = temp->student.score;           // 변수 fScore에 찾은 student의 score를 저장해놓고
            // temp를 다시 첫 요소부터 차례대로 돌면서 조건을 만족하는지 확인
            for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {
                if(temp->student.score > fScore)    // temp가 가리키는 구조체 student의 score가 찾은 student의 score보다 크다면
                    rank++;     // 등수가 하나 밀림
            }
            // for문이 종료되면 검색한 학생의 성적과 등수를 이름과 함께 출력
            printf("찾으시는 학생 %s은 %d점, %d등입니다.\n", temp->student.name, temp->student.score, rank);
            break;              // for문 종료
        }
    }
}

void exitProgram() {            // 프로그램 종료 멘트를 출력하는 함수 exitProgram()
    printf("프로그램을 종료합니다!\n");
}