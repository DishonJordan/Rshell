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

void executeExpressionBuilder(string i){
	 
	 Parser* pat = new Parser();
	 ExpressionBuilder* bob = new ExpressionBuilder (pat->parse_input(i));
	 Base* b = bob->build_tree();
	 if(b != NULL)
	   b->execute();

}
TEST(ExpressionBuilderTest, Test1) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionBuilderTest, Test2) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder(";");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionBuilderTest, Test3) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("||");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionBuilderTest, Test4) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("&&");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionBuilderTest, Test5) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test6) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A;");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test7) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionBuilderTest, Test8) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A || echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test9) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A && echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionBuilderTest, Test10) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionBuilderTest, Test11) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionBuilderTest, Test12) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; echo B && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionBuilderTest, Test13) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A || echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test14) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A || echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nC\n", output);
 }
TEST(ExpressionBuilderTest, Test15) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A || echo B && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nC\n", output);
 }
TEST(ExpressionBuilderTest, Test16) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A && echo B && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionBuilderTest, Test17) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A && echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nC\n", output);
 }
TEST(ExpressionBuilderTest, Test18) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A && echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\n", output);
 }
TEST(ExpressionBuilderTest, Test19) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A && echo B || echo C && echo D && echo E || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nB\nD\nE\n", output);
 }
TEST(ExpressionBuilderTest, Test20) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("#");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ExpressionBuilderTest, Test21) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A #; echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test22) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; #echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test23) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; # echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\n", output);
 }
TEST(ExpressionBuilderTest, Test24) {
	
	testing::internal::CaptureStdout();
	executeExpressionBuilder("echo A; echo hello#world; echo hi");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("A\nhello\n", output);
 }
/*
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/