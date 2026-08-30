#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; 
} tree;

tree* create_node(datatype key, tree *parent) 
{
    tree *new_node = (tree*)malloc(sizeof(tree));
    if (new_node) {
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = parent; 
    }
    return new_node;
}

tree* insert_node(tree *root, tree *parent, datatype key) 
{
    if (root == NULL) {
        return create_node(key, parent);
    }
    if (key < root->key) {
        root->left = insert_node(root->left, root, key);
    } else if (key > root->key) {
        root->right = insert_node(root->right, root, key);
    }
    return root;
}

tree* findNode(tree *root, int key) 
{
    if (root == NULL) return NULL;
    if (root->key == key) return root;

    tree *left_search = findNode(root->left, key);
    if (left_search != NULL) return left_search;

    return findNode(root->right, key);
}


tree * findBrother(tree *root, int key) 
{
    if (root == NULL) {
        return 0; 
    }

    tree *target = NULL;

    tree **queue = (tree**)malloc(10000 * sizeof(tree*));
    if (queue != NULL) {
        int head = 0;
        int tail = 0;
        
        queue[tail++] = root;
        
        while (head < tail) {
            tree *curr = queue[head++];
            if (curr->key == key) {
                target = curr;
                break; 
            }
            if (curr->left)  queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
        free(queue);
    }

    if (target == NULL) {
        return 0; 
    }
    
    tree *parent_node = target->parent;
    
    if (parent_node == NULL) {
        return 0;
    }
    
    if (parent_node->left == target) {
        return parent_node->right;
    } else {
        return parent_node->left;
    }
}


void free_tree(tree *root) 
{
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// ТОЧКА ВХОДА ДЛЯ ТЕСТИРОВАНИЯ
int main() 
{
    tree *root = NULL;
    datatype num;
    int search_key;

    // 1. Считываем числа дерева, пока не встретим 0 (маркер конца дерева по условию)
    while (scanf("%d", &num) == 1 && num != 0) {
        root = insert_node(root, NULL, num);
    }

    // 2. Считываем ключ элемента, брата которого нужно найти
    if (scanf("%d", &search_key) != 1) {
        free_tree(root);
        return 0;
    }

    // 3. Вызываем функцию поиска брата
    tree *brother = findBrother(root, search_key);

    // 4. Выводим результат (если брат найден — его ключ, иначе 0)
    if (brother != NULL) {
        printf("%d\n", brother->key);
    } else {
        printf("0\n");
    }

    // Освобождаем память
    free_tree(root);
    return 0;
}
