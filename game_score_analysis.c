include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define NO_NODE   -1

struct Node {
    int score;
    struct Node *left;
    struct Node *right;
};

/* Global result of the best path found so far */
int bestSum = INT_MIN;
int bestPath[MAX_NODES];
int bestLen = 0;

struct Node *createNode(int score) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    n->score = score;
    n->left = n->right = NULL;
    return n;
}

/* Build the tree from level-order values using a simple queue */
struct Node *buildTree(int values[], int n) {
    struct Node *queue[MAX_NODES];
    int front = 0, rear = 0, i = 1;

    if (n == 0 || values[0] == NO_NODE)
        return NULL;

    struct Node *root = createNode(values[0]);
    queue[rear++] = root;

    while (front < rear && i < n) {
        struct Node *cur = queue[front++];

        if (i < n && values[i] != NO_NODE) {
            cur->left = createNode(values[i]);
            queue[rear++] = cur->left;
        }
        i++;

        if (i < n && values[i] != NO_NODE) {
            cur->right = createNode(values[i]);
            queue[rear++] = cur->right;
        }
        i++;
    }
    return root;
}

/* Recursively print every root-to-leaf path and track the maximum sum */
void findPaths(struct Node *root, int path[], int len, int sum) {
    if (root == NULL)
        return;

    path[len++] = root->score;
    sum += root->score;

    if (root->left == NULL && root->right == NULL) {   /* leaf node */
        for (int i = 0; i < len; i++) {
            printf("%d", path[i]);
            if (i < len - 1)
                printf(" -> ");
        }
        printf("   (Sum = %d)\n", sum);

        if (sum > bestSum) {
            bestSum = sum;
            bestLen = len;
            for (int i = 0; i < len; i++)
                bestPath[i] = path[i];
        }
        return;
    }

    findPaths(root->left, path, len, sum);
    findPaths(root->right, path, len, sum);
}

void displayAllPaths(struct Node *root) {
    int path[MAX_NODES];
    if (root == NULL) {
        printf("Tree is empty. Build or load a tree first.\n");
        return;
    }
    bestSum = INT_MIN;
    bestLen = 0;
    printf("\nAll root-to-leaf paths:\n");
    findPaths(root, path, 0, 0);
}

void displayMaxPath(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty. Build or load a tree first.\n");
        return;
    }
    int path[MAX_NODES];
    bestSum = INT_MIN;
    bestLen = 0;

    printf("\nAll root-to-leaf paths:\n");
    findPaths(root, path, 0, 0);

    printf("\nMaximum score path: ");
    for (int i = 0; i < bestLen; i++) {
        printf("%d", bestPath[i]);
        if (i < bestLen - 1)
            printf(" -> ");
    }
    printf("\nMaximum sum       : %d\n", bestSum);
}

void freeTree(struct Node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node *root = NULL;
    int choice;

    do {
        printf("\n===== Game Score Analysis (Binary Tree) =====\n");
        printf("1. Build tree from your own scores\n");
        printf("2. Load sample tree\n");
        printf("3. Display all root-to-leaf paths\n");
        printf("4. Find path with maximum sum\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1: {
                int n, values[MAX_NODES];
                printf("How many values (max %d)? ", MAX_NODES);
                scanf("%d", &n);
                if (n < 1 || n > MAX_NODES) {
                    printf("Invalid count.\n");
                    break;
                }
                printf("Enter %d level-order scores (use -1 for no node):\n", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &values[i]);
                freeTree(root);
                root = buildTree(values, n);
                printf("Tree built successfully.\n");
                break;
            }
            case 2: {
                int sample[] = {10, 5, 8, 3, 7, -1, 12, 2, -1, 6, -1};
                freeTree(root);
                root = buildTree(sample, 11);
                printf("Sample tree loaded: 10 5 8 3 7 -1 12 2 -1 6 -1\n");
                break;
            }
            case 3:
                displayAllPaths(root);
                break;
            case 4:
                displayMaxPath(root);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    freeTree(root);
    return 0;
}