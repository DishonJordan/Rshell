#include <vector>
#include <string>
#include "parser.h"
#include "expressionbuilder.h"

using namespace std;


int main() {

	while (true) {
		string input;
		cout << "$ ";
		getline(cin, input);

		//quits program if quit is entered
		if (input.compare("exit") == 0)
			break;

		Parser* pat = new Parser();
		ExpressionBuilder* bob = new ExpressionBuilder(pat->parse_input(input));
		bob->build_tree()->execute();
	}

	return 0;
}
