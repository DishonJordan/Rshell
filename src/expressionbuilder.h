#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "base.h"
#include "operator.h"
#include "command.h"
#include "semicolon.h"
#include "and.h"
#include "or.h"

using namespace std;

class ExpressionBuilder {
private:
	vector<string> input;
	vector<int> op_index;

public:
	ExpressionBuilder(vector<string> commands) { //Populates input and op_index

		input = commands;

		//iterates through command and adds the indices of the operators to op_index
		for (unsigned int i = 0; i < input.size(); i++) {

			if (input[i].compare(";") == 0 || input[i].compare("&&") == 0 || input[i].compare("||") == 0)
				op_index.push_back(i);

		}

	}

	//Builds a tree of operators and commands using a vector<string> input.
	Base* build_tree() {

		Operator* top = new Operator();
		
		if (input.size() == 0|| (op_index.size() == 1 && input.size() == 1)) {//Empty input case or just a single operator
			return top;

		}
		else if (op_index.size() == 0) { //No operator case

			Command* c = new Command();

			PopulateCommand(0, input.size(), c);

			return c;


		}else { // Initializing the top node
                 	
			top = CheckOperator(input[op_index[op_index.size() - 1]]);

			//Creating a new command to hold the last command
			Command* command = new Command();

			PopulateCommand(op_index[op_index.size() - 1] + 1, input.size(), command);

			//Assigning that command to the right node of top
			top->setRightNode(command);

			add_children(top, op_index.size() - 2, op_index.size() - 1);

		}
		return top;

	}

	//Recursive function that builds the rest of the expression tree until there are no more operators and commands
	void add_children(Operator* parent, int left_index, int right_index) {

		if (left_index <  0) { //Base case: The last command of the tree

			Command* first_command = new Command();

			PopulateCommand(0, op_index[0], first_command);

			parent->setLeftNode(first_command);

			return;
		}

		Operator* op = CheckOperator(input[op_index[left_index]]);

		Command* command = new Command();	 

		PopulateCommand(op_index[left_index] + 1, op_index[right_index], command);

		//Assigning that command to the right node of op
		op->setRightNode(command);

		//Assigning the left node of the parent Operator to op
		parent->setLeftNode(op);

		//Recurse with the left node 
		add_children(op, left_index - 1, right_index - 1);

	}

	//Checks which operator the given string is and returns the new object
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
			cout << "Did not match any Operator. Returning default." << endl;
			return new Operator;
		}

	}

	//Populates command's internal vector with the strings in the input between the given indicies, converts that string into a char*
	void PopulateCommand(int initial_index, int final_index, Command* c) {

			for (int i = initial_index; i < final_index; i++) {

				c->add(const_cast<char*>(input[i].c_str()));
			}

		}



	

};
