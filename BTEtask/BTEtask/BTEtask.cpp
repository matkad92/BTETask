#include <iostream>
#include "CurlRequester.h"

int main()
{
    CurlRequester myRequest;

    std::string test = myRequest.getAllEmployees();
    std::cout << test<<std::endl;
    std::cout << "Program end\n";
}

