#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

typedef struct Stack {
    int buf[STACK_SIZE];    // ������ �������ʷ� ������ ������
    int top;                // ���� �ֱٿ� ������ ���� �ε���
} Stack;

void init(Stack* stack);
void showStatus(Stack* stack);
bool isEmpty(Stack* stack);
bool isFull(Stack* stack);
void push(Stack* stack, int value);
void pop(Stack* stack);

int main() {
    struct Stack stack;

    init(&stack);

    while (1) {
        printf("���� stack �� �����Դϴ�.\n");
        showStatus(&stack);
        int input = 0;
        printf("���� ���� �� ���ϴ� ���� ������(1: push, 2: pop, 3: �۾�����): ");
        scanf("%d", &input);

        if (input == 1) {
            int value = 0;
            printf("���Ͻô� ���� �Է��ϼ���: ");
            scanf("%d", &value);
            push(&stack, value);
            continue;
        } else if (input == 2) {
            pop(&stack);
            continue;
        } else if (input == 3) {
            break;
        } else {
            printf("���� ���� ���� �Է��ϼ���\n\n");
        }
    }

}



void init(Stack* stack) {

    // ó�� stack �� top �� -1 �� ����ŵ�ϴ�.
    stack->top = -1;
}

void showStatus(Stack* stack) {
    
    // stack �� ����Ǿ� �ִ� ������ ��� ����մϴ�.
    if (stack->top > -1) {
        printf("[ ");
        for (int i=0; i<stack->top+1; i++) {
            printf("%d ", stack->buf[i]);
        }
        printf("]\n\n");
    } else {
        printf("[  ]\n\n");
    }
}

bool isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return true;
    } else {
        return false;
    }
}
bool isFull(Stack* stack) {
    if (stack->top == STACK_SIZE - 1) {
        return true;
    } else {
        return false;
    }
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("stack �� �������ֽ��ϴ�.\n\n");
    } else {
        stack->buf[++(stack->top)] = value;
        printf("push ");
        printf("%d\n", value);
    }
}
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("stack �� �̹� ����ֽ��ϴ�.\n\n");
    } else {
        int value = stack->buf[(stack->top)--];
        printf("pop ");
        printf("%d\n", value);
    }
}