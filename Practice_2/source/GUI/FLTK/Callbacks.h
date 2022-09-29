#pragma once

#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>
#include "Fl_Widget_Wrapper.h"
#include "Person/Person.h"
#include "Input/Validation.h"

#include "Core/Log.h"

namespace CB
{
    inline void printSomethingToConsole(const char *text)
    {
        CLI_INFO("{0}", text);
    }

    inline void toggleTextVisibility(bool &conditionState, int buttonTrackerSize, std::vector<Fl_Text_Display *> text)
    {
        CLI_ERROR("FUNC CALLED.");
        if (buttonTrackerSize != 1)
        {
            CLI_ASSERT(0, "CANNOT CALL THIS CALLBACK WHEN MORE THAN 2 OR 0 BUTTONS IN AN INSTANCE OF A SINGULAR LAYER LOGIC");
            return;
        }
        if (conditionState)
        {
            for (int i = 0; i < text.size(); i++)
            {
                text[i]->show();
            }
            conditionState = false;
        }
        else
        {
            for (int i = 0; i < text.size(); i++)
            {
                text[i]->hide();
            }
            conditionState = true;
        }
    }

    inline void copy_input_to_output(std::vector<Fl_Input *> input, std::vector<Fl_Output *> output)
    {
        for (int i = 0; i < input.size(); i++)
        {
            output[i]->value(input[i]->value());
        }
    }

