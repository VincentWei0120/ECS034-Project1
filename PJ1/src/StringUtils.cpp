#include "../include/StringUtils.h"
#include <cctype>
#include <iostream>
#include <math.h>
#include <algorithm>
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
    std::string myString = str;
    int Index = 0;
    while ((Index = myString.find(old, Index)) != std::string::npos){
        myString.replace(Index, old.length(), rep);
        Index += rep.length();
    }
    return myString;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> strings;
    
    if (splt.empty()){
        int start = 0;
        int end = str.find_first_of(" ");
        while (end != std::string::npos){
        strings.push_back(Slice(str,start,end));
        start = end+1;
        end = str.find_first_of(splt, start);
        }
        if(start < str.length()){
        strings.push_back(str.substr(start));
        }
    }
    else{
        int start = 0;
        int end = str.find_first_of(splt);
        while (end != std::string::npos){
            strings.push_back(Slice(str,start,end));
            start = end+1;
            end = str.find_first_of(splt, start);
        }
        if(start < str.length()){
            strings.push_back(str.substr(start));
        }
    }   
    return strings;
}
std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string myString = "";
    if(vect.empty()){
        return myString;
    }
    else{
        myString = vect[0];
        for (int i = 1; i < vect.size(); i++){
            myString = myString + str + vect[i];
        }
        return myString;
    }
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string myString;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '\t'){
            int space = tabsize - (myString.length()%tabsize);
            for (int j = 0; j<space; j++){
                myString.push_back(' ');
            }
        }
        else{
            myString.push_back(str[i]);
        }
    }
    return myString;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // The +1 here is for the empty string 
    int rows = left.length()+1;
    int columns = right.length()+1;
    int matrix[rows][columns];
    //Initalize the first row and column with increasing values
    for (int i =0;i<rows;i++){
        matrix[i][0] = i;
    }
    for (int j =0;j<columns;j++){
        matrix[0][j] = j;
    }
    //Fill in rest
    for (int i = 1; i <= rows; i++){
        for (int j =1; j <= columns; j++){
            if (ignorecase){
                if (tolower(left[i-1]) == tolower(right[j-1])){
                    //no cost
                    matrix[i][j] = matrix[i-1][j-1];
                }
                else{
                    //choose minimum cost of insertion, deletion, substitution according to the wikipedia definition
                    matrix[i][j] = std::min(std::min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1])+1;
                }
            }
            else{
                if (left[i-1] == right[j-1]){
                    matrix[i][j] = matrix[i-1][j-1];
                }
                else{
                    matrix[i][j] = std::min(std::min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1])+1;
                }
            }
        }
    }
    //return the element in the last row and last column which has the final edit distance
    return matrix[rows-1][columns-1];
}

};