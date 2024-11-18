#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node for the linked list
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Hash Table
struct Node* hashTable[TABLE_SIZE];

// Hash function (simple modulo)
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key-value pair into hash table
void insert(int key, int value) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search for a value by key
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1; // Not found
}

// Delete a key-value pair
void delete(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp) {
        if (temp->key == key) {
            if (prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("Index %d: ", i);
        while (temp) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert elements
    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(2, 40);
    insert(12, 50);

    // Display hash table
    display();

    // Search for keys
    printf("Search key 21: %d\n", search(21));
    printf("Search key 2: %d\n", search(2));

    // Delete a key
    delete(11);
    display();

    return 0;
}
