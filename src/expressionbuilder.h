#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "base.h"
#include "operator.h"
#include "command.h"
#include "semicolon.h"
#include "and.h"
#include "test_command.h"
#include "or.h"
#include <stack>  

using namespace std;

class ExpressionBuilder {
	stack<string> input;

public:
	ExpressionBuilder(vector<string> commands) {

		//Converts our input vector into a stack
		for (int i = 0; i < commands.size(); i++) {
			input.push(commands[i]);
		}
	}

	Base* build_tree() {

		Base* top = NULL; //Defines a pointer to the top of the tree

		if (!input.empty())
			add_children(input, top); //Recursively builds the rest of the tree based off of the input
		return top;

	}
private:
	void add_children(stack<string> s, Base*& top) {

		stack<string> temp; //Defining a temporary stack to maintain the strings of the command
		string current = s.top();

		//Adding strings to the temp stack until an operator is found.
		while (!isOperator(current) && current.compare(")") != 0 && current.compare("(") != 0) {

			temp.push(current);

			s.pop();

			if (s.empty()) { //Base Case where the main stack is empty

				//Definining a new command and populating it based off of the temp stack
				Command* last_command = CheckCommand(temp.top());
				populateCommand(last_command, temp);

				if (top == NULL) { //Case where there was no prior top, so we assign this new command to the top
					top = last_command;
				}
				else { //Case where there was a previous operator top, so we assign this new command to the left node of top
					((Operator*&)top)->setLeftNode(last_command);
				}

				return; //Finished the leaf

			}

			current = s.top(); //Assigning the next top value to current

		}

		if (isOperator(current)) { //Standard Operator Case
			Operator* op = CheckOperator(current);

			//Definining a new command and populating it based off of the temp stack
			Command* cmd = CheckCommand(temp.top());
			populateCommand(cmd, temp);

			//Setting the right node of the new operator to
			op->setRightNode(cmd);

			top = op; //Assigning top to our operator

			s.pop(); //Removing the operator from the stack

			if (!s.empty())
				add_children(s, op->l_node); //Builds the rest of the tree with the current main stack and left node of the operator as the new top
			else
				top = NULL;
		}
		else if (current.compare(")") == 0) { //Precedence Operator Case

			int num_nested = 0; //holds the number of nested precedence operators

			s.pop(); //get rid of the ")"
			stack<string> stack_inverter; //Definition of another stack because our temp stack is upside down

			if (!s.empty())
				current = s.top();
			else {
				cout << "ERROR: PRECEDENCE NOT CLOSED" << endl;
				return;
			}

			while ((current.compare("(") != 0) || num_nested != 0) {
				stack_inverter.push(current);

				//If there is a nested ")" we increment num_nested
				if ((current.compare(")") == 0))
					num_nested++;
				else if ((current.compare("(") == 0)) //If there is a nested "(" we decrement num_nested
					num_nested--;

				s.pop();
				if (s.empty()) { //Case where the main stack is empty but the precedence operator was not closed
					cout << "ERROR: PRECEDENCE NOT CLOSED" << endl;
					return; //Exit gracefully
				}
				current = s.top(); //Assigning the next top value to current

			}

			//Assigning all of the elements of stack_inverter to the temp stack
			while (!stack_inverter.empty()) {
				temp.push(stack_inverter.top());
				stack_inverter.pop();
			}

			s.pop(); //get rid of "("



			if ((top == NULL) && !s.empty()) {//Case where there was no previous top
				Operator* op = CheckOperator(s.top());
				s.pop();
				top = op;

				if (!temp.empty())
					add_children(temp, op->r_node);

				add_children(s, op->l_node);

			}
			else {
				if (!s.empty()) { //Case where there is a previous top but there are more commands after the parenthesis
					Operator* op = CheckOperator(s.top());
					s.pop();
					top = op;
					if (!temp.empty())
						add_children(temp, op->r_node); //Recursively build the right tree with the inner parenthesis

					add_children(s, op->l_node); //Recursively build the left tree with the remainder of the stack
				}
				else if (s.empty()) { //Case where the commands in the parenthesis are the last commands
					if (!temp.empty())
						add_children(temp, top); //Recursively build the last command in the parenthesis

				}

			}



		}
		else if (current.compare("(") == 0) {
			cout << "ERROR: PRECEDENCE NOT CLOSED" << endl;
			return;
		}


	}


	//Fills command's internal vector with the stack contents
	void populateCommand(Command* c, stack<string> s) {
		while (!s.empty()) {
			char* ch = new char[s.top().size() - 1];
			strcpy(ch, s.top().c_str());
			c->add(ch);
			s.pop();
		}

	}


	//Compares operator to a given string and returns an Operator* of that type
	Operator* CheckOperator(string s) {

		if (s.compare(";") == 0) {
			return new Semicolon();
		}
		else if (s.compare("&&") == 0) {
			return new And();
		}
		else if (s.compare("||") == 0) {
			return new Or();
		}
		else {
			cout << s << " Did not match any Operator. Returning default." << endl;
			return new Operator;
		}

	}

	Command* CheckCommand(string s) {

		if (s.compare("test") == 0) {
			return new TestCommand();

		}else {
			return new Command();
		}

}

	//Checks to see if a string is a standard operator and returns true or false;
	bool isOperator(string s) {

		if (s.compare(";") == 0 || s.compare("&&") == 0 || s.compare("||") == 0) {
			return true;
		}
		return false;

	}



};
