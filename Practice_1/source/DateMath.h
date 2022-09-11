#pragma once

#include <ctime>

namespace DateMath
{

#define JANUARY 31
#define FEBRUARY 28
#define MARCH 31
#define APRIL 30
#define MAY 31
#define JUNE 30
#define JULY 31
#define AUGUST 31
#define SEPTEMBER 30
#define OCTOBER 31
#define NOVEMBER 30
#define DECEMBER 31

    enum Months
    {
        None = 0,
        January = 1,
        February = 2,
        March = 3,
        April = 4,
        May = 5,
        June = 6,
        July = 7,
        August = 8,
        September = 9,
        October = 10,
        November = 11,
        December = 12
    };

    struct DateYMD
    {
        int Year;
        Months Month;
        int Day;

        DateYMD(int year, Months month, int day) : Year(year), Month(month), Day(day) {}
    };

    static int CalculateYears(DateYMD Date)
    {
        std::time_t t = std::time(nullptr);
        std::tm *const localTime = std::localtime(&t);

        int day = localTime->tm_mday - Date.Day;
        int month = (localTime->tm_mon + 1) - Date.Month;
        int year = (1900 + localTime->tm_year) - Date.Year;

        if (day < 0)
        {
            month = month - 1;
        }
        if (month < 0)
        {
            year = year - 1;
        }

        return year;
    }

