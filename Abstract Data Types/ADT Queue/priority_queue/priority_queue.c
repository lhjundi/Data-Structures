#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 50
#define MAX_NAME_LENGTH 50
#define true 1
#define false 0

typedef int boolean;

typedef struct {
    char *name;
} t_client;

typedef struct {
    int start;
    int end;
    int count;
    t_client **items;
} t_queue;

/**
 * @brief Creates a new queue.
 * @param queue Pointer to the queue to be created.
 */
void create_queue(t_queue *queue);

/**
 * @brief Adds an item to the queue.
 * @param queue Pointer to the queue.
 * @param name Name of the item to be added.
 * @return true if the item was successfully added, false otherwise.
 */
boolean enqueue(t_queue *queue, char *name);

/**
 * @brief Removes an item from the queue.
 * @param queue Pointer to the queue.
 * @param client Pointer to a t_client structure to store the removed item.
 * @return true if an item was successfully removed, false otherwise.
 */
boolean dequeue(t_queue *queue, t_client *client);

/**
 * @brief Checks if the queue is full.
 * @param queue Pointer to the queue.
 * @return true if the queue is full, false otherwise.
 */
boolean is_full(t_queue *queue);

/**
 * @brief Checks if the queue is empty.
 * @param queue Pointer to the queue.
 * @return true if the queue is empty, false otherwise.
 */
boolean is_empty(t_queue *queue);

/**
 * @brief Destroys the queue.
 * @param queue Pointer to the queue to be destroyed.
 */
void destroy_queue(t_queue *queue);

/**
 * @brief Checks the result of memory allocation.
 * @param ptr Pointer to the allocated memory.
 * @return true if the allocation was successful, otherwise abort the program.
 */
boolean check_allocation(void *ptr);

/**
 * @brief Reads a command character from input.
 * @return Command character read from input.
 */
char read_command();

/**
 * @brief Processes a command character.
 * @param command Command character.
 * @param priority_queue Pointer to the priority queue.
 * @param general_queue Pointer to the general queue.
 * @param service_order Pointer to the service order queue.
 * @param consecutive_priority_count Pointer to the counter for consecutive priority items.
 */
void process_command(char command, t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count);

/**
 * @brief Handles the enqueue command.
 * @param queue Pointer to the queue where the item will be enqueued.
 */
void handle_enqueue_command(t_queue *queue);

/**
 * @brief Gets input commands and processes them.
 * @param priority_queue Pointer to the priority queue.
 * @param general_queue Pointer to the general queue.
 */
void get_input(t_queue *priority_queue, t_queue *general_queue);

/**
 * @brief Processes service order based on priority and general queues.
 * @param priority_queue Pointer to the priority queue.
 * @param general_queue Pointer to the general queue.
 * @param service_order Pointer to the service order queue.
 * @param consecutive_priority_count Pointer to the counter for consecutive priority items.
 */
void process_service_order(t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count);

/**
 * @brief Displays the items in a queue.
 * @param queue Pointer to the queue to be displayed.
 */
void show_output(t_queue *queue);

void create_queue(t_queue *queue) {
    queue->start = 0;
    queue->end = 0;
    queue->count = 0;
    queue->items = (t_client **)malloc(MAX_QUEUE_SIZE * sizeof(t_client *));
    check_allocation(queue->items);
}

boolean enqueue(t_queue *queue, char *name) {
    if (is_full(queue)) {
        return false;
    }

    queue->items[queue->end] = (t_client *)malloc(sizeof(t_client));
    check_allocation(queue->items[queue->end]);

    queue->items[queue->end]->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    check_allocation(queue->items[queue->end]->name);

    strcpy(queue->items[queue->end]->name, name);

    queue->end = (queue->end + 1) % MAX_QUEUE_SIZE;
    queue->count++;
    return true;
}

boolean dequeue(t_queue *queue, t_client *client) {
    if (is_empty(queue)) {
        return false;
    }

    client->name = queue->items[queue->start]->name;
    free(queue->items[queue->start]);
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
    for (int i = 0; i < queue->count; i++) {
        free(queue->items[(queue->start + i) % MAX_QUEUE_SIZE]->name);
        free(queue->items[(queue->start + i) % MAX_QUEUE_SIZE]);
    }
    free(queue->items);
}

boolean check_allocation(void *ptr) {
    if (!ptr) {
        printf("Memory allocation failed...aborting\n");
        exit(1);
    }
    return true;
}

char read_command() {
    char command;
    scanf(" %c", &command);
    return command;
}

void process_command(char command, t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count) {
    switch (command) {
        case 'g':
        case 'p':
            handle_enqueue_command(command == 'g' ? general_queue : priority_queue);
            break;
        case 's':
            process_service_order(priority_queue, general_queue, service_order, consecutive_priority_count);
            break;
    }
}

void handle_enqueue_command(t_queue *queue) {
    char name[MAX_NAME_LENGTH];
    scanf(" %s", name);
    enqueue(queue, name);
}

void process_service_order(t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count) {
    t_client temp_item;
    if ((*consecutive_priority_count < 3 && !is_empty(priority_queue)) || is_empty(general_queue)) {
        dequeue(priority_queue, &temp_item);
    } else {
        dequeue(general_queue, &temp_item);
        *consecutive_priority_count = 0;
    }
    enqueue(service_order, temp_item.name);
    free(temp_item.name);
}

void get_input(t_queue *priority_queue, t_queue *general_queue) {
    t_queue service_order;
    create_queue(&service_order);

    int consecutive_priority_count = 0;
    char command;

    do {
        command = read_command();
        process_command(command, priority_queue, general_queue, &service_order, &consecutive_priority_count);
    } while (command != 'f');

    show_output(&service_order);
    destroy_queue(&service_order);
}

void show_output(t_queue *queue) {
    int index = queue->start;
    for (int i = 0; i < queue->count; i++) {
        printf("%s\n", queue->items[index]->name);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
}

int main() {
    t_queue priority_queue, general_queue;
    create_queue(&priority_queue);
    create_queue(&general_queue);

    get_input(&priority_queue, &general_queue);

    destroy_queue(&priority_queue);
    destroy_queue(&general_queue);

    return 0;
}