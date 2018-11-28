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

void testExpressionBuilderTest(string i){
	 
	 Parser* pat = new Parser();
	 ExpressionBuilder* bob = new ExpressionBuilder (pat->parse_input(i));
	 Base* b = bob->build_tree();
	 if(b != NULL)
	   b->execute();

}
 TEST(ExpressionBuilderTestCommand, Test1) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("ERROR: TEST COMMAND NOT VALID\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test2) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("ERROR: TEST COMMAND NOT VALID\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test3) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -f");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test4) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -d");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
  TEST(ExpressionBuilderTestCommand, Test5) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -e");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test6) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-f]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test7) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-d]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test8) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-e]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test9) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -f tests/");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test10) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -d tests/");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test11) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -e tests/");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test12) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -f .gitignore");
	string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test13) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -d .gitignore");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test14) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -e .gitignore");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test15) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -f src/rshell.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test16) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -d src/rshell.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test17) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -e src/rshell.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test18) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -f djlawndjawld.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test19) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -d djlawndjawld.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test20) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("test -e djlawndjawld.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test21) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-f tests/]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test22) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-d tests/]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test23) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-e tests/]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test24) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-f .gitignore]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test25) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-d .gitignore]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test26) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-e .gitignore]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test27) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-f src/rshell.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test28) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-d src/rshell.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test30) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-e src/rshell.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(True)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test31) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-f djlawndjawld.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test32) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-d djlawndjawld.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
 TEST(ExpressionBuilderTestCommand, Test33) {
	
	testing::internal::CaptureStdout();
	testExpressionBuilderTest("[-e djlawndjawld.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("(False)\n", output);
 }
/*
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
 
 
