// #include <iostream>
// #include <iomanip>
// #include <sstream>
// #include <string>
// #include "test/tc_dlinkedlist.h"
// #include "test/tc_xarraylist.h"
// #include "test/tc_inventory.h"

// using namespace std;

// void (*func_ptr[17])() = {
//     dlistDemo1,
//     dlistDemo2,
//     dlistDemo3,
//     dlistDemo4,
//     dlistDemo5,
//     dlistDemo6,
//     xlistDemo1,
//     xlistDemo2,
//     xlistDemo3,
//     xlistDemo4,
//     xlistDemo_removeItem,
//     tc_inventory1001,
//     tc_inventory1002,
//     tc_inventory1003,
//     tc_inventory1004,
//     tc_inventory1006,
//     tc_inventory1007
// };

// void run(int func_idx)
// {
//     func_ptr[func_idx]();
// }

// int main(int argc, char **argv)
// {
//     cout << "Assignment-1" << endl;

//     if (argc == 1) {
//         cout << "No test index provided → running default test (tc_inventory1006)" << endl;
//         tc_inventory1006();
//     } else {
//         int idx = stoi(argv[1]);
//         if (idx >= 0 && idx < 17) {
//             cout << "Running test index: " << idx << endl;
//             run(idx);
//         } else {
//             cerr << "Invalid test index! Valid range: 0–15." << endl;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <limits>
using namespace std;
#include "test/tc_dlinkedlist.h"
#include "test/tc_xarraylist.h"
#include "test/tc_inventory.h"
// Khai báo prototype các test (đã có trong file của bạn)
// void testIntListBasic();
// void testPointPtrWithEquals();
// void testPointPtrWithoutEquals();
// void testPointValueIndexOf();
// void testPointPtrCustomComparator();
// void testGetAndModify();

// ================== Helper Functions ==================
void wait()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

int menuSelect(const string &title, const vector<string> &items)
{
    while (true)
    {
        cout << "\n==================== " << title << " ====================\n";
        for (int i = 0; i < (int)items.size(); i++)
            cout << " " << (i + 1) << ". " << items[i] << endl;
        cout << " 0. Back/Exit\n";
        cout << "=========================================================\n";
        cout << "Enter choice: ";

        int c;
        cin >> c;

        if (cin.fail())
        {
            clearInput();
            cout << "Invalid input! Try again.\n";
            continue;
        }

        return c;
    }
}

// ================== MAIN ==================
int main()
{
    while (true)
    {

        int group = menuSelect("MAIN MENU", {"DLinkedList Tests",
                                             "XArrayList Tests",
                                             "Inventory Tests"});

        if (group == 0)
        {
            cout << "Exiting program... Goodbye!\n";
            return 0;
        }

        // ------------------- DLinkedList MENU -------------------
        if (group == 1)
        {
            int c = menuSelect("DLinkedList Tests", {"List<int> basic operations",
                                                     "Point* WITH custom equals",
                                                     "Point* WITHOUT custom equals",
                                                     "Point value type indexOf",
                                                     "Point* custom comparator",
                                                     "get(index) returns reference + modify"});

            switch (c)
            {
            case 1:
                testIntListBasic();
                break;
            case 2:
                testPointPtrWithEquals();
                break;
            case 3:
                testPointPtrWithoutEquals();
                break;
            case 4:
                testPointValueIndexOf();
                break;
            case 5:
                testPointPtrCustomComparator();
                break;
            case 6:
                testGetAndModify();
                break;
            default:
                continue;
            }
            wait();
        }

        // ------------------- XArrayList MENU -------------------
        if (group == 2)
        {
            int c = menuSelect("XArrayList Tests", {"Basic int operations",
                                                    "Point value print",
                                                    "Point exact indexOf test",
                                                    "Point* WITH equals",
                                                    "removeItem(Point*)"});

            switch (c)
            {
            case 1:
                testXArrayList_IntBasic();
                break;
            case 2:
                testXArrayList_PointValuePrint();
                break;
            case 3:
                testXArrayList_PointIndexOf();
                break;
            case 4:
                testXArrayList_PointPtrWithEquals();
                break;
            case 5:
                testXArrayList_RemoveItem();
                break;
            default:
                continue;
            }
            wait();
        }

        // ------------------- Inventory MENU -------------------
        if (group == 3)
        {
            int c = menuSelect("Inventory Tests", {"List1D<int> basic",
                                                   "List2D<int> matrix",
                                                   "Build full inventory",
                                                   "Add product",
                                                   "Query simple",
                                                   "Remove duplicates",
                                                   "Complex query"});

            switch (c)
            {
            case 1:
                testInventory_List1DInt();
                break;
            case 2:
                testInventory_List2DInt();
                break;
            case 3:
                testInventory_BuildInventory();
                break;
            case 4:
                testInventory_AddProduct();
                break;
            case 5:
                testInventory_QuerySimple();
                break;
            case 6:
                testInventory_RemoveDuplicates();
                break;
            case 7:
                testInventory_QueryComplex();
                break;
            default:
                continue;
            }
            wait();
        }
    }

    return 0;
}