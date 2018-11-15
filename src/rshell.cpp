#include <vector>
#include <string>
#include "parser.h"
#include "expressionbuilder.h"
#include <stdio.h>

using namespace std;

int main() {
	string input;
	char user[20];//Defining a char array to hold client username
	char host[20];//Defining a char array to gold hostname
	
	getlogin_r(user,20); //Assigning username
	if(user == NULL) //Checking for any errors
	  perror("Could not retrieve username");
	  
	gethostname(host,20);//Assigning hostname
	if(host == NULL) //Checking for any errors
	  perror("Could not retrieve hostname");

	while (true) { //Inginite while loop for the main shell procedures
		

		cout <<"[" << user << "@" << host <<"]$ ";
		getline(cin, input);
		
		//quits program if quit is entered
		if (strcmp(input.data(),"exit") == 0)
			return 0;

		//Creating a parser to parse the user input
		Parser* pat = new Parser();
		//Creating an ExpressionBuilder to take in the parsed input
		ExpressionBuilder* bob = new ExpressionBuilder(pat->parse_input(input));
		//Building the command tree and executing it.
		bob->build_tree()->execute();
	}

	return 0;
}
