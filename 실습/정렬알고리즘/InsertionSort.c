#include <stdio.h>

// 삽입정렬은 시간복잡도가 케이스마다 다르다. 
// 최악의 경우에는 배열의 길이가 n 일때 n² 만큼 실행 --> for 문 내부의 while 문을 끝까지 실행... 오름차순 정렬을 하려고 하는데 내림차순 정렬이 된 배열을 다룰때
// 최선의 경우에는 배열의 길이가 n 일때 n 만큼 실행 --> 이미 정렬이 다 끝난 배열을 다룰 때

void insertionSort(int*, int);
void show(int*, int);

int main() {
    int arr[10] = {5, 3, 1, 9, 7, 6, 4, 2, 10, 8};

    printf("Current status of array: \n");
    show(arr, sizeof(arr)/sizeof(int));

    printf("Call insertionSort()\n\n");

    insertionSort(arr, sizeof(arr)/sizeof(int));

    printf("After call insertionSort()\n");
    show(arr, sizeof(arr)/sizeof(int));
}

void insertionSort(int* arr, int len) {

    // 예를 들면 위의 배열에서 3 부터 8까지는 정렬이 안된 상태이고 5 가 있는 곳은 정렬된 곳이라고 생각하는 거임.
    // 즉, i 의 위치를 기준으로 왼쪽은 정렬이 완료된 상태, 오른쪽은 하나씩 빼와서 왼쪽의 알맞은 위치에 넣어줘야 하는 것이다.
    for (int i=1; i<len; i++) {
        
        // 일단 오른쪽의 배열에서 맨 첫번재 것을 temp 에 저장한다.
        int temp = arr[i];

        // j 는 항상 i 보다 1 작은 값을 가져야 한다.
        int j = i-1;

        // j 가 0보다 큰지 판단하는 것은 i 의 위치를 기준으로 나눈 왼쪽의 배열을 전부 순회해서 확인을 했는지 체크하기 위해서이고
        // arr[j] 가 temp 보다 큰지 판단하는 것은 i 의 위치를 기준으로 나눈 오른쪽의 배열의 맨 첫번째 요소가 왼쪽의 어느 위치에 들어가야 하는지 판단하기 위해서이다.
        while (j >= 0 && arr[j] > temp) {
            
            // arr[j] 가 temp 보다 크다는 것은 arr[j+1] 의 자리에 arr[j] 의 값을 넣어야 한다는 것이다.
            // 오름차순으로 정렬해준다는 것을 알수있다.
            arr[j+1] = arr[j];

            // 위의 작업이 끝나면 j 의 위치를 1 감소시켜야 while 문이 정상적으로 작동할 수 있다.
            j--;
        }

        // main() 함수 내부의 arr 배열을 예시로 들어 이미 5 와 3 이 정렬이 되어 {3, 5} 로 왼쪽에 있다고 해보자.
        // 그럼 이제 1 을 {3, 5} 중에 알맞은 위치에 넣어주어야 한다.
        // 이때 while 문의 조건을 만족하게 된다.
        // i 는 현재 arr 에서 1의 위치이기 때문에 arr[2] 가 되므로 i 는 2이다. 그러므로 j 는 1 이 되고 첫번째 조건을 만족하게 된다.
        // 현재 arr[j] 는 {3, 5} 중에서 arr[1] 이므로 5가 되고 5는 1보다 크므로 두번째 조건도 만족하게 되어 while 문 내부의 코드를 실행하게 된다.
        // arr[j+1] = arr[j] 이므로 arr[2] = arr[1] 이 되어 원래 1 이 들어있던 곳에 5가 저장된다. 
        // 그러고 난뒤 j 는 값이 1 감소한다. 
        // 이제 다시 while 문의 첫번째(j 가 0 이므로 0보다 크거나 같음.), 두번째(arr[0] = 3 인데 3이 temp 인 1보다 큼.) 조건을 만족하게 된다.
        // 또 arr[j+1] = arr[j] 를 실행하는데 arr[j+1] 은 원래 5의 자리였고 여기에 3이 들어가게 된다.
        // 그리고 j 는 또 1이 감소하여 while 문을 더이상 반복하지 않게 된다.
        // 여기까지 다 돌고 났다면 최종적으로는 {3, 3, 5} 이런 모습일 것이다. 그럼 이제 1 을 알맞은 자리에 넣어주어야 하는데 그 자리는 j 가 이미 갖고 있는 -1 이라는 값에
        // 1을 더하여 arr[0] 에 1 을 넣어주게 된다.
        // 아래의 코드를 보다 자세하게 설명하기 위해 설명이 길어졌다. 
        arr[j+1] = temp;
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