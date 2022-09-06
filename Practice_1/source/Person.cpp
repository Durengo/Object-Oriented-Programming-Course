#include "Person.h"

#include <iostream>
#include <ctime>

Person::Person(const std::string& firstName, const std::string& lastName, DateOfBirth& birthday)
: FirstName(firstName), LastName(lastName), BirthDate(birthday)
{

}

int Person::Age()
{
    time_t now = time(0);
    char* dt = ctime(&now);

    std::cout << dt;

    return BirthDate.Year;
}