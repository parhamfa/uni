#include <iostream>
using namespace std;

int* queue;
int queue_size;
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == (queue_size-1)) {
        cout << "Queue is full...\n" <<endl;
    } else {
        rear++;
        queue[rear] = item;
        cout << "Added " << item << " to queue[" << rear << "]\n" <<endl;;
    }
}

void dequeue() {
    if (front == rear) {
        cout << "Queue is empty...\n" <<endl;
    } else {
        front++;
        cout << "Deleted " << queue[front] << " from queue[" << front << "]\n" <<endl;;
        queue[front] = NULL;
    }
}

void show() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty...\n" <<endl;;
    } else {
        cout << endl << " FRONT: " << front << "\t\tREAR: " << rear << endl << endl;
        for (int i = front+1; i <= rear; i++) {
            cout << "+-----+\t";
        }
        cout << endl;
        for (int i = front+1; i <= rear; i++) {
            cout << "|  " << queue[i] << "  |\t";
        }
        cout << endl;
        for (int i = front+1; i <= rear; i++) {
            cout << "+-----+\t";
        }
        cout << endl;
        for (int i = front+1; i <= rear; i++) {
            cout << "   " << i << "   \t";
        }
        cout << endl << endl;
    }
}

void clearConsole() {
    for (int i = 0; i < 500; i++) {
        cout << endl;
    }
}

int main() {
    
    int user_choice;
    int user_input;
    
    cout << "Enter queue size to create: ";
    cin >> queue_size;
    queue = new int[queue_size];
    
    while (true) {
        
        cout << "1) Add item to queue" <<endl;
        cout << "2) Delete item from queue" <<endl;
        cout << "3) Display items of queue" <<endl;
        cout << "4) Exit program\n\n" <<endl;
        
        cout << "Enter your choice: ";
        cin >> user_choice;
        clearConsole();
        
        switch (user_choice) {
                
            case 1:
                cout << "Enter item to add to the queue: ";
                cin >> user_input;
                clearConsole();
                enqueue(user_input);
                break;
                
            case 2:
                dequeue();
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
