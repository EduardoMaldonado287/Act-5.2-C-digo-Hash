#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Node.h"
using namespace std;
// #include "hashMap.h"

string getOnlyIpPart(string ipAndPort)
{
    int portPosition = ipAndPort.find_first_of(':');
    string ip = ipAndPort.substr(0, portPosition);
    return ip;
}

int main()
{
    vector<string> direccionesIp;
    unordered_map<string, string> umap;
    int counter = -1, countF, countNF, counterVec = 91910;
    string month, hour, con, ipAndPort, description, currentIpAddressString, day, dominio;
    ifstream logFile("bitacora-5_2.txt");


    string ip = "IPADDRESS";
    string dom = "DOMINIO";

    if (logFile.is_open())
    {
        getline(logFile, description);
 
        while (logFile >> month >> day >> hour >> ipAndPort)
        {
            getline(logFile, description);
            currentIpAddressString = getOnlyIpPart(ipAndPort);
            
            dominio = "";
            dominio += month;
            dominio += " ";
            dominio += day;
            dominio += " ";
            dominio += hour;
            dominio += description;
            direccionesIp.push_back(currentIpAddressString);

            // umap[ip] = currentIpAddressString;
            // umap[dom] = dominio; 
            if (umap.find(currentIpAddressString) != umap.end())
            {
                countF++;
            } else {
                countNF++;
            }
            umap.insert(make_pair(currentIpAddressString, dominio));
        }

        // for (auto itr = umap.begin(); itr != umap.end(); itr++)
        // {
        //     cout << "KEY: " << itr->first << " Value: " << itr-> second << endl;
        //     cout << counter++ << endl;
        // }
    }
    cout << countF << endl;
    cout << countNF << endl;
    return 0;
}