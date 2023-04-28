#include "EmployeeFinder.h"


void EmployeeFinder::findEmployee(const std::string& list)
{
	auto employeeListObcjectArr = json::parse(list);
    for (auto employees : employeeListObcjectArr)
    {
        if (employees["employee_id"] == seekedId)
        {
            firstName = employees["firstname"];
            lastName = employees["lastname"];
            break;
        }
    }
}

void EmployeeFinder::printEmployee()
{
    std::cout << "Name: " << firstName << " " << "LastName: " << lastName << std::endl;
}
