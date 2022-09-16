#include "Console.h"
#include "Input.h"
#include "Person.h"

#include <fmt/core.h>
#define print fmt::print

void test()
{
    Person P("Seb", "Ter", {2000, DateMath::Months::March, 23});
    P.DaysTillBirthday();
}

void mainLoop()
{
    std::string name = "";
    std::string surname = "";
    int year = 0, month = 0, day = 0;
    int currentYear = DateMath::getMaxYear();

    print("\nEnter name: ");
    // std::cin >> name;
    name = GIBS_NW();
    print("\nEnter surname: ");
    surname = GIBS_NW();
    print("\nEnter Date of Birth");
    print("\nEnter Birth Year ({0}-{1}): ", currentYear - 110, currentYear);
    year = GIBI(1900, currentYear);
    bool isLeap = DateMath::isLeapYear(year);
    if (year == currentYear)
    {
        int currentMonth = DateMath::getMaxMonth();
        int currentDays = DateMath::getMaxDay();
        print("\nEnter Birth Month (1-{0}): ", currentMonth);
        month = GIBI(1, currentMonth);
        month--;
        switch (month)
        {
        case 0:
            if (month + 1 == currentMonth)
            {
                print("\nJanuary {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nJanuary {0}-{1}: ", 1, DateMath::MonthDays::JANUARY);
                day = GIBI(1, DateMath::MonthDays::JANUARY);
                break;
            }
        case 1:
            if (month + 1 == currentMonth)
            {
                print("\nFebruary {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nFebruary {0}-{1}: ", 1, DateMath::MonthDays::FEBRUARY);
                day = GIBI(1, DateMath::MonthDays::FEBRUARY);
                break;
            }
        case 2:
            if (month + 1 == currentMonth)
            {
                print("\nMarch {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nMarch {0}-{1}: ", 1, DateMath::MonthDays::MARCH);
                day = GIBI(1, DateMath::MonthDays::MARCH);
                break;
            }
        case 3:
            if (month + 1 == currentMonth)
            {
                print("\nApril {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nApril {0}-{1}: ", 1, DateMath::MonthDays::APRIL);
                day = GIBI(1, DateMath::MonthDays::APRIL);
                break;
            }

        case 4:
            if (month + 1 == currentMonth)
            {
                print("\nMay {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nMay {0}-{1}: ", 1, DateMath::MonthDays::MAY);
                day = GIBI(1, DateMath::MonthDays::MAY);
                break;
            }

        case 5:
            if (month + 1 == currentMonth)
            {
                print("\nJune {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nJune {0}-{1}: ", 1, DateMath::MonthDays::JUNE);
                day = GIBI(1, DateMath::MonthDays::JUNE);
                break;
            }

        case 6:
            if (month + 1 == currentMonth)
            {
                print("\nJuly {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nJuly {0}-{1}: ", 1, DateMath::MonthDays::JULY);
                day = GIBI(1, DateMath::MonthDays::JULY);
                break;
            }

        case 7:
            if (month + 1 == currentMonth)
            {
                print("\nAugust {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nAugust {0}-{1}: ", 1, DateMath::MonthDays::AUGUST);
                day = GIBI(1, DateMath::MonthDays::AUGUST);
                break;
            }

        case 8:
            if (month + 1 == currentMonth)
            {
                print("\nSeptember {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nSeptember {0}-{1}: ", 1, DateMath::MonthDays::SEPTEMBER);
                day = GIBI(1, DateMath::MonthDays::SEPTEMBER);
                break;
            }

        case 9:
            if (month + 1 == currentMonth)
            {
                print("\nOctober {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nOctober {0}-{1}: ", 1, DateMath::MonthDays::OCTOBER);
                day = GIBI(1, DateMath::MonthDays::OCTOBER);
                break;
            }

        case 10:
            if (month + 1 == currentMonth)
            {
                print("\nNovember {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nNovember {0}-{1}: ", 1, DateMath::MonthDays::NOVEMBER);
                day = GIBI(1, DateMath::MonthDays::NOVEMBER);
                break;
            }

        case 11:
            if (month + 1 == currentMonth)
            {
                print("\nDecember {0}-{1}: ", 1, currentDays);
                day = GIBI(1, currentDays);
                break;
            }
            else
            {
                print("\nDecember {0}-{1}: ", 1, DateMath::MonthDays::DECEMBER);
                day = GIBI(1, DateMath::MonthDays::DECEMBER);
                break;
            }

        default:
            print("\nEXCEPTION!\n");
            return;
        }
    }
    else
    {
        print("\nEnter Birth Month (1-12): ");
        month = GIBI(1, 12);
        month--;
        print("\nEnter Birth Day (1-31): ");
        switch (month)
        {
        case 0:
            print("\nJanuary {0}-{1}: ", 1, DateMath::MonthDays::JANUARY);
            day = GIBI(1, DateMath::MonthDays::JANUARY);
            break;
        case 1:
            if (isLeap)
            {
                print("\nFebruary {0}-{1}: ", 1, DateMath::MonthDays::FEBRUARY + 1);
                day = GIBI(1, DateMath::MonthDays::FEBRUARY + 1);
                break;
            }
            else
            {
                print("\nFebruary {0}-{1}: ", 1, DateMath::MonthDays::FEBRUARY);
                day = GIBI(1, DateMath::MonthDays::FEBRUARY);
                break;
            }
        case 2:
            print("\nMarch {0}-{1}: ", 1, DateMath::MonthDays::MARCH);
            day = GIBI(1, DateMath::MonthDays::MARCH);
            break;
        case 3:
            print("\nApril {0}-{1}: ", 1, DateMath::MonthDays::APRIL);
            day = GIBI(1, DateMath::MonthDays::APRIL);
            break;
        case 4:
            print("\nMay {0}-{1}: ", 1, DateMath::MonthDays::MAY);
            day = GIBI(1, DateMath::MonthDays::MAY);
            break;
        case 5:
            print("\nJune {0}-{1}: ", 1, DateMath::MonthDays::JUNE);
            day = GIBI(1, DateMath::MonthDays::JUNE);
            break;
        case 6:
            print("\nJuly {0}-{1}: ", 1, DateMath::MonthDays::JULY);
            day = GIBI(1, DateMath::MonthDays::JULY);
            break;
        case 7:
            print("\nAugust {0}-{1}: ", 1, DateMath::MonthDays::AUGUST);
            day = GIBI(1, DateMath::MonthDays::AUGUST);
            break;
        case 8:
            print("\nSeptember {0}-{1}: ", 1, DateMath::MonthDays::SEPTEMBER);
            day = GIBI(1, DateMath::MonthDays::SEPTEMBER);
            break;
        case 9:
            print("\nOctober {0}-{1}: ", 1, DateMath::MonthDays::OCTOBER);
            day = GIBI(1, DateMath::MonthDays::OCTOBER);
            break;
        case 10:
            print("\nNovember {0}-{1}: ", 1, DateMath::MonthDays::NOVEMBER);
            day = GIBI(1, DateMath::MonthDays::NOVEMBER);
            break;
        case 11:
            print("\nDecember {0}-{1}: ", 1, DateMath::MonthDays::DECEMBER);
            day = GIBI(1, DateMath::MonthDays::DECEMBER);
            break;
        default:
            print("\nEXCEPTION!\n");
            return;
        }
    }

    Person P(name, surname, {year, static_cast<DateMath::Months>(month), day});

    while (true)
    {
        print("\n 0. To exit; 1. Print person (all) information; 2. Print specific person information; 3. Print person age; 4. Print days until person's birthday;");
        switch (GIBI(0, 4))
        {
        case 0:
            return;
        case 1:
            print("\nName: {0}; Surname: {1}; Age: {2};", P.GetName(), P.GetSurname(), P.GetAge());
            break;
        case 2:
            print("\n 0. Return; 1. Name; 2. Surname; 3. Age;");
            switch (GIBI(0, 3))
            {
            case 0:
                break;
            case 1:
                print("\n{0}", P.GetName());
                break;
            case 2:
                print("\n{0}", P.GetSurname());
                break;
            case 3:
                print("\n{0}", P.GetAge());
                break;
            }
            break;
        case 3:
            print("\n Person's age: {0}", P.GetAge());
            break;
        case 4:
            P.DaysTillBirthday();
            break;
        }
    }
}

