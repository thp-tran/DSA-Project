#include <iostream>
#include <iomanip>
#include "list/DLinkedList.h"
#include "util/Point.h"
using namespace std;

// ================================================================
// TEST 1: Test DLinkedList<int> add(), iterator, println()
// ================================================================
void testIntListBasic(){
    cout << "\n==================== TEST 1: Basic operations with List<int> ====================\n";

    List<int> dlist;
    cout << "Adding 20 integer items (value = index^2)...\n";
    for(int i = 0; i < 20; i++)
        dlist.add(i, i*i);

    cout << "\nList printed using println():\n";
    dlist.println();

    cout << "\nList printed using iterator manually:\n";
    for(List<int>::Iterator it = dlist.begin(); it != dlist.end(); it++)
        cout << *it << " ";
    cout << "\n";
}


// ================================================================
// TEST 2: DLinkedList<Point*> with equals (Point::pointEQ)
// ================================================================
void testPointPtrWithEquals(){
    cout << "\n==================== TEST 2: DLinkedList<Point*> WITH custom equals ====================\n";

    DLinkedList<Point*> list1(&DLinkedList<Point*>::free, &Point::pointEQ);

    cout << "Adding Points to list...\n";
    list1.add(new Point(23.2f, 25.4f));
    list1.add(new Point(24.6f, 23.1f));
    list1.add(new Point(12.5f, 22.3f));

    cout << "\nList1 contents:\n";
    for(auto it = list1.begin(); it != list1.end(); it++)
        cout << "  - " << **it << endl;

    cout << "\nSearching for test Points...\n";

    Point* p1 = new Point(24.6f, 23.1f);   // found in list
    Point* p2 = new Point(124.6f, 23.1f);  // not found

    cout << "Check p1 = " << *p1 << endl;
    cout << "  contains?  " << (list1.contains(p1) ? "YES" : "NO") << endl;
    cout << "  indexOf =  " << list1.indexOf(p1) << endl;

    cout << "\nCheck p2 = " << *p2 << endl;
    cout << "  contains?  " << (list1.contains(p2) ? "YES" : "NO") << endl;
    cout << "  indexOf =  " << list1.indexOf(p2) << endl;

    delete p1;
    delete p2;
}


// ================================================================
// TEST 3: DLinkedList<Point*> without equals → pointer comparison
// ================================================================
void testPointPtrWithoutEquals(){
    cout << "\n==================== TEST 3: DLinkedList WITHOUT custom equals ====================\n";
    cout << "Note: Comparison is BY POINTER, not by value!\n";
    cout << "=> Even if x,y are equal, contains() will return FALSE.\n\n";

    DLinkedList<Point*> list2(&DLinkedList<Point*>::free);

    cout << "Adding Points to list...\n";
    list2.add(new Point(23.2f, 25.4f));
    list2.add(new Point(24.6f, 23.1f));
    list2.add(new Point(12.5f, 22.3f));

    cout << "\nList2 contents:\n";
    for(auto it = list2.begin(); it != list2.end(); it++)
        cout << "  - " << **it << endl;

    Point* p1 = new Point(24.6f, 23.1f);

    cout << "\nSearching p1 = " << *p1 << "\n";
    cout << "  contains? " << (list2.contains(p1) ? "YES" : "NO") << endl;
    cout << "  indexOf  = " << list2.indexOf(p1) << endl;

    delete p1;
}


// ================================================================
// TEST 4: DLinkedList<Point> (not pointer) + test indexOf
// ================================================================
void testPointValueIndexOf(){
    cout << "\n==================== TEST 4: DLinkedList<Point> VALUE TYPE ====================\n";

    DLinkedList<Point> dList;

    cout << "Adding Point values...\n";
    dList.add(Point(1.5, 3.5));
    dList.add(Point(2.5, 4.5));
    dList.add(Point(1.6, 3.1));

    cout << "\nTesting indexOf(Point)...\n";
    Point p(1.6, 3.1);
    cout << "Searching for: " << p << endl;
    cout << "Found at index: " << dList.indexOf(p) << endl;
}


// ================================================================
// TEST 5: DLinkedList<Point*> with custom comparator + stringifier
// ================================================================
bool pointComparator(Point*& p1, Point*& p2){
    return (p1->getX() == p2->getX()) && (p1->getY() == p2->getY());
}
string LpointPtr2Str(Point*& ptr){
    stringstream os;
    os << "(" << ptr->getX() << ", " << ptr->getY() << ")";
    return os.str();
}

void testPointPtrCustomComparator(){
    cout << "\n==================== TEST 5: Using custom comparator + custom toString ====================\n";

    DLinkedList<Point*> dList(&DLinkedList<Point*>::free, &pointComparator);

    cout << "Adding Point objects...\n";
    dList.add(new Point(1.5, 3.5));
    dList.add(new Point(2.5, 4.5));
    dList.add(new Point(1.6, 3.1));

    cout << "\nList printed using custom stringifier:\n";
    dList.println(&LpointPtr2Str);

    cout << "\nTesting indexOf with custom comparator...\n";
    Point* p = new Point(1.6, 3.1);
    cout << *p << " found at index: " << dList.indexOf(p) << endl;

    delete p;
}


// ================================================================
// TEST 6: Test reference returned by get() and modifying list item
// ================================================================
void testGetAndModify(){
    cout << "\n==================== TEST 6: get(index) returns REFERENCE ====================\n";

    List<int> list;
    cout << "Adding 10 items to list...\n";
    for(int i = 0; i < 10; i++)
        list.add(i, i*i);

    cout << setw(25) << left << "Original list: ";
    list.println();

    cout << "Modifying list[5] through reference...\n";
    int& item = list.get(5);
    item = 999;

    cout << setw(25) << left << "After modification: ";
    list.println();
}
