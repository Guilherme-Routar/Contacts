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
     * row init initialize the zeroth row of the dynamic programming table
     */
    void row_init(int i);
    
    /**
     * column init initialize the zeroth column of the dynamic programming table
     */
    void column_init(int i);
    
    /**
     *  match(c,d) present the costs for transforming character c to d
     */
    int match(char c, char d);
    
    /**
     * indel(c) present the costs for inserting/deleting character c
     */
    int indel(char c);
    
    /**
     *  goal cell returns the indices of the cell marking the endpoint of the solution
     */
    void goal_cell(const char *s, const char *t, int *i, int *j);
}

#endif /* defined(__Contact_Manager__Util__) */
