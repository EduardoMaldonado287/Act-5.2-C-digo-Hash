#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;
// #include "Node.h"
// #include "hashMap.h"

string getOnlyIpPart(string ipAndPort)
{
    int portPosition = ipAndPort.find_first_of(':');
    string ip = ipAndPort.substr(0, portPosition);
    return ip;
}

int main()
{
    unordered_map<string, string> umap;
    int counter;
    string month, hour, con, ipAndPort, description, currentIpAddressString, day, dominio;
    ifstream logFile("bitacora-5_2.txt");

    if (logFile.is_open())
    {
        getline(logFile, description);
 
        while (logFile >> month >> day >> hour >> ipAndPort)
        {
            getline(logFile, description);
            currentIpAddressString = getOnlyIpPart(ipAndPort);
            
            dominio += month;
            dominio += " ";
            dominio += day;
            dominio += " ";
            dominio += hour;
            dominio += description;

            // cout << dominio << endl;

            umap["dominio"] = dominio;
            umap["ipAddress"] = currentIpAddressString;

            counter++;
            string key = "ipAddress";

            // if (umap.find(key) != umap.end())
            // {
            //     // cout << key << "FOUND" << endl; 
            //     counter++;
            //     // cout << counter << endl;
            // }
            umap.key_eq
            umap.at("ipAddress", key)
     
            dominio = "";
        }

        // unordered_map<string, string>:: iterator itr;
        // cout << "\nAll Elements : \n";
        // for (itr = umap.begin(); itr != umap.end(); itr++)
        // {
        //     cout << itr->first << "  " << itr->second << endl;
        // }
        cout << counter << endl;

    }
    return 0;
}