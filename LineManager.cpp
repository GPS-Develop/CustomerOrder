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
#include <fstream>

#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"

using namespace std;

LineManager::LineManager(std::string file, std::vector<Workstation *>& stations, std::vector<CustomerOrder>& orders)
{
    Utilities myUtil;

    std::ifstream ifs (file);
    if (!ifs.is_open())
    {
        throw string ("ERROR: Failed to open the file [") + file + "].";
    }

    std::string record = "";
    std::string CurrentStation = "";
    std::string NextStation = "";
    size_t next_pos;
    bool more;


    while (!ifs.eof())
    {
        next_pos = 0;
        std::getline(ifs, record);

        CurrentStation = myUtil.extractToken(record, next_pos, more);
        if (more) {
            NextStation = myUtil.extractToken(record, next_pos, more);
        }
        else
        {
            NextStation = "";
        }
        
        for (size_t i = 0; i < stations.size(); i++)
        {
            if (stations[i]->getItemName() == CurrentStation)
            {
                for (size_t y = 0; y < stations.size(); y++)
                {
                    if (stations[y]->getItemName() == NextStation)
                    {
                        stations[i]->setNextStation(*stations[y]);
                        break;
                    }
                }
                if (m_firstStation == nullptr)
                {
                    m_firstStation = stations[i];
                }
            }
        }
    }
    ifs.close();
    
    for (size_t x = 0; x < orders.size(); x++){
        ToBeFilled.push_back(std::move(orders[x]));
    }
        m_cntCustomerOrder = ToBeFilled.size();
        AssemblyLine = stations;
}

bool LineManager::run(std::ostream &os)
{
    static size_t count = 0;
    os << "Line Manager Iteration: " << ++count << std::endl;

    if (!ToBeFilled.empty())
    {
        int start = 0;
        for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
        {
            start = i;
            for (std::size_t j = 0; j < AssemblyLine.size(); ++j)
            {

                if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0)
                {
                    start = -1;
                }
            }

            if (start != -1)
            {
                break;
            }
        }

        *AssemblyLine[start] += std::move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }

    for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
    {
        AssemblyLine[i]->runProcess(os);
    }

    for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
    {
        if (AssemblyLine[i]->getNextStation() == nullptr)
        {
            CustomerOrder tmp;
            if (AssemblyLine[i]->getIfCompleted(tmp))
            {
                Completed.push_back(std::move(tmp));
            }
        }
        else
        {
            AssemblyLine[i]->moveOrder();
        }
    }

    if (Completed.size() == m_cntCustomerOrder)
    {
        return true;
    }
    else
        return false;
}

void LineManager::displayStationsSorted() const
{
    int start = 0;
    for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
    {
        start = i;
        for (std::size_t j = 0; j < AssemblyLine.size(); ++j)
        {

            if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0)
            {
                start = -1;
            }
        }

        if (start != -1)
        {
            break;
        }
    }

    const Workstation *begin = AssemblyLine[start];

    while (begin != nullptr)
    {
        begin->display(std::cout);
        begin = begin->getNextStation();
    }
}

void LineManager::displayStations() const
{
    for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
    {
        AssemblyLine[i]->display(std::cout);
    }
}

void LineManager::displayCompletedOrders(std::ostream &os) const
{
    for (std::size_t i = 0; i < Completed.size(); ++i)
    {
        Completed[i].display(os);
    }
}


