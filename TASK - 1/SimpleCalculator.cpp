#include <iostream>
#include <limits>
#include <sstream>

double enterNumber()
{
    double input = { 0.0 };
    std::string inputStr;

    while (true)
    {
        std::cout << "Enter an number: ";
        std::cin >> inputStr;

        std::stringstream ss(inputStr);
        if (ss >> input && ss.eof())
        {
            break;
        }

        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number(s) selection. Try again.\n";
        }
    }

    return input;
}

char pickOp()
{
    std::cout << "Pick an operator (+, -, *, /): ";
    char input;
    std::cin >> input;

    while (true)
    {
        if (std::cin.fail() || input != '+' && input != '-' && input != '*' && input != '/')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid operator try again\nPick an operator (+, -, *, /): ";
            std::cin >> input;
        }

        else if (!std::cin.fail() || input == '+' || input == '-' || input == '*' || input == '/')
        {
            break;
        }
    }

    return input;
}

int main()
{
    char continueE;

    do
    {
        double firstNum = { enterNumber() };

        char op = { pickOp() };

        double secondNum = { enterNumber() };

        switch(op)
        {
            case '+':
                std::cout << firstNum << " + " << secondNum << " = " << firstNum + secondNum << '\n';
                break;
            case '-':
                std::cout << firstNum << " - " << secondNum << " = " << firstNum - secondNum << '\n';
                break;
            case '*':
                std::cout << firstNum << " * " << secondNum << " = " << firstNum * secondNum << '\n';
                break;
            case '/':
                if (secondNum == 0)
                {
                    std::cout << "Anything divided by 0 is 0\n";
                }
                else
                {
                    std::cout << firstNum << " / " << secondNum << " = " << firstNum / secondNum << '\n';
                }
                break;
            default:
                std::cout << "Invalid Operator.\n";
        }
    
        std::cout << "Do you want to do another equation (y/Y for another or any key to exit)?: ";
        std::cin >> continueE;

        if (continueE != 'y' && continueE != 'Y')
        {
            break;
        }

    } while (continueE == 'y' || continueE == 'Y');

    return 0;
}