    static int DaysUntilDate(DateYMD Date)
    {
        std::time_t t = std::time(nullptr);
        std::tm *const localTime = std::localtime(&t);
        int totalDays = 0;

        if (Date.Month == localTime->tm_mon + 1 && Date.Day == localTime->tm_mday)
        {
            return totalDays;
        }
        if (Date.Month == localTime->tm_mon + 1 && Date.Day > localTime->tm_mday)
        {
            totalDays = Date.Day - localTime->tm_mday;
            return totalDays;
        }
        if (Date.Month == localTime->tm_mon + 1 && Date.Day < localTime->tm_mday)
        {
            int icount = 0;
            for (int i = localTime->tm_mon; icount != 12; i++)
            {
                if (i == 12)
                {
                    i = 0;
                }
                switch (i)
                {
                case 0:
                    totalDays += JANUARY;
                    break;
                case 1:
                    totalDays += FEBRUARY;
                    break;
                case 2:
                    totalDays += MARCH;
                    break;
                case 3:
                    totalDays += APRIL;
                    break;
                case 4:
                    totalDays += MAY;
                    break;
                case 5:
                    totalDays += JUNE;
                    break;
                case 6:
                    totalDays += JULY;
                    break;
                case 7:
                    totalDays += AUGUST;
                    break;
                case 8:
                    totalDays += SEPTEMBER;
                    break;
                case 9:
                    totalDays += OCTOBER;
                    break;
                case 10:
                    totalDays += NOVEMBER;
                    break;
                case 11:
                    totalDays += DECEMBER;
                    break;
                default:
                    break;
                }
                icount++;
            }
            totalDays += Date.Day - localTime->tm_mday;
            return totalDays;
        }
        if (Date.Month < localTime->tm_mon + 1)
        {
            switch (localTime->tm_mon)
            {
            case 0:
                totalDays += JANUARY - localTime->tm_mday;
                break;
            case 1:
                totalDays += FEBRUARY - localTime->tm_mday;
                break;
            case 2:
                totalDays += MARCH - localTime->tm_mday;
                break;
            case 3:
                totalDays += APRIL - localTime->tm_mday;
                break;
            case 4:
                totalDays += MAY - localTime->tm_mday;
                break;
            case 5:
                totalDays += JUNE - localTime->tm_mday;
                break;
            case 6:
                totalDays += JULY - localTime->tm_mday;
                break;
            case 7:
                totalDays += AUGUST - localTime->tm_mday;
                break;
            case 8:
                totalDays += SEPTEMBER - localTime->tm_mday;
                break;
            case 9:
                totalDays += OCTOBER - localTime->tm_mday;
                break;
            case 10:
                totalDays += NOVEMBER - localTime->tm_mday;
                break;
            case 11:
                totalDays += DECEMBER - localTime->tm_mday;
                break;
            default:
                break;
            }
            for (int i = localTime->tm_mon + 1; i != 12; i++)
            {
                switch (i)
                {
                case 0:
                    totalDays += JANUARY;
                    break;
                case 1:
                    totalDays += FEBRUARY;
                    break;
                case 2:
                    totalDays += MARCH;
                    break;
                case 3:
                    totalDays += APRIL;
                    break;
                case 4:
                    totalDays += MAY;
                    break;
                case 5:
                    totalDays += JUNE;
                    break;
                case 6:
                    totalDays += JULY;
                    break;
                case 7:
                    totalDays += AUGUST;
                    break;
                case 8:
                    totalDays += SEPTEMBER;
                    break;
                case 9:
                    totalDays += OCTOBER;
                    break;
                case 10:
                    totalDays += NOVEMBER;
                    break;
                case 11:
                    totalDays += DECEMBER;
                    break;
                default:
                    break;
                }
            }
            int icount = 1;
            for (int i = 0; icount != Date.Month; i++)
            {
                if (i == 12)
                {
                    i = 0;
                }
                switch (i)
                {
                case 0:
                    totalDays += JANUARY;
                    break;
                case 1:
                    totalDays += FEBRUARY;
                    break;
                case 2:
                    totalDays += MARCH;
                    break;
                case 3:
                    totalDays += APRIL;
                    break;
                case 4:
                    totalDays += MAY;
                    break;
                case 5:
                    totalDays += JUNE;
                    break;
                case 6:
                    totalDays += JULY;
                    break;
                case 7:
                    totalDays += AUGUST;
                    break;
                case 8:
                    totalDays += SEPTEMBER;
                    break;
                case 9:
                    totalDays += OCTOBER;
                    break;
                case 10:
                    totalDays += NOVEMBER;
                    break;
                case 11:
                    totalDays += DECEMBER;
                    break;
                default:
                    break;
                }
                icount++;
            }
            totalDays += Date.Day;
            return totalDays;
        }
        if (Date.Month > localTime->tm_mon + 1)
        {
            switch (localTime->tm_mon)
            {
            case 0:
                totalDays += JANUARY - localTime->tm_mday;
                break;
            case 1:
                totalDays += FEBRUARY - localTime->tm_mday;
                break;
            case 2:
                totalDays += MARCH - localTime->tm_mday;
                break;
            case 3:
                totalDays += APRIL - localTime->tm_mday;
                break;
            case 4:
                totalDays += MAY - localTime->tm_mday;
                break;
            case 5:
                totalDays += JUNE - localTime->tm_mday;
                break;
            case 6:
                totalDays += JULY - localTime->tm_mday;
                break;
            case 7:
                totalDays += AUGUST - localTime->tm_mday;
                break;
            case 8:
                totalDays += SEPTEMBER - localTime->tm_mday;
                break;
            case 9:
                totalDays += OCTOBER - localTime->tm_mday;
                break;
            case 10:
                totalDays += NOVEMBER - localTime->tm_mday;
                break;
            case 11:
                totalDays += DECEMBER - localTime->tm_mday;
                break;
            default:
                break;
            }
            int icount = 1;
            for (int i = localTime->tm_mon + 1; i != Date.Month - 1; i++)
            {
                if (i == 12)
                {
                    i = 0;
                }
                switch (i)
                {
                case 0:
                    totalDays += JANUARY;
                    break;
                case 1:
                    totalDays += FEBRUARY;
                    break;
                case 2:
                    totalDays += MARCH;
                    break;
                case 3:
                    totalDays += APRIL;
                    break;
                case 4:
                    totalDays += MAY;
                    break;
                case 5:
                    totalDays += JUNE;
                    break;
                case 6:
                    totalDays += JULY;
                    break;
                case 7:
                    totalDays += AUGUST;
                    break;
                case 8:
                    totalDays += SEPTEMBER;
                    break;
                case 9:
                    totalDays += OCTOBER;
                    break;
                case 10:
                    totalDays += NOVEMBER;
                    break;
                case 11:
                    totalDays += DECEMBER;
                    break;
                default:
                    break;
                }
                icount++;
            }
            totalDays += Date.Day;
            return totalDays;
        }
    }

}