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

void printParse(string i){
	 
	Parser* pat = new Parser();	
	vector<string> v = pat->parse_input(i);
	
	for(int i =0; i < v.size(); i++)
		cout<< "[" << v[i] << "]";
	 
	 
 }
 
TEST(ParserTest, Test1) {
	
	testing::internal::CaptureStdout();
	printParse("");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ParserTest, Test2) {
	
	testing::internal::CaptureStdout();
	printParse(";");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[;]", output);
 }
TEST(ParserTest, Test3) {
	
	testing::internal::CaptureStdout();
	printParse("||");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[||]", output);
 }
TEST(ParserTest, Test4) {
	
	testing::internal::CaptureStdout();
	printParse("&&");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[&&]", output);
 }
TEST(ParserTest, Test5) {
	
	testing::internal::CaptureStdout();
	printParse("echo A");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A]", output);
 }
TEST(ParserTest, Test6) {
	
	testing::internal::CaptureStdout();
	printParse("echo A;");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;]", output);
 }
TEST(ParserTest, Test7) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][echo][B]", output);
 }
TEST(ParserTest, Test8) {
	
	testing::internal::CaptureStdout();
	printParse("echo A || echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][echo][B]", output);
 }
TEST(ParserTest, Test9) {
	
	testing::internal::CaptureStdout();
	printParse("echo A && echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][echo][B]", output);
 }
TEST(ParserTest, Test10) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][echo][B][;][echo][C]", output);
 }
TEST(ParserTest, Test11) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][echo][B][||][echo][C]", output);
 }
TEST(ParserTest, Test12) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; echo B && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][echo][B][&&][echo][C]", output);
 }
TEST(ParserTest, Test13) {
	
	testing::internal::CaptureStdout();
	printParse("echo A || echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][echo][B][||][echo][C]", output);
 }
TEST(ParserTest, Test14) {
	
	testing::internal::CaptureStdout();
	printParse("echo A || echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][echo][B][;][echo][C]", output);
 }
TEST(ParserTest, Test15) {
	
	testing::internal::CaptureStdout();
	printParse("echo A || echo B && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][||][echo][B][&&][echo][C]", output);
 }
TEST(ParserTest, Test16) {
	
	testing::internal::CaptureStdout();
	printParse("echo A && echo B && echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][echo][B][&&][echo][C]", output);
 }
TEST(ParserTest, Test17) {
	
	testing::internal::CaptureStdout();
	printParse("echo A && echo B; echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][echo][B][;][echo][C]", output);
 }
TEST(ParserTest, Test18) {
	
	testing::internal::CaptureStdout();
	printParse("echo A && echo B || echo C");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][echo][B][||][echo][C]", output);
 }
TEST(ParserTest, Test19) {
	
	testing::internal::CaptureStdout();
	printParse("echo A && echo B || echo C && echo D && echo E || echo F");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][&&][echo][B][||][echo][C][&&][echo][D][&&][echo][E][||][echo][F]", output);
 }
TEST(ParserTest, Test20) {
	
	testing::internal::CaptureStdout();
	printParse("#");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("", output);
 }
TEST(ParserTest, Test21) {
	
	testing::internal::CaptureStdout();
	printParse("echo A #; echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A]", output);
 }
TEST(ParserTest, Test22) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; #echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;]", output);
 }
TEST(ParserTest, Test23) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; # echo B");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;]", output);
 }
TEST(ParserTest, Test24) {
	
	testing::internal::CaptureStdout();
	printParse("echo A; echo hello#world; echo hi");
	string output = testing::internal::GetCapturedStdout();
	
     EXPECT_EQ("[echo][A][;][echo][hello]", output);
 }
 
/*
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/