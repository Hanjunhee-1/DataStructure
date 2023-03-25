#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
    int data;           // 각 노드가 가지는 int 형 데이터.
    struct Node* next;  // 바로 다음 노드를 가리키는 next 포인터
} Node;

typedef struct Queue {
    Node* front;        // queue 의 구조상 맨 앞
    Node* rear;         // queue 의 구조상 맨 뒤
    int count;          // queue 안의 노드의 갯수
} Queue;

// Queue 의 내용을 전부 초기화
void initQueue(Queue*);

// 현재 Queue 의 데이터 상황 출력
void show(Queue*);

// Queue 가 비었는지 확인
bool isEmpty(Queue*);

// Queue 에 값을 추가
void enqueue(Queue*, int);

// Queue 에서 값을 삭제
int dequeue(Queue*);


int main() {
    Queue queue;
    initQueue(&queue);

    while (1) {
        printf("현재 queue 의 상황입니다.\n");
        show(&queue);

        printf("다음 보기 중 원하는 것을 골라주세요(1: enqueue, 2: dequeue, 3: 작업종료): ");
        int input = 0;
        scanf("%d", &input);

        if (input == 1) {
            int data = 0;
            printf("원하시는 값을 입력하세요: ");
            scanf("%d", &data);
            enqueue(&queue, data);
            continue;
        } else if (input == 2) {
            printf("현재 Queue 에서 %d 가 삭제되었습니다. ", dequeue(&queue));
        } else if (input == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("보기 중에만 입력해주세요\n\n");
            continue;
        }
    }
}


void initQueue(Queue* queue) {
    // front 와 rear 에 대한 포인터를 NULL 로 초기화하고 노드 갯수도 0으로 만듬.
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

void show(Queue* queue) {
    if (queue->count > 0) {
        Node* i = (Node*) malloc(sizeof(Node));
        i = queue->front;
        printf("──────────────────────────────────────────────────────────────────\n");
        for (int j=0; j<queue->count; j++) {
            printf("%d | ", i->data);
            if (i->next) {
                i = i->next;
            } else {
                break;
            }
        }
        printf("\n");
        printf("──────────────────────────────────────────────────────────────────\n\n");
    } else {
        printf("──────────────────────────────────────────────────────────────────\n");
        printf("queue 가 비어있습니다.\n");
        printf("──────────────────────────────────────────────────────────────────\n\n");
    }
}

bool isEmpty(Queue* queue) {
    // count 가 0이라는 것은 노드가 하나도 없다는 것이므로 비어있다는 것.
    return queue->count == 0;
}

void enqueue(Queue* queue, int data) {
    // 새로운 노드를 생성
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    // queue 가 비어있다면 새로운 노드가 front 가 됨.
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        // 그렇지 않다면 맨 뒤의 노드의 다음 노드로 설정함.
        queue->rear->next = newNode;
    }

    // 맨 뒤를 새로운 노드로 설정.
    queue->rear = newNode;
    
    // queue 의 노드 갯수 증가
    queue->count++;
}

int dequeue(Queue* queue) {
    // dequeue() 함수의 반환값
    int response = 0;

    // front 의 정보를 저장할 임시 노드 생성
    Node* temp = (Node*) malloc(sizeof(Node));

    // 만약 queue 가 비어있다면 dequeue 할 것이 없기 때문에 에러 출력.
    if (isEmpty(queue)) {
        printf("queue 가 비어있습니다.");
        return 0;
    } 

    temp = queue->front;
    response = temp->data;

    // 원래의 front 를 지우는 것이므로 기존에 front 의 next 로 되어있던 애를 front 로 바꿔준다.
    queue->front = temp->next;
    free(temp);

    // queue 의 노드 갯수 감소
    queue->count--;

    return response;
}