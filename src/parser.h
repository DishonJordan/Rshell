#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

class Parser {

public:
	Parser() {}

	vector<string> parse_input(string input) {

		//Defining the output vector
		vector<string> output; 

		//Delete everything after #
		size_t comment_index = input.find("#");
		if (comment_index != string::npos)
			input = input.substr(0, comment_index);

		input = seperateOperators(input);


		char inputArray[input.size() - 1];
		strcpy(inputArray, input.c_str());

		char* cptr = strtok(inputArray, " ");

		//Iterating through inputted string and adding each string seperated by a space to the input vector
		while (cptr != NULL) {

			string temp = cptr;

			output.push_back(temp);

			cptr = strtok(NULL, " ");

		}

		//Prints output for verification
	/*	for (int i = 0; i < output.size(); i++)
			cout <<"[" << output[i] << "]";
		cout << endl;
	*/	
		return output;
	

	}

	//Adds extra spaces before and after operators so that strtok creates a seperate string for them
	string seperateOperators(string s) {

		string temp;
		
		for (int i = 0; i < s.size(); i++) {

			if (s[i] == ';') {
				temp.append(" ; ");
			}
			else if (s[i] == ')') {
				temp.append(" ) ");
			}
			else if (s[i] == '(') {
				temp.append(" ( ");
			}
            else if (s[i] == '[') {//converts a [ to a test command
				temp.append(" test ");
                for (int j = 0; j < s.size(); j++) {  // Finds the ] and erases it from the string
                    if (s[j] == ']')
                        s.erase(j, 1);
                }
			}  
			else {
				temp += s[i];
			}
		
		}
        return temp;

	}
	   	 
};
