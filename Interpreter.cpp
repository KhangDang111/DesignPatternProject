#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Expression {
public:
    virtual int interpret(map<string, int>& variables) = 0;
    virtual ~Expression() {}
};

class Number : public Expression {
private:
    int number;
public:
    Number(int num) : number(num) {}
    int interpret(map<string, int>&) { return number; }
};

class Variable : public Expression {
private:
    string name;
public:
    Variable(string varName) : name(varName) {}
    int interpret(map<string, int>& variables) {
        return variables[name];
    }
};

class Operator : public Expression {
private:
    char op;
    Expression *leftOperand;
    Expression *rightOperand;
public:
    Operator(char opr, Expression *left, Expression *right) : op(opr), leftOperand(left), rightOperand(right) {}
    ~Operator() {
        delete leftOperand;
        delete rightOperand;
    }
    int interpret(map<string, int>& variables) {
        switch(op) {
            case '+': return leftOperand->interpret(variables) + rightOperand->interpret(variables);
            case '-': return leftOperand->interpret(variables) - rightOperand->interpret(variables);
            case '*': return leftOperand->interpret(variables) * rightOperand->interpret(variables);
            case '/': return leftOperand->interpret(variables) / rightOperand->interpret(variables);
            default: return 0;
        }
    }
};

class Parser {
protected:
    stack<Expression *> expressions;
public:
    void parse(string expression) {
        for (int i = 0; i < expression.length(); ++i) {
            if (isalpha(expression[i])) {
                expressions.push(new Variable(string(1, expression[i])));
            } else if (isdigit(expression[i])) {
                expressions.push(new Number(expression[i] - '0'));
            } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                Expression *left = expressions.top();
                expressions.pop();
                Expression *right = expressions.top();
                expressions.pop();
                expressions.push(new Operator(expression[i], left, right));
            }
        }
    }
    int evaluate(map<string, int>& variables) {
        return expressions.top()->interpret(variables);
    }
};

class SimpleParser : public Parser {
public:
    int evaluate(string expression, map<string, int>& variables) {
        parse(expression);
        return Parser::evaluate(variables);
    }
};

int main() {
    string expression = "a+b*c-d";
    SimpleParser parser;
    map<string, int> variables;
    variables["a"] = 5;
    variables["b"] = 10;
    variables["c"] = 2;
    variables["d"] = 3;
    cout << "Result: " << parser.evaluate(expression, variables) << endl;
    return 0;
}
