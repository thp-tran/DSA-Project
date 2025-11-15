#include <iostream>
#include "app/inventory.h" 

using namespace std;

//New tc
void testInventory_List1DInt() {
    cout << "\n==================== INVENTORY TEST: List1D<int> Basic ====================\n";

    cout << "[STEP] Creating simple 1D array: {1, 2, 3, 4, 5}\n";
    int arr[] = {1, 2, 3, 4, 5};

    cout << "[STEP] Building List1D<int> from array...\n";
    List1D<int> list1D(arr, 5);

    cout << "[RESULT] List1D content:\n";
    cout << list1D.toString() << endl;
}

void testInventory_List2DInt() {
    cout << "\n==================== INVENTORY TEST: List2D<int> Matrix ====================\n";

    cout << "[STEP] Creating 3 rows: {1,2,3}, {4,5,6}, {7,8,9}\n";

    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};

    List1D<int> arr2D[] = {
        List1D<int>(row0, 3),
        List1D<int>(row1, 3),
        List1D<int>(row2, 3)
    };

    cout << "[STEP] Building List2D<int> matrix...\n";
    List2D<int> matrix(arr2D, 3);

    cout << "[RESULT] Matrix content:\n";
    cout << matrix.toString() << endl;
}

void testInventory_BuildInventory() {
    cout << "\n==================== INVENTORY TEST: Build Inventory ====================\n";

    cout << "[STEP] Creating attribute lists for 3 products...\n";

    InventoryAttribute arrA[] = { {"weight",10}, {"height",156} };
    InventoryAttribute arrB[] = { {"weight",20}, {"depth",24}, {"height",100} };
    InventoryAttribute arrC[] = { {"color",2} };

    List1D<InventoryAttribute> listAttrA(arrA, 2);
    List1D<InventoryAttribute> listAttrB(arrB, 3);
    List1D<InventoryAttribute> listAttrC(arrC, 1);

    cout << "[STEP] Creating attributes matrix (3 rows)...\n";
    List1D<InventoryAttribute> attrs[] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> matrix(attrs, 3);

    cout << "[STEP] Creating product names + quantities...\n";
    string names[] = { "Product A", "Product B", "Product C" };
    int qty[] = { 50, 30, 20 };

    InventoryManager inventory(matrix, List1D<string>(names,3), List1D<int>(qty,3));

    cout << "[RESULT] Inventory created successfully:\n";
    cout << inventory.toString() << endl;
}

void testInventory_AddProduct() {
    cout << "\n==================== INVENTORY TEST: Add Product ====================\n";

    cout << "[STEP] Building initial inventory with 3 products...\n";

    InventoryAttribute arrA[] = { {"weight",10}, {"height",156} };
    InventoryAttribute arrB[] = { {"weight",20}, {"depth",24}, {"height",100} };
    InventoryAttribute arrC[] = { {"color",2} };

    List1D<InventoryAttribute> listA(arrA, 2);
    List1D<InventoryAttribute> listB(arrB, 3);
    List1D<InventoryAttribute> listC(arrC, 1);

    List1D<InventoryAttribute> rows[] = { listA, listB, listC };
    List2D<InventoryAttribute> matrix(rows, 3);

    string names[] = { "Product A", "Product B", "Product C" };
    int qty[] = { 50, 30, 20 };

    InventoryManager inventory(matrix, List1D<string>(names,3), List1D<int>(qty,3));

    cout << "[INFO] Initial inventory:\n" << inventory.toString() << endl;

    cout << "[STEP] Creating new product: Product D\n";
    InventoryAttribute arrD[] = { {"weight",15}, {"height",140} };
    List1D<InventoryAttribute> listD(arrD, 2);

    cout << "[STEP] Adding Product D with qty = 40...\n";
    inventory.addProduct(listD, "Product D", 40);

    cout << "[RESULT] Updated inventory:\n";
    cout << inventory.toString() << endl;
}

