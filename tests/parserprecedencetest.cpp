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

void printParePrecedence(string i){
	 
	Parser* pat = new Parser();	
	vector<string> v = pat->parse_input(i);
	
	for(int i =0; i < v.size(); i++)
		cout<< "[" << v[i] << "]";
	 
	 
 }

TEST(ParserPrecedenceTest, Test1) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo hello)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][hello][)]", output);
 }
TEST(ParserPrecedenceTest, Test2) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo hello");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][hello]", output);
 }
TEST(ParserPrecedenceTest, Test3) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo hello(");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][hello][(]", output);
 }
TEST(ParserPrecedenceTest, Test4) {
	
	testing::internal::CaptureStdout();
	printParePrecedence(")echo hello");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[)][echo][hello]", output);
 }
TEST(ParserPrecedenceTest, Test5) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("()");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][)]", output);
 }
TEST(ParserPrecedenceTest, Test6) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(;) ");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][;][)]", output);
 }
TEST(ParserPrecedenceTest, Test7) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(||)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][||][)]", output);
 }
TEST(ParserPrecedenceTest, Test8) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)]", output);
 }
TEST(ParserPrecedenceTest, Test9) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A);");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][;]", output);
 }
TEST(ParserPrecedenceTest, Test10) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A); echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][;][echo][B]", output);
 }
TEST(ParserPrecedenceTest, Test11) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A; (echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][(][echo][B][)]", output);
 }
TEST(ParserPrecedenceTest, Test12) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A; echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][;][echo][B][)]", output);
 }
TEST(ParserPrecedenceTest, Test13) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A) || echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][||][echo][B]", output);
 }
TEST(ParserPrecedenceTest, Test14) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A || (echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][(][echo][B][)]", output);
 }
TEST(ParserPrecedenceTest, Test15) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A || echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][||][echo][B][)]", output);
 }
TEST(ParserPrecedenceTest, Test16) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A) && echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][&&][echo][B]", output);
 }
TEST(ParserPrecedenceTest, Test17) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A && (echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][(][echo][B][)]", output);
 }
TEST(ParserPrecedenceTest, Test18) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A && echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][&&][echo][B][)]", output);
 }
TEST(ParserPrecedenceTest, Test19) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A); echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][;][echo][B][;][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test20) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A; (echo B); echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][(][echo][B][)][;][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test21) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A; echo B; (echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][echo][B][;][(][echo][C][)]", output);
 }
TEST(ParserPrecedenceTest, Test22) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A; echo B); echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][;][echo][B][)][;][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test23) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A; (echo B; echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][(][echo][B][;][echo][C][)]", output);
 }
TEST(ParserPrecedenceTest, Test24) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A; echo B; echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][;][echo][B][;][echo][C][)]", output);
 }
 TEST(ParserPrecedenceTest, Test25) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A) || echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][||][echo][B][||][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test26) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A || (echo B) || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][(][echo][B][)][||][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test27) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A || echo B || (echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][echo][B][||][(][echo][C][)]", output);
 }
TEST(ParserPrecedenceTest, Test28) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A || echo B) || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][||][echo][B][)][||][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test29) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A || (echo B || echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][(][echo][B][||][echo][C][)]", output);
 }
TEST(ParserPrecedenceTest, Test30) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A || echo B || echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][||][echo][B][||][echo][C][)]", output);
 }
 TEST(ParserPrecedenceTest, Test31) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A) && echo B && echo C") ;
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][)][&&][echo][B][&&][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test32) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A && (echo B) && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][(][echo][B][)][&&][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test33) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A && echo B && (echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][echo][B][&&][(][echo][C][)]", output);
 }
TEST(ParserPrecedenceTest, Test34) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A && echo B) && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][&&][echo][B][)][&&][echo][C]", output);
 }
TEST(ParserPrecedenceTest, Test35) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("echo A && (echo B && echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][(][echo][B][&&][echo][C][)]", output);
 }
TEST(ParserPrecedenceTest, Test36) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("(echo A && echo B && echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][echo][A][&&][echo][B][&&][echo][C][)]", output);
 }
TEST(ParserNestedPrecedenceTest, Test1) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("((echo A && echo B && echo C))");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][(][echo][A][&&][echo][B][&&][echo][C][)][)]", output);
 }
TEST(ParserNestedPrecedenceTest, Test2) {
	
	testing::internal::CaptureStdout();
	printParePrecedence("((echo A && echo B) && echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[(][(][echo][A][&&][echo][B][)][&&][echo][C][)]", output);
 }
 
/*
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
