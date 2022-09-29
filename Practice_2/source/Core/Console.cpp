#include "Console.h"

#include "Person/Person.h"
#include "Core/Log.h"
#include "Input/Input.h"

void test()
{
    Person P("Seb", "Ter", {2000, DateMath::Months::March, 23});
    CLI_WARN("DAYS UNTIL = {0}", P.DaysTillBirthday());
}

void mainLoop()
{
    std::string name = "";
    std::string surname = "";
    int year = 0, month = 0, day = 0;
    int currentYear = DateMath::getMaxYear();

    CLI_TRACE("Enter name: ");
    name = GIBS_NW();
    CLI_TRACE("Enter surname: ");
    surname = GIBS_NW();
    CLI_TRACE("Enter Date of Birth");
    CLI_TRACE("Enter Birth Year ({0}-{1}): ", currentYear - 110, currentYear);
    year = GIBI(1900, currentYear);
    bool isLeap = DateMath::isLeapYear(year);
    if (year == currentYear)
    {
        int currentMonth = DateMath::getMaxMonth();
        int currentDays = DateMath::getMaxDay();
        CLI_TRACE("Enter Birth Month (1-{0}): ", currentMonth);
        month = GIBI(1, currentMonth);
        month--;
        if (month + 1 == currentMonth)
        {
            CLI_TRACE("{0} {1}-{2}: ", DateMath::monthsEnumToText(static_cast<DateMath::Months>(month - 1)), 1, currentDays);
            day = GIBI(1, currentDays);
        }
        else
        {
            CLI_TRACE("{0} {1}-{2}: ", DateMath::monthsEnumToText(static_cast<DateMath::Months>(month)), 1, DateMath::MonthDays[month]);
            day = GIBI(1, DateMath::MonthDays[month - 1]);
        }
    }
    else
    {
        CLI_TRACE("Enter Birth Month (1-12): ");
        month = GIBI(1, 12);
        month--;
        CLI_TRACE("Enter Birth Day (1-31): ");
        switch (month)
        {
        case DateMath::Months::February:
            if (isLeap)
            {
                CLI_TRACE("{0} {1}-{2}: ", DateMath::monthsEnumToText(static_cast<DateMath::Months>(month)), 1, DateMath::MonthDays[month] + 1);
                day = GIBI(1, DateMath::MonthDays[month] + 1);
                break;
            }
            else
            {
                CLI_TRACE("{0} {1}-{2}: ", DateMath::monthsEnumToText(static_cast<DateMath::Months>(month)), 1, DateMath::MonthDays[month]);
                day = GIBI(1, DateMath::MonthDays[month]);
                break;
            }
            break;
        default:
            CLI_TRACE("{0} {1}-{2}: ", DateMath::monthsEnumToText(static_cast<DateMath::Months>(month)), 1, DateMath::MonthDays[month]);
            day = GIBI(1, DateMath::MonthDays[month]);
            break;
        }
    }

    Person P(name, surname, {year, static_cast<DateMath::Months>(month), day});

    while (true)
    {
        CLI_TRACE(" 0. To exit; 1. Print person (all) information; 2. Print specific person information; 3. Print person age; 4. Print days until person's birthday;");
        switch (GIBI(0, 4))
        {
        case 0:
            return;
        case 1:
            CLI_INFO("Name: {0}; Surname: {1}; Age: {2};", P.GetName(), P.GetSurname(), P.GetAge());
            break;
        case 2:
            CLI_TRACE(" 0. Return; 1. Name; 2. Surname; 3. Age;");
            switch (GIBI(0, 3))
            {
            case 0:
                break;
            case 1:
                CLI_INFO("{0}", P.GetName());
                break;
            case 2:
                CLI_INFO("{0}", P.GetSurname());
                break;
            case 3:
                CLI_INFO("{0}", P.GetAge());
                break;
            }
            break;
        case 3:
            CLI_INFO(" Person's age: {0}", P.GetAge());
            break;
        case 4:
            CLI_INFO("Days left until birthday: {0}", P.DaysTillBirthday());
            break;
        }
    }
}
