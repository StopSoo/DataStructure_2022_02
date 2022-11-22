#include <stdio.h>          // 기본 입출력 라이브러리
#include <stdlib.h>         // malloc() 함수를 사용하기 위한 헤더 파일

typedef struct Node {       // 노드 구조체를 선언하고 Node로 이름 변경
    int key;    // 노드의 값이 들어갈 정수형 변수 key
    struct Node* l_link;    // 왼쪽 링크 l_link
    struct Node* r_link;    // 오른쪽 링크 r_link
} Node;

Node* searchNode(Node *root, int value) {   // 노드를 탐색하는 함수 searchNode()
    Node *temp = root;      // 임시 노드 선언 후 root 대입
    if (temp->key == value) {   // temp의 값이 value와 같다면
        printf("값을 찾았습니다! 찾은 값 : %d", value);   // 멘트 출력
        return temp;    // 노드 temp를 반환
    } else if (temp->key < value) {     // temp의 값이 value보다 작다면
        searchNode(temp->r_link, value);    // temp의 오른쪽 서브 트리를 탐색
    } else if (temp->key > value) {     // temp의 값이 value보다 크다면
        searchNode(temp->l_link, value);    // temp의 왼쪽 서브 트리를 탐색
    } else {    // 존재하지 않는 값을 탐색했을 경우
        printf("값이 존재하지 않습니다.\n");  // 멘트를 출력
    }
}

Node* new_node(int item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->l_link = temp->r_link = NULL;
    return temp;
}

Node* insertNode(Node* root, int value) {   // 노드를 삽입하는 함수 insertNode()
    if (root == NULL)   // 트리가 공백이면
        return new_node(value); // 새로운 노드를 반환
    // 순차적으로 트리를 탐색
    if (value < root->key)
        root->l_link = insertNode(root->l_link, value);
    else if (value > root->key)
        root->r_link = insertNode(root->r_link, value);
    // 루트 포인터를 반환
   return root;
}

Node *min_value_node(Node *root) {
    Node *current = root;

    while (current->l_link != NULL)
        current = current->key;
    return current;
}
Node* deleteNode(Node *root, int value) {       // 노드를 삭제하는 함수 deleteNode()
    if (root == NULL)
        return root;
    if (value < root->key) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
        root->l_link = deleteNode(root->l_link, value);
    else if (value > root->key) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
        root->r_link = deleteNode(root->r_link, value);
    else {				// 키가 루트와 같으면 이 노드를 삭제함
        if (root->l_link == NULL) {	    // (1) or (2)
            Node *temp = root->r_link;
            free(root);
            return temp;
        }
        else if (root->r_link == NULL) {	// (1) or (2)
            Node *temp = root->l_link;
            free(root);
            return temp;
        }

        Node * temp = min_value_node(root->r_link); 		// (3)
        root->key = temp->key; 				// 직후 키 복사
        root->r_link = deleteNode(root->r_link, temp->key); 	// 직후 노드 삭제
    }
    printf("값 삭제가 완료되었습니다 ! 삭제한 값 : %d\n", value);  // 멘트 출력
    return root;

//    Node *temp = root;      // 임시 노드 temp를 생성하고 인수로 받은 root를 저장
//    Node* parent = NULL;    // 부모 노드를 저장할 parent를 생성하고 NULL로 초기화
//    // 찾는 노드가 없거나 키를 찾은 것도 아니라면 반복문을 계속 돌아야 함
//    while ((temp != NULL) && (temp->key != value)) {
//        parent = temp;
//        if (temp->key < value) {    // 노드 temp의 값이 삭제하려는 값보다 작다면
//            temp = temp->r_link;    // temp의 오른쪽 서브 트리를 탐색함
//        } else {        // 노드 temp의 값이 삭제하려는 값보다 크다면
//            temp = temp->l_link;    // temp의 왼쪽 서브 트리를 탐색함
//        }
//    }
//
//    if (temp == NULL) { // value를 찾는데 실패해 루트 노드를 그대로 반환
//        printf("찾는 노드가 없습니다.\n");
//        return root;
//    }
//    // temp가 단말 노드일 경우
//    if (temp->l_link == NULL && temp->r_link == NULL){
//        // 현재 노드가 루트 노드인데 차수가 0인 경우와, 루트가 아닌데 차수가 0인 경우로 나눠야 함
//        if (parent == NULL) {   // 부모 노드가 비어 있을 경우
//            root = NULL;
//        } else {    // 부모 노드가 존재할 경우
//            if (parent->l_link == temp) {   // 부모 노드의 왼쪽 자식이 temp일 경우
//                parent->l_link = NULL;  // temp 삭제
//            } else {    // 부모 노드의 오른쪽 자식이 temp일 경우
//                parent->r_link = NULL;  // temp 삭제
//            }
//        }
//    } // temp의 왼쪽 자식, 오른쪽 자식 중 하나만 NULL일 경우
//    else if (temp->l_link == NULL || temp->r_link == NULL) {
//        // 왼쪽 노드랑 오른쪽 노드 중 값이 있는 걸 child에 넣음
//        Node *child = (temp->l_link != NULL) ? temp->l_link : temp->r_link;
//        if (parent == NULL) {   // 부모 노드가 NULL일 경우
//            root = child;
//        } else {    // 부모 노드가 존재할 경우
//            if (parent->l_link == temp) {   // 부모 노드의 왼쪽 자식이 temp일 경우
//                parent->l_link = child;
//            } else {    // 부모 노드의 오른쪽 자식이 temp일 경우
//                parent->r_link = child;
//            }
//        }
//    } else {    // 차수가 2일 때
//        Node *succ_parent = temp;   // 노드 succ_parent를 생성하고 temp를 대입
//        Node *succ = temp->r_link;  // 노드 succ를 생성하고 temp의 오른쪽 링크를 대입
//        while (succ->l_link != NULL){   // succ가 비어있지 않은 동안 반복문 수행
//            succ_parent = succ;
//            succ = succ->l_link;
//        }
//        temp->key = succ->key;
//
//        if (succ_parent->l_link == succ){   // succ_parenct의 왼쪽 링크가 succ와 같다면
//            succ_parent->l_link = succ->r_link;
//        } else {    // 아닐 경우
//            succ_parent->r_link = succ->r_link;
//        }
//        temp = succ;    // temp에 succ를//    printf("값 삭제가 완료되었습니다 ! 삭제한 값 : %d\n", value);  // 멘트 출력 할당
//    }
//    free(temp);     // temp에 대해 메모리 반환
//    return root;    // root 반환
}

