#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char op;
    int val;
    bool isOperator;
    struct Node *left, *right;
};

struct Node* createOperandNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->isOperator = false;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createOperatorNode(char op, struct Node* left, struct Node* right) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->op = op;
    newNode->isOperator = true;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int evaluate(struct Node* root) {
    if (root == NULL) return 0;

    if (!root->isOperator) {
        return root->val;
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->op) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }

    return 0;
}

int main() {
    struct Node* root = createOperatorNode('+',
                            createOperatorNode('*',
                                createOperandNode(3),
                                createOperandNode(4)
                            ),
                            createOperandNode(5)
                        );

    printf("Expression Tree Evaluation Result: %d\n", evaluate(root));

    return 0;
}