    inline void reset_input_and_output(std::vector<Fl_Input *> input, std::vector<Fl_Output *> output)
    {
        for (int i = 0; i < input.size(); i++)
        {
            input[i]->value("");
        }
        for (int i = 0; i < output.size(); i++)
        {
            output[i]->value("");
        }
    }
    inline void reset_input_and_output_hide_box_and_text(std::vector<Fl_Input *> input, std::vector<Fl_Output *> output, std::vector<Fl_Box *> box, std::vector<Fl_Text_Display *> text)
    {
        for (int i = 0; i < input.size(); i++)
        {
            input[i]->value("");
        }
        for (int i = 0; i < output.size(); i++)
        {
            output[i]->value("");
        }
        for (int i = 0; i < box.size(); i++)
        {
            if (box[i]->visible_r())
            {
                box[i]->hide();
            }
        }
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i]->visible_r())
            {
                text[i]->hide();
            }
        }
    }

    inline void person_copy_parse_paste(std::vector<Fl_Input *> input, std::vector<Fl_Output *> output, std::vector<Fl_Box *> box, std::vector<Fl_Text_Display *> text, Person *person)
    {
        if (input.size() < 5 || input.size() > 5)
        {
            CLI_ASSERT(0, "NOT ENOUGH INPUTS PROVIDED FOR CALLBACK");
            return;
        }
        if (output.size() > 7 || output.size() < 7)
        {
            CLI_ASSERT(0, "NOT ENOUGH OUTPUTS PROVIDED FOR CALLBACK");
            return;
        }
        if (box.size() > 5 || box.size() < 5)
        {
            CLI_ASSERT(0, "NOT ENOUGH BOXES PROVIDED FOR CALLBACK");
            return;
        }
        if (text.size() > 5 || text.size() < 5)
        {
            CLI_ASSERT(0, "NOT ENOUGH TEXTS PROVIDED FOR CALLBACK");
            return;
        }
        if (person != nullptr)
        {
            Person *temp = person;
            person = nullptr;
            delete (temp);
        }

        bool invalid1 = false;
        bool invalid2 = false;
        bool invalid3 = false;
        bool invalid4 = false;
        bool invalid5 = false;
        int currentYear = DateMath::getMaxYear();
        int currentMonth = DateMath::getMaxMonth();
        int currentDays = DateMath::getMaxDay();

        std::string name = STOS_CON(input[0]->value());
        if (name == "-1")
        {
            CLI_TRACE("INPUT INVALID : {0}", name);

            text[0]->show();
            box[0]->show();
            invalid1 = true;
        }
        std::string surname = STOS_CON(input[1]->value());
        if (surname == "-1")
        {
            CLI_TRACE("INPUT INVALID : {0}", surname);
            text[1]->show();
            box[1]->show();
            invalid2 = true;
        }

        int year = STOI(currentYear - 110, currentYear, input[2]->value());
        if (year == -1)
        {
            CLI_TRACE("INPUT INVALID : {0}", year);
            text[2]->show();
            box[2]->show();
            invalid3 = true;
        }
        int month = 0, day = 0;

        bool isLeap = DateMath::isLeapYear(year);

        if (year == currentYear)
        {
            month = STOI(1, DateMath::getMaxMonth(), input[3]->value());
            if (month == -1)
            {
                CLI_TRACE("INPUT INVALID : {0}", month);
                text[3]->show();
                box[3]->show();
                invalid4 = true;
            }
            else if (month == currentMonth)
            {
                day = STOI(1, currentDays, input[4]->value());
                if (day == -1)
                {
                    CLI_TRACE("INPUT INVALID : {0}", day);
                    text[4]->show();
                    box[4]->show();
                    invalid5 = true;
                }
            }
            else
            {
                month--;
                day = STOI(1, DateMath::MonthDays[month], input[4]->value());
            }
        }
        else
        {
            month = STOI(1, 12, input[3]->value());
            if (month == -1)
            {
                CLI_TRACE("INPUT INVALID : {0}", month);
                text[3]->show();
                box[3]->show();
                invalid4 = true;
                int temp = STOI(1, currentDays, input[4]->value());
                if (temp == -1)
                {
                    CLI_TRACE("INPUT INVALID : {0}", day);
                    text[4]->show();
                    box[4]->show();
                    invalid5 = true;
                }
            }
            else
            {
                month--;
                switch (month)
                {
                case DateMath::Months::February:
                    if (isLeap)
                    {
                        day = STOI(1, DateMath::MonthDays[month] + 1, input[4]->value());
                        break;
                    }
                    else
                    {
                        day = STOI(1, DateMath::MonthDays[month], input[4]->value());
                        break;
                    }
                default:
                    day = STOI(1, DateMath::MonthDays[month], input[4]->value());
                    break;
                }
                if (day == -1)
                {
                    CLI_TRACE("INPUT INVALID : {0}", day);
                    text[4]->show();
                    box[4]->show();
                    invalid5 = true;
                }
            }
        }

        if (!invalid1)
        {
            text[0]->hide();
            box[0]->hide();
        }
        if (!invalid2)
        {
            text[1]->hide();
            box[1]->hide();
        }
        if (!invalid3)
        {
            text[2]->hide();
            box[2]->hide();
        }
        if (!invalid4)
        {
            text[3]->hide();
            box[3]->hide();
        }
        if (!invalid5)
        {
            text[4]->hide();
            box[4]->hide();
        }

        CLI_INFO("NAME: {0}; SURNAME: {1}; YEAR: {2}; MONTH: {3}; DAY: {4}", name, surname, year, month, day);

        if (!invalid1 && !invalid2 && !invalid3 && !invalid4 && !invalid5)
        {
            person = new Person(name, surname, {year, static_cast<DateMath::Months>(month), day});

            output[0]->value(person->GetName().c_str());
            output[1]->value(person->GetSurname().c_str());
            output[2]->value(std::to_string(person->GetBirthDate().Year).c_str());
            output[3]->value(std::to_string(person->GetBirthDate().Month + 1).c_str());
            output[4]->value(std::to_string(person->GetBirthDate().Day).c_str());
            output[5]->value(std::to_string(person->GetAge()).c_str());
            output[6]->value(std::to_string(person->DaysTillBirthday()).c_str());
        }
        else
        {
            output[0]->value("");
            output[1]->value("");
            output[2]->value("");
            output[3]->value("");
            output[4]->value("");
            output[5]->value("");
            output[6]->value("");
        }

        if (person == nullptr)
        {
            CLI_INFO("PERSON = NULLPTR");
        }
        else
        {
            CLI_INFO("PERSON = NOT NULLPTR");
        }
    }
}