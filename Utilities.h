// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef Utilities_h
#define Utilities_h

#include <string>
#include <stdio.h>

class Utilities
{
public:
    void setFieldWidth(size_t fw);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimeter);
    static char getDelimeter();

private:
    size_t m_widthField = 1;
    static char m_delimiter;
};
#endif /* Utilities_h */
