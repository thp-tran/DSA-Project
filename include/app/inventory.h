#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "list/XArrayList.h"
#include "list/DLinkedList.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// -------------------- List1D --------------------
template <typename T>
class List1D
{
private:
    IList<T> *pList;

public:
    List1D();
    List1D(int num_elements);
    List1D(const T *array, int num_elements);
    List1D(const List1D<T> &other);
    virtual ~List1D();

    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    void add(int index, const T& value)
    {
        pList->add(index, value);
    }
    void removeAt(int index)
    {
        pList->removeAt(index);
    }
    string toString() const;

    friend ostream &operator<<(ostream &os, const List1D<T> &list)
    {
        os << list.toString();
        return os;
    }
    List1D<T> &operator=(const List1D<T> &other); 
};

// -------------------- List2D --------------------
template <typename T>
class List2D
{
private:
    IList<IList<T> *> *pMatrix;

public:
    List2D();
    List2D(List1D<T> *array, int num_rows);
    List2D(const List2D<T> &other);
    virtual ~List2D();
    void removeAt(int index)
    {
        pMatrix->removeAt(index);
    }
    int rows() const;
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;

    friend ostream &operator<<(ostream &os, const List2D<T> &matrix)
    {
        os << matrix.toString();
        return os;
    }
    List2D<T> &operator=(const List2D<T> &other);
};

struct InventoryAttribute
{
    string name;
    double value;
    InventoryAttribute() : name(""), value(0.0) {}
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    string toString() const { return name + ": " + to_string(value); }
    bool operator==(const InventoryAttribute& other) const {
        return name == other.name && value == other.value;
    }
    friend std::ostream &operator<<(std::ostream &os, const InventoryAttribute &attr) {
        return os << attr.toString();
    }
};

// -------------------- InventoryManager --------------------
class InventoryManager
{
private:
    List2D<InventoryAttribute> attributesMatrix;
    List1D<string> productNames;
    List1D<int> quantities;

public:
    InventoryManager();
    InventoryManager(const List2D<InventoryAttribute> &matrix,
                     const List1D<string> &names,
                     const List1D<int> &quantities);
    InventoryManager(const InventoryManager &other);

    int size() const;
    List1D<InventoryAttribute> getProductAttributes(int index) const;
    string getProductName(int index) const;
    int getProductQuantity(int index) const;
    void updateQuantity(int index, int newQuantity);
    void addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity);
    void removeProduct(int index);

    List1D<string> query(string attributeName, const double &minValue,
                         const double &maxValue, int minQuantity, bool ascending) const;

    void removeDuplicates();

    static InventoryManager merge(const InventoryManager &inv1,
                                  const InventoryManager &inv2);

    void split(InventoryManager &section1,
               InventoryManager &section2,
               double ratio) const;

    List2D<InventoryAttribute> getAttributesMatrix() const;
    List1D<string> getProductNames() const;
    List1D<int> getQuantities() const;
    string toString() const;
    bool checkSameAttributes(List1D<InventoryAttribute> a, List1D<InventoryAttribute> b)
    {
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                if(a.get(i).name == b.get(j).name && a.get(i).value != b.get(j).value)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    pList = new XArrayList<T>();
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
    pList = new XArrayList<T>();
    for(int i = 0; i < num_elements; i++)
    {
      pList->add(T());
    }
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    pList = new XArrayList<T>();
    for(int i = 0; i < num_elements; i++)
    {
        pList->add(array[i]);
    }
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
    pList = new XArrayList<T>();
    for(int i = 0; i < other.size(); i++)
    {
        pList->add(other.get(i));
    }
}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
    delete pList;
}

template <typename T>
List1D<T> &List1D<T>::operator=(const List1D<T> &other)
{
    if(this != &other)
    {
        delete pList;
        pList = new XArrayList<T>();
        for(int i = 0; i < other.size(); i++)
        {
            pList->add(other.get(i));
        }
    }
    return *this;
}


template <typename T>
int List1D<T>::size() const
{
    // TODO
    return pList->size();
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO
    return pList->get(index);
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    // TODO
    if(index < 0 || index > pList->size())
    {
        throw out_of_range("Index is out of range!");
    }
    if(index == pList->size())
    {
        pList->add(value);
    }
    else
    {
        pList->removeAt(index);
        pList->add(index, value);
    }
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    pList->add(value);
}

template <typename T>
string List1D<T>::toString() const
{
    // TODO
    return pList->toString();
}



// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T> &List2D<T>::operator=(const List2D<T> &other)
{
    if(this != &other)
    {
        for (int i = 0; i < pMatrix->size(); i++)
        {
            IList<T> *row = pMatrix->get(i);
            if (row != nullptr)
            {
                delete row; 
            }
        }
        delete pMatrix;
    }
    pMatrix = new XArrayList<IList<T> *>();
    for(int i = 0; i < other.rows(); i++)
    {
        setRow(i, other.getRow(i));
    }
    return *this;
}

template <typename T>
List2D<T>::List2D()
{
    // TODO
    pMatrix = new XArrayList<IList<T> *>();
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    // TODO
    pMatrix = new XArrayList<IList<T> *>();
    for(int i = 0; i < num_rows; i++)
    {
        setRow(i, array[i]);
    }
}

template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO
    pMatrix = new XArrayList<IList<T> *>();
    for(int i = 0; i < other.rows(); i++)
    {
        setRow(i, other.getRow(i));
    }
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    for (int i = 0; i < pMatrix->size(); i++)
    {
        IList<T> *row = pMatrix->get(i);
        if (row != nullptr)
        {
            delete row; 
        }
    }
    delete pMatrix;
}

template <typename T>
int List2D<T>::rows() const
{
    // TODO
    return pMatrix->size();
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // TODO
    if(rowIndex < 0 || rowIndex > pMatrix->size()) throw out_of_range("Index is out of range!");
    XArrayList<T>* tmp = new XArrayList<T>();
    for(int i = 0; i < row.size(); i++)
    {
        tmp->add(row.get(i));
    }
    if(rowIndex < pMatrix->size())
    {
        delete pMatrix->get(rowIndex);
        pMatrix->removeAt(rowIndex);
        pMatrix->add(rowIndex, tmp);
    }
    else 
    {
        pMatrix->add(rowIndex, tmp);
    }
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
    return dynamic_cast<XArrayList<T>*> (pMatrix->get(rowIndex))->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= pMatrix->size())
        throw out_of_range("Index is out of range!");
    List1D<T> p;
    XArrayList<T> *tmp = dynamic_cast<XArrayList<T> *>(pMatrix->get(rowIndex));
    for (int i = 0; i < tmp->size(); i++)
    {
        p.add(tmp->get(i));
    }
    return p;
}

template <typename T>
string List2D<T>::toString() const
{
    // TODO
    stringstream ss;
    ss << "[";
    for (int i = 0; i < pMatrix->size(); i++)
    {

        ss << pMatrix->get(i)->toString();
        if (i != pMatrix->size() - 1)
            ss << ", ";
    }
    ss << "]";
    return ss.str();
}


// -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
    attributesMatrix = List2D<InventoryAttribute>();
    productNames = List1D<string>();
    quantities = List1D<int>();
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
    attributesMatrix = List2D<InventoryAttribute>(matrix);
    productNames = List1D<string>(names);
    this->quantities = List1D<int>(quantities);
}

InventoryManager::InventoryManager(const InventoryManager &other)
{
    // TODO
    attributesMatrix = List2D<InventoryAttribute>(other.getAttributesMatrix());
    productNames = List1D<string>(other.getProductNames());
    this->quantities = List1D<int>(other.getQuantities());
}

int InventoryManager::size() const
{
    // TODO
    return this->productNames.size();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
    if (index < 0 || index >= this->attributesMatrix.rows())
        throw out_of_range("Index is invalid!");
    return this->attributesMatrix.getRow(index);
}

string InventoryManager::getProductName(int index) const
{
    // TODO
    if (index < 0 || index >= this->attributesMatrix.rows())
        throw out_of_range("Index is invalid!");
    return this->productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
    if (index < 0 || index >= this->attributesMatrix.rows())
        throw out_of_range("Index is invalid!");
    return this->quantities.get(index);
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    if (index < 0 || index >= this->attributesMatrix.rows())
        throw out_of_range("Index is invalid!");
    this->quantities.set(index, newQuantity);
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // TODO
    attributesMatrix.setRow(attributesMatrix.rows(), attributes);
    productNames.add(name);
    quantities.add(quantity);
}

void InventoryManager::removeProduct(int index)
{
    // TODO
    if (index < 0 || index >= this->attributesMatrix.rows())
        throw out_of_range("Index is invalid!");
    attributesMatrix.removeAt(index);
    productNames.removeAt(index);
    quantities.removeAt(index);
}

