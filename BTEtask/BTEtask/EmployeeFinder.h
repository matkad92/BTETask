#pragma once
#include <string>
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

class EmployeeFinder
{
	int seekedId;
	std::string firstName, lastName;
	void findEmployee(const std::string& list);
	void printEmployee();

public:
	EmployeeFinder(int sendId, const std::string &list )
	{
		seekedId = sendId;
		findEmployee(list);
		printEmployee();
	
	}


};

