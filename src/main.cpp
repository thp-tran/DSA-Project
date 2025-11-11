#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "test/tc_dlinkedlist.h"
#include "test/tc_xarraylist.h"
#include "test/tc_inventory.h"

using namespace std;

void (*func_ptr[17])() = {
    dlistDemo1,
    dlistDemo2,
    dlistDemo3,
    dlistDemo4,
    dlistDemo5,
    dlistDemo6,
    xlistDemo1,
    xlistDemo2,
    xlistDemo3,
    xlistDemo4,
    xlistDemo_removeItem,
    tc_inventory1001,
    tc_inventory1002,
    tc_inventory1003,
    tc_inventory1004,
    tc_inventory1006,
    tc_inventory1007
};

void run(int func_idx)
{
    func_ptr[func_idx]();
}

int main(int argc, char **argv)
{
    cout << "Assignment-1" << endl;

    if (argc == 1) {
        cout << "No test index provided → running default test (tc_inventory1006)" << endl;
        tc_inventory1006();
    } else {
        int idx = stoi(argv[1]);
        if (idx >= 0 && idx < 17) {
            cout << "Running test index: " << idx << endl;
            run(idx);
        } else {
            cerr << "Invalid test index! Valid range: 0–15." << endl;
        }
    }

    return 0;
}