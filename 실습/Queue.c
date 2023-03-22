#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
    int data;           // �� ��尡 ������ int �� ������.
    struct Node* next;  // �ٷ� ���� ��带 ����Ű�� next ������
} Node;

typedef struct Queue {
    Node* front;        // queue �� ������ �� ��
    Node* rear;         // queue �� ������ �� ��
    int count;          // queue ���� ����� ����
} Queue;

// Queue �� ������ ���� �ʱ�ȭ
void initQueue(Queue*);

// ���� Queue �� ������ ��Ȳ ���
void show(Queue*);

// Queue �� ������� Ȯ��
bool isEmpty(Queue*);

// Queue �� ���� �߰�
void enqueue(Queue*, int);

// Queue ���� ���� ����
int dequeue(Queue*);


int main() {
    Queue queue;
    initQueue(&queue);

    while (1) {
        printf("���� queue �� ��Ȳ�Դϴ�.\n");
        show(&queue);

        printf("���� ���� �� ���ϴ� ���� ����ּ���(1: enqueue, 2: dequeue, 3: �۾�����): ");
        int input = 0;
        scanf("%d", &input);

        if (input == 1) {
            int data = 0;
            printf("���Ͻô� ���� �Է��ϼ���: ");
            scanf("%d", &data);
            enqueue(&queue, data);
            continue;
        } else if (input == 2) {
            printf("���� Queue ���� %d �� �����Ǿ����ϴ�. ", dequeue(&queue));
        } else if (input == 3) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        } else {
            printf("���� �߿��� �Է����ּ���\n\n");
            continue;
        }
    }
}


void initQueue(Queue* queue) {
    // front �� rear �� ���� �����͸� NULL �� �ʱ�ȭ�ϰ� ��� ������ 0���� ����.
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

void show(Queue* queue) {
    if (queue->count > 0) {
        Node* i = (Node*) malloc(sizeof(Node));
        i = queue->front;
        printf("������������������������������������������������������������������������������������������������������������������������������������\n");
        for (int j=0; j<queue->count; j++) {
            printf("%d | ", i->data);
            if (i->next) {
                i = i->next;
            } else {
                break;
            }
        }
        printf("\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������\n\n");
    } else {
        printf("������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("queue �� ����ֽ��ϴ�.\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������\n\n");
    }
}

bool isEmpty(Queue* queue) {
    // count �� 0�̶�� ���� ��尡 �ϳ��� ���ٴ� ���̹Ƿ� ����ִٴ� ��.
    return queue->count == 0;
}

void enqueue(Queue* queue, int data) {
    // ���ο� ��带 ����
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    // queue �� ����ִٸ� ���ο� ��尡 front �� ��.
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        // �׷��� �ʴٸ� �� ���� ����� ���� ���� ������.
        queue->rear->next = newNode;
    }

    // �� �ڸ� ���ο� ���� ����.
    queue->rear = newNode;
    
    // queue �� ��� ���� ����
    queue->count++;
}

int dequeue(Queue* queue) {
    // dequeue() �Լ��� ��ȯ��
    int response = 0;

    // front �� ������ ������ �ӽ� ��� ����
    Node* temp = (Node*) malloc(sizeof(Node));

    // ���� queue �� ����ִٸ� dequeue �� ���� ���� ������ ���� ���.
    if (isEmpty(queue)) {
        printf("queue �� ����ֽ��ϴ�.");
        return 0;
    } 

    temp = queue->front;
    response = temp->data;

    // ������ front �� ����� ���̹Ƿ� ������ front �� next �� �Ǿ��ִ� �ָ� front �� �ٲ��ش�.
    queue->front = temp->next;
    free(temp);

    // queue �� ��� ���� ����
    queue->count--;

    return response;
}