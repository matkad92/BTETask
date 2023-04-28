#pragma once

#include <string>
#include "curl/curl.h"
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

class CurlRequester
{	
    static size_t myWrite(void* buffer, size_t size, size_t nmemb, void* param);

public:
	std::string getAllEmployees();
};

