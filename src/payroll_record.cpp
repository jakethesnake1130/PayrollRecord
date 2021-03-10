#include <iostream>
#include <iomanip>
#include "payroll_record.h"

//Default constructor with blank slate data
PayrollRecord::PayrollRecord() : hours_(0), payRate_(kMinimumWage),
                                 firstName_("it is"), lastName_("unknown") {}

//Non-default constructor -- accepts arguments
PayrollRecord::PayrollRecord(double hours, double payRate, std::string employeeName)
{
    set_hours(hours);
    set_pay_rate(payRate);
    set_name(employeeName);
}

//Class-wide constants
const double PayrollRecord::kMinimumWage = 7.25;
const double PayrollRecord::kRegularHours = 40;
const double PayrollRecord::kOvertimeRate = 1.5;

/*
 * Set hours of a PayrollRecord object
 * Accepts argument for hours
 */
void PayrollRecord::set_hours(double hours)
{
    if(hours >= 0 && hours <= 168)
    {
        hours_ = hours;
    }
    else
    {
        hours_ = 0;
    }
}

/*
 * Set pay rate of a PayrollRecord object
 * Accepts argument for pay rate
 */
void PayrollRecord::set_pay_rate(double pay_rate)
{
    if(pay_rate >= kMinimumWage)
    {
        payRate_ = pay_rate;
    }
    else
    {
        payRate_ = kMinimumWage;
    }
}

/*
 * Set hours of a PayrollRecord object
 * Accepts argument for pay rate
 */
void PayrollRecord::set_name(std::string name)
{
    int position;
    position = name.find(",");

    if(position != std::string::npos)
    {
        //Separate first and last name
        lastName_ = name.substr(0, position);
        firstName_ = name.substr(position);
        //Remove the comma and space succeeding it
        firstName_.replace(0, 2, "");
    }
    else
    {
        position = name.find_last_of(" ");
        if(position != std::string::npos)
        {
            firstName_ = name.substr(0, position);
            lastName_ = name.substr(position);
            lastName_.replace(0, 1, "");
        }
    }
}

/*
 * Computes the gross salary for one week
 * Uses the hours_ and payRate_ variables to compute total amount earned
 * Accounts for overtime pay rate
 */
double PayrollRecord::ComputeGross() const
{
    double grossPay;

    if(hours_ > kRegularHours)
    {
        grossPay = (40 * payRate_) + ((hours_ - 40) * payRate_ * kOvertimeRate);
    }
    else
    {
        grossPay = hours_ * payRate_;
    }

    return grossPay;
}

/*
 * Writes data in raw form from a PayrollRecord object
 * Accepts argument for output destination
 */
void PayrollRecord::WriteData(std::ostream &out) const
{
    out << std::fixed << std:: setprecision(2) << hours_ << " " << payRate_
        << " " << ComputeGross() << std::endl;
    out << lastName_ << ", " << firstName_ << std::endl;
}

/*
 * Writes formatted data from a PayrollRecord object
 * Accepts argument for output destination
 */
void PayrollRecord::WriteReport(std::ostream &out) const
{
    out << std::fixed << std::setprecision(2);
    out << firstName_ << " " << lastName_ << std::endl;
    out << "   " << "Hours Worked: " << hours_ << std::endl;
    out << "   " << "Pay Rate: $" << payRate_ << std::endl;
    out << "   " << "Gross Pay: $" << ComputeGross() << std::endl;
}