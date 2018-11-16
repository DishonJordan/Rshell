#pragma once
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Parser {

public:
	Parser() {}

	vector<string> parse_input(string input) {

		char inputArray[input.size() - 1]; 
		strcpy(inputArray, input.c_str());
		vector<string> output;

		char* cptr = strtok(inputArray, " ");

		//Look for # and delete everything after it
		int count = 0;
		for (char& c : input) {
			if (c == '#') {
				input.erase(input.at(count), input.size() - 1);
				break;
			}
			count++;
		}

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
			else if (!(strcmp(&temp.at(last_index), ";"))) { // Checking the special semicolon case at the end of the string

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

