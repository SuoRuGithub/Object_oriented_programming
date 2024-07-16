#include "Date.hpp"

// 必备隐性行为
Date::Date(unsigned int Year, unsigned int Month, unsigned int Day){
    Set(Year, Month, Day);
}
Date::Date(const Date& Source){
    m_Year = Source.Year;
    m_Month = Source.Month;
    m_Day = Source.Day;
}
Date& Date::operator=(const Date& Source){
    if (this != &Source){
        m_Year = Source.Year;
        m_Month = Source.Month;
        m_Day = Source.Day;
    }
    return *this;
}
Date::~Date(){
    //
}

// non-stactic setters
void Date::Set(unsigned int Year, unsigned int Month, unsigned int Day){
    if (IsValid(Year, Month, Day)){
        m_Year = Year;
        m_Month = Month;
        m_Day = Day;
    }
    else{
        m_Year = MinYear;
        m_Month = MinMonth;
        m_Day = 1;
    }
}

// non-static getters
bool Date::IsLeapYear() const{  //常函数声明和定义都需要加上const关键字
    return IsLeapYear(m_Year);
}

unsigned int Date::DaysFrom19000101() const{
    unsigned int res = 365 * (m_Year - 1900 - 1) +  
                        ((m_Year - 1u) / 4u - (m_Year - 1u) / 100u + (m_Year - 1u) / 400u);
    for (unsigned Month = 1; Month < m_Month; Month++ ){
        res += DaysInMonth[IsLeapYear()][Month];
    }
    res += m_Day;
    return res - 1; 
}  

int Date::DaysBetween(const Date& ADate) const{
    return DaysFrom19000101() - ADate.DaysFrom19000101();
}     

bool Date::IsEarlierThan(const Date& ADate) const{
    return DaysFrom19000101() < ADate.DaysFrom19000101();
}

bool Date::IsSame(const Date& ADate) const{
    // return DaysFrom19000101() == ADate.DaysFrom19000101();
    return (m_Year == ADate.Year) & (m_Month == ADate.Month) & (m_Day == ADate.Day);    //按位与，更快？
}

bool Date::IsLaterThan(const Date& ADate) const{
    return DaysFrom19000101() > ADate.DaysFrom19000101();
}

// operator overload
int Date::operator-(const Date& ADate) const{
    return this->DaysBetween(ADate);
}
bool Date::operator>(const Date& ADate) const{
    return this->IsLaterThan(ADate);
}
bool Date::operator<(const Date& ADate) const{
    return this->IsEarlierThan(ADate);
}
bool Date::operator==(const Date& ADate) const{
    return this->IsSame(ADate);
}
bool Date::operator>=(const Date& ADate) const{
    return (this->IsLaterThan(ADate)) | (this->IsSame(ADate));
}
bool Date::operator<=(const Date& ADate) const{
    return (this->IsEarlierThan(ADate)) | (this->IsSame(ADate));
}
bool Date::operator!=(const Date& ADate) const{
    return !this->IsSame(ADate);
}

// static getters
bool Date::IsValid(unsigned int Year, unsigned int Month, unsigned int Day){
    return (Year >= MinYear) & (Year <= MaxYear) & (Month >= MinMonth) & (Month <= MaxMonth) & (Day >= 1) & (Day <= DaysInMonth[IsLeapYear(Year)][Month]);
}

bool Date::IsLeapYear(unsigned int Year){
    return (Year % 4 == 0) & (Year % 100 != 0) | (Year % 400 == 0);
}

bool Date::IsLeapYear(const Date& ADate){
    return IsLeapYear(ADate.Year);
}

unsigned int Date::DaysFrom19000101(unsigned int Year, unsigned int Month, unsigned int Day){
    return Date(Year, Month, Day).DaysFrom19000101();
}  

unsigned int Date::DaysFrom19000101(const Date& ADate){
    return ADate.DaysFrom19000101();
}

int Date::DaysBetween(unsigned int Year1, unsigned int Month1, unsigned int Day1, unsigned int Year2, unsigned int Month2, unsigned int Day2){
    return DaysFrom19000101(Year1, Month1, Day1) - DaysFrom19000101(Year2, Month2, Day2);
}

const unsigned int Date::MinYear    {1900u};     // 这里设置u表示是一个
const unsigned int Date::MaxYear    {9999u};
const unsigned int Date::MinMonth   {1u};
const unsigned int Date::MaxMonth   {12u};
const unsigned int Date::DaysInMonth[2u][13u] {
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};  // 太乐了，我已经忘记了Cpp的数组是大括号