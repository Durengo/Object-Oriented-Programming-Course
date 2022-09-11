#include "Person.h"

#include <fmt/core.h>

Person::Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD &birthday)
    : FirstName(firstName), LastName(lastName), BirthDate(birthday)
{
    CalculateAge();
}

Person::Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD birthday)
    : FirstName(firstName), LastName(lastName), BirthDate(birthday)
{
    CalculateAge();
}

std::string Person::GetName()
{
    return FirstName;
}

std::string Person::GetSurname()
{
    return LastName;
}

int Person::GetAge()
{
    return CurrentAge;
}

void Person::CalculateAge()
{
    CurrentAge = DateMath::CalculateYears(BirthDate);
}

void Person::DaysTillBirthday()
{
    fmt::print("\nDays left until birthday: {0}\n", DateMath::DaysUntilDate(BirthDate));
}