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

void printTestParse(string i){
	 
	Parser* pat = new Parser();	
	vector<string> v = pat->parse_input(i);
	
	for(int i =0; i < v.size(); i++)
		cout<< "[" << v[i] << "]";
	 
	 
 }
 TEST(ParserTestCommand, Test1) {
	
	testing::internal::CaptureStdout();
	printTestParse("test");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test]", output);
 }
 TEST(ParserTestCommand, Test2) {
	
	testing::internal::CaptureStdout();
	printTestParse("[]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test]", output);
 }
 TEST(ParserTestCommand, Test3) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -f");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f]", output);
 }
 TEST(ParserTestCommand, Test4) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -d");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d]", output);
 }
  TEST(ParserTestCommand, Test5) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -e");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e]", output);
 }
 TEST(ParserTestCommand, Test6) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-f]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f]", output);
 }
 TEST(ParserTestCommand, Test7) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-d]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d]", output);
 }
 TEST(ParserTestCommand, Test8) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-e]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e]", output);
 }
 TEST(ParserTestCommand, Test9) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -f tests/");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][tests/]", output);
 }
 TEST(ParserTestCommand, Test10) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -d tests/");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][tests/]", output);
 }
 TEST(ParserTestCommand, Test11) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -e tests/");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][tests/]", output);
 }
 TEST(ParserTestCommand, Test12) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -f .gitignore");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][.gitignore]", output);
 }
 TEST(ParserTestCommand, Test13) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -d .gitignore");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][.gitignore]", output);
 }
 TEST(ParserTestCommand, Test14) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -e .gitignore");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][.gitignore]", output);
 }
 TEST(ParserTestCommand, Test15) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -f src/rshell.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][src/rshell.cpp]", output);
 }
 TEST(ParserTestCommand, Test16) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -d src/rshell.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][src/rshell.cpp]", output);
 }
 TEST(ParserTestCommand, Test17) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -e src/rshell.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][src/rshell.cpp]", output);
 }
 TEST(ParserTestCommand, Test18) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -f djlawndjawld.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][djlawndjawld.cpp]", output);
 }
 TEST(ParserTestCommand, Test19) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -d djlawndjawld.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][djlawndjawld.cpp]", output);
 }
 TEST(ParserTestCommand, Test20) {
	
	testing::internal::CaptureStdout();
	printTestParse("test -e djlawndjawld.cpp");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][djlawndjawld.cpp]", output);
 }
 TEST(ParserTestCommand, Test21) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-f tests/]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][tests/]", output);
 }
 TEST(ParserTestCommand, Test22) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-d tests/]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][tests/]", output);
 }
 TEST(ParserTestCommand, Test23) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-e tests/]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][tests/]", output);
 }
 TEST(ParserTestCommand, Test24) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-f .gitignore]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][.gitignore]", output);
 }
 TEST(ParserTestCommand, Test25) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-d .gitignore]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][.gitignore]", output);
 }
 TEST(ParserTestCommand, Test26) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-e .gitignore]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][.gitignore]", output);
 }
 TEST(ParserTestCommand, Test27) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-f src/rshell.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][src/rshell.cpp]", output);
 }
 TEST(ParserTestCommand, Test28) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-d src/rshell.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][src/rshell.cpp]", output);
 }
 TEST(ParserTestCommand, Test30) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-e src/rshell.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][src/rshell.cpp]", output);
 }
 TEST(ParserTestCommand, Test31) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-f djlawndjawld.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-f][djlawndjawld.cpp]", output);
 }
 TEST(ParserTestCommand, Test32) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-d djlawndjawld.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-d][djlawndjawld.cpp]", output);
 }
 TEST(ParserTestCommand, Test33) {
	
	testing::internal::CaptureStdout();
	printTestParse("[-e djlawndjawld.cpp]");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[test][-e][djlawndjawld.cpp]", output);
 }
/*
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
 
 