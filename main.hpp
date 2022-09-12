//
// Created by Griffin Thompson on 9/12/22.
//

#ifndef INC_02NB_FINANCIAL_GOAL_CALCULATOR_REDUX_MAIN_HPP
#define INC_02NB_FINANCIAL_GOAL_CALCULATOR_REDUX_MAIN_HPP

int getChoice();

void enterValues(double& investment, double& rate);

int calculateYearsToGoal(double investment, double goal, double rate);

double getInvestmentGrowth(double investment, double rate, int years);

#endif //INC_02NB_FINANCIAL_GOAL_CALCULATOR_REDUX_MAIN_HPP
