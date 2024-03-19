#include <stdio.h>
#define MAX_SIZE 100 // ť�� �ִ� ũ��

int queue[MAX_SIZE];
int front = 0, rear = 0; // ť�� �հ� �ڸ� ����Ű�� ������

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int is_empty() {
    return front == rear;
}

// ť�� ���� ���ִ��� Ȯ���ϴ� �Լ�
int is_full() {
    return rear == MAX_SIZE;
}

// ť�� �����͸� �߰��ϴ� �Լ�
void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full.\n");
        return;
    }
    queue[rear++] = data;
}

// ť���� �����͸� �����ϰ� ��ȯ�ϴ� �Լ�
int dequeue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue[front++];
    return data;
}

// ť�� ��� �����͸� ����ϴ� �Լ�
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