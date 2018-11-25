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

void executeExpressionPrecedence(string i){
	 
	 Parser* pat = new Parser();
	 ExpressionBuilder* bob = new ExpressionBuilder (pat->parse_input(i));
	 Base* b = bob->build_tree();
	 if(b!= NULL)
	   b->execute();

}

TEST(ExpressionPrecedenceTest, Test1) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo hello)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("ERROR: PRECEDENCE NOT CLOSED\n", output);
 }
TEST(ExpressionPrecedenceTest, Test2) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo hello");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("ERROR: PRECEDENCE NOT CLOSED\n", output);
 }
TEST(ExpressionPrecedenceTest, Test3) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo hello(");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("ERROR: PRECEDENCE NOT CLOSED\n", output);
 }
TEST(ExpressionPrecedenceTest, Test4) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence(")echo hello");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("ERROR: PRECEDENCE NOT CLOSED\n", output);
 }
TEST(ExpressionPrecedenceTest, Test5) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("()");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionPrecedenceTest, Test6) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(;) ");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionPrecedenceTest, Test7) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(||)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionPrecedenceTest, Test8) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test9) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A);");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test10) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A); echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionPrecedenceTest, Test11) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A; (echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionPrecedenceTest, Test12) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A; echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionPrecedenceTest, Test13) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A) || echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test14) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A || (echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test15) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A || echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test16) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A) && echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionPrecedenceTest, Test17) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && (echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionPrecedenceTest, Test18) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionPrecedenceTest, Test19) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A); echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test20) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A; (echo B); echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test21) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A; echo B; (echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test22) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A; echo B); echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test23) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A; (echo B; echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test24) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A; echo B; echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
 TEST(ExpressionPrecedenceTest, Test25) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A) || echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test26) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A || (echo B) || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test27) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A || echo B || (echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test28) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A || echo B) || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test29) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A || (echo B || echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionPrecedenceTest, Test30) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A || echo B || echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
 TEST(ExpressionPrecedenceTest, Test31) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A) && echo B && echo C") ;
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test32) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && (echo B) && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test33) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && echo B && (echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test34) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B) && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test35) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && (echo B && echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test36) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B && echo C)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionPrecedenceTest, Test37) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B) || echo C && echo D && echo E || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test38) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && (echo B || echo C) && echo D && echo E || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test39) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && echo B || (echo C && echo D) && echo E || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test40) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && echo B || echo C && (echo D && echo E) || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test41) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && echo B || echo C && echo D && (echo E || echo F)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test42) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B) || (echo C && echo D) && (echo E || echo F)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test43) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B || echo C) && (echo D && echo E || echo F)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test44) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(echo A && echo B || echo C && echo D) && echo E || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test45) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && (echo B || echo C && echo D && echo E) || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionPrecedenceTest, Test46) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("echo A && echo B || (echo C && echo D && echo E || echo F)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionNestedPrecedenceTest, Test1) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("(())");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionNestedPrecedenceTest, Test2) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("((echo A && echo B) || (echo C && echo D))");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionNestedPrecedenceTest, Test3) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("((echo A && echo B) || echo C && echo D)");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\n", output);
 }
TEST(ExpressionNestedPrecedenceTest, Test4) {
	
	testing::internal::CaptureStdout();
	executeExpressionPrecedence("((echo A && echo B) || (echo C && echo D && echo E || echo F))");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
 
 
 
 int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
