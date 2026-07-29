#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    if (head == NULL)
    {
        return 0;
    }
    uint64_t max_addres = head->address;
    size_t max_size = head->size;
    const list *current = head;
    while (current != NULL)
    {
        // printf("Address: %llu | Size: %5zu | Next: %p\n",
        //                (unsigned long long)current->address, current->size, (void *)current->next);

        if (current->size > max_size)
        {
            max_size = current->size;
            max_addres = current->address;
        }
        current = current->next;
    }

    return max_addres;
}

int main(int argc, char *argv[])
{
    list *head = NULL;
    list *tail = NULL;

    // тестовые данные
    struct list arr[3] = {
        {140525067852320, 10, "0"},
        {140525067852350, 30, "1"},
        {140525067852900, 100, "2"}};

    // заполняем лист структурами
    int index = 0;
    while (index < 3)
    {
        list *new_node = (list *)malloc(sizeof(list));

        new_node->address = arr[index].address;
        new_node->size = arr[index].size;

        new_node->next = NULL;
        // Формируем список
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }

        index++;
    }

    // передаем новый лист на обработку
    uint64_t res = findMaxBlock(head);

    return 0;
}