List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    // TODO
    List1D<InventoryAttribute> queryList;
    List1D<string> ans;
    List1D<int> quantityList;
    List1D<string> returnList;

    // Lọc các sản phẩm thỏa điều kiện
    for (int i = 0; i < attributesMatrix.rows(); i++)
    {
        List1D<InventoryAttribute> crrRow = attributesMatrix.getRow(i);
        for (int j = 0; j < crrRow.size(); j++)
        {
            if (crrRow.get(j).name == attributeName && quantities.get(i) >= minQuantity)
            {
                queryList.add(crrRow.get(j));
                ans.add(productNames.get(i));
                quantityList.add(quantities.get(i));
            }
        }
    }

    // Sắp xếp bằng Insertion Sort
    if (ascending)
    {
        for (int i = 1; i < queryList.size(); i++)
        {
            InventoryAttribute key = queryList.get(i);
            string keyName = ans.get(i);
            int keyQuantity = quantityList.get(i);
            int j = i - 1;

            while (j >= 0 && (queryList.get(j).value > key.value ||
                              (queryList.get(j).value == key.value && quantityList.get(j) > keyQuantity)))
            {
                queryList.set(j + 1, queryList.get(j));
                ans.set(j + 1, ans.get(j));
                quantityList.set(j + 1, quantityList.get(j));
                j--;
            }
            queryList.set(j + 1, key);
            ans.set(j + 1, keyName);
            quantityList.set(j + 1, keyQuantity);
        }
    }
    else
    {
        for (int i = 1; i < queryList.size(); i++)
        {
            InventoryAttribute key = queryList.get(i);
            string keyName = ans.get(i);
            int keyQuantity = quantityList.get(i);
            int j = i - 1;

            while (j >= 0 && (queryList.get(j).value < key.value ||
                              (queryList.get(j).value == key.value && quantityList.get(j) <= keyQuantity)))
            {
                queryList.set(j + 1, queryList.get(j));
                ans.set(j + 1, ans.get(j));
                quantityList.set(j + 1, quantityList.get(j));
                j--;
            }
            queryList.set(j + 1, key);
            ans.set(j + 1, keyName);
            quantityList.set(j + 1, keyQuantity);
        }
    }

    // Đưa danh sách tên sản phẩm đã sắp xếp vào returnList
    for (int i = 0; i < ans.size(); i++)
    {
        returnList.add(ans.get(i));
    }

    return returnList;
}

void InventoryManager::removeDuplicates()
{
    // TODO
    for (int i = 0; i < productNames.size() - 1; i++)
    {
        for (int j = i + 1; j < productNames.size(); j++)
        {
            if (productNames.get(j) == productNames.get(i) && checkSameAttributes(attributesMatrix.getRow(i), attributesMatrix.getRow(j)))
            {
                updateQuantity(i, quantities.get(i) + quantities.get(j) );
                removeProduct(j);
                j--;
            }
        }
    }
}

InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // TODO
    List2D<InventoryAttribute> list = List2D<InventoryAttribute>();
    List1D<string> names = List1D<string>();
    List1D<int> quantities = List1D<int>();
    for (int i = 0; i < inv1.size(); i++)
    {
        list.setRow(list.rows(), inv1.getProductAttributes(i));
        names.add(inv1.getProductName(i));
        quantities.add(inv1.getProductQuantity(i));
    }
    for (int i = 0; i < inv2.size(); i++)
    {
        list.setRow(list.rows(), inv2.getProductAttributes(i));
        names.add(inv2.getProductName(i));
        quantities.add(inv2.getProductQuantity(i));
    }
    InventoryManager mergeList = InventoryManager(list, names, quantities);
    return mergeList;
}

void InventoryManager::split(InventoryManager &section1,
                             InventoryManager &section2,
                             double ratio) const
{
    // TODO
    section1 = InventoryManager();
    section2 = InventoryManager();
    if (ratio < 0)
    {
        ratio = 0;
    }
    if (ratio > 1)
    {
        ratio = 1;
    }
    int size1 = (this->size() * ratio + 0.9); // Cộng thêm gần 1 để đảm bảo làm tròn lên
    int size2 = this->size() - size1;
    for (int i = 0; i < size1; i++)
    {
        section1.addProduct(this->getAttributesMatrix().getRow(i), this->getProductNames().get(i), this->getQuantities().get(i));
    }
    for (int i = size1; i < this->size(); i++)
    {
        section2.addProduct(this->getAttributesMatrix().getRow(i), this->getProductNames().get(i), this->getQuantities().get(i));
    }
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // TODO
    return this->attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
    return this->productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
    return this->quantities;
}

string InventoryManager::toString() const
{
    // TODO
    stringstream ss;
    ss << "InventoryManager[\n";
    ss << "  AttributesMatrix: ";
    ss << attributesMatrix.toString();
    ss << ",\n";
    ss << "  ProductNames: ";
    ss << productNames.toString();
    ss << ",\n";
    ss << "  Quantities: ";
    ss << quantities.toString();
    ss << "\n";
    ss << "]";
    return ss.str();
}

#endif /* INVENTORY_MANAGER_H */
