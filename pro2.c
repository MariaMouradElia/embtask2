#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>

#define bool int;

typedef struct stackNode{ char value;
                          struct stackNode* nextptr;
} ST_stack_n_t;

ST_stack_n_t* head = NULL;

bool expression_check(char* exp);
bool check_parentheses(char x, char y);
void push(ST_stack_n_t* pointer, char data);
char pop(ST_stack_n_t* pointer);

int main() {
	char expression[100];
	printf("please enter your equation:\n");
	gets(expression);
	if (expression_check(expression) == 0)
		printf("\nyour equation is not balanced !");
	else
		printf("\nyour equation is balanced :)");
	return 0;
}

bool expression_check(char* exp) {
	int i = 0;
	while (exp[i]) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {   //if the loop contains an opened bracket, push it into the stack (implemented by the linked list))
			push(head, exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') { //if the loop contains a closed bracket,and if the array is empty,the equation is unbalenced
			if (head == NULL)
				return 0;
			else if (check_parentheses(pop(head), exp[i]) == 0)     // else, compare the current closed bracket in the array and see if it matches the last opened bracket in the linked list
				return 0;

		}
		i++;

	}
	return 1;
}

//this function compare the current closed bracket in the array and see if it matches the last opened bracket, pushed in the linked list
bool check_parentheses(char x, char y){
	if (x == '(' && y == ')')
		return 1;
	else if (x == '[' && y == ']')
		return 1;
	else if (x == '{' && y == '}')
		return 1;
	return 0;
}

// function to allocate a memory for a new node then push a character in it
void push(ST_stack_n_t* pointer, char data) {
	ST_stack_n_t* node= (ST_stack_n_t*)malloc(sizeof(ST_stack_n_t));
	if (node == NULL) {
		printf("Stack overflow!\n");
		exit(1);
	}
	node->value = data;
	node->nextptr = head;
	head = node;
}

// function that moves head pointer to next node then free the first node (delete it)
char pop(ST_stack_n_t* pointer){
	char bracket;
	if (head == NULL) {                // to check first if the stack has any element to pop
		printf("Stack is empty!\n");
		exit(1);
	}
	
	ST_stack_n_t* temp = NULL;
	temp = head;
	bracket = temp->value;            // pop last element
	head = temp->nextptr;
	free(temp);
	return bracket;
}

