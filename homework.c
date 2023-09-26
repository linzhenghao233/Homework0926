#include<stdio.h>
#include <stdlib.h>

void connect(struct Node* L1, struct Node* L2, int m, int n);
void print(struct Node* L);

struct Node {
    int data;
    struct Node* next;
};

int main(void){
    struct Node* L1 = (struct Node*)malloc(sizeof(struct Node));
    int m = 3, n = 2;

    L1->data = 1;
    L1->next = (struct Node*)malloc(sizeof(struct Node));
    L1->next->data = 2;
    L1->next->next = (struct Node*)malloc(sizeof(struct Node));
    L1->next->next->data = 3;
    L1->next->next->next = NULL;

    struct Node* L2 = (struct Node*)malloc(sizeof(struct Node));
    L2->data = 1;
    L2->next = (struct Node*)malloc(sizeof(struct Node));
    L2->next->data = 2;
    L2->next->next = NULL;

    connect(L1, L2, m, n);
    print(m >= n ? L2 : L1);

    return 0;
}

void connect(struct Node* L1, struct Node* L2, int m, int n) {
    if (m >= n) {
        while (L2->next != NULL)
            L2 = L2->next;
        L2->next = L1;
    }
    else {
        while (L1->next != NULL)
           L1 = L1->next;
        L1->next = L2;
    }
}

void print(struct Node* L) {
    while (L != NULL) {
        printf("%d\n", L->data);
        L = L->next;
    }
}
//遍历最短的到最末的一个，然后将最短的next指向另一个的头节点
//所以时间复杂度是O(n)，n取决于最短的链表的长度