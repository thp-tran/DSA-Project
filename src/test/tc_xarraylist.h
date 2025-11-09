#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "util/Point.h"
using namespace std;

void xlistDemo1(){
    XArrayList<int> iList;
    for(int i = 0; i< 10 ; i++)
        iList.add(i, i*i);
    
    //iList.dump();
    for(XArrayList<int>::Iterator it=iList.begin(); it != iList.end(); it++ )
        cout << *it << ", found at: " << iList.indexOf(*it) << endl;
    cout << endl;
    int item = 120;
    int foundIdx = iList.indexOf(item);
    cout    << "lookup for " << item  << " found at: " << foundIdx << endl;
}

void xlistDemo2(){
    XArrayList<Point> alist;
    alist.add(Point(23.2f, 25.4f));
    alist.add(Point(24.6f, 23.1f));  
    alist.println();
}

void xlistDemo3(){
    XArrayList<Point> alist;
    alist.add(Point(23.2f, 25.4f));
    alist.add(Point(24.6f, 23.1f));  
    
    int idx1 = alist.indexOf(Point(24.6f, 23.1f));
    int idx2 = alist.indexOf(Point(24.61f, 23.1f));
    
    cout << "result 1 : " << idx1 << endl;
    cout << "result 2 : " << idx2 << endl;
}

void xlistDemo4(){
    XArrayList<Point*> list1(&XArrayList<Point*>::free, &Point::pointEQ);
    list1.add(new Point(23.2f, 25.4f));
    list1.add(new Point(24.6f, 23.1f));  
    list1.add(new Point(12.5f, 22.3f)); 
    
    for(XArrayList<Point*>::Iterator it = list1.begin(); it != list1.end(); it++)
        cout << **it << endl;
    
    Point* p1 = new Point(24.6f, 23.1f); //found in list
    Point* p2 = new Point(124.6f, 23.1f); //not found
    cout << *p1 << "=> " << (list1.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list1.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p2) << endl;
    
    ///Different results if not pass &Point::equals
    cout << endl << endl;
    XArrayList<Point*> list2(&XArrayList<Point*>::free);
    list2.add(new Point(23.2f, 25.4f));
    list2.add(new Point(24.6f, 23.1f));  
    list2.add(new Point(12.5f, 22.3f)); 
    
    for(XArrayList<Point*>::Iterator it = list2.begin(); it != list2.end(); it++)
        cout << **it << endl;
    
    cout << *p1 << "=> " << (list2.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list2.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list2.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list2.indexOf(p2) << endl;
    
    delete p1; delete p2;
}

void xlistDemo_removeItem() {
    cout << "======== DEMO removeItem() with Point* ========" << endl;

    XArrayList<Point*> list(&XArrayList<Point*>::free, &Point::pointEQ);

    list.add(new Point(1.0f, 2.0f, 3.0f));
    list.add(new Point(3.0f, 4.0f, 5.0f));
    list.add(new Point(5.0f, 6.0f, 7.0f));

    cout << "Initial list:" << endl;
    for (XArrayList<Point*>::Iterator it = list.begin(); it != list.end(); it++)
        cout << **it << endl;

    Point* pFound = new Point(3.0f, 4.0f, 5.0f);
    Point* pNotFound = new Point(99.0f, 99.0f, 99.0f);

    cout << endl << "Removing existing point: " << *pFound << endl;
    bool removed1 = list.removeItem(pFound, [](Point* p){ delete p; });
    cout << "Result: " << (removed1 ? "Removed successfully" : "Not found") << endl;

    cout << "List after removing:" << endl;
    for (XArrayList<Point*>::Iterator it = list.begin(); it != list.end(); it++)
        cout << **it << endl;

    cout << endl << "Removing non-existing point: " << *pNotFound << endl;
    bool removed2 = list.removeItem(pNotFound, [](Point* p){ delete p; });
    cout << "Result: " << (removed2 ? "Removed successfully" : "Not found") << endl;

    cout << endl << "Final list:" << endl;
    for (XArrayList<Point*>::Iterator it = list.begin(); it != list.end(); it++)
        cout << **it << endl;

    delete pFound;
    delete pNotFound;

    cout << "======== END DEMO ========" << endl;
}
