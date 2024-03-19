#include <stdio.h>
#define MAX_SIZE 100 // 큐의 최대 크기

int queue[MAX_SIZE];
int front = 0, rear = 0; // 큐의 앞과 뒤를 가리키는 포인터

// 큐가 비어있는지 확인하는 함수
int is_empty() {
    return front == rear;
}

// 큐가 가득 차있는지 확인하는 함수
int is_full() {
    return rear == MAX_SIZE;
}

// 큐에 데이터를 추가하는 함수
void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full.\n");
        return;
    }
    queue[rear++] = data;
}

// 큐에서 데이터를 삭제하고 반환하는 함수
int dequeue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue[front++];
    return data;
}

// 큐의 모든 데이터를 출력하는 함수
void print_queue() {
    printf("Queue: ");
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    print_queue();
    printf("Dequeued data: %d\n", dequeue());
    print_queue();
    return 0;
}