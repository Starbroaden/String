#pragma once
#include <cstddef>
#include <cstring> 
#include <algorithm> 

struct String {

   String(const char *str = "")
    {
        size = strlen(str);
        this -> str = new char[size + 1];
        for (size_t i = 0; i <= size; ++i)
        {
            this -> str[i] = str[i];
        } 
    }

    String(size_t n, char c) 
    {
        str = new char[n + 1];
        for (size_t i = 0; i < n; ++i)
        {
            str[i] = c;
        } 
        str[n] = '\0';
        size = strlen(str);
    }
   
    ~String()
    {
        delete [] str;
    }

    String(const String &other) : size(other.size), str(new char[other.size + 1]) 
    {
        for (size_t i = 0; i != size; ++i)
        str[i] = other.str[i];
        str[size] = '\0';
    }

    String &operator = (const String &other) 
    {
        if (this != &other)
        {
        delete[] str;
        str = new char[other.size + 1];
        strcpy(str, other.str);
        size = other.size;
        return *this;
        }
    }


    void append(const String &other) 
    {
        char * temp = new char [size + other.size + 1];
        strcpy(temp, str);
        strcat(temp + size, other.str);
        temp[size + other.size] = '\0';
        delete[] str;
        str = temp;
        size = strlen(str);
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