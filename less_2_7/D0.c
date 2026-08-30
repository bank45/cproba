#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char word[20];
    struct list *next;
};

void add_to_list(struct list **head, const char *word) {
    struct list *new_node = (struct list*)malloc(sizeof(struct list));
    if (!new_node) return;
    
    strncpy(new_node->word, word, 19);
    new_node->word[19] = '\0';
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct list *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void swap_elements(struct list *a, struct list *b) {
    char temp[20];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

void sort_list(struct list *head) {
    if (head == NULL) return;
    int swapped;
    struct list *ptr1;
    struct list *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                swap_elements(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void print_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        printf("%s", current->word);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void delete_list(struct list **head) {
    struct list *current = *head;
    struct list *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

int main() {
    char input[1000];
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }
    if (len > 0 && input[len - 1] == '.') {
        input[len - 1] = '\0';
    }

    struct list *head = NULL;

    char *token = strtok(input, " ");
    while (token != NULL) {
        if (strlen(token) > 0) {
            add_to_list(&head, token);
        }
        token = strtok(NULL, " ");
    }

    sort_list(head);
    print_list(head);

    // Очищаем память
    delete_list(&head);

    return 0;
}
