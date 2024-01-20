#include "../include/StringUtils.h"
#include <cctype>
#include <iostream>
#include <cmath>
namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    if (end==0){
        return str.substr(start, str.length()-start);
    }
    else if (end>0){
        return str.substr(start, end-start);
    }
    else{
        return str.substr(start, str.length()+end-start);
    }
    
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
        else{
            num = Index+1;
        }
    }

    if (num == str.length()){
        return "";
    }
    else {
        return str.substr(num, str.length()-num);
    }
}

std::string RStrip(const std::string &str) noexcept{
    size_t num = 0;
    for(size_t Index = str.length()-1; Index>=0; Index--){
        if(str[Index] != ' '){
            num = Index;
            break;
        }
        else{
            num = Index;
        }
    }
    if (num == str.length()){
        return "";
    }
    else {
        return str.substr(0, num+1);
    }
}

std::string Strip(const std::string &str) noexcept{
    std::string myString = StringUtils::LStrip(str);
    myString = StringUtils::RStrip(myString);
    return myString;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    int len = str.length();
    int remain = width - len;
    std::string myStr;
    if (remain%2 == 0){
        myStr = StringUtils::LJust(str,remain/2+len,fill);
        myStr = StringUtils::RJust(myStr,width,fill);
    }
    else{
        myStr = StringUtils::LJust(str,ceil(remain/2)+len,fill);
        myStr = StringUtils::RJust(myStr,width,fill);
    }
    return myStr;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    int len = str.length();
    int remain = width - len;
    std::string fillString(remain,fill);
    std::string result = str + fillString;
    return result;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    int len = str.length();
    int remain = width - len;
    std::string fillString(remain,fill);
    std::string result = fillString + str;
    return result;
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