#include <stdio.h>
#include <stdlib.h>

/**
 * Tree 를 구현해볼 것입니다.
 * 
 * 다음과 같은 값을 추가해주는 함수들이 존재합니다.
 * insertLeft() -> 넘겨받은 노드의 왼쪽에 새로운 node 를 추가해줍니다.
 * insertRight() -> 넘겨받은 노드의 왼쪽에 새로운 node 를 추가해줍니다.
 * 
 * DFS 방식으로 Tree 를 순회하는 함수들이 존재합니다.
 * preOrder() -> root, left, right 순으로 Tree 를 순회합니다.
 * inOrder() -> left, root, right 순으로 Tree 를 순회합니다.
 * postOrder() -> left, right, root 순으로 Tree 를 순회합니다.
 */

/**
 * 예시 트리 구조
 *                      1
 *              2               3
 *         4         5                6
 *                7                8     9
 *                   10
 */

typedef struct Node {
    int data;                   // 값을 저장합니다.
    struct Node* leftChild;     // leftChild Node 를 가리킵니다. 
    struct Node* rightChild;    // rightChild Node 를 가리킵니다.
} Node;

// 값 추가 함수
void insertLeft(Node* parent, int data);
void insertRight(Node* parent, int data);

// 순회함수
void preOrder(Node* tree);
void inOrder(Node* tree);
void postOrder(Node* tree);


int main() {

    // tree 를 정의하고 left, right 를 각각 NULL 로 초기화합니다.
    Node tree;
    tree.data = 1;
    tree.leftChild = NULL;
    tree.rightChild = NULL;

    // 예시 트리구조 대로 tree 의 각 노드를 구성합니다. 
    insertLeft(&tree, 2);
    insertLeft(tree.leftChild, 4);
    insertRight(tree.leftChild, 5);
    insertLeft(tree.leftChild->rightChild, 7);
    insertRight(tree.leftChild->rightChild->leftChild, 10);
    insertRight(&tree, 3);
    insertRight(tree.rightChild, 6);
    insertLeft(tree.rightChild->rightChild, 8);
    insertRight(tree.rightChild->rightChild, 9);

    printf("preOrder() result:\n");
    preOrder(&tree);

    printf("\n\n");
    printf("inOrder() result:\n");
    inOrder(&tree);

    printf("\n\n");
    printf("postOrder() result:\n");
    postOrder(&tree);
}

void insertLeft(Node* parent, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    parent->leftChild = newNode;
}

void insertRight(Node* parent, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    parent->rightChild = newNode;
}

// root -> left -> right
void preOrder(Node* tree) {
    // tree 가 null 이면 종료합니다.
    if (tree == NULL) return;

    printf("%d\t", tree->data);
    preOrder(tree->leftChild);
    preOrder(tree->rightChild);
}

// left -> root -> right
void inOrder(Node* tree) {
    if (tree == NULL) return;

    inOrder(tree->leftChild);
    printf("%d\t", tree->data);
    inOrder(tree->rightChild);
}

// left -> right -> root
void postOrder(Node* tree) {
    if (tree == NULL) return;

    postOrder(tree->leftChild);
    postOrder(tree->rightChild);
    printf("%d\t", tree->data);
}