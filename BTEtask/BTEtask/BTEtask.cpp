#include <iostream>
#include "CurlRequester.h"
#include "EmployeeFinder.h"

int main()
{
    int seekedId{ 5 };
    
    CurlRequester myRequest;

    EmployeeFinder myEmployee(seekedId, myRequest.getAllEmployees());
    
}

