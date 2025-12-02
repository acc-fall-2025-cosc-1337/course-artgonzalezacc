#include<string>
#include "function_str.h"

using std::string;

int main()
{
    string lang = "C++";
    string_value_param(lang);
    string_ref_param(lang);
    string_ref_param_ref_for(lang);

    return 0;
}