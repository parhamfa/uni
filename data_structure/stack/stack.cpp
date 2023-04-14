#include <iostream>
using namespace std;

int* stack;  // pointer to integer used as stack
int stack_size;  // variable to store stack size
int top = -1;  // variable to store the index of top element, initialized to -1 since there are no elements yet

void push(int item) {  // function to push an item onto the stack
  
    if (top == stack_size) {  // if the stack is already full
        cout << "Stack is full...\n" <<endl;
    } else {
        top++;  // increment the top index
        stack[top] = item;  // add the item to the top of the stack
        cout << "Added " << item << " to stack[" << top << "]\n" <<endl;;
    }
}

void pop() {  // function to pop an item from the stack

    if (top == -1) {  // if the stack is already empty
        cout << "Stack is empty...\n" <<endl;
    } else {
        cout << "Deleted " << stack[top] << " from stack[" << top << "]\n" <<endl;  // print the element that is being deleted
        stack[top] = NULL;  // set the value at top index to NULL
        top--;  // decrement the top index
    }
}

void show() {  // function to display the stack

    if (top == -1) {  // if the stack is already empty
        cout << "Stack is empty...\n\n";
    } else {
        cout << "Stack (TOP = " << top << "):\n";  // print the current top index
        for (int i = top; i >= 0; i--) {  // iterate from the top element to the bottom element
            cout << i << " | ";  // print the index of the element
            if (stack[i] < 10) {  // if the element is less than 10, add an extra space for formatting purposes
                cout << " ";
            }
            cout << stack[i] << " |\n";  // print the value of the element
        }
        cout << "   ---\n\n";  // print the bottom of the stack
    }
}

void clearConsole() {  // function to clear the console

    for (int i = 0; i < 500; i++) {
        cout << endl;
    }
}

int main() {

    int user_choice;
    int user_input;

    cout << "Enter stack size to create: ";
    cin >> stack_size;
    stack = new int[stack_size];  // dynamically allocate memory for the stack

    while (true) {  // continue running the program until user chooses to exit

        cout << "1) Add item to stack" <<endl;
        cout << "2) Delete item from stack" <<endl;
        cout << "3) Display items of stack" <<endl;
        cout << "4) Exit program\n\n" <<endl;

        cout << "Enter your choice: ";
        cin >> user_choice;
        clearConsole();

        switch (user_choice) {

            case 1:
                cout << "Enter item to add to the stack: ";
                cin >> user_input;
                clearConsole();
                push(user_input);
                break;

            case 2:
                pop();
                break;

            case 3:
                show();
                break;

            case 4:
                return 0;
                break;
        
         
            default:
                cout << "Invalid input... try again." <<endl;;
                break;
        }
    }

    return 0;

}
