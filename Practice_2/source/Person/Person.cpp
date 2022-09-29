#include "Person.h"

// Person::Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD &birthday)
//     : FirstName(firstName), LastName(lastName), BirthDate(birthday)
// {
//     CalculateAge();
// }

Person::Person(const std::string &firstName, const std::string &lastName, DateMath::DateYMD birthday)
    : FirstName(firstName), LastName(lastName), BirthDate(birthday)
{
    CalculateAge();
}

void Person::CalculateAge()
{
    CurrentAge = DateMath::CalculateYears(BirthDate);
}

int Person::DaysTillBirthday()
{
    return DateMath::DaysUntilDate(BirthDate);
}