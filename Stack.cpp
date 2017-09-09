#include "stdafx.h"
#include "stdio.h" 
#include "stdlib.h" 
#include <iostream>	


using namespace std;

typedef struct node{
	int item;
	struct node *next;
} Node;

typedef struct stack{
	Node *top;	
	int size;					// переменная размера стака
} Stack;

void initial(Stack *s) {
	s->size = 0;					// задать значение size равное нулю 
	s->top = NULL;					// top стака указывает теперь на NULL 
}

void push(Stack *s, int value) {			// Push функция для сохраниения данных в top стака 
	Node *node_point;				// node теперь указатель 

	node_point = (Node *)malloc(sizeof(Node));	//выделяем место для node 
	if (node_point == NULL) {
							// программа будет завершена, если не будет выделена память под node 
		exit(1);
	}

	node_point->item = value;			// значение value, которое мы хотим сохранить в node 
	node_point->next = s->top;			// копируем последний top стака
		
	s->top = node_point;				// теперь top ссылаеться на новый top стака 																	
	s->size++;					// прибавляем к счетчику размера стака 
}

int pop(Stack *s) {
	int temp;
	Node *np;

	if (!s->top) {					// программа будет завершена, если стак пустой
		exit(1);
	}

	np = s->top;
	temp = np->item;
	s->top = np->next;
	s->size--;
	free(np);

	return temp;
}

int main() {

	int pop_variable;				// объявление переменной для pop
	Stack stk;					// обозначаем объект стака
	initial(&stk);					// инииализируем структуру данных равное 0
	
	push(&stk, 5);					// записываем(push) значение 5 в стак 
	push(&stk, -1);					// записываем(push) значение 8 в стак 
	push(&stk, 4);
		
							// Теперь стак содержит 8, 5 и NULL соответственно.  
	
	pop_variable = pop(&stk);			// считываем значение стака равное 4 и меняем top стака(pop). Теперь стак содержит 8, 5 и NULL.
	cout << pop_variable << endl;
	pop_variable = pop(&stk);			// считываем значение стака равное 8 и меняем top стака(pop). Теперь стак содержит 5 и NULL.
	cout << pop_variable << endl;
	pop_variable = pop(&stk);			// считываем значение стака равное 5 и меняем top стака(pop). Теперь стак содержит NULL.
	cout << pop_variable << endl;
	
	_gettch();
	return 0;
}
