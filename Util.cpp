#include "Util.h"


namespace util
{
    int editDistance(string pattern, string text)
    {
        int n = (int)text.length();
        vector<int> d(n+1);
        int old;
        int neww;
        
        for (int j=0; j<=n; j++)
        {
            d[j]=j;
        }
        
        int m = (int)pattern.length();
        
        for (int i=1; i<=m; i++)
        {
            old = d[0];
            d[0] = i;
            
            for (int j=1; j<=n; j++)
            {
                if (pattern[i-1]==text[j-1])
                {
                    neww = old;
                }
                else
                {
                    neww = min(old,d[j]);
                    neww = min(neww,d[j-1]);
                    neww = neww +1;
                }
                
                old = d[j];
                d[j] = neww;
            }
        }
        
        return d[n];
    }
    
    //============================================================================
    
    int minEditDistance(string pattern, string text)
    {
        int minEditDistance = INT_MAX;
        
        if(pattern.length() >= text.length())
        {
            minEditDistance = editDistance(pattern, text);
        }
        else
        {
            for(int i=1;i<=text.length();i++)
            {
                for(int j=0;j<i;j++)
                {
                    int tempDist = editDistance(pattern,text.substr(j,(i-j)));
                    
                    if(tempDist < minEditDistance)
                    {
                        minEditDistance = tempDist;
                    }
                }
            }
        }
        return minEditDistance;
        
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
    
}