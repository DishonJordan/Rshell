#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Base.h"
#include "Operator.h"
#include "Command.h"

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


		if (input.size() == 0) {//Empty input case
			return top;

		}
		else if (op_index.size() == 0) { //No operator case

			Command* c = new Command();

			//Assigning all strings in input to the new command and returning it
			for (unsigned int i = 0; i < input.size(); i++)
				c->add(const_cast<char*>(input[i].c_str()));

			return c;


		}
		else {
			//Changing top into a Semicolon/And/Or based off of which one it is
			if (input[op_index[op_index.size() - 1]].compare(";"))
				top = new Operator(); //Change to Semicolon
			if (input[op_index[op_index.size() - 1]].compare("&&"))
				top = new Operator(); //Change to AND
			if (input[op_index[op_index.size() - 1]].compare("||"))
				top = new Operator(); //Change to OR

			//Creating a new command to hold the last command
			Command* command = new Command();

			//Assigning all strings in input to the new command
			for (int i = op_index[op_index.size() - 1] + 1; i < input.size(); i++)
				command->add(const_cast<char*>(input[i].c_str()));

			//Assigning that command to the right node of top
			top->r_node = command;

			//Calling a recurs ive helper function to finish the rest of the tree
			add_children(top, op_index.size() - 2, op_index.size() - 1);

		}
		return top;

	}

	void add_children(Operator* parent, int left_index, int right_index) {


		if (left_index < 0) { //Base case: The last command of the tree

			Command* first_command = new Command();
			for (int i = 0; i < op_index[right_index]; i++)
				first_command->add(const_cast<char*>(input[i].c_str()));

			parent->l_node = first_command;

			return;
		}
		Operator* op = new Operator();

		//Changing op into a Semicolon/And/Or based off of which one it is
		if (input[op_index[right_index]].compare(";"))
			op = new Operator(); //Change to Semicolon
		if (input[op_index[right_index]].compare("&&"))
			op = new Operator(); //Change to AND
		if (input[op_index[right_index]].compare("||"))
			op = new Operator(); //Change to OR

		Command* command = new Command();

		//Assigning all strings in input to the new command
		for (int i = op_index[left_index] + 1; i < op_index[right_index]; i++)
			command->add(const_cast<char*>(input[i].c_str()));

		//Assigning that command to the right node of op
		op->r_node = command;

		//Assigning the left node of the parent Operator to op
		parent->l_node = op;

		//Recurse with the left node 
		add_children(op, left_index - 1, right_index - 1);

	}

};