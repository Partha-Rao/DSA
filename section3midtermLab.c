#include <stdio.h>
#define MAX 50

int undostack[MAX];
int redostack[MAX];
int topundo=-1;
int topredo=-1;

void push(int op){
    if (topundo>=MAX-1){
        printf("Overflow. The stack is full.");
        return;
    } else {
        undostack[++topundo]=op;
        topredo=-1;
        printf("Performed operation: %d\n", op);
    }
}
void undo() {
    if (topundo < 0) {
        printf("Nothing to undo.\n");
        return;
    } else {
        int op = undostack[topundo--];    
        redostack[++topredo] = op;         
        printf("Undone. Next operation that can be redone is= %d\n", op);
    } 
}
void redo() {
    if (topredo < 0) {
        printf("Nothing to redo.\n");
        return;
    } else {
        int op = redostack[topredo--];    
        undostack[++topundo] = op;         
        printf("Redo complete. Operation redone= %d\n", op);
    }
   
}
int main(){
    push(101);
    push(102);
    push(103);
    undo();
    undo();
    redo();

    push(104);
    undo();

}


   
