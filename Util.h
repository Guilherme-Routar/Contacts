#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <vector>

namespace util
{
    using namespace std;
    
    /**
     * Calculates edit distance between two strings
     */
    int editDistance(string pattern, string text);
    
    /**
     * Calculates the minimum edit distance between two string with character error tolerance
     */
    int minEditDistance(string pattern, string text);
    
    /**
     * String to lower case
     */
    string strToLower(string &transStr);
}

#endif /* defined(__Contact_Manager__Util__) */
