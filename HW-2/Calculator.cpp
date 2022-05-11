#include "Calculator.h"
#include<string>
#include<iostream>

using namespace std;

Calculator::Calculator(string infixExp) {
	this->infixExpression = infixExp;
	this->postfixExpression = "";

	stack = new Stack();
	string value;
	istringstream iss(infixExpression);

	while (iss >> value && value.compare(";") != 0) {

		StackItem* item = new StackItem(value);

		if (!item->isOperator) {
			postfixExpression += item->toString() + " "; //if item is an operand, output immedaitely
		}
		else {
			if (item->op == OPERATOR_LEFTPAR) { //if the item is a left parenthesis, push onto the stack
				stack->push(item);
			}
			else if (item->op == OPERATOR_RIGHTPAR) //if the item is a right parenthesis

			{
				while (!stack->isEmpty() && stack->top()->op != OPERATOR_LEFTPAR) { //pop the stack and output the contents until a left parenthesis
					postfixExpression += stack->top()->toString() + " ";
					delete stack->pop();
				}
				delete stack->pop(); // (parenthesis is popped but not output)
			}
			else //if the item is an operator,
			{
				while (!stack->isEmpty() && stack->top()->op >= item->op) //pop and output all the operators with higher or equal precendence, then push the item onto the stack
				{
					postfixExpression += stack->top()->toString() + " ";
					delete stack->pop();
				}
				if (stack->isEmpty() || (stack->top()->op < item->op) ||  stack->top()->op == OPERATOR_LEFTPAR ) //if the stack is empty or the top element is a left parenthesis or if the top element has a lower precendence
				{
					stack->push(item); //push the item onto the stack
				}

			}

		}
	}
	while (!stack->isEmpty())
	{
		postfixExpression += stack->top()->toString() + " ";
		delete stack->pop();
	}
	postfixExpression += ";";
}

string Calculator::getPostfix() {
	return postfixExpression; // returns the postfix representation of the arithmetic expression
}

int Calculator::calculate(){
	string Result; //Store current result of operations + - * /
	string Answer; //final answer after loop
	string num1;   //number popped out of stack
	string num2;   //number popped out of stack

	stack = new Stack();
	string value;
	istringstream iss(getPostfix());

	while (iss >> value && value.compare(";") != 0) {
		StackItem* item = new StackItem(value);

		if (!item->isOperator) { //if number is encountered push onto stack
			stack->push(item); 
		}
		else					 // if operator is encountered pop two numbers, apply the operator and push the result back to stack
		{
			num1 = stack->top()->toString();
			delete stack->pop();
			num2 = stack->top()->toString();
			delete stack->pop();
			
			if (item->op == OPERATOR_PLUS) {
				Result = to_string(stoi(num2) + stoi(num1));
				StackItem* a = new StackItem(Result);
				stack->push(a);
				delete a;
			}
			else if (item->op == OPERATOR_MINUS) {
				Result = to_string(stoi(num2) - stoi(num1));
				StackItem* a = new StackItem(Result);
				stack->push(a);
				delete a;
			}
			else if (item->op == OPERATOR_DIVISION) {
				Result = to_string(stoi(num2) / stoi(num1));
				StackItem* a = new StackItem(Result);
				stack->push(a);
				delete a;
			}
			else if (item->op == OPERATOR_MULTIPLICATION) {
				Result = to_string(stoi(num2) * stoi(num1));
				StackItem* a = new StackItem(Result);
				stack->push(a);
				delete a;
			}

		}
	}
	Answer = stack->top()->toString();
	return stoi(Answer);
}
/*The calculate method makes use of stack to evaluate the postfix expression and return
the result.*/

Calculator::~Calculator() {
	delete stack;
}
/*All the memory that is allocated within the methods should be freed before their return.
Also, the destructor of the Calculator class should free all the memory (e.g., stack object)
that is allocated within its constructor.*/
