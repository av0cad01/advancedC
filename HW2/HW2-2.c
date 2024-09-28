#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head);

size_t totalMemoryUsage(list *head)
{
    struct list *ptr = head;                //получаем указатель на начало списка       
    size_t sumBlockSize = NULL;             
    while(ptr) {                            //пока список не пуст
        sumBlockSize += ptr->size;          //прибавляем размер текущего элемента списка к сумме
        ptr = ptr->next;                    //переходим к следующему элементу списка
    }
    return sumBlockSize;                    //возвращаем значение
}