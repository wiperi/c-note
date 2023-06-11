/* 8.巨人航空公司的机群由 12 个座位的飞机组成。它每天飞行一个航
班。根据下面的要求，编写一个座位预订程序。
a.该程序使用一个内含 12 个结构的数组。每个结构中包括：一个成员
表示座位编号、一个成员表示座位是否已被预订、一个成员表示预订人的
名、一个成员表示预订人的姓。
b.该程序显示下面的菜单：
To choose a function, enter its letter label:
a) Show number of empty seats
b) Show list of empty seats
c) Show alphabetical list of seats
d) Assign a customer to a seat assignment
e) Delete a seat assignment
f) Quit
c.该程序能成功执行上面给出的菜单。选择d)和e)要提示用户进行额外
输入，每个选项都能让用户中止输入。
d.执行特定程序后，该程序再次显示菜单，除非用户选择f)。 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STRLEN 80
typedef struct {
    int seat_id;
    bool isbooked;
    char register_first_name[STRLEN];
    char register_second_name[STRLEN];
} seat;

// a) Show number of empty seats
void showNumberOfEmptySeats(seat *plane, int number_of_seats) {
    int count = 0;

    for (int i = 0; i < number_of_seats; i++) {
        if (!plane[i].isbooked) {
            count++;
        }
    }
    printf("Number of vacant seats are %d\n", count);
}

// b) Show list of empty seats
void showListOfEmptySeats(seat plane[], int number_of_seats) {
    for (int i = 0; i < number_of_seats; i++) {
        if (!plane[i].isbooked) {
            printf("Seat ID: %d, is still vacant.\n", plane[i].seat_id);
        }
    }
}

// c) Show alphabetical list of seats
void showAlphabeticalListOfSeats(seat plane[], int number_of_seats) {
    // Create a ptr array
    seat *ptr[number_of_seats];
    for (int i = 0; i < number_of_seats; i++) {
        ptr[i] = &plane[i];
    }

    // Use insertion sort to sort the ptr array
    seat *buffer;
    for (int i = 1; i < number_of_seats; i++) {
        buffer = ptr[i];
        int compare_entry = i - 1;
        while (compare_entry >= 0 && strcmp(ptr[compare_entry]->register_first_name, buffer->register_first_name) > 0) {
            ptr[compare_entry + 1] = ptr[compare_entry];
            compare_entry--;
        }
        ptr[compare_entry + 1] = buffer;
    }

    puts("List of Seats in order are :");
    for (int i = 0; i < number_of_seats; i++) {
        if (ptr[i]->isbooked) {
            printf("%s\n", ptr[i]->register_first_name);
        }
    }
    puts("End.");
}

// d) Assign a customer to a seat assignment
void assignCustomerToASeat(seat plane[], int number_of_seats, char *fname, char *sname) {
    for (int i = 0; i < number_of_seats; i++) {
        if (plane[i].isbooked) {
            continue;
        } else {
            plane[i].isbooked = true;
            strcpy(plane[i].register_first_name, fname);
            strcpy(plane[i].register_second_name, sname);
            puts("Assignment succeed.");
            return;
        }
    }
    puts("Assignment failed. There is no vacant now.");
}

// e) Delete a seat assignment
void deleteSeatAssignment(seat plane[], int number_of_seats, char *fname) {
    for (int i = 0; i < number_of_seats && plane[i].isbooked; i++) {
        if (strcmp(plane[i].register_first_name, fname) == 0) {
            plane[i].isbooked = false;
            strcpy(plane[i].register_first_name, "\0");
            strcpy(plane[i].register_second_name, "\0");
            puts("Delete susseed.");
            return;
        }
    }
    puts("Delete failed. Couldn't find the name");
}

// Clear input buffer
void eatLine(void) {
    while (getchar() != '\n')
        ;
}

int main(void) {
    const int number_of_seats = 12;
    seat plane[number_of_seats];
    char fname[STRLEN], sname[STRLEN];

    // Initalize the plane[]
    for (int i = 0; i < number_of_seats; i++) {
        plane[i].seat_id = i + 1;
        plane[i].isbooked = false;
        strcpy(plane[i].register_first_name, "");
        strcpy(plane[i].register_second_name, "");
    }

    char choice;
    do {
        puts("****************************************************");
        puts("To choose a function, enter its letter label:");
        printf(
            "a) Show number of empty seats\n"
            "b) Show list of empty seats\n"
            "c) Show alphabetical list of seats\n"
            "d) Assign a customer to a seat assignment\n"
            "e) Delete a seat assignment\n"
            "f) Quit\n");

        // Test input value
        while ((choice = getchar()) != EOF && !strchr("abcdef", choice)) {
            if (choice != '\n') {
                eatLine();
            }
            puts("Illegal input. Try again.");
        }
        eatLine();

        switch (choice) {
            case 'a':
                showNumberOfEmptySeats(plane, number_of_seats);
                break;
            case 'b':
                showListOfEmptySeats(plane, number_of_seats);
                break;
            case 'c':
                showAlphabeticalListOfSeats(plane, number_of_seats);
                break;
            case 'd':
                puts("Input the first name");
                scanf("%s", fname);
                eatLine();
                puts("Input the second name");
                scanf("%s", sname);
                eatLine();
                assignCustomerToASeat(plane, number_of_seats, fname, sname);
                break;
            case 'e':
                puts("Input seat owner's first name which you want to delete.");
                scanf("%s", fname);
                eatLine();
                deleteSeatAssignment(plane, 12, fname);
                break;
            default:
                puts("Default triggered. Error.");
                break;
        }
    } while (choice != 'f');
    puts("Bye.");
}