#pragma once

#include <string>

enum Months {
    None = 0,
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

struct DateOfBirth {
    int Year;
    Months Month;
    int Day;

    DateOfBirth(int year, Months month, int day) : Year(year), Month(month), Day(day) {}
};

class Person 
{
private:
std::string FirstName;
std::string LastName;
DateOfBirth BirthDate;
public:
Person(const std::string& firstName, const std::string& lastName, DateOfBirth& birthday);

int Age();


};