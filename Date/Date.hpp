#ifndef Date_cpp
#define Date_cpp

class Date{
public:

    // 必备隐性行为
    Date(unsigned int Year = 2004, unsigned int Month = 12, unsigned int Day = 26);
    Date(const Date& Source);
    Date& operator=(const Date& Source);
    ~Date();

    // non-static setters
    void Set(unsigned int Year, unsigned int Month, unsigned int Day);
    
    // non-static getters
    bool IsLeapYear() const;                // 非静态getter需要const修饰
    unsigned int DaysFrom19000101() const;  
    int DaysBetween(const Date& ADate) const;     // const防止修改其他对象，传引用节省空间.
    bool IsEarlierThan(const Date& ADate) const;
    bool IsSame(const Date& ADate) const;
    bool IsLaterThan(const Date& ADate) const;
    
    // operator overload
    int operator-(const Date& ADate) const;
    bool operator>(const Date& ADate) const;
    bool operator<(const Date& ADate) const;
    bool operator==(const Date& ADate) const;
    bool operator>=(const Date& ADate) const;
    bool operator<=(const Date& ADate) const;
    bool operator!=(const Date& ADate) const;

    // static getters
    static bool IsValid(unsigned int Year, unsigned int Month, unsigned int Day);
    static bool IsLeapYear(unsigned int Year);
    static bool IsLeapYear(const Date& ADate);
    static unsigned int DaysFrom19000101(unsigned int Year, unsigned int Month, unsigned int Day);  
    static unsigned int DaysFrom19000101(const Date& ADate);
    static int DaysBetween(unsigned int Year1, unsigned int Month1, unsigned int Day1, unsigned int Year2, unsigned int Month2, unsigned int Day2);

    // 常引用成员
    const unsigned int& Year    {m_Year};
    const unsigned int& Month   {m_Month};
    const unsigned int& Day     {m_Day};

    //静态数据成员
    static const unsigned int MinYear;
    static const unsigned int MaxYear;
    static const unsigned int MinMonth;
    static const unsigned int MaxMonth;
    static const unsigned int DaysInMonth[2][13];   // isLeapYear可以作为第一维下标，为了方便使用，第二维设为13

private:
    unsigned int m_Year     {2004};
    unsigned int m_Month    {12};
    unsigned int m_Day      {26};
    bool isLeapYear         {true};
};

#endif