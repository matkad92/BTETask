#include <iostream>
#include "CurlRequester.h"
#include "EmployeeFinder.h"

int main()
{
    CurlRequester myRequest;
    EmployeeFinder myEmployee;

    std::string test = myRequest.getAllEmployees();
    std::cout << test<<std::endl;
    std::cout << "Program end\n";
}

