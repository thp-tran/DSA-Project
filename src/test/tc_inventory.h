#include <iostream>
#include "app/inventory.h" 

using namespace std;

void tc_inventory1001() {
    int arr[] = {1, 2, 3, 4, 5};
    List1D<int> list1D(arr, 5);
    
    cout << list1D.toString() << endl;
}

void tc_inventory1002() {
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    
    List1D<int> arr2D[] = { List1D<int>(row0, 3), List1D<int>(row1, 3), List1D<int>(row2, 3) };
    
    List2D<int> matrix(arr2D, 3);
    
    cout << matrix.toString() << endl;
}

void tc_inventory1003() {
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);
    
    cout << inventory.toString() << endl;
}

void tc_inventory1004(){
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);
    
    InventoryAttribute attrD1("weight", 15);
    InventoryAttribute attrD2("height", 140);
    InventoryAttribute arrD[] = { attrD1, attrD2 };
    int numAttrD = sizeof(arrD) / sizeof(arrD[0]);
    List1D<InventoryAttribute> listAttrD(arrD, numAttrD);
    inventory.addProduct(listAttrD, "Product D", 40);
    cout << "\nAfter adding Product D:" << endl;
    cout << inventory.toString() << endl;
}

void tc_inventory1005(){
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);

    List1D<string> queryResult = inventory.query("weight", 10, 20, 30, true);
    cout << "\nQuery result (weight between 10 and 20, quantity >= 30):" << endl;
    cout << queryResult << endl;
}

void tc_inventory1006(){
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);

    inventory.addProduct(listAttrA, "Product A", 20);
    cout << "\nAfter adding duplicate of Product A:" << endl;
    cout << inventory.toString() << endl;
    inventory.removeDuplicates();
    cout << "\nAfter removing duplicates:" << endl;
    cout << inventory.toString() << endl;
}

void tc_inventory1007() {
    cout << "\n===== TEST CASE: tc_inventory1007 =====" << endl;

    // --- Tạo dữ liệu ban đầu ---
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    List1D<InventoryAttribute> listAttrA(arrA, 2);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    List1D<InventoryAttribute> listAttrB(arrB, 3);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute attrC2("height", 75);
    InventoryAttribute arrC[] = { attrC1, attrC2 };
    List1D<InventoryAttribute> listAttrC(arrC, 2);

    // Gom các list vào matrix 2D
    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    // Tên và số lượng sản phẩm
    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);

    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    // --- Tạo InventoryManager ---
    InventoryManager inventory(attributesMatrix, productNames, quantities);

    // --- In thông tin kho ban đầu ---
    cout << "\n=== INVENTORY BEFORE QUERY ===" << endl;
    cout << inventory.toString() << endl;

    // --- Thiết lập truy vấn ---
    string targetAttr = "height";
    int minVal = 50;
    int maxVal = 150;
    int minQuantity = 40;
    bool includeLowerBound = false;

    cout << "\n=== QUERY CONDITION ===" << endl;
    cout << "Attribute: " << targetAttr << endl;
    cout << "Range: [" << minVal << ", " << maxVal << "]" << endl;
    cout << "Min Quantity: " << minQuantity << endl;
    cout << "Include Lower Bound: " << (includeLowerBound ? "true" : "false") << endl;

    // --- Thực hiện truy vấn ---
    List1D<string> queryResult = inventory.query(targetAttr, minVal, maxVal, minQuantity, includeLowerBound);

    // --- In kết quả ---
    cout << "\n=== QUERY RESULT ===" << endl;
    if (queryResult.size() == 0) {
        cout << "⚠️  No products matched the query." << endl;
    } else {
        cout << queryResult << endl;

    cout << "\n===== END TEST CASE =====" << endl;
    }
}
