// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include "Station.h"
#include "Utilities.h"

struct Item
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const std::string &src) : m_itemName(src){};
};

class CustomerOrder
{
public:
    CustomerOrder();
    ~CustomerOrder();
    CustomerOrder(const std::string &);
    CustomerOrder(const CustomerOrder &p2) { throw "COPY CONSTRUCTOR NOT ALLOWED"; };
    CustomerOrder &operator=(const CustomerOrder &other) = delete;
    
    bool isOrderFilled() const;
    bool isItemFilled(const std::string &itemName) const;
    void fillItem(Station &station, std::ostream &os);
    void display(std::ostream &os) const;
    
    CustomerOrder &operator=(CustomerOrder &&co) noexcept
    {
        if (&co == this)
            return *this;

        if (m_lstItem == nullptr)
        {
        }
        else
        {
            for (unsigned int i = 0; i < m_cntItem; i++)
            {
                delete m_lstItem[i];
            }
        }

        delete[] m_lstItem;

        m_name = co.m_name;
        m_product = co.m_product;
        m_cntItem = co.m_cntItem;

        m_lstItem = co.m_lstItem;
        co.m_lstItem = nullptr;

        return *this;
    }

    CustomerOrder(CustomerOrder &&co) noexcept
    {
        m_name = co.m_name;
        m_product = co.m_product;
        m_cntItem = co.m_cntItem;

        m_lstItem = co.m_lstItem;
        co.m_lstItem = nullptr;
    }
private:
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    Item **m_lstItem;
    static size_t m_widthField;

};
#endif
