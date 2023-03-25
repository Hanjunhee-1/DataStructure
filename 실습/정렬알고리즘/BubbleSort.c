#include <stdio.h>

// 버블정렬은 항상 n² 만큼 실행하기 때문에 그리 좋은 정렬알고리즘이 아니다. 
void bubbleSort(int*, int);
void show(int*, int);

int main() {
    int arr[10] = {5, 3, 1, 9, 7, 6, 4, 2, 10, 8};

    printf("Current status of array: \n");
    show(arr, sizeof(arr)/sizeof(int));

    printf("Call bubbleSort()\n\n");
    
    bubbleSort(arr, sizeof(arr)/sizeof(int));

    printf("After call bubbleSort()\n");
    show(arr, sizeof(arr)/sizeof(int));
}

void bubbleSort(int* arr, int len) {
    
    // 배열의 마지막 index 부터 정렬을 완료해줄거임.
    for (int i=len-1; i>0; i--) {
        
        // arr[j] 와 arr[j+1] 을 비교해줄거임. 
        for (int j=0; j<i; j++) {

            // 만약 arr[j] 가 더 크다면 arr[j+1] 과 자리를 바꿈.
            // 오름차순으로 정렬한다는 것을 알수 있음.
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void show(int* arr, int len) {
    int i=0;
    
    printf("[ ");
    for (i=0; i<len-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n\n", arr[i]);
}