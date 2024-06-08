#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_binary_tree.h"

t_node* create_node(char item) {
    t_node *node = (t_node*) malloc(sizeof(t_node));
    if (node == NULL) {
        printf("Error in create node %c\n", item);
        exit(1);
    }
    node->value = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int pre(t_node *root) {
    if (root == NULL) return 0;
    printf("%c ", root->value);
    pre(root->left);
    pre(root->right);
    return 1;
}

int in(t_node *root) {
    if (root == NULL) return 0;
    in(root->left);
    printf("%c ", root->value);
    in(root->right);
    return 1;
}

int post(t_node *root) {
    if (root == NULL) return 0;
    post(root->left);
    post(root->right);
    printf("%c ", root->value);
    return 1;
}

int height(t_node *node) {
    if (node == NULL) {
        return 0;
    } else {
        int h_left = height(node->left);
        int h_right = height(node->right);
        if (h_left > h_right)
            return h_left + 1;
        return h_right + 1;
    }
}


void print_rec(t_node *node, int i) {
    if (node == NULL) {
        return;
    }
    print_rec(node->right, i + 1);
    for (int j = 0; j < i; j++) {
        printf("\t");
    }
    printf("%c\n", node->value);
    print_rec(node->left, i + 1);
}

void print(t_node *root) {
    print_rec(root, 0);
}

char* create_string(char *string, int begin, int end) {
    char *new_string = (char*) malloc((end - begin + 1) * sizeof(char));
    int i = begin, j = 0;
    for (; i < end; i++) {
        new_string[j] = string[i];
        j++;
    }
    new_string[j] = '\0';
    return new_string;
}

t_node* search_node(t_node* root, char value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->value == value) {
        return root;
    }
    t_node* node = search_node(root->left, value);
    if (node == NULL) {
        node = search_node(root->right, value);
    }
    return node;
}

char* find_left(char* string) {
    int begin = 3, end;
    int par = 1, i = 3;
    while (par != 0) {
        if (string[i] == '(') {
            par++;
        } else if (string[i] == ')') {
            par--;
        }
        i++;
    }
    end = i;
    return create_string(string, begin, end - 1);
}

char* find_right(char* string) {
    int begin = 3, end;
    int par = 1, i = 4;
    char compare;
    while (par != 0) {
        compare = string[i];
        if (compare == '(') {
            par++;
        } else if (compare == ')') {
            par--;
        }
        i++;
    }
    end = i;
    begin = end + 1;
    par = 1;
    while (par != 0) {
        compare = string[i];
        if (compare == '(') {
            par++;
        } else if (compare == ')') {
            par--;
        }
        i++;
    }
    end = i;
    return create_string(string, begin, end - 1);
}

t_node* rec_create(char *string) {
    if (string[0] == '\0' || string[1] == ')') {
        return NULL;
    }

    t_node* node = create_node(string[1]);
    node->left = rec_create(find_left(string));
    node->right = rec_create(find_right(string));

    return node;
}

t_node* create(char *string) {
    t_node *node = rec_create(string);
    return node;
}

void free_tree(t_node *node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int is_open_parens(char character){
    return character == '(';
}

int is_close_parens(char character){
    return character == ')';
}

int is_valid_character(char character){
    return  character != ',' && character != ' ' 
            && !is_open_parens(character) && !is_close_parens(character) && character != '\0';
}

void count_elements(char *input, int *node_count, int *open_parens, int *close_parens) {
    *node_count = 0;
    *open_parens = 0;
    *close_parens = 0;
    int i = 0;
    while (i < (int) strlen(input)) {
        if (is_valid_character(input[i])) {
            (*node_count)++;
        }
        if (is_open_parens(input[i])) {
            (*open_parens)++;
        } else if (is_close_parens(input[i])) {
            (*close_parens)++;
        }
        i++;
    }
}

int parentheses_balanced(int open_parens, int close_parens) {
    return open_parens == close_parens;
}

int valid_structure(int node_count, int open_parens, int close_parens) {
    return ((node_count * 2) + 1 == open_parens) && ((node_count * 2) + 1 == close_parens);
}

int valid_input(char *input) {
    int node_count, open_parens, close_parens;
    count_elements(input, &node_count, &open_parens, &close_parens);
    if (!parentheses_balanced(open_parens, close_parens)) return 0;
    if (valid_structure(node_count, open_parens, close_parens)) return 1;
    return 0;
}