void testInventory_QuerySimple() {
    cout << "\n==================== INVENTORY TEST: Query Simple ====================\n";

    cout << "[STEP] Preparing inventory...\n";

    InventoryAttribute arrA[] = { {"weight",10}, {"height",156} };
    InventoryAttribute arrB[] = { {"weight",20}, {"depth",24}, {"height",100} };
    InventoryAttribute arrC[] = { {"color",2} };

    List1D<InventoryAttribute> rows[] = {
        List1D<InventoryAttribute>(arrA, 2),
        List1D<InventoryAttribute>(arrB, 3),
        List1D<InventoryAttribute>(arrC, 1)
    };

    List2D<InventoryAttribute> matrix(rows, 3);

    string names[] = { "Product A", "Product B", "Product C" };
    int qty[] = { 50, 30, 20 };

    InventoryManager inventory(matrix, List1D<string>(names,3), List1D<int>(qty,3));

    cout << "[INFO] Inventory loaded:\n" << inventory.toString() << endl;

    cout << "[STEP] Running query: weight between 10 and 20, qty >= 30\n";
    List1D<string> result = inventory.query("weight", 10, 20, 30, true);

    cout << "[RESULT] Query output:\n";
    cout << result << endl;
}

void testInventory_RemoveDuplicates() {
    cout << "\n==================== INVENTORY TEST: Remove Duplicates ====================\n";

    cout << "[STEP] Building inventory...\n";

    InventoryAttribute arrA[] = { {"weight",10}, {"height",156} };
    InventoryAttribute arrB[] = { {"weight",20}, {"depth",24}, {"height",100} };
    InventoryAttribute arrC[] = { {"color",2} };

    List1D<InventoryAttribute> rows[] = {
        List1D<InventoryAttribute>(arrA,2),
        List1D<InventoryAttribute>(arrB,3),
        List1D<InventoryAttribute>(arrC,1)
    };

    List2D<InventoryAttribute> matrix(rows, 3);

    string names[] = { "Product A", "Product B", "Product C" };
    int qty[] = { 50, 30, 20 };

    InventoryManager inventory(matrix, List1D<string>(names,3), List1D<int>(qty,3));

    cout << "[INFO] Initial inventory:\n" << inventory.toString() << endl;

    cout << "[STEP] Adding duplicate of Product A (qty=20)...\n";
    inventory.addProduct(rows[0], "Product A", 20);

    cout << "[INFO] Inventory AFTER adding duplicate:\n" << inventory.toString() << endl;

    cout << "[STEP] Removing duplicates...\n";
    inventory.removeDuplicates();

    cout << "[RESULT] Inventory AFTER removing duplicates:\n" << inventory.toString() << endl;
}

void testInventory_QueryComplex() {
    cout << "\n==================== INVENTORY TEST: Query Complex ====================\n";

    cout << "[STEP] Preparing inventory with complex attributes...\n";

    InventoryAttribute arrA[] = { {"weight",10}, {"height",156} };
    InventoryAttribute arrB[] = { {"weight",20}, {"depth",24}, {"height",100} };
    InventoryAttribute arrC[] = { {"color",2}, {"height",75} };

    List1D<InventoryAttribute> rows[] = {
        List1D<InventoryAttribute>(arrA,2),
        List1D<InventoryAttribute>(arrB,3),
        List1D<InventoryAttribute>(arrC,2)
    };

    List2D<InventoryAttribute> matrix(rows, 3);

    string names[] = { "Product A", "Product B", "Product C" };
    int qty[] = { 50, 30, 20 };

    InventoryManager inventory(matrix, List1D<string>(names,3), List1D<int>(qty,3));

    cout << "[INFO] Loaded inventory:\n" << inventory.toString() << endl;

    cout << "[STEP] Running complex query:\n";
    cout << " - Attribute: height\n";
    cout << " - Range: [50, 150]\n";
    cout << " - Min qty: 40\n";
    cout << " - Include lower bound: false\n";

    List1D<string> result = inventory.query("height", 50, 150, 40, false);

    cout << "[RESULT] Query result:\n";
    cout << result << endl;
}
