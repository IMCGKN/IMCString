#pragma once

#include <string.h>
#include <stdio.h>
#include <iostream>

namespace imc
{
    class String
    {
    private:
        char* str;
    public:
        String()
        {
            str = new char[1];
            str[0] = '\0';
        }

        String(char* val)
        {
            if(val == nullptr)
            {
                str = new char[1];
                str[0] = '\0';
            }
            else
            {
                str = val;
            }
        }

        String& operator=(char* val)
        {
            if(val == nullptr)
            {
                str = new char[1];
                str[0] = '\0';
                return *this;
            }
            str = val;
            return *this;
        }

        String& operator=(String& val)
        {
            str = val.str;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const String& st)
        {
            os << st.str;
            return os;
        }

        String& operator+(String& val1)
        {
            char* total{ new char[strlen(this->str) + strlen(val1.str) + 1] };
            total = strcpy(total, this->str);
            total = strcat(total, val1.str);
            this->str = total;
            return *this;
        }

        String& operator+(char* val1)
        {
            char* total{ new char[strlen(this->str) + strlen(val1) + 1] };
            total = strcpy(total, this->str);
            total = strcat(total, val1);
            this->str = total;
            return *this;
        }

        char& operator[](uint32_t i)
        {
            return str[i];
        }

        friend char* operator+(char* s1, String& s2)
        {
            char* total{ new char[strlen(s1) + strlen(s2.str) + 1] };
            total = strcpy(total, s1);
            total = strcat(total, s2.str);
            return total;
        }

        uint32_t getSize()
        {
            return strlen(str);
        }
    };
};
