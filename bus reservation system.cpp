#include <iostream>
#include <string>
#include <vector>

using namespace std;
class BusReservationSystem {

private:

    vector<vector<bool> >seats;  // 2D array representing seats (true = reserved, false = available)
    const int rows = 5;  // Number of rows of seats
    const int cols = 6;  // Number of columns of seats

public:
    BusReservationSystem() {
        // Initialize the bus seats as available (false)
        seats = vector<vector<bool> >(rows, vector<bool>(cols, false));
    }

    // Function to display the seat map
    void displaySeats() {
        cout << "\nBus Seat Reservation System\n";
        cout << "----------------------------\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (seats[i][j]) {
                    cout << "[X]";  // Reserved seat
                } else {
                    cout << "[ ]";  // Available seat
                }
            }
            cout << endl;
        }
    }

    // Function to reserve a seat
    bool reserveSeat(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            if (!seats[row][col]) {
                seats[row][col] = true;  // Reserve the seat
                cout << "Seat (" << row + 1 << ", " << col + 1 << ") reserved successfully!\n";
                return true;
            } else {
                cout << "Sorry, this seat is already reserved.\n";
                return false;
            }
        } else {
            cout << "Invalid seat number. Please try again.\n";
            return false;
        }
    }

    // Function to cancel a reservation
    bool cancelReservation(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            if (seats[row][col]) {
                seats[row][col] = false;  // Cancel the reservation
                cout << "Reservation for seat (" << row + 1 << ", " << col + 1 << ") has been canceled.\n";
                return true;
            } else {
                cout << "This seat is not reserved yet.\n";
                return false;
            }
        } else {
            cout << "Invalid seat number. Please try again.\n";
            return false;
        }
    }
};

int main() {
    BusReservationSystem bus;
    int choice, row, col;

    while (true) {
        cout << "\nBus Reservation System\n";
        cout << "1. View Seat Map\n";
        cout << "2. Reserve a Seat\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bus.displaySeats();
                break;

            case 2:
                cout << "Enter row number (1-5): ";
                cin >> row;
                cout << "Enter column number (1-6): ";
                cin >> col;
                bus.reserveSeat(row - 1, col - 1);  // Adjust to 0-based index
                break;

            case 3:
                cout << "Enter row number (1-5): ";
                cin >> row;
                cout << "Enter column number (1-6): ";
                cin >> col;
                bus.cancelReservation(row - 1, col - 1);  // Adjust to 0-based index
                break;

            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

