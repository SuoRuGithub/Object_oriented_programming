#ifndef Date_cpp
#define Date_cpp

class Date{
public:

    // �ر�������Ϊ
    Date(unsigned int Year = 2004, unsigned int Month = 12, unsigned int Day = 26);
    Date(const Date& Source);
    Date& operator=(const Date& Source);
    ~Date();

    // non-static setters
    void Set(unsigned int Year, unsigned int Month, unsigned int Day);
    
    // non-static getters
    bool IsLeapYear() const;                // �Ǿ�̬getter��Ҫconst����
    unsigned int DaysFrom19000101() const;  
    int DaysBetween(const Date& ADate) const;     // const��ֹ�޸��������󣬴����ý�ʡ�ռ�.
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

    // �����ó�Ա
    const unsigned int& Year    {m_Year};
    const unsigned int& Month   {m_Month};
    const unsigned int& Day     {m_Day};

    //��̬���ݳ�Ա
    static const unsigned int MinYear;
    static const unsigned int MaxYear;
    static const unsigned int MinMonth;
    static const unsigned int MaxMonth;
    static const unsigned int DaysInMonth[2][13];   // isLeapYear������Ϊ��һά�±꣬Ϊ�˷���ʹ�ã��ڶ�ά��Ϊ13

private:
    unsigned int m_Year     {2004};
    unsigned int m_Month    {12};
    unsigned int m_Day      {26};
    bool isLeapYear         {true};
};

#endif