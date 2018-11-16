# Rshell Assignment 
## Introduction
This Rshell program processes commands entered by the user and executes them similarly to that of BASH in Linux, with the additional feature of being able to chain commands with the three operators `;` , `&&`, and `||`. The design pattern used in this project is a composite pattern. We choose to implement this partitioning pattern because it allows us significant extensibility when adding new features. Commands have the following format:
```
$ executable [argumentList] [connector] [cmd] ...
```
## UML
![UML Diagram](https://github.com/cs100/assignment-1-team-7-1/blob/master/rshell_uml.png)

## Classes

In utilizing the composite design pattern, we built a `Base` class with two subclasses, a leaf node `Command` and a composite node `Operator`. The Operator class also had three subclasses representing the 3 types of connectors: `Semicolon`, `Or`, and `And`. In addition to the composite structure we also have two other classes `Parser` and `ExpressionBuilder`. The Parser class facilitates the translation if the user inputted string, into a `vector<string>` of commands and operators, to be handed over to the ExpressionBuilder class. The ExpressionBuilder class builds a tree based off of the `vector<string>` delivered by the Parser and dynamically creates this structure. An example of our process of breaking down the inputted string and building an tree of executions can be seen in the figure below.

![Flow Diagram](https://github.com/cs100/assignment-1-team-7-1/blob/master/rshell_tree_structure.png)

## Known Bugs

1. Calling the exit command after a command fails, will not exit the program. The user has to type exit another time.
2. Calling # after a connector causes a segmentation fault
