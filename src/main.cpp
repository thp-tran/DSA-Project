#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "test/tc_dlinkedlist.h"
#include "test/tc_xarraylist.h"
#include "test/tc_inventory.h"

using namespace std;

void (*func_ptr[16])() = {
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
    tc_inventory1006
};

void run(int func_idx)
{
    func_ptr[func_idx]();
}

int main(int argc, char **argv)
{
    // cout << "Assignment-1" << endl;
    // if (argc == 1) {
    //     tc_inventory1006();
    // }
    cout << "Hello from main\n";
    IList<int> *list1 = new XArrayList<int>(NULL, NULL, 10);
    cout << "New list\n";
    list1->add(19);
    cout << "Add 19\n";
    list1->add(20);
    cout << "Add 20\n";
    string s = list1->toString(NULL);
    cout << s << endl;
    return 0;
}