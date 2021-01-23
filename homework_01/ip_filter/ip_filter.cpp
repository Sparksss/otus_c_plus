#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string split(const std::string &str, char d)
{
    std::string r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);

    return str.substr(start, stop - start);
}

std::vector<int> castToInt(std::string &line, char d)
{
    std::vector<int> o;

    std::string::size_type start = 0;
    std::string::size_type stop = line.find_first_of(d);

    while(stop != std::string::npos)
    {
        o.push_back(std::stoi(line.substr(start, stop - start)));

        start = stop + 1;
        stop = line.find_first_of(d, start);
    }

    o.push_back(std::stoi(line.substr(start)));
    
    return o;
}


void showIpByCondition(std::vector<std::vector<int>> &listOfIps, int indexOfList, int numberOfCondition) {
  
  const int LAST_INDEX_OF_IP_PART = 3;

    for(auto& ip : listOfIps) 
    {
        if(ip[indexOfList] == numberOfCondition) 
        {
            for(int i = 0; i < 4; i++) 
            {
                std::cout << ip[i];
                
                if(i != LAST_INDEX_OF_IP_PART) 
                {
                   std::cout << '.';
                }
            }

            std::cout << std::endl;
        }
    }
}

bool greaterThen(std::vector<int> a, std::vector<int> b) {
    return a > b;
}

int main() 
{
  try 
  {
     std::vector<std::vector<int>> ip_pool;


        for(std::string line; std::getline(std::cin, line);)
        {

            // std::string line = ips[i];
            
            // slice characters until it's not next column(\t)
            std::string str = split(line, '\t');

            // slice ip adress by dot(.)
            ip_pool.push_back(castToInt(str, '.'));
        }


        // selectionSort(ip_pool);

        std::sort(ip_pool.begin(), ip_pool.end(), greaterThen);

        const int LAST_INDEX_OF_IP_PART = 3;

        for(auto& ip : ip_pool) {
            
            for(int i = 0; i < 4; i++) 
            {
                std::cout << ip[i];
                if(i != LAST_INDEX_OF_IP_PART) {
                    std::cout << '.';
                }
            }
            std::cout << std::endl;
        }


        showIpByCondition(ip_pool, 0, 1);

        for(auto& ip : ip_pool) {
            if(ip[0] == 46 && ip[1] == 70) 
            {
                 for(int i = 0; i < 4; i++) 
                {
                    std::cout << ip[i];
                    if(i < 3) {
                        std::cout << '.';
                    }
                }
                std::cout << std::endl;
            }
        }

        for(auto& ip : ip_pool) 
        {
            
            bool findNumber = false;
            
            for(int i = 0; i < 4; i++) 
            {
              if(ip[i] == 46) {
                  findNumber = true;
                  break;
              }
            }

            if(findNumber) 
            {
                for(int i = 0; i < 4; i++) 
                {
                  std::cout << ip[i];
                  if(i < 3) 
                  {
                      std::cout << '.';
                  }
                }
                std::cout << std::endl;
                findNumber = false;
            }
            
        }
                
    } 
    catch(const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}