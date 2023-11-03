#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define your hash table and node structures, as well as the hash_djb2 and key_index functions here

int main() {
    unsigned long int size = 100; // Choose an appropriate size for your hash table
    hash_table_t *ht = hash_table_create(size);

    // Add elements to the hash table
    hash_table_set(ht, "name", "John Doe");
    hash_table_set(ht, "age", "30");
    hash_table_set(ht, "city", "New York");

    // Access elements from the hash table
    char *name = hash_table_get(ht, "name");
    char *age = hash_table_get(ht, "age");
    char *city = hash_table_get(ht, "city");

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("City: %s\n", city);

    // Remember to free the memory when you're done
    free(name);
    free(age);
    free(city);

    // Free the hash table and its elements
    hash_table_delete(ht);

    return 0;
}

