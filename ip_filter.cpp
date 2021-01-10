#include <iostream>
#include <string>
#include <vector>

std::string split(const std::string &str, char d)
{
    std::string r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);

    return str.substr(start, stop - start);
}

std::vector<int> castToInt(std::string line, char d)
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


void showIpByCondition(std::vector<std::vector<int>> listOfIps, int indexOfList, int numberOfCondition) {
  const int LAST_INDEX_OF_IP_PART = 3;
  int sizeOfPool = listOfIps.size();

  for(int index = 0; index < sizeOfPool; index++)
  {
   if(listOfIps[index][indexOfList] == numberOfCondition) 
     {
     for(int i = 0; i < 4; i++) 
      {
        std::cout << listOfIps[index][i];
        if(i != LAST_INDEX_OF_IP_PART) {
            std::cout << '.';
        }
      }
      std::cout << std::endl;
     }
  }
}

std::vector<std::vector<int>> selectionSort(std::vector<std::vector<int>> ip_pool) {

    int sizeOfPool = ip_pool.size();
    for(int startIndex = 0; startIndex < sizeOfPool - 1; startIndex++) 
    {
            
        int biggestIndex = startIndex;
         
        for(int currentIndex = startIndex + 1; currentIndex < sizeOfPool; currentIndex++) 
        {
            if(ip_pool[currentIndex][0] > ip_pool[biggestIndex][0]) 
            {
                    biggestIndex = currentIndex;
            }
            else if(ip_pool[currentIndex][0] == ip_pool[biggestIndex][0]) 
            {
                for(int i = 1; i < 4; i++) 
                {
                    if(ip_pool[currentIndex][i] > ip_pool[biggestIndex][i]) 
                    {
                        biggestIndex = currentIndex;
                        break;
                    }
                }

            }
                
        }

        std::swap(ip_pool[startIndex], ip_pool[biggestIndex]);

    }
    return ip_pool;
}


void showMessagePrintCondition() {
  std::cout << "<< print by condition >>" << std::endl;
}

int main(int argc, char const *argv[]) 
{
  try 
  {
     std::vector<std::vector<int>> ip_pool;

//         const char *ips[37] = {
// "113.162.145.156\t",
// "183.88.197.193\t",
// "49.74.228.23\t",
// "124.224.214.76\t",
// "107.185.11.105\t",
// "41.235.16.95\t",
// "68.37.186.197\t",
// "188.72.127.199\t",
// "173.171.247.113\t",
// "173.171.247.113\t",
// "49.35.12.51\t",
// "67.167.96.234\t",
// "204.11.243.70\t",
// "182.58.201.28\t",
// "168.167.95.164\t",
// "153.151.156.27\t",
// "79.110.28.59\t",
// "37.188.189.227\t",
// "188.69.198.152\t",
// "98.196.145.69\t",
// "68.202.216.62\t",
// "68.202.216.62\t",
// "68.202.216.62\t",
// "5.189.203.79\t",
// "197.42.2.124\t",
// "95.10.3.43\t",
// "180.251.148.71\t",
// "113.144.6.220\t",
// "89.236.227.204\t",
// "67.250.31.212\t",
// "67.250.31.212\t",
// "177.66.186.82\t",
// "107.209.121.224\t",
// "213.103.211.108\t",
// "27.49.172.153\t",
// "78.158.5.183\t",
// "78.158.5.183\t"
// };


        for(std::string line; std::getline(std::cin, line);)
        // int size = 37;
        // for(int i = 0; i < size; i++)
        {

            // std::string line = ips[i];
            
            // for end of input
            std::size_t found = line.find("end");
            if (found != std::string::npos) {
                break;
            }   
            // slice characters until it's not next column(\t)
            std::string str = split(line, '\t');

            // slice ip adress by dot(.)
            ip_pool.push_back(castToInt(str, '.'));
        }


        ip_pool = selectionSort(ip_pool);

        int sizeOfPool = ip_pool.size();

        const int LAST_INDEX_OF_IP_PART = 3;

        for (int index = 0; index < sizeOfPool; ++index)
        {
            for(int i = 0; i < 4; i++) 
            {
                std::cout << ip_pool[index][i];
                if(i != LAST_INDEX_OF_IP_PART) {
                    std::cout << '.';
                }
            }
            std::cout << std::endl;
        }

        showMessagePrintCondition();

        showIpByCondition(ip_pool, 0, 1);

        showMessagePrintCondition();

        for(int index = 0; index < sizeOfPool; index++)
        {
            if(ip_pool[index][0] == 46 && ip_pool[index][1] == 70) 
            {
                 for(int i = 0; i < 4; i++) 
                {
                     std::cout << ip_pool[index][i];
                    if(i != 4) {
                        std::cout << '.';
                    }
                }
                std::cout << std::endl;
            }
        }

        showMessagePrintCondition();

        showIpByCondition(ip_pool, 0, 46);

    } 
    catch(const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}