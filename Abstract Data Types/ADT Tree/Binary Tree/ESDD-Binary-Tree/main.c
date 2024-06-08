//ESDD Trabalho Prático 05 - Árvore Binária

//Erick Henrique Akira Kajitani Motta
//Lucas Jundi Hikazudani
//Murilo Correa S Silva
//Joao Pedro Piccino Marafiotti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_binary_tree.h"

void print_menu() {
    printf("\nMenu:\n");
    printf("1. create (input) --- Example: create (A,(B,(),()),(C,(F,(),()),()))\n");
    printf("2. print\n");
    printf("3. pre\n");
    printf("4. in\n");
    printf("5. post\n");
    printf("6. height (node) --- Example: height A\n");
    printf("7. exit\n");
    printf("Enter command: ");
}

int main() {
    t_node *tree = NULL;
    char command[100];
    char input[100];

    while (1) {
        print_menu();
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "create", 6) == 0) {
            sscanf(command + 7, " %[^\n]", input);
            if (valid_input(input)) {
                if (tree != NULL) {
                    free_tree(tree);
                }
                tree = create(input);
                printf("Tree created.\n");
            } else {
                printf("Invalid input.\n");
            }
        } else if (strncmp(command, "pre", 3) == 0) {
            if (tree != NULL) {
                pre(tree);
                printf("\n");
            } else {
                printf("Tree is empty.\n");
            }
        } else if (strncmp(command, "in", 2) == 0) {
            if (tree != NULL) {
                in(tree);
                printf("\n");
            } else {
                printf("Tree is empty.\n");
            }
        } else if (strncmp(command, "post", 4) == 0) {
            if (tree != NULL) {
                post(tree);
                printf("\n");
            } else {
                printf("Tree is empty.\n");
            }
        } else if (strncmp(command, "height", 6) == 0) {
            char node;
            sscanf(command + 7, " %c", &node);
            t_node *n = search_node(tree, node);
            if (n) {
                printf("Height of %c: %d\n", node, height(n));
            } else {
                printf("Node %c not found.\n", node);
            }
        } else if (strncmp(command, "print", 5) == 0) {
            if (tree != NULL) {
                print(tree);
            } else {
                printf("Tree is empty.\n");
            }
        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    free_tree(tree);
    return 0;
}
