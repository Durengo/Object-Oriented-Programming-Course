#pragma once

#include <ctime>
#include <fmt/core.h>

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
        January = 0,
        February = 1,
        March = 2,
        April = 3,
        May = 4,
        June = 5,
        July = 6,
        August = 7,
        September = 8,
        October = 9,
        November = 10,
        December = 11
    };

    struct DateYMD
    {
        int Year;
        Months Month;
        int Day;

        DateYMD(int year, Months month, int day) : Year(year), Month(month), Day(day) {}
    };

    static bool isLeapYear(int year)
    {
        return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

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

        int year = 1900 + localTime->tm_year;
        bool isLeap = isLeapYear(year);
        fmt::print("Y: {0}\n", year);

        if (Date.Month == localTime->tm_mon && Date.Day == localTime->tm_mday)
        {
            return totalDays;
        }
        if (Date.Month == localTime->tm_mon && Date.Day > localTime->tm_mday)
        {
            totalDays = Date.Day - localTime->tm_mday;
            return totalDays;
        }
        if (Date.Month == localTime->tm_mon && Date.Day < localTime->tm_mday)
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
                    if(isLeap) totalDays++;
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
        if (Date.Month < localTime->tm_mon)
        {
            fmt::print("{0}\n", totalDays);
            switch (localTime->tm_mon)
            {
            case 0:
                totalDays += JANUARY - localTime->tm_mday;
                break;
            case 1:
                if(isLeap) totalDays++;
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
            fmt::print("{0}\n", totalDays);
            for (int i = localTime->tm_mon + 1; i != 12; i++)
            {
                switch (i)
                {
                case 0:
                    totalDays += JANUARY;
                    break;
                case 1:
                    if(isLeap) totalDays++;
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
            fmt::print("{0}\n", totalDays);
            int icount = 0;
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
                    if(isLeap) totalDays++;
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
            fmt::print("{0}\n", totalDays);
            totalDays += Date.Day;
            fmt::print("{0}\n", totalDays);
            return totalDays;
        }
        if (Date.Month > localTime->tm_mon)
        {
            switch (localTime->tm_mon)
            {
            case 0:
                totalDays += JANUARY - localTime->tm_mday;
                break;
            case 1:
                if(isLeap) totalDays++;
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
            int icount = 0;
            for (int i = localTime->tm_mon + 1; i != Date.Month; i++)
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
                    if(isLeap) totalDays++;
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