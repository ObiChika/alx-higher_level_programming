#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000 // You can change this value based on your requirements

typedef struct Node {
    char* key;
    char* value;
    struct Node* next;
} Node;

typedef struct hash_table_t {
    unsigned long int size;
    Node** array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size) {
    hash_table_t *new_table = (hash_table_t *)malloc(sizeof(hash_table_t));
    if (new_table == NULL) {
        return NULL; // Memory allocation failed
    }

    new_table->size = size;
    new_table->array = (Node **)malloc(sizeof(Node *) * size);
    if (new_table->array == NULL) {
        free(new_table);
        return NULL; // Memory allocation failed
    }

    for (unsigned long int i = 0; i < size; i++) {
        new_table->array[i] = NULL;
    }

    return new_table;
}

