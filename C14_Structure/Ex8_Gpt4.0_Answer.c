/**
 * 程序清单14.8 一个座位预订管理程序
 *
 * 这个C程序管理一个座位系统，可能用于剧院或飞机等场所。它使用一个结构体Seat来表示每个座位，包括座位号，一个布尔值表示座位是否被预订，以及预订人的名和姓。
 *
 * 程序为用户提供了一个菜单，有以下选项：
 *
 * 显示空座位的数量。
 * 显示空座位的列表。
 * 显示座位的字母顺序列表。
 * 将客户分配给一个座位。
 * 删除座位分配。
 * 退出程序。
 * 每个选项对应程序中的一个函数。用户可以通过输入相应的字母来选择一个选项。程序然后会调用相应的函数来执行请求的操作。
 *
 * main函数初始化了一个包含12个Seat结构体的数组，所有座位都标记为未预订。然后它进入一个循环，向用户展示菜单并执行请求的操作，直到用户选择退出。
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int seatNumber;
    bool isReserved;
    char firstName[20];
    char lastName[20];
} Seat;

void showEmptySeats(Seat seats[], int size);
void showListOfEmptySeats(Seat seats[], int size);
void showAlphabeticalListOfSeats(Seat seats[], int size);
void assignCustomerToSeat(Seat seats[], int size);
void deleteSeatAssignment(Seat seats[], int size);

int main() {
    Seat seats[12];
    for (int i = 0; i < 12; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isReserved = false;
    }

    char choice;
    do {
        printf("\nTo choose a function, enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical list of seats\n");
        printf("d) Assign a customer to a seat assignment\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'a':
            showEmptySeats(seats, 12);
            break;
        case 'b':
            showListOfEmptySeats(seats, 12);
            break;
        case 'c':
            showAlphabeticalListOfSeats(seats, 12);
            break;
        case 'd':
            assignCustomerToSeat(seats, 12);
            break;
        case 'e':
            deleteSeatAssignment(seats, 12);
            break;
        case 'f':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'f');

    return 0;
}

/**
 * Displays the number of empty seats in the array of seats.
 * 
 * @param seats The array of seats.
 * @param size The size of the array.
 */
void showEmptySeats(Seat seats[], int size) {
    int emptySeats = 0;
    for (int i = 0; i < size; i++) {
        if (!seats[i].isReserved) {
            emptySeats++;
        }
    }
    printf("Number of empty seats: %d\n", emptySeats);
}

/**
 * Displays the list of empty seats in the array of seats.
 * 
 * @param seats The array of seats.
 * @param size The size of the array.
 */
void showListOfEmptySeats(Seat seats[], int size) {
    printf("Empty seats: ");
    for (int i = 0; i < size; i++) {
        if (!seats[i].isReserved) {
            printf("%d ", seats[i].seatNumber);
        }
    }
    printf("\n");
}

/**
 * Displays the alphabetical list of seats in the array of seats.
 * 
 * @param seats The array of seats.
 * @param size The size of the array.
 */
void showAlphabeticalListOfSeats(Seat seats[], int size) {
    Seat sortedSeats[size];
    memcpy(sortedSeats, seats, sizeof(sortedSeats));
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(sortedSeats[i].lastName, sortedSeats[j].lastName) > 0) {
                Seat temp = sortedSeats[i];
                sortedSeats[i] = sortedSeats[j];
                sortedSeats[j] = temp;
            }
        }
    }

    printf("Alphabetical list of seats:\n");
    for (int i = 0; i < size; i++) {
        if (sortedSeats[i].isReserved) {
            printf("%d - %s, %s\n", sortedSeats[i].seatNumber, sortedSeats[i].lastName, sortedSeats[i].firstName);
        }
    }
}

/**
 * Assigns a customer to a seat in the array of seats.
 * 
 * @param seats The array of seats.
 * @param size The size of the array.
 */
void assignCustomerToSeat(Seat seats[], int size) {
    int seatNumber;
    printf("Enter seat number (1-12) to assign: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > 12) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (seats[seatNumber - 1].isReserved) {
        printf("This seat is already reserved.\n");
        return;
    }

    printf("Enter customer's first name: ");
    scanf("%s", seats[seatNumber - 1].firstName);
    printf("Enter customer's last name: ");
    scanf("%s", seats[seatNumber - 1].lastName);

    seats[seatNumber - 1].isReserved = true;
    printf("Seat assigned!\n");
}

/**
 * Deletes the assignment of a seat in the array of seats.
 * 
 * @param seats The array of seats.
 * @param size The size of the array.
 */
void deleteSeatAssignment(Seat seats[], int size) {
    int seatNumber;
    printf("Enter seat number (1-12) to delete assignment: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > 12) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (!seats[seatNumber - 1].isReserved) {
        printf("This seat is not reserved.\n");
        return;
    }

    seats[seatNumber - 1].isReserved = false;
    strcpy(seats[seatNumber - 1].firstName, "");
    strcpy(seats[seatNumber - 1].lastName, "");
    printf("Seat assignment deleted!\n");
}