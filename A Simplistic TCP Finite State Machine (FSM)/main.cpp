#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <string>

using namespace std;


void print_vector(std::vector<int> data)
{
    for (int i = 0; i < data.size(); i++) 
    {
        cout << data[i] << ",";
    }
    cout << endl;
}

bool is_in(vector<int>& data, unsigned int lookUpValue) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == lookUpValue) {
            return true;
        }
    }
    return false;
}

unsigned int how_often(vector<int> data, unsigned int lookUpValue) {
    unsigned int total = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == lookUpValue)
            total += 1;
    }
    return total;
}



string traverse_TCP_states(const vector<string>& events) {
    map<string, map<string, string>> stateTransitions;
    stateTransitions["CLOSED"]["APP_PASSIVE_OPEN"] = "LISTEN";
    stateTransitions["CLOSED"]["APP_ACTIVE_OPEN"] = "SYN_SENT";
    stateTransitions["LISTEN"]["RCV_SYN"] = "SYN_RCVD";
    stateTransitions["LISTEN"]["APP_SEND"] = "SYN_SENT";
    stateTransitions["LISTEN"]["APP_CLOSE"] = "CLOSED";
    stateTransitions["SYN_RCVD"]["APP_CLOSE"] = "FIN_WAIT_1";
    stateTransitions["SYN_RCVD"]["RCV_ACK"] = "ESTABLISHED";
    stateTransitions["SYN_SENT"]["RCV_SYN"] = "SYN_RCVD";
    stateTransitions["SYN_SENT"]["RCV_SYN_ACK"] = "ESTABLISHED";
    stateTransitions["SYN_SENT"]["APP_CLOSE"] = "CLOSED";
    stateTransitions["ESTABLISHED"]["APP_CLOSE"] = "FIN_WAIT_1";
    stateTransitions["ESTABLISHED"]["RCV_FIN"] = "CLOSE_WAIT";
    stateTransitions["FIN_WAIT_1"]["RCV_FIN"] = "CLOSING";
    stateTransitions["FIN_WAIT_1"]["RCV_FIN_ACK"] = "TIME_WAIT";
    stateTransitions["FIN_WAIT_1"]["RCV_ACK"] = "FIN_WAIT_2";
    stateTransitions["CLOSING"]["RCV_ACK"] = "TIME_WAIT";
    stateTransitions["FIN_WAIT_2"]["RCV_FIN"] = "TIME_WAIT";
    stateTransitions["TIME_WAIT"]["APP_TIMEOUT"] = "CLOSED";
    stateTransitions["CLOSE_WAIT"]["APP_CLOSE"] = "LAST_ACK";
    stateTransitions["LAST_ACK"]["RCV_ACK"] = "CLOSED";
    string startState = "CLOSED";
    for (auto element : events) {
        startState = stateTransitions[startState][element];
    }
    if (startState.size() == 0)
        return "ERROR";
    return startState;
}


int main()
{
    using vs = std::vector<std::string>;

    vs test1 = { "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN" };
    vs test2 = { "APP_PASSIVE_OPEN",  "RCV_SYN","RCV_ACK" };
    vs test3 = { "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE" };
    vs test4 = { "APP_ACTIVE_OPEN" };
    vs test5 = { "APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND" };

    cout << traverse_TCP_states(test1) << endl;
    cout << traverse_TCP_states(test2) << endl;
    cout << traverse_TCP_states(test3) << endl;
    cout << traverse_TCP_states(test4) << endl;
    cout << traverse_TCP_states(test5) << endl;

    return 0;
}