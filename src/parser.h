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
                         
                 //Delete everything after #
                 size_t comment_index = input.find("#");
                 if(comment_index != string::npos)
                         input = input.substr(0,comment_index);
 
                 char inputArray[input.size() - 1]; 
                 strcpy(inputArray, input.c_str());
                 vector<string> output;
 
                 char* cptr = strtok(inputArray, " ");
                 
 
 
                 //Iterating through inputted string and adding each string to the input vector
                 while (cptr != NULL) {
 
                         string temp = cptr;
                         int last_index = temp.length() - 1;

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
