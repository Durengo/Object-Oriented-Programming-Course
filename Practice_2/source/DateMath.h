#pragma once

#include <ctime>

namespace DateMath
{
    enum MonthDays
    {
        JANUARY = 31,
        FEBRUARY = 28,
        MARCH = 31,
        APRIL = 30,
        MAY = 31,
        JUNE = 30,
        JULY = 31,
        AUGUST = 31,
        SEPTEMBER = 30,
        OCTOBER = 31,
        NOVEMBER = 30,
        DECEMBER = 31
    };

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

    static int getMaxYear()
    {
        std::time_t t = std::time(nullptr);
        std::tm *const localTime = std::localtime(&t);
        return 1900 + localTime->tm_year;
    }

    static int getMaxMonth()
    {
        std::time_t t = std::time(nullptr);
        std::tm *const localTime = std::localtime(&t);
        return (localTime->tm_mon + 1);
    }

    static int getMaxDay()
    {
        std::time_t t = std::time(nullptr);
        std::tm *const localTime = std::localtime(&t);
        return localTime->tm_mday;
    }

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
                    totalDays += MonthDays::JANUARY;
                    break;
                case 1:
                    if (isLeap)
                        totalDays++;
                    totalDays += MonthDays::FEBRUARY;
                    break;
                case 2:
                    totalDays += MonthDays::MARCH;
                    break;
                case 3:
                    totalDays += MonthDays::APRIL;
                    break;
                case 4:
                    totalDays += MonthDays::MAY;
                    break;
                case 5:
                    totalDays += MonthDays::JUNE;
                    break;
                case 6:
                    totalDays += MonthDays::JULY;
                    break;
                case 7:
                    totalDays += MonthDays::AUGUST;
                    break;
                case 8:
                    totalDays += MonthDays::SEPTEMBER;
                    break;
                case 9:
                    totalDays += MonthDays::OCTOBER;
                    break;
                case 10:
                    totalDays += MonthDays::NOVEMBER;
                    break;
                case 11:
                    totalDays += MonthDays::DECEMBER;
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
            switch (localTime->tm_mon)
            {
            case 0:
                totalDays += MonthDays::JANUARY - localTime->tm_mday;
                break;
            case 1:
                if (isLeap)
                    totalDays++;
                totalDays += MonthDays::FEBRUARY - localTime->tm_mday;
                break;
            case 2:
                totalDays += MonthDays::MARCH - localTime->tm_mday;
                break;
            case 3:
                totalDays += MonthDays::APRIL - localTime->tm_mday;
                break;
            case 4:
                totalDays += MonthDays::MAY - localTime->tm_mday;
                break;
            case 5:
                totalDays += MonthDays::JUNE - localTime->tm_mday;
                break;
            case 6:
                totalDays += MonthDays::JULY - localTime->tm_mday;
                break;
            case 7:
                totalDays += MonthDays::AUGUST - localTime->tm_mday;
                break;
            case 8:
                totalDays += MonthDays::SEPTEMBER - localTime->tm_mday;
                break;
            case 9:
                totalDays += MonthDays::OCTOBER - localTime->tm_mday;
                break;
            case 10:
                totalDays += MonthDays::NOVEMBER - localTime->tm_mday;
                break;
            case 11:
                totalDays += MonthDays::DECEMBER - localTime->tm_mday;
                break;
            default:
                break;
            }
            for (int i = localTime->tm_mon + 1; i != 12; i++)
            {
                switch (i)
                {
                case 0:
                    totalDays += MonthDays::JANUARY;
                    break;
                case 1:
                    if (isLeap)
                        totalDays++;
                    totalDays += MonthDays::FEBRUARY;
                    break;
                case 2:
                    totalDays += MonthDays::MARCH;
                    break;
                case 3:
                    totalDays += MonthDays::APRIL;
                    break;
                case 4:
                    totalDays += MonthDays::MAY;
                    break;
                case 5:
                    totalDays += MonthDays::JUNE;
                    break;
                case 6:
                    totalDays += MonthDays::JULY;
                    break;
                case 7:
                    totalDays += MonthDays::AUGUST;
                    break;
                case 8:
                    totalDays += MonthDays::SEPTEMBER;
                    break;
                case 9:
                    totalDays += MonthDays::OCTOBER;
                    break;
                case 10:
                    totalDays += MonthDays::NOVEMBER;
                    break;
                case 11:
                    totalDays += MonthDays::DECEMBER;
                    break;
                default:
                    break;
                }
            }
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
                    totalDays += MonthDays::JANUARY;
                    break;
                case 1:
                    if (isLeap)
                        totalDays++;
                    totalDays += MonthDays::FEBRUARY;
                    break;
                case 2:
                    totalDays += MonthDays::MARCH;
                    break;
                case 3:
                    totalDays += MonthDays::APRIL;
                    break;
                case 4:
                    totalDays += MonthDays::MAY;
                    break;
                case 5:
                    totalDays += MonthDays::JUNE;
                    break;
                case 6:
                    totalDays += MonthDays::JULY;
                    break;
                case 7:
                    totalDays += MonthDays::AUGUST;
                    break;
                case 8:
                    totalDays += MonthDays::SEPTEMBER;
                    break;
                case 9:
                    totalDays += MonthDays::OCTOBER;
                    break;
                case 10:
                    totalDays += MonthDays::NOVEMBER;
                    break;
                case 11:
                    totalDays += MonthDays::DECEMBER;
                    break;
                default:
                    break;
                }
                icount++;
            }
            totalDays += Date.Day;
            return totalDays;
        }
        if (Date.Month > localTime->tm_mon)
        {
            switch (localTime->tm_mon)
            {
            case 0:
                totalDays += MonthDays::JANUARY - localTime->tm_mday;
                break;
            case 1:
                if (isLeap)
                    totalDays++;
                totalDays += MonthDays::FEBRUARY - localTime->tm_mday;
                break;
            case 2:
                totalDays += MonthDays::MARCH - localTime->tm_mday;
                break;
            case 3:
                totalDays += MonthDays::APRIL - localTime->tm_mday;
                break;
            case 4:
                totalDays += MonthDays::MAY - localTime->tm_mday;
                break;
            case 5:
                totalDays += MonthDays::JUNE - localTime->tm_mday;
                break;
            case 6:
                totalDays += MonthDays::JULY - localTime->tm_mday;
                break;
            case 7:
                totalDays += MonthDays::AUGUST - localTime->tm_mday;
                break;
            case 8:
                totalDays += MonthDays::SEPTEMBER - localTime->tm_mday;
                break;
            case 9:
                totalDays += MonthDays::OCTOBER - localTime->tm_mday;
                break;
            case 10:
                totalDays += MonthDays::NOVEMBER - localTime->tm_mday;
                break;
            case 11:
                totalDays += MonthDays::DECEMBER - localTime->tm_mday;
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
                    totalDays += MonthDays::JANUARY;
                    break;
                case 1:
                    if (isLeap)
                        totalDays++;
                    totalDays += MonthDays::FEBRUARY;
                    break;
                case 2:
                    totalDays += MonthDays::MARCH;
                    break;
                case 3:
                    totalDays += MonthDays::APRIL;
                    break;
                case 4:
                    totalDays += MonthDays::MAY;
                    break;
                case 5:
                    totalDays += MonthDays::JUNE;
                    break;
                case 6:
                    totalDays += MonthDays::JULY;
                    break;
                case 7:
                    totalDays += MonthDays::AUGUST;
                    break;
                case 8:
                    totalDays += MonthDays::SEPTEMBER;
                    break;
                case 9:
                    totalDays += MonthDays::OCTOBER;
                    break;
                case 10:
                    totalDays += MonthDays::NOVEMBER;
                    break;
                case 11:
                    totalDays += MonthDays::DECEMBER;
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