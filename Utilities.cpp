// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <cstring>
#include <algorithm>

char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth)
{
    m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
    return m_widthField;
}

void Utilities::setDelimiter(char newDelimeter)
{
    m_delimiter = newDelimeter;
}

char Utilities::getDelimeter()
{
    return m_delimiter;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    std::string token;

    if (next_pos <= str.length())
    {
        size_t location = str.find_first_of(m_delimiter, next_pos);
        if (location != std::string::npos)
        {
            token = str.substr(next_pos, location - next_pos);
            next_pos = location + 1;
        }
        else
        {
            token = str.substr(next_pos);
            next_pos = str.length() + 1;
        }

        if ((token.empty()) && (next_pos != str.length() + 1))
        {
            more = false;
            throw str + "<-- ERROR: Token Failure";
        }

        if (m_widthField < token.length())
        {
            m_widthField = token.length();
        }

        more = next_pos <= str.length();
    }

    return token;
}
