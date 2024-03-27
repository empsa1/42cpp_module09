#include "../includes/RPN.hpp"

RPN::RPN(RPN const &other)
{
    *this = other;
}

std::stack<int> RPN::getStack() const
{
    return this->stack;
}

RPN &RPN::operator=(RPN const &other)
{
    this->stack = std::stack<int>();
    std::stack<int> tempStack = other.getStack();
    while (!tempStack.empty()) {
        this->stack.push(tempStack.top());
        tempStack.pop();
    }
    return *this;
}

RPN::RPN(const std::string& expression)
{
    int i = -1;
    while (expression[++i] != '\0')
    {
        if (std::isdigit(expression[i]))
        {
            stack.push(expression[i] - '0');
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (stack.size() < 2)
            {
                throw IllegallOperatorNumbersException();
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            int result;
            if (expression[i] == '+')
                result = operand1 + operand2;
            else if (expression[i] == '-')
                result = operand1 - operand2;
            else if (expression[i] == '*')
                result = operand1 * operand2;
            else if (expression[i] == '/')
            {
                if (operand2 == 0)
                    throw DivisionByZeroException();
                else
                {
                    result = operand1 / operand2;
                }
            }
            stack.push(result);
        }
        else if (std::isspace(expression[i]))
            continue ;
        else
        {
            std::cout << RED << "Error: Invalid argument token! in argument: " << expression[i] << RESET << std::endl;
            return ;
        }   
    }
    if (stack.size() != 1)
    {
        std::cout << RED << "Error: Invalid Expression!" << RESET << std::endl;
        return ;
    }
    std::cout << GREEN << stack.top() << RESET << std::endl;
}

RPN::~RPN()
{

}