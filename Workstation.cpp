// Name: Gurpreet Singh
// Seneca Student ID: 074913146
// Seneca email: gsingh432@myseneca.ca
// Date of completion: Nov 28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
#include "Workstation.h"

using namespace std;

Workstation::Workstation(std::string &str) : Station(str)
{
    m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream &os)
{
    if (m_orders.empty())
    {
        return;
    }

    m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder()
{

    if (m_orders.empty())
    {
        return false;
    }

    if (m_orders.front().isItemFilled(this->getItemName()) && m_pNextStation)
    {
        *m_pNextStation += std::move(m_orders.front());
        m_orders.pop_front();
        return true;
    }
        return false;
}

void Workstation::setNextStation(Workstation& station)
{

    m_pNextStation = &station;
}
 
const Workstation *Workstation::getNextStation() const
{
    return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder &order)
{
    if (m_orders.empty() == false && m_orders.back().isOrderFilled())
    {
        order = std::move(m_orders.front());
        m_orders.pop_front();
        return true;
    }
    
    return false;
}

void Workstation::display(std::ostream &os) const
{
    if (m_pNextStation == nullptr)
    {
        os << getItemName() << " --> END OF LINE" << endl;
    }
    else
    {
        os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
    }
}

Workstation &Workstation::operator+=(CustomerOrder &&aa)
{

    m_orders.push_back(std::move(aa));

    return *this;
}
