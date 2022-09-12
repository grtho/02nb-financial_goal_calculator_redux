#include <iostream>
#include <iomanip>

#include "main.hpp"

using std::cout, std::cin, std::endl, std::setw, std::setprecision, std::fixed;

int main() {

    cout << "Financial Goal Calculator" << endl;

    bool quit = false;
    while (!quit)
    {
        int answer = getChoice();

        switch (answer)
        {
            case 1: { // calculateYearsToGoal()
                double investment = 0;
                double goal = 0;
                double rate = 0;

                enterValues(investment, rate);

                cout << "Enter financial Goal: ";
                cin >> goal;

                int yearsToGoal = calculateYearsToGoal(investment, goal, rate);

                cout << "That will take " << yearsToGoal << " years" << endl;

                break;
            }
            case 2: { // getInvestmentGrowth()
                double investment = 0;
                double rate = 0;
                int years = 0;

                enterValues(investment, rate);

                cout << "Enter Years to maturity: ";
                cin >> years;

                double amount = getInvestmentGrowth(investment, rate, years);

                cout << "You will have " << fixed << setprecision(2) << amount << " in " << years << " years" << endl;
                break;
            }
            case 3:
                quit = true;
                break;
        }
    }

    return 0;
}


int getChoice()
{
    while (true)
    {
        int answer = -1;
        cout << "1. Calculate Years to Financial Goal\n2. Calculate Amount based on Years\n3. Quit" << endl;
        cin >> answer;

        switch(answer)
        {
            case 1:
            case 2:
            case 3:
                return answer;
            default:
                cout << "Please enter a proper option." << endl;
                continue;
        }
    }
}

void enterValues(double& investment, double& rate)
{
    cout << "Enter Investment Amount: ";
    cin >> investment;
    cout << "Enter Interest Rate (in percent): ";
    cin >> rate;

    // make the percent a decimal value.
    rate /= 100;
}

int calculateYearsToGoal(double investment, double goal, double rate)
{
    double money = investment;

    int year = 0;

    for (year = 1; money < goal; year++)
    {
        money += money * rate;

        cout << "Year" << setw(4) << year << ". " << fixed << setprecision(2) << money << endl;
    }

    return year - 1;
}

double getInvestmentGrowth(double investment, double rate, int years)
{
    double money = investment;

    int year;
    for (year = 0; year < years; year++)
    {
        money += money * rate;
    }

    return money;
}