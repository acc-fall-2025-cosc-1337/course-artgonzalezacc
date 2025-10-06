#include "default.h"

double show_area(double length, double width)
{
    return length * width;
}

double get_biweekly_gross_pay(double hours, double rate)
{
    return hours * rate;
}

double get_biweekly_gross_pay(double salary)
{
    return salary / BI_WEEKLY_WEEKS;
}