#include <iostream>
#include "Date.cpp"

// for test
void fuc_test(const Date& ADate){
    std::cout << ADate.Year << "-" << ADate.Month << "-" << ADate.Day << std::endl; 
}

int main(){
    std::cout << "***Test for construction.***" << std::endl;
    Date d1;
    Date d2(2024, 7, 16);
    Date d3 = d2;
    fuc_test(d1);
    fuc_test(d2);
    fuc_test(d3);

    std::cout << "***Test for set.***" << std::endl;
    d3.Set(2023, 6, 8);
    fuc_test(d3);

    std::cout << "***Test for leap year.***" << std::endl;
    if (d3.IsLeapYear()){
        std::cout << d3.Year << " is a leap year." << std::endl;
    }
    else{
        std::cout << d3.Year << " is not a leap year." << std::endl;
    }
    
    std::cout << "***Test for days from 1900-01-01.***" << std::endl;
    std::cout << d3.DaysFrom19000101() << std::endl;

    std::cout << "***Test for days between and oprerator minus .***" << std::endl;
    std::cout << "I have been wasting for " << d2.DaysBetween(d1) <<" days in the world." << std::endl;
    std::cout << "I have been wasting for " << d2 - d1 <<" days in the world." << std::endl;

    std::cout << "***Test for earlier / later / same and the correspond operators.***" << std::endl;
    Date d4 = d3;
    std::cout << "d4 == d3:" << std::endl;
    fuc_test(d4);
    fuc_test(d3);
    std::cout << d4.IsSame(d3) << std::endl;
    std::cout << std::to_string(d4 == d3) << std::endl;

    std::cout << "d2 > d3:" << std::endl;
    fuc_test(d2);
    fuc_test(d3);
    std::cout << d2.IsLaterThan(d3) << std::endl;
    std::cout << std::to_string(d2 > d3) << std::endl;
    
    std::cout << "d3 < d2:" << std::endl;
    fuc_test(d3);
    fuc_test(d2);
    std::cout << d3.IsEarlierThan(d2) << std::endl;
    std::cout << std::to_string(d3 < d2) << std::endl;

    std::cout << "***Test for static getters.***" << std::endl;
    std::cout << "2004-12-32 is valid? " << std::to_string(Date::IsValid(2004, 12, 32)) << std::endl;

    std::cout << "2185 is leap year? " << std::to_string(Date::IsLeapYear(2185)) << std::endl;
    
    std::cout << "Days between today and 2004-12-26: " << Date::DaysBetween(2024, 7, 16, 2004, 12, 26) << std::endl;
    
    std::cout << "Days from 1900-01-01 to today: " << Date::DaysFrom19000101(2024, 7, 16) << std::endl;

    return 0;
}