#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "util/Point.h"
using namespace std;

void testXArrayList_IntBasic(){
    cout << "\n==================== XARRAYLIST TEST 1: Basic integer operations ====================\n";

    XArrayList<int> iList;

    cout << "Adding items: value = i*i\n";
    for(int i = 0; i < 10; i++)
        iList.add(i, i*i);

    cout << "\nIterating list and printing indexOf for each element:\n";
    for(auto it = iList.begin(); it != iList.end(); it++)
        cout << "  value = " << *it << " | indexOf = " << iList.indexOf(*it) << endl;

    int item = 120;
    cout << "\nSearching for " << item << "...\n";
    cout << "Result index = " << iList.indexOf(item) << endl;
}

void testXArrayList_PointValuePrint(){
    cout << "\n==================== XARRAYLIST TEST 2: Point (value type) print ====================\n";

    XArrayList<Point> alist;

    cout << "Adding Point values...\n";
    alist.add(Point(23.2f, 25.4f));
    alist.add(Point(24.6f, 23.1f));

    cout << "\nPrinting list using println():\n";
    alist.println();
}

void testXArrayList_PointIndexOf(){
    cout << "\n==================== XARRAYLIST TEST 3: indexOf(Point) exact match ====================\n";

    XArrayList<Point> alist;
    alist.add(Point(23.2f, 25.4f));
    alist.add(Point(24.6f, 23.1f));

    cout << "Searching for exact existing Point...\n";
    cout << "Index: " << alist.indexOf(Point(24.6f, 23.1f)) << endl;

    cout << "Searching for slightly different Point...\n";
    cout << "Index: " << alist.indexOf(Point(24.61f, 23.1f)) << endl;
}

void testXArrayList_PointPtrWithEquals(){
    cout << "\n==================== XARRAYLIST TEST 4: Point* WITH custom equals ====================\n";

    XArrayList<Point*> list1(&XArrayList<Point*>::free, &Point::pointEQ);

    list1.add(new Point(23.2f, 25.4f));
    list1.add(new Point(24.6f, 23.1f));  
    list1.add(new Point(12.5f, 22.3f)); 

    cout << "List contents:\n";
    for(auto it = list1.begin(); it != list1.end(); it++)
        cout << "  - " << **it << endl;

    Point* p1 = new Point(24.6f, 23.1f);
    Point* p2 = new Point(124.6f, 23.1f);

    cout << "\nSearching p1 = " << *p1 << endl;
    cout << "contains? " << (list1.contains(p1) ? "YES" : "NO") << endl;
    cout << "indexOf  = " << list1.indexOf(p1) << endl;

    cout << "\nSearching p2 = " << *p2 << endl;
    cout << "contains? " << (list1.contains(p2) ? "YES" : "NO") << endl;
    cout << "indexOf  = " << list1.indexOf(p2) << endl;

    delete p1;
    delete p2;
}

void testXArrayList_RemoveItem(){
    cout << "\n==================== XARRAYLIST TEST 5: removeItem(Point*) ====================\n";

    XArrayList<Point*> list(&XArrayList<Point*>::free, &Point::pointEQ);

    list.add(new Point(1.0f, 2.0f));
    list.add(new Point(3.0f, 4.0f));
    list.add(new Point(5.0f, 6.0f));

    cout << "Initial list:\n";
    for(auto it = list.begin(); it != list.end(); it++)
        cout << "  - " << **it << endl;

    Point* found = new Point(3.0f, 4.0f);
    Point* notFound = new Point(99.0f, 99.0f);

    cout << "\nRemoving existing: " << *found << endl;
    bool ok1 = list.removeItem(found, [](Point* p){ delete p; });
    cout << "Result: " << (ok1 ? "Removed" : "Not found") << endl;

    cout << "\nList after removal:\n";
    for(auto it = list.begin(); it != list.end(); it++)
        cout << "  - " << **it << endl;

    cout << "\nRemoving non-existing: " << *notFound << endl;
    bool ok2 = list.removeItem(notFound, [](Point* p){ delete p; });
    cout << "Result: " << (ok2 ? "Removed" : "Not found") << endl;

    delete found;
    delete notFound;
}
