#ifndef PAYROLL_RECORD_H
#define PAYPAYROLL_RECORD_H

class PayrollRecord
{
public:
    PayrollRecord();
    PayrollRecord(double hours, double payRate, std::string employeeName);
    ~PayrollRecord() {};

    static const double kMinimumWage;
    static const double kRegularHours;
    static const double kOvertimeRate;

    double get_hours() const {return hours_;};
    double get_pay_rate() const {return payRate_;};
    std::string get_first_name() const {return firstName_;};
    std::string get_last_name() const {return lastName_;};

    void set_hours(double hours);
    void set_pay_rate(double payRate);
    void set_name(std::string name);

    double ComputeGross() const;

    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;

private:
    double hours_;
    double payRate_;
    std::string firstName_;
    std::string lastName_;
};

#endif