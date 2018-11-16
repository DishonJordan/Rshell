#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

class Parser {

public:
	Parser() {}

	vector<string> parse_input(string input) {

		//Look for # and delete everything after it
		//This code block fixes the bug of seg fault when a operator is followed by a #
		for (std::string::size_type i = 0; i < input.size(); i++) {
			if (input.at(i) == '#') {
				input = input.substr(0, i - 1);
				break;
			}
		}

		//This code block fixes the seg fault special case bug of trailing operator with no right-hand command
		if (input.at(input.size()-1) == ';')
			input = input.substr(0, input.size() - 1);
		if (input.at(input.size()-1) == '&' || input.at(input.size()-1) == '|')
			input = input.substr(0, input.size() - 2);

		char inputArray[input.size() - 1];
		strcpy(inputArray, input.c_str());
		vector<string> output;

		char* cptr = strtok(inputArray, " ");

		//Iterating through inputted string and adding each string to the input vector
		while (cptr != NULL) {

			string temp = cptr;
			int last_index = temp.length() - 1;
			size_t comment_index = temp.find("#");

			if (comment_index != string::npos) { //Checking for any comments. meaning a # was found

				//Making sure we dont add an empty string to the vector
				if (comment_index > 0)
					output.push_back(temp.substr(0, comment_index));

				//Everything after the comment is not included, so we break from our parse
				break;

			}
			if (!(strcmp(&temp.at(last_index), ";"))) { // Checking the special semicolon case at the end of the string

				//Making sure we dont add an empty string to the vector
				if (last_index > 0)
					output.push_back(temp.substr(0, last_index));

				output.push_back(";");

			}
			else {

				output.push_back(temp);
			}

			cptr = strtok(NULL, " ");

		}
		
		return output;

	}





};

