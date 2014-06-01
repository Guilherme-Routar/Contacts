#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <vector>

#define MAXLEN 15

#define MATCH 0 /* enumerated type symbol for match */
#define INSERT 1 /* enumerated type symbol for insert */
#define DELETE 2 /* enumerated type symbol for delete */

namespace util
{
    using namespace std;
    
    /**
     * Finds if a char exists in a string
     */
    int findCharInString(string charToFind, string text);
    
    /**
     * String to lower case
     */
    string strToLower(string &transStr);
    
    /**
     * Calculates edit distance between two strings
     */
    int editDistance(const char *s, const char *t);
    
    /**
     *
     */
    void row_init(int i);
    
    /**
     *
     */
    void column_init(int i);
    
    /**
     *
     */
    int match(char c, char d);
    
    /**
     *
     */
    int indel(char c);
    
    /**
     *
     */
    void goal_cell(const char *s, const char *t, int *i, int *j);
}

#endif /* defined(__Contact_Manager__Util__) */
