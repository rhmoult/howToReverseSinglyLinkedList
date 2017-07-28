#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* root) {
    while (root) {
        printf("%d", root->data);
        root = root->next;
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

    Node* root = &a;
    print_list(root);
    root = reverse(root);
    print_list(root);

    return 0;
}
