CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/rshell.cpp
    )

ADD_EXECUTABLE(test
  tests/expressionprecedencetest.cpp
  tests/expressionbuildertest.cpp
  tests/parsertest.cpp
  tests/parserprecedencetest.cpp
  tests/parsertestcommand.cpp
  tests/expressiontestcommand.cpp
  tests/redirectiontest.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
