#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;

typedef struct QueueNode {
    tree *node;
    int hd; 
    struct QueueNode *next;
} QueueNode;

void enqueue(QueueNode **head, QueueNode **tail, tree *node, int hd) 
{
    if (!node) return;
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->node = node;
    new_node->hd = hd;
    new_node->next = NULL;
    if (*tail == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

QueueNode* dequeue(QueueNode **head, QueueNode **tail) 
{
    if (*head == NULL) return NULL;
    QueueNode *temp = *head;
    *head = (*head)->next;
    if (*head == NULL) *tail = NULL;
    return temp;
}


void btUpView(tree *root) 
{
    if (root == NULL) return;

    typedef struct QueueNode {
        tree *node;
        int hd;
        struct QueueNode *next;
    } QueueNode;

    static int left_view[1005] = {0};  
    static int right_view[1005] = {0}; 
    static int has_left[1005] = {0};   
    static int has_right[1005] = {0};  
    
    for(int i = 0; i < 1005; i++) {
        has_left[i] = 0;
        has_right[i] = 0;
    }

    int min_hd = 0, max_hd = 0;

    QueueNode *q_head = NULL;
    QueueNode *q_tail = NULL;

    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->node = root;
    new_node->hd = 0;
    new_node->next = NULL;
    q_head = q_tail = new_node;

    while (q_head != NULL) {
        QueueNode *curr = q_head;
        q_head = q_head->next;
        if (q_head == NULL) q_tail = NULL;

        tree *node = curr->node;
        int hd = curr->hd;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (hd >= 0) {
            if (hd < 1005 && !has_right[hd])
            {
                right_view[hd] = node->key;
                has_right[hd] = 1;
            }
        } else {
            int abs_hd = -hd;
            if (abs_hd < 1005 && !has_left[abs_hd]) 
            {
                left_view[abs_hd] = node->key;
                has_left[abs_hd] = 1;
            }
        }

        if (node->left) {
            QueueNode *q_left = (QueueNode*)malloc(sizeof(QueueNode));
            q_left->node = node->left;
            q_left->hd = hd - 1;
            q_left->next = NULL;
            if (q_tail == NULL) {
                q_head = q_tail = q_left;
            } else {
                q_tail->next = q_left;
                q_tail = q_left;
            }
        }

        if (node->right) {
            QueueNode *q_right = (QueueNode*)malloc(sizeof(QueueNode));
            q_right->node = node->right;
            q_right->hd = hd + 1;
            q_right->next = NULL;
            if (q_tail == NULL) {
                q_head = q_tail = q_right;
            } else {
                q_tail->next = q_right;
                q_tail = q_right;
            }
        }

        free(curr);
    }

    int first = 1;
    for (int hd = min_hd; hd <= max_hd; hd++) {
        if (hd < 0) {
            if (has_left[-hd]) {
                if (!first) printf(" ");
                printf("%d", left_view[-hd]);
                first = 0;
            }
        } else {
            if (has_right[hd]) {
                if (!first) printf(" ");
                printf("%d", right_view[hd]);
                first = 0;
            }
        }
    }
    printf("\n");
}

tree* create_node(datatype key) 
{
    tree *new_node = (tree*)malloc(sizeof(tree));
    if (new_node) {
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

tree* insert_node(tree *root, datatype key) 
{
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else if (key > root->key) {
        root->right = insert_node(root->right, key);
    }
    return root;
}

int main() 
{
    tree *root = NULL;
    datatype num;

    while (scanf("%d", &num) == 1 && num != 0) {
        root = insert_node(root, num);
    }

    btUpView(root);

    return 0;
}
