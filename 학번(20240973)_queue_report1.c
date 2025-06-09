#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(CircularQueue *q) {
    return q->front == q->rear;
}

bool isFull(CircularQueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % SIZE;
    return true;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return -1; // 값이 없는 경우 -1을 반환하도록 수정
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    return value;
}

void printQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }
    printf("큐의 데이터: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value;
    
    while (true) {
        printf("\n1. 삽입\n2. 삭제\n3. 큐 데이터 출력\n4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("삽입할 값: ");
                scanf("%d", &value);
                if (enqueue(&q, value)) {
                    printf("%d가 큐에 삽입되었습니다.\n", value);
                }
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("삭제된 값: %d\n", value);
                }
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도해주세요.\n");
                break;
        }
    }
    return 0;
}
