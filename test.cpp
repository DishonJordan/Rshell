#include "src/base.h"
#include "src/command.h"
#include "src/expressionbuilder.h"
#include "src/operator.h"
#include "src/parser.h"
#include "src/and.h"
#include "src/or.h"
#include "src/semicolon.h"

#include <vector>
#include <string>
#include <cstring>

#include "gtest/gtest.h"

using namespace std;

/* ExpressionBuilder Testing w/ varying amount of connectors */
TEST(ExpressionBuilderTEST, EmptyCommandTEST) {
    vector<string> v;
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_EQ(0, ep->build_tree()->execute());
}

TEST(ExpressionBuilderTEST, NoConnectorTEST) {
    vector<string> v = {"ls", "-a"}; 
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(ExpressionBuilderTEST, SingleConnectorTEST) {
    vector<string> v = {"ls", "-l", ";", "exit"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(ExpressionBuilderTEST, TwoConnectorTEST) {
    vector<string> v = {"echo", "hello", "||", "ls", "-lA", ";", "ls"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(ExpressionBuilderTEST, ThreeConnectorTest) {
    vector<string> v = {"ls", "-a", "&&", "echo", "Hello World", "||", "ls", "-l", ";", "exit"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree());
}

TEST(ExpressionBuilderTEST, TopTreeTEST) {
    vector<string> v = {"echo", "hello", ";", "ls", "-a", "||", "mkdir", "test", "&&", "echo", "world", ";", "git", "status"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);
    Base* top = ep->build_tree();
    vector<string> v2 = {";"};
    ExpressionBuilder* ep2 = new ExpressionBuilder(v2);
    Base* test_top = ep2->build_tree();

    EXPECT_EQ(test_top, top);
}
/* Operator Testing */

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
