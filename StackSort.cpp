#include <iostream>
using namespace std;

struct stack {
	int info;                           //create dynamic memory for stack 1
	stack* next;
};

struct stack2 {
    int info;                           //create dynamic memory for stack 2
    stack2* next;
};

stack* top = NULL;                      //initialize stack 1 and 2 top
stack2* top2 = NULL;

void push(int item) {   
	stack* newnode = new stack;           // function for pushing into the original stack
	newnode->info = item;
	newnode->next = top;
	top = newnode;
}

void push2(int item) {
    stack2* newnode = new stack2;         // function for pushing into the temporary stack
    newnode->info = item;
    newnode->next = top2;
    top2 = newnode;
}

int pop() {
    
    int temp = top->info;               // function for poping from the original stack
    top = top->next;
    return temp;
}

int pop2() {

    int temp = top2->info;              // function for poping from the temporary stack
    top2 = top2->next;
    return temp;
}

bool isEmpty1() {
    if (top == NULL)
        return true;                    // check if the original stack is empty or not
    return false;
}

bool isEmpty2() {
    if (top2 == NULL)
        return true;                   // check if the temporary stack is empty or not
    return false;
}

void traverse() {
    for (stack* curr = top; curr != NULL; curr = curr->next) {
        cout << curr->info<<" ";                                    //print the original stack
    }
}

int peak() {
    return top2->info;                                             // see the value of the top element in temporary stack
}


void sortAccending() {
    int temp;
    while (!isEmpty1()) {                              // continue looping until the original stack is empty.
        temp = pop();                                 // get the top element of the original stack and store it in temp.
        while (!isEmpty2() && peak() > temp) {       // continue looping if the temporary stack is not empty 
                                                    // and the top element of the temporary stack (peak) is greater than temp

            push(pop2());                          // if it's greater than the temp push the top element into the original stack
        }
        push2(temp);                              // after the temporary stack bacome empty or the temp is greater than peak, 
                                                 // push the temp into temporary stack
    }
    for (stack2* curr = top2; curr != NULL; curr = curr->next) {
        push(pop2());                                // copy the sorted stack from temporary stack into the original stack
    }                                               // thus become in accending ordered
}


void sortDccending() {
    int temp;
    while (!isEmpty1()) {
        temp = pop();
        while (!isEmpty2() && peak() < temp) {  

            push(pop2());           // same as accending but compare if the temp is less than top element of temporary stack
        }
        push2(temp);
    }
    for (stack2* curr = top2; curr != NULL; curr = curr->next) {
        push(pop2());                    // copy the sorted stack from temporary stack into the original stack
    }                                   // thus become in decinding ordered
}
int main()
{
    int c;
    int item;
    
    while (1) {
        cout << "\nSelect\n1 To Push\n"
            << "2 To Traverse\n"
            << "3 To Sort the stack in accending order\n"
            << "4 To Sort the stack in decending order\n"
            << "\n\nYour Choice  -- > ";
        cin >> c;
        switch (c) {
        case 1: cout << "Enter an elements: "; cin >> item; push(item); break;
        case 2: cout << "The elements of the stack are: "; traverse(); break;
        case 3: cout << "***The stack has been sorted in Accending order*** \n"; sortAccending(); break;
        case 4: cout << "***The stack has been sorted in Decending order*** \n"; sortDccending(); break;
                   
        }
    }
    return 0;
}