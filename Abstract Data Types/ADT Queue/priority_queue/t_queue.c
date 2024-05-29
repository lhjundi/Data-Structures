#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_queue.h"

#define true 1
#define false 0

void create_queue(t_queue *queue) {
    queue->start = 0;
    queue->end = 0;
    queue->count = 0;
}

boolean enqueue(t_queue *queue, char *name) {
    if (is_full(queue)) {
        return false;
    }

    t_client *new_client = (t_client *)malloc(sizeof(t_client));
    check_allocation(new_client);

    new_client->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    check_allocation(new_client->name);

    strcpy(new_client->name, name);

    queue->items[queue->end] = new_client;
    queue->end = (queue->end + 1) % MAX_QUEUE_SIZE;
    queue->count++;
    return true;
}

boolean dequeue(t_queue *queue, t_client *client) {
    if (is_empty(queue)) {
        return false;
    }

    client->name = queue->items[queue->start]->name;

    queue->start = (queue->start + 1) % MAX_QUEUE_SIZE;
    queue->count--;
    return true;
}

boolean is_full(t_queue *queue) {
    return queue->count == MAX_QUEUE_SIZE;
}

boolean is_empty(t_queue *queue) {
    return queue->count == 0;
}

void destroy_queue(t_queue *queue) {
    while (!is_empty(queue)) {
        free(queue->items[queue->start]->name);
        free(queue->items[queue->start]);
        queue->start = (queue->start + 1) % MAX_QUEUE_SIZE;
        queue->count--;
    }
}

boolean check_allocation(void *ptr) {
    if (!ptr) {
        printf("Memory allocation failed...aborting\n");
        exit(1);
    }
    return true;
}

void handle_enqueue_command(t_queue *queue) {
    char name[MAX_NAME_LENGTH];
    scanf(" %s", name);
    enqueue(queue, name);
}

void process_service_order(t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count) {
    t_client temp_item;

    if (*consecutive_priority_count < 3 && !is_empty(priority_queue)) {
        dequeue(priority_queue, &temp_item);
        (*consecutive_priority_count)++;
    } else if (!is_empty(general_queue)) {
        dequeue(general_queue, &temp_item);
        *consecutive_priority_count = 0;
    } else if (!is_empty(priority_queue)) {
        dequeue(priority_queue, &temp_item);
        *consecutive_priority_count = 1;
    }

    if (temp_item.name) {
        enqueue(service_order, temp_item.name);
        free(temp_item.name);
    }
}

void show_output(t_queue *queue) {
    int index = queue->start;
    for (int i = 0; i < queue->count; i++) {
        printf("%s\n", queue->items[index]->name);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
}
