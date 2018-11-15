#include "../src/base.h"
#include "../src/command.h"
#include "../src/expressionbuilder.h"
#include "../src/operator.h"
#include "../src/parser.h"
#include "../src/and.h"
#include "../src/or.h"
#include "../src/semicolon.h"

#include <vector>
#include <string>

#include "gtest/gtest.h"

using namespace std;

TEST(testing, test1) {
    vector<string> v = {"ls", "-a"}; 
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(testing, test2) {
    vector<string> v = {"ls", "-l", ";", "echo","hello"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

void printParser(vector<string> v){
  
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

}

TEST(ParerTest, SingleCommand) {
		string s = "echo hello";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("echo hello ", output);
}

TEST(ParerTest, TwoOperators) {
		string s = "echo hello; echo world || echo hi";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("echo hello ; echo world || echo hi ", output);
}

TEST(ParerTest, ManyOperators) {
		string s = "echo hello; echo world || echo hi; echo hello && echo world";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("echo hello ; echo world || echo hi ; echo hello && echo world ", output);
}
TEST(ParerTest, EmptyInput) {
		string s = "";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("", output);
}
TEST(ParerTest, CommentAfterOperator) {
		string s = "echo hello; #echo world || echo hi; echo hello && echo world";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("echo hello ; ", output);
}
TEST(ParerTest, CommentWithSpaces) {
		string s = "echo hello; # echo world || echo hi; echo hello && echo world";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("echo hello ; ", output);
}
TEST(ParerTest, CommentBetweenArgs) {
    
    string s = "echo hello; echo#world || echo hi; echo hello && echo world";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
    printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("echo hello ; echo ", output);
}
TEST(ParerTest, OnlyComment) {
		string s = "#";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("", output);
}
TEST(ParerTest, OnlySemicolon) {
	string s = ";";
    Parser* pat = new Parser();
  
    testing::internal::CaptureStdout();    
		printParser(pat->parse_input(s));
    string output = testing::internal::GetCapturedStdout();
  
    EXPECT_EQ("; ", output);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
