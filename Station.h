// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef Station_h
#define Station_h

#include <iostream>

class Station
{
public:
    Station(const std::string& str);
    const std::string& getItemName() const;
    unsigned int getNextSerialNumber();
    unsigned int getQuantity() const;
    void updateQuantity();
    void display(std::ostream&, bool)const;

private:
    size_t m_id;
    std::string m_itemName;
    std::string m_description;
    int m_serialNumber;
    unsigned int m_quantity;

    static size_t field_width;
    static size_t id_generator;
};

#endif /* Station_h */
