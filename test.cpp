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

#include "gtest/gtest.h"

using namespace std;

TEST(testing, test1) {
    vector<string> v = {"ls", "-a"}; 
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

TEST(testing, test2) {
    vector<string> v = {"ls", "-l", ";", "exit"};
    ExpressionBuilder* ep = new ExpressionBuilder(v);

    EXPECT_TRUE(ep->build_tree()->execute());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
