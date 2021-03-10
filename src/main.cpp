#include <iostream>
#include <fstream>
#include <array>
#include "payroll_record.h"

using namespace std;

int main()
{
    //Input/Output objects
    ifstream in;
    ofstream out;

    //Initialization of PayrollRecord array, limited to 32 elements
    array<PayrollRecord, 32> payrollArray;

    //string used to store user's input for name of input file
    string filename;

    //Prompt to take in file name
    cout << "Please enter the filename to be recorded" << endl;
    cin >> filename;
    //Append prefix necessary to find file location
    filename.insert(0, "../../");

    //Attempt to open and reject if unable to locate file
    in.open(filename);
    if(in.fail())
    {
        cout << "Unable to find file. Shutting down.";
        return 0;
    }

    //Loop through the input file, storing the information in temporary variables
    //Use setter functions to construct a PayrollRecord object, repeat x the size of the array
    for(int i = 0; i < payrollArray.size(); ++i)
    {
        double hours, payRate;
        string name;

        in >> hours;
        in >> payRate;
        in.ignore();
        getline(in, name);

        payrollArray[i].set_hours(hours);
        payrollArray[i].set_pay_rate(payRate);
        payrollArray[i].set_name(name);
    }
    in.close();

    //Print raw data to one file
    out.open("../../payroll_data.txt");
    for(int i = 0; i < payrollArray.size(); ++i)
    {
        payrollArray[i].WriteData(out);
    }
    out.close();

    //Print formatted data to another
    out.open("../../payroll_report.txt");
    for(int i = 0; i < payrollArray.size(); ++i)
    {
        payrollArray[i].WriteReport(out);
    }
    out.close();


  return 0;
}
