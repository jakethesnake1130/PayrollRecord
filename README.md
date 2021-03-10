# CHALLENGE: THE PAYROLLRECORD CLASS


---
## Purpose

This activity will provide an opportunity to demonstrate what you have
 learned about creating and using a 
programmer-defined data type.

## Skills and Knowledge

This activity will help you practice the following skills that are essential to know for basic programming in `C++`:

- Declaring and Implementing a class  
- Using a class you have created


This project will also help you to become familiar with the following important content knowledge in CS:

- Working in a development environment.
- Creating and using class libraries
- Using file input and output
- String manipulation
- Use basic unit testing to validate your code: `catch2`.



---
### Files to work on

You will be working the following files:

The class will be created in the `payroll_record` class library. The library consists
of these two files:
  - `src/payroll_record.cpp`
  - `src/payroll_record.h`

The "driver" will be in
 - `src/main.cpp`.

You will also produce additional output files.

--- 
## Problem to Solve

A company needs a program that will compute weekly payroll. They do payroll for 
many different companies. They receive hours worked and wage information 
stored in a file from each company.They need a program that can read the files 
and produce the information needed to print payroll data and reports.

For this activity we will be creating a program that creates and uses the 
PayrollRecord class to create this 
functionality. This is just the beginning of a program to read and report 
payroll data. It will compute and report 
the gross pay. A more complete version will include various deductions, 
compute net pay, and produce fund transfer reports.

This activity uses many of the programming tools we learned in previous 
modules and in other activities in this module. 

---
 

## Part 1: Creating the PayrollRecord Class
Create the PayrollRecord class and add getter methods, setter methods, constructors, and a destructor. 

*Note*: Naming of the public interface is critical. It is important to name the class and public members as specified. Otherwise, the unit tests will not work.

The class declaration is to go in the header file, `payroll_record.h`, 
and the method implementations in `payroll_record.cpp`. You can have some
 methods be inline if they only have one or two statements.

*Note*: Avoid the C++ `using` and `using namespace` directives in a header file. This means when using names from the std namespace, preface them with `std::` as shown below.
```cpp
  std::string 
```

### Part 1.1: Add the private data members
The PayrollRecord class has four private data members for the following values.
   - The hours. This is a double that stores the number of hours worked in this pay period. 
   - The pay rate. This is a double and stores how much the employee is paid
   per hour.
   - A first name. This is a string that contains the employee's first name 
   and any middle name or initial.
   - A last name. This is a string that contains the employee's last name.
   There are no spaces in the last name.

### Part 1.2: Add the public static constants
The PayrollRecord class has three public static members. These will be used
in some of the class methods. Here are the declarations for these static 
members. 

```cpp
  static const double kMinimumWage;
  static const double kRegularHours;
  static const double kOvertimeRate;
```
Declare these constants in `payroll_record.h` and define them and set 
    their values in `payroll_record.cpp`.
 
- kMinimumWage is the legal minimum hourly wage, set this to 7.25.
- kRegularHours is the number of regular hours in a week. When someone
works more than this many hours they receive overtime pay. Set this
to 40.
- kOvertimeRate is the mulitiplier for computing overtime pay, set this to 1.5.
  
### Part 1.3: Add the getter methods
Add a getter method for each 
private data member that returns its current value.
None of these getter methods will make changes to the actual object 
    so they can be const methods.

Here are the declarations for the getter methods.

```cpp
  double get_hours() const;
  double get_pay_rate() const;
  std::string get_first_name() const;
  std::string get_last_name() const;
```

### Part 1.4: Add the setter methods
The setter methods allow us to 
control what values the private data members can contain. There will be a 
setter method for each data member. Enforce the following.

   1. The hours worked is between 0-168 (including 0 and 168). If the hours
   sent is outside this range, set hours to 0.
   3. The pay rate is at least minimum wage. If a pay rate is sent that
    is less than this, set pay rate to minimum wage. Use the constant 
    kMinimumWage when working with minimum wage. 
   4. The name. Notice how this is one setter for two data members. When
   companies send the employee name it is the full name
   and has to be parsed to determine the first and last names. Any 
   middle name or initial is included in the first name.
   The name sent is either in first last format or last, 
   first format. The code is to handle either format and set the first 
   and last name data members. There is no space in the last name.
   
   You may find it helpful to use the string method find_last_of.

Here are the declarations for the setter methods.

```cpp
  void set_hours(double hours);
  void set_pay_rate(double pay_rate);
  void set_name(std::string name);
```
    
### Part 1.5: Add the default constructor

This constructor has no parameters and sets the following values.

- hours to 0
- pay rate to minimim wage
- first name to "it is"
- last name to "unknown"
    
Here is the declaration for the default constructor.

```cpp
  PayrollRecord();
```

