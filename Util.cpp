#include "Util.h"


namespace util
{
    
    int findCharInString(string charToFind, string text)
    {
        for(int i=1;i<=text.length();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(charToFind == text.substr(j,(i-j)))
                {
                    return 0;
                }
            }
        }
        
        return 1;
    }
    
    
    //============================================================================
    
    string strToLower(string &transStr)
    {
        string strOut = transStr;
        
        for(int i=0; i<strOut.length();i++)
        {
            strOut[i] = tolower(strOut[i]);
        }
        
        return strOut;
    }
    
    //============================================================================
    
    typedef struct {
        int cost; /* cost of reaching this cell */
        int parent; /* parent cell */
    } cell;
    
    //============================================================================
    
    cell m[MAXLEN+1][MAXLEN+1]; /* dynamic programming table */
    
    //============================================================================
    
    int editDistance(const char *s, const char *t)
    {
        int i,j,k;              /* counters */
        int opt[3];             /* cost of the three options */
        
        for (i=0; i<MAXLEN; i++)
        {
            row_init(i);
            column_init(i);
        }
        
        for (i=1; i<strlen(s); i++)
        {
            for (j=1; j<strlen(t); j++)
            {
                opt[MATCH] = m[i-1][j-1].cost + match(s[i],t[j]);
                opt[INSERT] = m[i][j-1].cost + indel(t[j]);
                opt[DELETE] = m[i-1][j].cost + indel(s[i]);
                
                m[i][j].cost = opt[MATCH];
                m[i][j].parent = MATCH;
                
                for (k=INSERT; k<=DELETE; k++)
                    if (opt[k] < m[i][j].cost)
                    {
                        m[i][j].cost = opt[k];
                        m[i][j].parent = k;
                    }
                
            }
        }
        
        goal_cell(s,t,&i,&j);
        
        return( m[i][j].cost );
    }
    
    //============================================================================
    
    void row_init(int i)
    {
        m[0][i].cost = 0;
        m[0][i].parent = -1;
    }
    
    //============================================================================
    
    void column_init(int i)
    {
        m[i][0].cost = i;
        
        if (i>0)
        {
            m[i][0].parent = DELETE;
        }
        else
        {
            m[i][0].parent = -1;
        }
    }
    
    //============================================================================
    
    int match(char c, char d)
    {
        if (c == d)
        {
            return(0);
        }
        else
        {
            return(1);
        }
    }
    
    //============================================================================
    
    int indel(char c)
    {
        return(1);
    }
    
    //============================================================================
    
    void goal_cell(const char *s, const char *t, int *i, int *j)
    {
        int k; /* counter*/
        
        *i = strlen(s) - 1;
        *j = 0;
        
        for(k=1; k<strlen(t); k++)
        {
            if(m[*i][k].cost < m[*i][*j].cost)
            {
                *j = k;
            }
        }
        

    }
    
}