#include "Console.h"

#include <iostream>
#include "Person.h"
#include <fmt/core.h>

#define print fmt::print

void test()
{
    Person P("Seb", "Ter", {2000, DateMath::Months::December, 31});
    P.DaysTillBirthday();
}

void mainLoop()
{
    std::string name = "";
    std::string surname = "";
    int year = 0, month = 0, day = 0;

    print("\nEnter name: ");
    std::cin >> name;
    print("\nEnter surname: ");
    std::cin >> surname;
    print("\nEnter Date of Birth");
    print("\nEnter Birth Year (1900-2022): ");
    year = GIBI(1900, 2022);

    print("\nEnter Birth Month (1-12): ");
    month = GIBI(1, 12);
    month--;
    print("\nEnter Birth Day (1-31): ");
    switch (month)
    {
    case 0:
        print("\nJanuary {0}-{1}: ", 1, JANUARY);
        day = GIBI(1, JANUARY);
        break;
    case 1:
        print("\nFebruary {0}-{1}: ", 1, FEBRUARY);
        day = GIBI(1, FEBRUARY);
        break;
    case 2:
        print("\nMarch {0}-{1}: ", 1, MARCH);
        day = GIBI(1, MARCH);
        break;
    case 3:
        print("\nApril {0}-{1}: ", 1, APRIL);
        day = GIBI(1, APRIL);
        break;
    case 4:
        print("\nMay {0}-{1}: ", 1, MAY);
        day = GIBI(1, MAY);
        break;
    case 5:
        print("\nJune {0}-{1}: ", 1, JUNE);
        day = GIBI(1, JUNE);
        break;
    case 6:
        print("\nJuly {0}-{1}: ", 1, JULY);
        day = GIBI(1, JULY);
        break;
    case 7:
        print("\nAugust {0}-{1}: ", 1, AUGUST);
        day = GIBI(1, AUGUST);
        break;
    case 8:
        print("\nSeptember {0}-{1}: ", 1, SEPTEMBER);
        day = GIBI(1, SEPTEMBER);
        break;
    case 9:
        print("\nOctober {0}-{1}: ", 1, OCTOBER);
        day = GIBI(1, OCTOBER);
        break;
    case 10:
        print("\nNovember {0}-{1}: ", 1, NOVEMBER);
        day = GIBI(1, NOVEMBER);
        break;
    case 11:
        print("\nDecember {0}-{1}: ", 1, DECEMBER);
        day = GIBI(1, DECEMBER);
        break;
    default:
        print("\nEXCEPTION!\n");
        return;
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

    std::cout << P.GetAge() << "\n";
    P.DaysTillBirthday();

    GIBI(1, 3);
}

int GIBI()
{
    std::string input;
    int converted;
    while (true)
    {
        std::cin >> input;
        try
        {
            converted = std::stoi(input);
            break;
        }
        catch (std::invalid_argument &i)
        {
            print("{0}", i.what());
            print("\n!EXCEPTION!\n");
            print("\n!EXCEPTION!\n !STOI INVALID ARGUMENT!: ", input, "\n");
        }
        catch (std::out_of_range &i)
        {
            print("{0}", i.what());
            print("\n!EXCEPTION!\n");
            print("\n!EXCEPTION!\n !STOI OUT OF RANGE!: ", input, "\n");
        }
    }
    return converted;
}

int GIBI(int min, int max)
{
    while (true)
    {
        int input = GIBI();
        if (input >= min && input <= max)
        {
            return input;
        }
        else
        {
            print("!EXCEPTION!\n");
            print("\n!EXCEPTION!\n !OUT OF RANGE INPUT: ", input, " in", min, " ", max);
        }
    }
}

double GIBD()
{
    std::string input;
    double converted;
    while (true)
    {
        std::cin >> input;
        try
        {
            converted = std::stod(input);
            break;
        }
        catch (std::invalid_argument &i)
        {
            print("{0}", i.what());
            print("\n!EXCEPTION!\n");
            print("\n!EXCEPTION!\n !STOI INVALID ARGUMENT!: ", input, "\n");
        }
        catch (std::out_of_range &i)
        {
            print("{0}", i.what());
            print("\n!EXCEPTION!\n");
            print("\n!EXCEPTION!\n !STOI OUT OF RANGE!: ", input, "\n");
        }
    }
    return converted;
}

std::string GIBS()
{
    std::string input;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

std::string GIBSWW()
{
    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input;
}

int Get_Input_Yes_Or_No()
{
    while (true)
    {
        print("Answer with: (1) Yes; (0) No.\n");
        int input = GIBI(0, 1);

        switch (input)
        {
        case 0:
            print("\nNo selected!\n");
            return input;
        case 1:
            print("\nYes selected!\n");
            return input;
        default:
            print("\n!EXCEPTION!\n");
            break;
        }
    }
}