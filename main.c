#include <stdio.h>
#include <string.h>
#include <stdlib.h> // students usually include this out of habit

#define MAX 100

// student like struct
struct item {
    int id;
    char cat[50];
    char desc[100];
    int status; // 0 is pending, 1 is matched
};

// global variables
struct item lost_arr[MAX];
struct item found_arr[MAX];

int lost_cnt = 0;
int found_cnt = 0;
int id_counter = 101; 

void addLost() {
    if (lost_cnt == MAX) {
        printf("Array is full!\n");
        return;
    }
    struct item temp;
    temp.id = id_counter;
    id_counter++;
    temp.status = 0;

    printf("Enter category (no spaces): ");
    scanf("%s", temp.cat); 
    
    printf("Enter description: ");
    scanf(" %[^\n]s", temp.desc); // using the space trick for strings

    lost_arr[lost_cnt] = temp;
    lost_cnt++;
    
    //printf("debug: added id %d\n", temp.id);
    printf("Item added succesfully. ID is %d\n\n", temp.id);
}

void addFound() {
    if (found_cnt == MAX) {
        printf("Array is full!\n");
        return;
    }
    struct item temp;
    temp.id = id_counter++;
    temp.status = 0;

    printf("Enter category (no spaces): ");
    scanf("%s", temp.cat);
    
    printf("Enter description: ");
    scanf(" %[^\n]s", temp.desc);

    found_arr[found_cnt] = temp;
    found_cnt++;
    
    printf("Item added succesfully. ID is %d\n\n", temp.id);
}

void searchItem() {
    char s[50];
    printf("Enter category to search: ");
    scanf("%s", s);

    int flag = 0;

    printf("\n-- LOST ITEMS --\n");
    for (int i = 0; i < lost_cnt; i++) {
        // basic strcmp (case sensitive)
        if (strcmp(lost_arr[i].cat, s) == 0) {
            printf("ID: %d | Desc: %s | ", lost_arr[i].id, lost_arr[i].desc);
            if(lost_arr[i].status == 0) {
                printf("Status: Pending\n");
            } else {
                printf("Status: Matched\n");
            }
            flag = 1;
        }
    }

    printf("\n-- FOUND ITEMS --\n");
    for (int j = 0; j < found_cnt; j++) {
        if (strcmp(found_arr[j].cat, s) == 0) {
            printf("ID: %d | Desc: %s | ", found_arr[j].id, found_arr[j].desc);
            if(found_arr[j].status == 0) {
                printf("Status: Pending\n");
            } else {
                printf("Status: Matched\n");
            }
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("Not found anything.\n");
    }
    printf("\n");
}

void do_matching() {
    printf("\n--- Matcher ---\n");
    int got_match = 0;

    for (int i = 0; i < lost_cnt; i++) {
        if (lost_arr[i].status == 1) {
            continue; // skip if already matched
        }

        for (int j = 0; j < found_cnt; j++) {
            if (found_arr[j].status == 1) {
                continue;
            }

            // check if category is exactly the same
            if (strcmp(lost_arr[i].cat, found_arr[j].cat) == 0) {
                printf("Found a potential match!!\n");
                printf("Lost: %d - %s\n", lost_arr[i].id, lost_arr[i].desc);
                printf("Found: %d - %s\n", found_arr[j].id, found_arr[j].desc);
                
                char ch;
                printf("Do you want to match them? (y/n): ");
                scanf(" %c", &ch);
                
                if (ch == 'y' || ch == 'Y') {
                    lost_arr[i].status = 1;
                    found_arr[j].status = 1;
                    printf("Matched succesfully!\n\n");
                    got_match = 1;
                    break; // break inner loop, move to next lost item
                } else {
                    printf("Skipping...\n\n");
                }
            }
        }
    }

    if (got_match == 0) {
        printf("No matches right now.\n");
    }
    printf("\n");
}

int main() {
    int ch;

    // while loop for menu
    while (1) {
        printf("=== Lost and Found System ===\n");
        printf("1. Add Lost item\n");
        printf("2. Add Found item\n");
        printf("3. Search by category\n");
        printf("4. Match items\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        // if-else ladder instead of switch case
        if (ch == 1) {
            addLost();
        } 
        else if (ch == 2) {
            addFound();
        } 
        else if (ch == 3) {
            searchItem();
        } 
        else if (ch == 4) {
            do_matching();
        } 
        else if (ch == 5) {
            printf("Bye bye!\n");
            break;
        } 
        else {
            printf("Wrong choice try again.\n\n");
        }
    }
    return 0;
}
