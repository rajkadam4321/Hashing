#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];
int hash2(int key) {
    return 7 - (key % 7); // Secondary hash function for double hashing
}

// Initialize hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Hash function (simple modulo)
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Linear Probing
void insertLinear(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

// Quadratic Probing
void insertQuadratic(int key) {
    int index = hashFunction(key);
    int i = 1;
    while (hashTable[index] != EMPTY) {
        index = (index + i * i) % TABLE_SIZE;
        i++;
    }
    hashTable[index] = key;
}

// Double Hashing
void insertDoubleHashing(int key) {
    int index = hashFunction(key);
    int stepSize = hash2(key);
    while (hashTable[index] != EMPTY) {
        index = (index + stepSize) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

// Display hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    initialize();

    // Insertion using linear probing
    printf("Using Linear Probing:\n");
    insertLinear(5);
    insertLinear(15);
    insertLinear(25);
    insertLinear(35);
    display();

    initialize();

    // Insertion using quadratic probing
    printf("\nUsing Quadratic Probing:\n");
    insertQuadratic(5);
    insertQuadratic(15);
    insertQuadratic(25);
    insertQuadratic(35);
    display();

    initialize();

    // Insertion using double hashing
    printf("\nUsing Double Hashing:\n");
    insertDoubleHashing(5);
    insertDoubleHashing(15);
    insertDoubleHashing(25);
    insertDoubleHashing(35);
    display();

    return 0;
}
