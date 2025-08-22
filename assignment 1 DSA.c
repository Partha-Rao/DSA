/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tab {
    int pageID;                 
    char url[100];              
    struct Tab *prev, *next;    
} Tab;

Tab *head = NULL;       
Tab *current = NULL;    
int pageCounter = 0;    

Tab* createTab(char url[]) {
    Tab *newTab = (Tab*)malloc(sizeof(Tab));
    newTab->pageID = ++pageCounter;    
    strcpy(newTab->url, url);          
    newTab->prev = NULL;
    newTab->next = NULL;
    return newTab;
}

void visitNewPage() {
    char url[100];
    printf("Enter URL: ");
    scanf("%s", url);

    Tab *newTab = createTab(url);

    if (head == NULL) {
        head = newTab;
        current = newTab;
    } else {
        newTab->prev = current;
        newTab->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newTab;
        }
        current->next = newTab;
        current = newTab; 
    }

    printf("Opened new page: [%d] %s\n", current->pageID, current->url);
}

void moveNext() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved to next tab: [%d] %s\n", current->pageID, current->url);
    } else {
        printf("No next tab available!\n");
    }
}

void movePrev() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved to previous tab: [%d] %s\n", current->pageID, current->url);
    } else {
        printf("No previous tab available!\n");
    }
}

void showCurrent() {
    if (current == NULL) {
        printf("No current tab!\n");
    } else {
        printf("Current tab: [%d] %s\n", current->pageID, current->url);
    }
}

void closeTab() {
    if (head == NULL) {
        printf("No tabs to close!\n");
        return;
    }

    int id;
    printf("Enter pageID of tab to close: ");
    scanf("%d", &id);

    Tab *temp = head;
    while (temp != NULL && temp->pageID != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Tab with ID %d not found!\n", id);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; 

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    printf("Closed tab: [%d] %s\n", temp->pageID, temp->url);
    free(temp);
}

void showHistory() {
    if (head == NULL) {
        printf("No history! (No tabs)\n");
        return;
    }

    Tab *temp = head;
    printf("Tab History:\n");
    while (temp != NULL) {
        printf("[%d] %s\n", temp->pageID, temp->url);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n===== Browser Menu =====\n");
        printf("1. Visit New Page\n");
        printf("2. Go Forward\n");
        printf("3. Go Backward\n");
        printf("4. Show Current Tab\n");
        printf("5. Close Tab\n");
        printf("6. Show History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: visitNewPage(); break;
            case 2: moveNext(); break;
            case 3: movePrev(); break;
            case 4: showCurrent(); break;
            case 5: closeTab(); break;
            case 6: showHistory(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