### Part 1.6: Add a non-default constructor
This constructor has three parameters
- hours
- pay rate
- employee name

To set these values, call the setter methods. 

Here is the declaration  for the non-default constructor.

```cpp              
  PayrollRecord(double hours, double pay_rate, std::string name);
```

### Part 1.7: Add the destructor. 

Nothing needs to be done in the destructor. 
    
Here is the declaration  for the destructor.

```cpp
  ~PayrollRecord();
```


---

## Part 2: The ComputeGross method

For the weekly payroll, the gross pay is needed. Write a method named ComputeGross. This method has no 
parameters. It returns a double.

The method computes and returns the gross pay. The computation for gross pay 
 depends on whether the hours worked is greater than the regular hours or not 
 (kRegularHours). If the 
 hours worked is kRegularHours or less, the gross pay is the number of 
 hours worked times the pay rate.

Examples:
 
```
hours worked: 32
pay rate: 18.50
gross pay = 32 * 18.50

hours worked: 40
pay rate: 9.75
gross pay = 40 * 9.75
```
 
When the hours worked is greater than the regular hours, the gross is the 
sum of regular pay and overtime pay. The regular pay is kRegularHours times the pay rate. The overtime pay is the number of hours over kRegularHours 
times the pay rate times the multiplier (kOvertimeRate). 

Examples:
 
```
hours worked: 42
pay rate: 13.50
gross pay = (40 * 13.50) + (2 * 13.50 * 1.5)

hours worked: 50
pay rate: 21.25
gross pay = (40 * 21.25) + (10 * 21.25 * 1.5)
```
 
Return the computed gross pay.

This method will not make changes to the actual object so it can be a const method.

  Here is the declaration  for the ComputeGross method.

  ```cpp
    double ComputeGross() const;
  ```

---

## Part 3: The WriteData method

Each company gets a payroll report that includes the payroll information 
including gross pay. 

Create a method named WriteData. The method has one parameter of type ostream
and returns nothing. The WriteData method is to write the following data to 
the output stream. It is to be written on two lines. 

- The first line contains three items separated by a space and ending with
a carriage return
  - hours worked
  - pay rate
  - gross pay
- The second line contains a name in last, first format and ends with a carriage return

Set the precision on the output stream to display two digits after the decimal place.

Example:
```
51.00 25.00 1412.50
Taylor, Terri K.
```
This method will not make changes to the actual object so it can be a const method.

Here is the declaration for the WriteData method.

```cpp
void WriteData(std::ostream &out) const;
```


---

## Part 3: The WriteReport method

Some companies want a payroll report that 
includes the data with labels. 
Write a method named WriteReport. This method has one parameter of type ostream 
and returns nothing.  

The WriteReport method is to write the following report to the output stream. 
It is to be written on four lines as shown below. Lines 2-4 start with three
spaces.

    
    First Last
       Hours Worked: hours
       Pay Rate: $rate
       Gross Pay: $gross

 Set the precision on the output stream to display two digits after the decimal place.

Example:

    Kim Watson
       Hours Worked: 43.50
       Pay Rate: $23.50
       Gross Pay: $123.38

This method makes no change to the object itself so it can be a const method.

Here is the declaration for the WriteReport method.

  ```cpp
    void WriteReport(std::ostream &out) const;
  ```

---

## Part 4: Using PayrollRecord in main 

In main write code that uses the PayrollRecord class. This code will
read data from a file and store it in an array. Then it will write the 
payroll data with gross pay to an output file and a payroll report to
another output file.

### Part 4.1: Read the payroll data
 
Get the name of the input file from the user. The user is to enter 
just the filename and extension. The program is 
to add any path needed for the files to work as expected. Open this file. If the file
does not open, shut down the program.
Read the data from the file and store it in an array of PayrollRecords.

When reading the data, be sure to protect the array from 
going out of bounds. Make the array size 32. This will let
us test this.

There is an input file named payroll_input.txt that has fewer than 32 payroll
entries. The code would read this entire file.

There is an input file named too_much_data.txt that has more than 32 payroll
entries. The code would read only the first 32 entries. Although we are using
an array with a size of 32 to test the array is protected, the code is to protect the array no matter
what the size is. Use the size of the array rather than the number 32 when
writing the loop condition.

### Part 4.2: Write the payroll data

Use the WriteData method to write the payroll data including gross pay to
the file payroll_data.txt.

### Part 4.3: Write the payroll report

Use the WriteReport method to write a payroll report to
the file payroll_report.txt.



---

## Validate your code

Once you are satisfied with your work, run the unit test file:

From the dropdown select main_test and run.

Sample output:

Tests passed: 31 of 31 tests

---

## Submit your code

Zip your src folder and submit in Canvas.
