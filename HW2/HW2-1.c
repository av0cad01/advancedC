#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

int *findMaxBlocks(struct list *head);      //по условию функция типа void, но такая функция не возращает значение

int *findMaxBlocks(struct list *head)
{
    struct list *ptr = head;                //получаем указатель на начало списка
    void *maxBlockAddress = NULL;           
    size_t maxBlockSize = NULL;             
    while(ptr) {                            //пока список не пуст
        if(maxBlockSize<ptr->size) {        //сравниваем текущее значение с максимальным
            maxBlockSize = ptr->size;       //если значение больше максимального, приравниваем максимальное к текущему
            maxBlockAddress = ptr->address; //записываем адресс текущего максимального значения
        }
        ptr = ptr->next;
    }
    return maxBlockAddress;                 //возвращаем значение
}