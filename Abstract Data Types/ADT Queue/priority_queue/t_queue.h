#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 50
#define MAX_NAME_LENGTH 50

typedef int boolean;

typedef struct {
    char *name;
} t_client;

typedef struct {
    int start;
    int end;
    int count;
    t_client *items[MAX_QUEUE_SIZE];
} t_queue;

void create_queue(t_queue *queue);
boolean enqueue(t_queue *queue, char *name);
boolean dequeue(t_queue *queue, t_client *client);
boolean is_full(t_queue *queue);
boolean is_empty(t_queue *queue);
void destroy_queue(t_queue *queue);
boolean check_allocation(void *ptr);
void handle_enqueue_command(t_queue *queue);
void process_service_order(t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count);
void show_output(t_queue *queue);

#endif // QUEUE_H
