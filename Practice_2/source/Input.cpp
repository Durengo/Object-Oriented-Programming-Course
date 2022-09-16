#include "Input.h"

#include <iostream>
#include <string_view>
#include <algorithm>

#include <fmt/core.h>
#define print fmt::print

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

std::string GIBS_NW()
{
    std::string input;
    bool valid = false;
    do
    {
        std::getline(std::cin, input);
        valid = validateName(input);
        if (!valid)
        {
            print("THIS DATA CANNOT HAVE:\n 1. MORE THAN ONE CAPITAL LETTER AND ONLY AT THE START;\n 2. ANY NUMBERS OR SYMBOLS;\n 3. WHITESPACE\nTry again: ");
        }
    } while (!valid);
    std::cin.clear();
    // print("VALID = {0}\n", valid);
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

bool validateName(const std::string &name)
{
    if (name != "" && isLetters(name) && oneCapital(name))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLetters(const std::string_view &name)
{
    return all_of(name.begin(), name.end(), [](char ch)
                  { return (isalpha(ch)); });
}

bool oneCapital(const std::string &name)
{
    int cCount = 0;
    for (std::size_t i{}; i < name.length() && cCount < name.length(); i++)
    {
        // print("NAME[{0}] = {1}; UPPER[{0}] = {2}\n", i, name[i], toupper(name.c_str()[i]));
        switch (cCount)
        {
        case 0:
            if (name[0] != toupper(name.c_str()[0]))
            {
                print("FIRST LETTER IS NOT CAPITAL.\n");
                return false;
            }
            cCount++;
            break;
        default:
            if (name[i] == toupper(name.c_str()[i]))
            {
                print("MORE THAN ONE CAPITAL LETTER.\n");
                return false;
            }
            cCount++;
            break;
        }
    }
    return true;
}