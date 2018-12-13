#include "../src/base.h"
#include "../src/command.h"
#include "../src/expressionbuilder.h"
#include "../src/operator.h"
#include "../src/parser.h"
#include "../src/and.h"
#include "../src/or.h"
#include "../src/semicolon.h"
#include "../src/oredirect.h"
#include "../src/iredirect.h"
#include "../src/doubleoredirect.h"
#include "../src/pipe.h"

#include <vector>
#include <string>
#include <fstream>

#include "gtest/gtest.h"

void executeRedirect(string i){
	 
	 Parser* pat = new Parser();
	 ExpressionBuilder* bob = new ExpressionBuilder (pat->parse_input(i));
	 Base* b = bob->build_tree();
	 if(b!= NULL)
	   b->execute();

}

void printFileContents(string s){
    ifstream f(s);

    if (f.is_open())
        std::cout << f.rdbuf();
}

TEST(RedirectTest, Test1) {
	
	testing::internal::CaptureStdout();
	executeRedirect(">");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
}
TEST(RedirectTest, Test2) {
	
	testing::internal::CaptureStdout();
	executeRedirect("<");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
}

TEST(RedirectTest, Test3) {
	
	testing::internal::CaptureStdout();
	executeRedirect(">>");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
}

TEST(RedirectTest, Test4) {
	
	executeRedirect("echo hello > output.txt");

	testing::internal::CaptureStdout();
	printFileContents("output.txt");
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("hello\n", output);
}
TEST(RedirectTest, Test5) {
	
	executeRedirect("echo hello world > output.txt");

	testing::internal::CaptureStdout();
	printFileContents("output.txt");
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("hello world\n", output);
}
TEST(RedirectTest, Test6) {
	
	executeRedirect("echo hello >> output.txt ");

	testing::internal::CaptureStdout();
	printFileContents("output.txt");
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("hello world\nhello\n", output);
}
TEST(RedirectTest, Test7) {

	testing::internal::CaptureStdout();
	executeRedirect("cat < output.txt ");
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("hello world\nhello\n", output);
}
TEST(RedirectTest, Test8) {

	testing::internal::CaptureStdout();
	executeRedirect("|");
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("", output);
}


/*
 int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/