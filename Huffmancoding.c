
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* node = malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void sortNodes(struct Node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[i]->freq > nodes[j]->freq) {
                struct Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

struct Node* buildHuffman(char chars[], int freq[], int n) {
    struct Node* nodes[100];

    for (int i = 0; i < n; i++)
        nodes[i] = createNode(chars[i], freq[i]);

    while (n > 1) {
        sortNodes(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* parent =
            createNode('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        nodes[0] = parent;
        nodes[1] = nodes[n - 1];
        n--;
    }

    return nodes[0];
}

void printCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        if (top == 0) printf("0");
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    char chars[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 9, 12, 13};
    int n = 4;
    int code[100];

    struct Node* root = buildHuffman(chars, freq, n);

    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    return 0;
}