void printTree(Node *root, int space, int height) {     // 트리를 출력하는 함수 printTree()
    int s = space;
    int h = height;
    if (root == NULL){      // 트리가 비어있을 경우
        return;
    }
    s += h;
    printTree(root->r_link, s, h);  // 오른쪽 서브트리에 대해 프린트 함수를 실행
    printf("\n");

    for (int i = h; i < s; i++) {
        printf(" ");
    }
    printf(root->key);

    printf("\n");
    printTree(root->l_link, s, h);  // 왼쪽 서브트리에 대해 프린트 함수를 실행
}

int choiceUser() {  // 사용자가 선택할 수 있는 메뉴를 출력하고, 입력을 받아 저장하는 함수 choiceUser()
    int choice;     // 사용자의 입력을 받아 저장할 정수형 변수 choice
    // 사용자가 선택할 수 있는 메뉴를 출력
    printf("1. 삽입\n");
    printf("2. 삭제\n");
    printf("3. 탐색\n");
    printf("4. 출력\n");
    printf("5. 종료\n");
    printf("위 항목 중 하나를 선택해주세요.\n");
    printf(">>>  ");
    scanf("%d", &choice);       // 사용자로부터 입력을 받아 변수 choice에 저장
    return choice;  // choice를 반환함
}

int main()
{
    int val;        // 사용자로부터 받은 값을 저장하는 정수형 변수 val
    Node* root = insertNode(NULL, 10);      // 노드 root를 생성하고 10이라는 값을 저장
    while(1) {
        switch (choiceUser()) {     // choiceUser()를 통해 사용자로부터 값을 입력 받음
            case 1: // 값이 1일 때
                printf("삽입을 선택하셨습니다.\n");
                printf("삽입할 값을 입력해주세요 : ");
                scanf("%d", &val);  // 사용자로부터 입력 받은 값을 변수 val에 저장함
                root = insertNode(root, val);   // val에 대해 함수 insertNode()를 실행하여 root에 저장
                printf("\n");   // 한 줄 개행
                break;     // 다음 반복으로 넘어감
            case 2: // 값이 2일 때
                printf("삭제를 선택하셨습니다.\n");
                printf("삭제할 값을 입력해주세요 : ");
                scanf("%d", &val);  // 사용자로부터 입력 받은 값을 변수 val에 저장함
                root = deleteNode(root, val);   // val에 대해 함수 deleteNode()를 실행하여 root에 저장
                printf("\n");   // 한 줄 개행
                break;     // 다음 반복으로 넘어감
            case 3: // 값이 3일 때
                printf("탐색을 선택하셨습니다.\n");
                printf("탐색할 값을 입력해주세요 : ");
                scanf("%d", &val);  // 사용자로부터 입력 받은 값을 변수 val에 저장함
                root = searchNode(root, val);
                printf("\n");   // 한 줄 개행
                break;     // 다음 반복으로 넘어감
            case 4: // 값이 4일 때
                printTree(root, 0, 10);    // printTree() 함수를 실행
                printf("\n");   // 한 줄 개행
                break;     // 다음 반복으로 넘어감
            case 5: // 값이 5일 때
                printf("프로그램이 종료되었습니다.\n");     // 멘트 출력
                return 0;  // 0을 반환하고 프로그램 종료
            default:    // 위 경우들이 아닐 때
                printf("잘못된 값을 선택하셨습니다.\n");    // 멘트 출력
                printf("\n");   // 한 줄 개행
                break;     // 다음 반복으로 넘어감
        }
    }
}