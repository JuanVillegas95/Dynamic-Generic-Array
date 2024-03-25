# Vector Library for C

The Vector Library provides a generic, dynamically resizable array implementation in C, similar to `std::vector` in C++ or `List` in other high-level languages. It supports operations like initialization, adding elements, printing elements, and destruction of the vector. Below is an example of how to use this library for different data types including `int`, `char`, and a custom `struct`.

## Features

- **Generic Implementation**: Use with any data type.
- **Dynamic Resizing**: Automatically grows as you add elements.
- **Easy to Use**: Simple API for common vector operations.

## Example Usage

This example demonstrates creating vectors for `int`, `char`, and a custom `struct Person`. It includes adding elements to vectors, printing vector contents, and properly destroying vectors to free allocated memory.

```c
#include <stdio.h>
#include "vector.h"

typedef struct {
    int id;
    char name[20];
} Person;

void print_person(void *data) {
    Person *person = (Person *)data;
    printf("ID: %d, Name: %s\n", person->id, person->name);
}

int main(int argc, char** argv) {
    // Dynamic array of ints
    vector(int) arr_int = vector_init(int);
    for (int i = 0; i < 20; ++i) {
        vector_add(arr_int, i);
    }
    vector_print(arr_int, print_int);
    printf("\n");
    vector_destroy(arr_int);

    // Dynamic array of chars
    vector(char) arr_char = vector_init(char);
    for (char c = 'a'; c < 'k'; ++c) {
        vector_add(arr_char, c);
    }
    vector_print(arr_char, print_char);
    printf("\n");
    vector_destroy(arr_char);

    // Dynamic array of Persons
    vector(Person) arr_person = vector_init(Person);
    Person people[] = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
    for (int i = 0; i < 3; ++i) {
        vector_add(arr_person, people[i]);
    }
    vector_print(arr_person, print_person);
    
    print_vector_info(arr_person);
    vector_destroy(arr_person);

    return 0;
}
```

## Compiling and Running
Ensure you include both vector.c and vector.h in your project, and compile them along with your source file. For example:

```bash
gcc -o my_program my_program.c vector.c -I.
```
Replace my_program.c with the name of your source file. After compiling, you can run your program as follows:

```bash
./my_program
```
This simple yet powerful vector library is designed to be easy to integrate into any C project, providing flexible and dynamic array capabilities with minimal overhead.