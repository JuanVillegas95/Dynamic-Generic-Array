#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

// Structure to hold information about the vector
typedef struct {
    size_t capacity; // Total capacity of the vector
    size_t size;     // Current number of elements in the vector
    size_t element_size; // Size of each element in the vector
} vector_info;

// Macro to define a vector for a specific type
#define vector(T) T*

// Initializes a vector for a specific type
#define vector_init(type) (type *)_vector_init(sizeof(type))

// Returns a pointer to the vector_info structure from the given vector pointer
#define vector_header(ptr) ((vector_info *)((char *)(ptr) - sizeof(vector_info)))

// Retrieves the current size (number of elements) of the vector
#define vector_size(ptr) (vector_header(ptr)->size)

// Adds a value to the end of the vector, ensuring capacity and incrementing the size
#define vector_add(arr, value) do { \
    _vector_ensure_capacity((void **)&(arr), sizeof(*arr)); \
    (arr)[vector_size(arr)] = (value); \
    vector_header(arr)->size++; \
} while (0)

// Retrieves the current capacity of the vector
#define vector_capacity(ptr) (vector_header(ptr)->capacity)

// Retrieves the size of elements stored in the vector
#define vector_element_size(ptr) (vector_header(ptr)->element_size)

// Function prototypes for vector operations

// Internal function to initialize a vector of a specific element size
void *_vector_init(size_t element_size);

// Ensures that the vector has enough capacity, and resizes if necessary
void _vector_ensure_capacity(void **arr, size_t element_size);

// Destroys the vector, freeing its memory
void vector_destroy(void *arr);

// Removes the last element from the vector, decreasing its size
void vector_pop(void *arr);

// Prints information about the vector, such as capacity, size, and element size
void print_vector_info(void *arr);

// Function prototypes for printing elements of specific types
void print_int(void *data);    // Prints an integer
void print_char(void *data);   // Prints a character

// Generic function to print the elements of a vector using a provided print function
void vector_print(void *arr, void (*print_func)(void *));

#endif // VECTOR_H
