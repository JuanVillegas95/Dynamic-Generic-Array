#include "vector.h"
#include <stdio.h>

// Initializes a vector with an initial capacity and element size.
void *_vector_init(size_t element_size) {
    // Allocate memory for the vector metadata and initial element storage.
    vector_info *info = malloc(sizeof(vector_info) + (element_size * 2));
    if (!info) {
        perror("Failed to allocate memory for vector");
        exit(EXIT_FAILURE);
    }
    info->capacity = 2; 
    info->size = 0;    
    info->element_size = element_size; 
    return (void *)(info + 1); // Return pointer to the first element.
}

// Ensures the vector has enough capacity to add new elements, resizing if necessary.
void _vector_ensure_capacity(void **arr, size_t element_size) {
    vector_info *info = vector_header(*arr);
    if (info->size == info->capacity) {
        size_t new_capacity = info->capacity * 2;
        vector_info *new_info = realloc(info, sizeof(vector_info) + new_capacity * element_size);
        if (!new_info) {
            perror("Failed to reallocate memory for vector");
            exit(EXIT_FAILURE);
        }
        *arr = (void *)(new_info + 1); // Update the vector pointer.
        new_info->capacity = new_capacity; 
    }
}

// Prints information about the vector (capacity, size, and element size).
void print_vector_info(void *arr) {
    vector_info *info = vector_header(arr);
    printf("Array Info:\n");
    printf("Capacity: %zu\n", info->capacity);
    printf("Size: %zu\n", info->size);
    printf("Element Size: %zu bytes\n", info->element_size);
}

// Prints an integer element.
void print_int(void *data) {
    printf("%d ", *(int *)data);
}

// Prints a char element.
void print_char(void *data) {
    printf("%c ", *(char *)data);
}

// Prints elements of the vector using a specified print function.
void vector_print(void *arr, void (*print_func)(void *)) {
    for (int i = 0; i < vector_size(arr); ++i) {
        print_func((char *)arr + i * vector_element_size(arr));
    }
}

// Destroys the vector, freeing its allocated memory.
void vector_destroy(void *arr) {
    if (arr == NULL) return; 
    vector_info *info = vector_header(arr);
    free(info); 
}

// Removes the last element from the vector.
void vector_pop(void *arr) {
    vector_info *info = vector_header(arr);
    if (info->size > 0) {
        info->size--; 
    }
}
