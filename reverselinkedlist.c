#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* printNode) {
    while (printNode) {
        printf("%d", printNode->data);
        printNode = printNode->next;
    }
    printf("\n");
}

Node* reverse(Node* root) {
    Node* new_root = 0;
    while (root) {
        Node* next = root->next;
        root->next = new_root;
        new_root = root;
        root = next;
    }
    return new_root;
}

int main() {
    Node d = { 4, 0 };
    Node c = { 3, &d };
    Node b = { 2, &c };
    Node a = { 1, &b };

    Node* head = &a;
    print_list(head);
    head = reverse(head);
    print_list(head);

    return 0;
}
