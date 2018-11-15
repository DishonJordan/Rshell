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

/* Connector and ExpressionBuilder Testing */
TEST(ConnectorTEST, EmptyCommandTEST) {
    vector<string> v;
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_EQ(0, ep->build_tree()->execute());
}

TEST(ConnectorTEST, NoConnectorTEST) {
    vector<string> v = {"ls", "-a"}; 
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(ConnectorTEST, SingleConnectorTEST) {
    vector<string> v = {"ls", "-l", ";", "exit"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(ConnectorTEST, TwoConnectorTEST) {
    vector<string> v = {"echo", "hello", "||", "ls", "-lA", ";", "ls"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(ConnectorTEST, ThreeConnectorTest) {
    vector<string> v = {"ls", "-a", "&&", "echo", "Hello World", "||", "ls", "-l", ";", "exit"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

/* Command Testing */
TEST(CommandTEST, ls1TEST) {
    vector<char*> v = {"ls", "-a"};
    ExpressionBuilder* ep = new ExpressionBuilder(v); // Used to convert from char* to string
    Base* cmd = ep->build_tree();

    EXPECT_TRUE(cmd->execute());
}

TEST(CommandTEST, ls2TEST) {
    vector<char*> v = {"ls", "-l"};
    Base* cmd = new Command(v);
    
    EXPECT_TRUE(cmd->execute());
}

TEST(CommandTEST, ls3TEST) {
    vector<char*> v = {"ls"};
    Base* cmd = new Command(v);
    
    EXPECT_TRUE(cmd->execute());
}

TEST(CommandTEST, echoTEST) {
    vector<char*> v = {"echo", "Hello World!"};
    Base* cmd = new Command(v);

    cmd->execute();
    EXPECT_TRUE(cmd->execute());
}
/* Operator Testing */
/*
TEST(OperatorTEST, test1) {
    vector<char*> v1 = {"ls", "-a"};
    vector<char*> v2 = {"echo", "hello"};
    Base* cmd1 = new Command(v1);
    Base* cmd2 = new Command(v2);
    Base* op = new Operator();
    
    op->setLeftNode(cmd1);
    op->setRightNode(cmd2);

    Operator* And = new And(cmd1, cmd2);
    EXPECT_TRUE(And->execute());
}
*/
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
