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

void showEmptySeats(Seat seats[], int size) {
    int emptySeats = 0;
    for (int i = 0; i < size; i++) {
        if (!seats[i].isReserved) {
            emptySeats++;
        }
    }
    printf("Number of empty seats: %d\n", emptySeats);
}

void showListOfEmptySeats(Seat seats[], int size) {
    printf("Empty seats: ");
    for (int i = 0; i < size; i++) {
        if (!seats[i].isReserved) {
            printf("%d ", seats[i].seatNumber);
        }
    }
    printf("\n");
}

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

void deleteSeatAssignment(Seat seats[], int size) {
    int seatNumber;
    printf("Enter seat number (1-12) to delete assignment: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > 12) {
        printf("Invalid seatnumber. Please try again.\n");
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