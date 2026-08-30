#include<stdio.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *Book);
void searchContact(AddressBook *Book);
void editContact(AddressBook *Book);
void deleteContact(AddressBook *Book);
void listContacts(AddressBook *Book);
void saveContactsToFile(AddressBook *Book);
void loadContactsToFile(AddressBook *Book);

