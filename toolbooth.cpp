#include <iostream> // input-output stream library for console operations
#include <conio.h>  // conio.h library for console input functions (specific to Windows)
using namespace std;

// Class representing a Car
class Car {
private:    
    bool toll; // Member variable to indicate whether the car pays the toll
public:
    // Constructor to initialize the toll payment state
    Car(bool pays) : toll(pays) {}
    
    //Constant Member Function to check if the car is paying the toll
    bool isPaying() const {
        return toll; // Return the toll payment status
    }
};

// Class representing the TollBooth
class tollBooth {
private:
    unsigned int numCars; // Total number of cars that have passed through(can't have negative value)
    double totalCash;     // Total amount of cash collected
public:
    // Constructor to initialize the number of cars and total cash to zero
    tollBooth() : numCars(0), totalCash(0) {}

    // Method to process a Car object
    void processCar(const Car& car) {
        numCars++; // Increment the car count
        if (car.isPaying()) { // Check if the car is paying
            totalCash += 0.50; // Add 0.50 to the total cash collected
        }
    }    

    // Constant Member Function to display the total number of cars and cash collected
    void display() const {
        cout << "Total cars passed: " << numCars << endl; // display the total number of cars
        cout << "Total cash collected: $" << totalCash << endl; // display the total cash collected
    }
};

// Function to display the menu options
void displayMenu() {
    cout << "Choose the appropriate option: " << endl; // Prompt for user action
    cout << "Paying Car (Press +)" << endl; // Option to register a paying car
    cout << "Non-Paying Car (Press -)" << endl; // Option to register a non-paying car
    cout << "Escape (esc)" << endl; // Option to exit the program
    cout << endl; // Print a blank line for better readability
}

// Main function to run the program
int main() {
    tollBooth t1; // Create an instance of the tollBooth class
    while (true) { // Infinite loop to continuously display the menu and process input
        displayMenu(); // Display the menu options
        char command = _getch(); // Wait for a key press and store it in command
        
        if (command == 43) { // Check if the key pressed is '+' (ASCII 43)
            Car car(true); // Create a Car object indicating payment
            t1.processCar(car); // Process the car through the toll booth
            cout << "Toll paid successfully." << endl; // Confirm payment
            cout << endl; // Print a blank line for readability
        }
        else if (command == 45) { // Check if the key pressed is '-' (ASCII 45)
            Car car(false); // Create a Car object indicating no payment
            t1.processCar(car); // Process the car through the toll booth
            cout << "Toll unpaid." << endl; // Confirm no payment
            cout << endl; // Print a blank line for readability
        }
        else if (command == 27) { // Check if the key pressed is the Escape key (ASCII 27)
            t1.display(); // Display total cars and cash collected
            break; // Exit the loop
        }
        else { // If the input is not recognized
            cout << "Invalid input"; // Print an error message
        }
    }
    
    return 0;
}
