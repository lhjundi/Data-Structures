#include <stdio.h>
#include "t_queue.h"

char read_command();
void process_command(char command, t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count);
void get_input(t_queue *priority_queue, t_queue *general_queue);

char read_command() {
    char command;
    scanf(" %c", &command);
    return command;
}

void process_command(char command, t_queue *priority_queue, t_queue *general_queue, t_queue *service_order, int *consecutive_priority_count) {
    switch (command) {
        case 'g':
            handle_enqueue_command(general_queue);
            break;
        case 'p':
            handle_enqueue_command(priority_queue);
            break;
        case 's':
            process_service_order(priority_queue, general_queue, service_order, consecutive_priority_count);
            break;
    }
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

int main() {
    t_queue priority_queue, general_queue;
    create_queue(&priority_queue);
    create_queue(&general_queue);

    get_input(&priority_queue, &general_queue);

    destroy_queue(&priority_queue);
    destroy_queue(&general_queue);

    return 0;
}
