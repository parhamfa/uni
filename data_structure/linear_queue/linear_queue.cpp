// This program demonstrates the implementation of a queue using an array.

#include <iostream>
using namespace std;

// Declare global variables
int* queue; // pointer to integer array
int queue_size; // size of the queue
int front = -1, rear = -1; // front and rear pointers initialized to -1

// Function to add an element to the rear of the queue
void enqueue(int item) {
    // If the rear pointer has reached the end of the array, the queue is full
    if (rear == (queue_size-1)) {
        cout << "Queue is full...\n" <<endl;
    } else {
        rear++; // Move the rear pointer to the next available position
        queue[rear] = item; // Insert the new item at the rear of the queue
        cout << "Added " << item << " to queue[" << rear << "]\n" <<endl;;
    }
}

// Function to remove an element from the front of the queue
void dequeue() {
    // If the front and rear pointers are the same, the queue is empty
    if (front == rear) {
        cout << "Queue is empty...\n" <<endl;
    } else {
        front++; // Move the front pointer to the next element
        cout << "Deleted " << queue[front] << " from queue[" << front << "]\n" <<endl;;
        queue[front] = NULL; // Set the element to NULL (optional)
    }
}

// Function to display the contents of the queue
void show() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty...\n" <<endl;;
    } else {
        // Print the front and rear pointers
        cout << endl << " FRONT: " << front << "\t\tREAR: " << rear << endl << endl;
        // Print the contents of the queue
        for (int i = front+1; i <= rear; i++) {
            if (to_string(queue[i]).length() == 1) {
                cout << "+-----+\t";
            } else if (to_string(i).length() == 2) {
                cout << "+------+\t";
            } else {
                cout << "+-------+\t";
            }
        }
        cout << endl;
        for (int i = front+1; i <= rear; i++) {
            cout << "|  " << queue[i] << "  |\t";
        }
        cout << endl;
        for (int i = front+1; i <= rear; i++) {
            if (to_string(queue[i]).length() == 1) {
                cout << "+-----+\t";
            } else if (to_string(i).length() == 2) {
                cout << "+------+\t";
            } else {
                cout << "+-------+\t";
            }
        }
        cout << endl;
        for (int i = front+1; i <= rear; i++) {
            if (to_string(queue[i]).length() == 1) {
                cout << "   " << i << "   \t";
            } else if (to_string(i).length() == 2) {
                cout << "    " << i << "    \t";
            } else {
                cout << "     " << i << "     \t";
            }
        }
        cout << endl << endl;
    }
}

// Function to clear the console (not used in the current code)
void clearConsole() {
    for (int i = 0; i < 500; i++) {
        cout << endl;
    }
}


int main() {
    
    // Declare variables
    int user_choice; // User's choice of action
    int user_input; // User's input for adding to queue

    // Prompt user to enter queue size and allocate memory for queue
    cout << "Enter queue size to create: ";
    cin >> queue_size; // User inputs queue size
    queue = new int[queue_size]; // Memory is allocated for the queue

    // Start a loop to prompt user for actions until the user decides to exit the program
    while (true) {
    
        // Display menu options to user
        cout << "1) Add item to queue" <<endl;
        cout << "2) Delete item from queue" <<endl;
        cout << "3) Display items of queue" <<endl;
        cout << "4) Exit program\n\n" <<endl;
    
        // Prompt user for choice of action
        cout << "Enter your choice: ";
        cin >> user_choice;
        clearConsole(); // Clear console for readability
    
        // Switch statement to determine which function to call based on user's choice
        switch (user_choice) {
            
            case 1:
                // Prompt user to enter an item to add to the queue
                cout << "Enter item to add to the queue: ";
                cin >> user_input;
                clearConsole(); // Clear console for readability
                enqueue(user_input); // Call function to add user's input to the queue
                break;
            
            case 2:
                dequeue(); // Call function to remove the first item in the queue
                break;
            
            case 3:
                show(); // Call function to display the items in the queue
                break;
            
            case 4:
                return 0; // Exit the program
                break;
        
            default:
                cout << "Invalid input... try again." <<endl;;
                break;
        }
    }
        return 0;
}
