#pragma once

#include <string>
#include "Core/DateMath.h"

class Person
{
private:
    std::string FirstName;
    std::string LastName;
    DateMath::DateYMD BirthDate;
    int CurrentAge = 0;

public:
    // Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD &birthday);
    Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD birthday);

    std::string GetName() const { return FirstName; }
    std::string GetSurname() const { return LastName; }
    DateMath::DateYMD GetBirthDate() const { return BirthDate; }
    int GetAge() const { return CurrentAge; }

    int DaysTillBirthday();

private:
    void CalculateAge();
};