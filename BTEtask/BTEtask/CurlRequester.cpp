#define CURL_STATICLIB
#include "CurlRequester.h"


size_t CurlRequester::myWrite(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

std::string CurlRequester::getAllEmployees()
{
	
    std::string resultToken;
    CURL* curl = nullptr;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);


    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://194.182.75.112:10443/v1/authorize");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"login\":\"saikadmin\",\"password\":\"saikadmin\"}");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, myWrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resultToken);
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);

        if (CURLE_OK != res) {
            std::cerr << "CURL error: " << res << '\n';
        }
        curl_easy_cleanup(curl);
        curl = nullptr;
    }

    auto tokenJsonObject = json::parse(resultToken);
    std::string token = tokenJsonObject["token"];
    //std::cout << token << std::endl;

    std::string authorizationString = "Authorization: Token ";
    authorizationString += token;
    //std::cout << authorizationString << std::endl;
	
    CURL* curlEmployee = nullptr;
    CURLcode remEmployee;
    curlEmployee = curl_easy_init();
    std::string employeeList;
    struct curl_slist* headers = nullptr;

    if (curlEmployee) {
        curl_easy_setopt(curlEmployee, CURLOPT_URL, "https://194.182.75.112:10443/v1/tab/employees");
        curl_easy_setopt(curlEmployee, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curlEmployee, CURLOPT_WRITEFUNCTION, myWrite);

        headers = curl_slist_append(headers, authorizationString.c_str());
        curl_easy_setopt(curlEmployee, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curlEmployee, CURLOPT_WRITEDATA, &employeeList);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        remEmployee = curl_easy_perform(curlEmployee);

        if (CURLE_OK != remEmployee) {
            std::cerr << "CURL error: " << remEmployee << '\n';
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curlEmployee);
        curlEmployee = nullptr;
    }

    curl_global_cleanup();
	return employeeList;
}
