#pragma once

#include <string>

#include "DateMath.h"

class Person
{
private:
    std::string FirstName;
    std::string LastName;
    DateMath::DateYMD BirthDate;
    int CurrentAge = 0;

public:
    Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD &birthday);
    Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD birthday);

    std::string GetName();
    std::string GetSurname();
    int GetAge();
    void DaysTillBirthday();

private:
    void CalculateAge();
};