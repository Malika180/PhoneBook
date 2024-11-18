//Malika Eshmukhamedova
//OI6MWF

#include "PhoneBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize(PhoneBook* phoneBook, int size) {
    phoneBook->numEntries = size;
    phoneBook->size = 0;
    phoneBook->entriesArr = (Entry*)malloc(sizeof(Entry) * size);
    if (phoneBook->entriesArr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

bool insert(PhoneBook* phoneBook, const char* name, const char* phoneNum) {
    if (phoneBook->size == phoneBook->numEntries) {
        return false;
    }
    Entry data;
    strncpy(data.name, name, sizeof(data.name) - 1);
    data.name[sizeof(data.name) - 1] = '\0'; 
    strncpy(data.phoneNumber, phoneNum, sizeof(data.phoneNumber) - 1);
    data.phoneNumber[sizeof(data.phoneNumber) - 1] = '\0'; 
    phoneBook->entriesArr[phoneBook->size] = data;
    phoneBook->size++;
    return true;
}

char* search(PhoneBook* phoneBook, const char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->entriesArr[i].name, name) == 0) {
            return phoneBook->entriesArr[i].phoneNumber;
        }
    }
    return NULL;
}

void print(const PhoneBook* phoneBook) {
    for (int i = 0; i < phoneBook->size; i++) {
        printf("Name: %s, Phone number: %s\n", phoneBook->entriesArr[i].name, phoneBook->entriesArr[i].phoneNumber);
    }
}



void destruct(PhoneBook* phoneBook) {
    free(phoneBook->entriesArr);
    phoneBook->entriesArr = NULL; 
    phoneBook->size = 0;
    phoneBook->numEntries = 0;
}
