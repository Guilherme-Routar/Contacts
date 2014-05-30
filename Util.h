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
}

#endif /* defined(__Contact_Manager__Util__) */
