#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

typedef struct Stack {
    int buf[STACK_SIZE];    // 값들을 차례차례로 저장할 보관소
    int top;                // 가장 최근에 보관한 값의 인덱스
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
        printf("현재 stack 의 상태입니다.\n");
        showStatus(&stack);
        int input = 0;
        printf("다음 보기 중 원하는 것을 고르세요(1: push, 2: pop, 3: 작업종료): ");
        scanf("%d", &input);

        if (input == 1) {
            int value = 0;
            printf("원하시는 값을 입력하세요: ");
            scanf("%d", &value);
            push(&stack, value);
            continue;
        } else if (input == 2) {
            pop(&stack);
            continue;
        } else if (input == 3) {
            break;
        } else {
            printf("보기 중의 값만 입력하세요\n\n");
        }
    }

}



void init(Stack* stack) {

    // 처음 stack 의 top 은 -1 을 가리킵니다.
    stack->top = -1;
}

void showStatus(Stack* stack) {
    
    // stack 에 저장되어 있는 값들을 모두 출력합니다.
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
        printf("stack 이 가득차있습니다.\n\n");
    } else {
        stack->buf[++(stack->top)] = value;
        printf("push ");
        printf("%d\n", value);
    }
}
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("stack 이 이미 비어있습니다.\n\n");
    } else {
        int value = stack->buf[(stack->top)--];
        printf("pop ");
        printf("%d\n", value);
    }
}