#pragma once
#include <iostream>
unsigned new_strlen(const char * str)
{
    int i = 0;
    for (const char * c = str; *c != '\0'; ++c)    
    {
        i += 1;
    }
    return i;
}

void new_strcat(char *to, const char *from) 
{
    unsigned l_to  = new_strlen(to);
    unsigned l_from = new_strlen(from);
    for (unsigned z = 0; z < l_from; ++z)
    {
        *(to + l_to + z) = *(from + z);
    }
    *(to + l_to + l_from) = '\0';
}

void new_strcpy(char *to, const char *from) 
{
    delete [] to;
    unsigned l_from = new_strlen(from);
    char * str = new char [l_from];
    for (unsigned z = 0; z < l_from; ++z)
    {
        *(to + z) = *(from + z);
    }
    *(to + l_from) = '\0';
}


int new_strstr(const char *to, const char *from)  
{
    unsigned l_to  = new_strlen(to);
    unsigned l_from = new_strlen(from);
    if (l_from == 0)
    {
        return 0;
    }
    else
    {
        if (l_to == 0)
        {
            return -1;
        }
        else
        {
            for (unsigned z = 0; z < l_to; ++z)
        {
        if (*(to + z) == *(from))
        {
            unsigned ch = 0;
            for (unsigned x = 0; x < l_from; ++x)
            {  
                if (*(to + z + x) == *(from + x))
                {
                    ch += 1;
                }
            }
            if (ch == l_from)
            {
                return z;
            }
        }
        }
        return -1;
        }
        
    }
}

char * new_getstr()
{
    char c = 0;
    int i = 0;
    char * dynamic_memory = new char[1];
    while (std::cin.get(c) && (c != '\n')) 
    {
		i++;
		dynamic_memory[i-1] = c;
		char * new_dynamic_memory = new char[i+1];
		int k = 0;
		while (k < i)
		{
			new_dynamic_memory[k] = dynamic_memory[k];
			k++;
		}
		delete [] dynamic_memory;
		dynamic_memory = new_dynamic_memory;
    }
    dynamic_memory[i] = '\0';
    return dynamic_memory;
}


char * resize(const char *str, unsigned size, unsigned new_size)
{
    char * new_str = new char[new_size];
    for(int k = 0; (k < size) && (k < new_size); ++k)
    {
        new_str[k] = str[k];
    }
    delete[] str;
    return new_str;
}