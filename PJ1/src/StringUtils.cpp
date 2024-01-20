#include "../include/StringUtils.h"
#include <cctype>
namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    
    return str.substr(start, str.length()-start);
}

std::string Capitalize(const std::string &str) noexcept{
    auto copy = str;
    copy[0] = toupper(str[0]);
    for(size_t Index = 1; Index < copy.length(); Index++){
        copy[Index] = tolower(copy[Index]);
    }
    return copy;
}

std::string Upper(const std::string &str) noexcept{
    auto copy = str;
    for(size_t Index = 0; Index < copy.length(); Index++){
        copy[Index] = toupper(copy[Index]);
    }
    return copy;
}

std::string Lower(const std::string &str) noexcept{
    auto copy = str;
    for(size_t Index = 0; Index < copy.length(); Index++){
        copy[Index] = tolower(copy[Index]);
    }
    return copy; 
}

std::string LStrip(const std::string &str) noexcept{
    size_t num = 0;
    for(size_t Index = 0; Index < str.length(); Index++){
        if (str[Index] != ' '){
            num = Index;
            break;
        }
    }
    return str.substr(num, str.length()-num);
}

std::string RStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};