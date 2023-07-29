#pragma once
#include "functions.h"

struct New_String 
{
   New_String(const char *str = "")
    {
        size = new_strlen(str);
        this -> str = new char[size + 1];
        for (size_t i = 0; i <= size; ++i)
        {
            this -> str[i] = str[i];
        } 
    }

    New_String(size_t n, char c) 
    {
        str = new char[n + 1];
        for (size_t i = 0; i < n; ++i)
        {
            str[i] = c;
        } 
        str[n] = '\0';
        size = new_strlen(str);
    }
   
    ~New_String()
    {
        delete [] str;
    }

    New_String(const New_String &other) : size(other.size), str(new char[other.size + 1]) 
    {
        for (size_t i = 0; i != size; ++i)
        str[i] = other.str[i];
        str[size] = '\0';
    }

    New_String &operator = (const New_String &other) 
    {
        if (this != &other)
        {
        delete[] str;
        str = new char[other.size + 1];
        new_strcpy(str, other.str);
        size = other.size;
        return *this;
        }
    }

    void append(const New_String &other) 
    {
        char * temp = new char [size + other.size + 1];
        new_strcpy(temp, str);
        new_strcat(temp + size, other.str);
        temp[size + other.size] = '\0';
        delete[] str;
        str = temp;
        size = new_strlen(str);
    }
    
    char & get(size_t idx)     
    {
        return str[idx]; 
    }
    
    size_t length()
    {
        return size;
    }    

	size_t size;
	char *str;
};