#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_BLOCK_SIZE 10  //to define stack_block_size macro value.

typedef struct stack{
    int *array;
    int currentsize;
    int maxsize;

}stack;


stack * init_return(){ //to create init_return function.
/*
* This function creates an empty stack and it returns this struct.
*
* Returns a stack.
*/
    struct stack * stack = (struct stack *)malloc(sizeof(struct stack)); //to create a stack and give allocate memory.
    stack -> maxsize = STACK_BLOCK_SIZE;                                
    stack -> currentsize = -1;
    stack -> array = (int*) malloc(stack -> maxsize * sizeof(int));
    return stack;            //to return created stack.
}

int init(stack * s){ //to create init function.
/*
* This function checks stack initialization is succesfull or failed.
*
* Returns 1 if initialization is succesful else it returns 0.
*/
    if(s->maxsize !=0){  //to check maxsize is equal to 0 or not.
        return 1;        //to return 1 when initialization is succesfull.
    }
    else{
        return 0; //to return 0 when initialization is not succesfull.
    }
}

void push(stack *stack, int d) //to create push function.
{
/*
* This function takes a stack and integer as a parameter and it stored given integer to given stack.
* Also it checks the stack is full or not if it is full then it allocate more memory for the stack.
*
* In here given stack is a peg and given integer is a disk number.
*
* Returns nothing because function type is void.
*/
    if (stack->currentsize == stack->maxsize - 1){ //to check stack is full or not.
      stack -> maxsize = stack -> maxsize + STACK_BLOCK_SIZE;
      stack -> array = (int*)realloc(stack -> array, stack -> maxsize * sizeof(int)); //to allocate memory for the stack.
    }     
    stack -> array[++stack -> currentsize] = d; //to store given integer to given stack.
}
int pop(stack* stack){ //to create pop function.
/*
* This function takes a stack and it checks is it empty or not then if it is not empty then it removes last element of stack.
*
* Returns 0 if given stack is empty.
*/
    if (stack->currentsize == -1) //to check given stack is empty or not.
        return 0;
    return stack -> array[stack -> currentsize--]; //to remove last element of stack.
}

void print_movements_of_disks(char fromPeg, char toPeg, int disk) //to create print_movements_of_disks function.
{
/*
* This function prints movements of disks from one peg to other peg.
*
* Returns nothing because function type is void.
*/
    printf("Move the disk %d from \'%c\' to \'%c\'\n",disk, fromPeg, toPeg); //to print movements of disks.
}
void move_disk(stack *original,stack *destination, char s, char d)//to create move_disk function.
{
/*
* This function takes original and destination pegs and disk and it moves disks one peg to other peg
*  with calling pop and push funtion.
* also it calls print_movements_of_disks function to printing movements.
*
* Returns nothing because function type is void.
*/
    int peg1 = pop(original);
    int peg2 = pop(destination);
 
    if (peg1 == 0) //to checking peg1 is empty or not.
    {
        push(original, peg2); //to call push function for move disk from orginal to peg2.
        print_movements_of_disks(d, s, peg2); //to printing movement of disk.
    }
 
    
    else if (peg2 == 0) //to checking peg2 is empty or not.
    {
        push(destination, peg1); //to call push function for move disk from destination to peg1.
        print_movements_of_disks(s, d, peg1); //to printing movement of disk.
    }
 
    
    else if (peg1 > peg2) //to checking top disk of peg1 is greater than top disk of peg2 or not.
    {
        push(original, peg1);//to call push function for move disk from original to peg1.
        push(original,peg2); //to call push function for move disk from original to peg2.
        print_movements_of_disks(d, s,peg2);//to printing movement of disk.
    }
 
    
    else //to other condition.
    {
        push(destination,peg2);//to call push function for move disk from destination to peg2.
        push(destination,peg1);//to call push function for move disk from destination to peg1.
        print_movements_of_disks(s, d, peg1); //to printing movement of disk.
    }
}

void iterative_tower_of_hanoi(int tower_size, stack *original, stack *temporary, stack *destination)//to create iterative_tower_of_hanoi function.
{
/*
* This function takes three stack for pegs and size of tower 
*  and it calls move_disk function to move disks between three pegs in different conditions.
* It does iterations of tower of hanoi with using move_disk function.
*
* Returns nothing because function type is void.
*/
    int i, total_number_of_moves;  //to define integers.
    char s = '1', d = '3', a = '2'; //to define characters for peg numbers.
 
    if (tower_size % 2 == 0)
    {
        char temp = d;                             
        d = a;                                    
        a = temp;
    }
    total_number_of_moves = pow(2, tower_size) - 1; //to calculate total number of moves.
 
    for (i = tower_size; i >= 1; i--) //to push larger disk firstly.
        push(original, i); //to call push function for push a disk.
 
    for (i = 1; i <= total_number_of_moves; i++) //to create a loop with size of number of moves for movements of disks.
    {
        if (i % 3 == 1)
        move_disk(original, destination, s, d); //to call move_disk function for first condition.
 
        else if (i % 3 == 2)
        move_disk(original, temporary, s, a); //to call move_disk function for second condition.
 
        else if (i % 3 == 0)
        move_disk(temporary, destination, a, d); //to call move_disk function for third condition.
    }
}

 int main() //to create main function
{
   
    int tower_size; //to define an integer for size of tower.

    printf("\nEnter Tower Size : ");
    scanf("%d",&tower_size);          //to get user input for size of tower.
    printf("\n");
 
    stack *original, *destination, *temporary; //to create three stacks.
 
    original = init_return(); //to initialize an empty stack for original stack.
    temporary = init_return(); //to initialize an empty stack for temporary stack.
    destination = init_return(); //to initialize an empty stack for destination stack.
 
    iterative_tower_of_hanoi(tower_size, original, temporary, destination); //to call iterative_tower_of_hanoi function for solve the puzzle.
    return 0;
} //end of the code.
