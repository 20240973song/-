#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertLast(Node* head, int data);
void printList(Node* head);
int searchValue1(Node* head, int value);
void searchValue2(Node* head, int value);
void freeList(Node* head);

int main() {
    Node* head = NULL;

    for (int i = 0; i < 10; i++) {
        head = insertLast(head, i * 10);
    }

    printList(head);

    int val = 30;
    int pos = searchValue1(head, val);
    if (pos != -1) {
        printf("%d의 위치는 %d번째입니다.\n", val, pos);
    } else {
        printf("%d는 리스트에 없습니다.\n", val);
    }

    searchValue2(head, val);

    freeList(head);

    return 0;
}

Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchValue1(Node* head, int value) {
    int index = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void searchValue2(Node* head, int value) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            printf("%d를 찾았습니다.\n", value);
            if (prev != NULL) {
                printf("앞 노드의 값: %d\n", prev->data);
            } else {
                printf("앞 노드 없음 (처음 노드)\n");
            }

            if (current->next != NULL) {
                printf("뒤 노드의 값: %d\n", current->next->data);
            } else {
                printf("뒤 노드 없음 (마지막 노드)\n");
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("%d는 리스트에 없습니다.\n", value);
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}
