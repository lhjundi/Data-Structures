#ifndef T_BINARY_TREE_H
#define T_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char value;
    struct _node *left;
    struct _node *right;
} t_node;

t_node* create(char *string);
int pre(t_node *tree);
int in(t_node *tree);
int post(t_node *tree);
int height(t_node *node);
void print(t_node *tree);
void free_tree(t_node *node);
t_node* search_node(t_node* root, char value);
int is_open_parens(char character);
int is_close_parens(char character);
int is_valid_character(char character);
void count_elements(char *input, int *node_count, int *open_parens, int *close_parens);
int parentheses_balanced(int open_parens, int close_parens);
int valid_structure(int node_count, int open_parens, int close_parens);
int valid_input(char *input);


#endif