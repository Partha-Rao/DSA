/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void addCall(int customerID){
    if ((front==0 & rear==MAX-1)||(front==rear+1)){
        printf("Overflow condition. The queue is full. Please wait.\n");
        return;
    }
    if (front==-1){
        front=rear=0;
    } else if (rear==MAX-1){
        rear=0;
    } else {
        rear++;
    }
    queue[rear]=customerID;
    printf("Call added: %d\n", customerID);
}
void removeCall(){
    if (front==-1){
        printf("Underflow. No call is there to remove.\n");
        return;
    }
    int customerID=queue[front];
    if (front==rear){
        front=rear=-1;
    } else if (front==MAX-1){
        front=0;
    } else {
        front++;
    }
    printf("Removed customer: %d\n", customerID);
}
void display(){
    if (front==-1 && rear==-1){
        printf("Queue is empty, nothing to display.");
        return;
    }
    printf("Customers in queue: ");
    if (front<=rear){
        for (int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    } else {
        for (int i=front; i<MAX; i++){
            printf("%d ", queue[i]);
            
        }
        for (int i=0; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
    
    
}
int main(){
    addCall(101);
    addCall(102);
    addCall(103);
    addCall(104);
    addCall(105);
    display();
    addCall(106);
    removeCall(101);
    removeCall(102);
    display();
    addCall(106);
    addCall(107);
    display();
    
    
    
}