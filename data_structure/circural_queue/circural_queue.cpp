//This code implements a circular queue data structure using an array

#include <iostream>
using namespace std;

int* queue; // Pointer to the start of the queue
int queue_size; // Maximum size of the queue
int front = 0, rear = 0; // Indexes of the front and rear elements of the queue

void enqueue(int item) {
    // Adds an item to the rear of the queue

    if (front == ((rear + 1) % queue_size)) {
        // If the queue is full, print an error message
        cout << "Queue is full...\n" <<endl;
    } else {
        // Otherwise, add the item to the rear of the queue
        rear = ((rear + 1) % queue_size);
        queue[rear] = item;
        cout << "Added " << item << " to queue[" << rear << "]\n" <<endl;;
    }
}

void dequeue() {
    // Removes the front item from the queue

    if (front == rear) {
        // If the queue is empty, print an error message
        cout << "Queue is empty...\n" <<endl;
    } else {
        // Otherwise, remove the front item from the queue
        front = ((front + 1) % queue_size);
        cout << "Deleted " << queue[front] << " from queue[" << front << "]\n" <<endl;;
        queue[front] = NULL;
    }
}

void show() {
    // Displays the contents of the queue

    if (front == 0 && rear == 0) {
        // If the queue is empty, print an error message
        cout << "Queue is empty...\n" <<endl;;
    } else {
        // Otherwise, print the front and rear indexes of the queue
        cout << endl << " FRONT: " << front << "\t\tREAR: " << rear << endl << endl;

        // Print the queue as a series of boxes, with the item in each box
        for (int i = 0; i < queue_size; i++) {
            cout << "+-----+\t";
        }
        cout << endl;
        for (int i = 0; i < queue_size; i++) {
            cout << "|  " << queue[i] << "  |\t";
        }
        cout << endl;
        for (int i = 0; i < queue_size; i++) {
            cout << "+-----+\t";
        }
        cout << endl;
        for (int i = 0; i < queue_size; i++) {
            cout << "   " << i << "   \t";
        }
        cout << endl << endl;
    }
}

void clearConsole() {
    // Clears the console by printing many blank lines

    for (int i = 0; i < 500; i++) {
        cout << endl;
    }
}

// This function takes user inputs and controls the flow of the program
int main() {
    

    // Declare and initialize variables
    int user_choice;
    int user_input;

    // Ask the user to enter queue size and create queue of that size
    cout << "Enter queue size to create: ";
    cin >> queue_size;
    queue = new int[queue_size];

    // Loop indefinitely until user chooses to exit the program
    while (true) {

        // Display menu options to the user
        cout << "1) Add item to queue" <<endl;
        cout << "2) Delete item from queue" <<endl;
        cout << "3) Display items of queue" <<endl;
        cout << "4) Exit program\n\n" <<endl;

        // Get user input for choice and clear console
        cout << "Enter your choice: ";
        cin >> user_choice;
        clearConsole();

        // Use switch case to perform appropriate operation based on user input
        switch (user_choice) {
            
            // If user chooses to add item, get input and call enqueue function
            case 1:
                cout << "Enter item to add to the queue: ";
                cin >> user_input;
                clearConsole();
                enqueue(user_input);
                break;
            
            // If user chooses to delete item, call dequeue function
            case 2:
                dequeue();
                break;
            
            // If user chooses to display items, call show function
            case 3:
                show();
                break;
            
            // If user chooses to exit program, return 0 to exit main function
            case 4:
                return 0;
                break;
        
            // If user input is invalid, inform the user
            default:
                cout << "Invalid input... try again." <<endl;;
                break;
        }
    }
    // Return 0 to indicate successful execution of main function
    return 0;

}
