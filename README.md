# 🧾 Inventory Management System (C++17)

A data-structure–based **Inventory Management System** implemented in **C++17**, applying concepts of **Object-Oriented Programming (OOP)**, **templates**, and **iterators**.  
This project was developed as part of the *Data Structures and Algorithms* course (CO2003), Ho Chi Minh City University of Technology (HCMUT).

---

## 📚 Overview

The project demonstrates the use of **custom list data structures** and **modular software design** to manage warehouse (inventory) data efficiently.  
It includes both low-level data structures and high-level application classes for real-world data manipulation.

---

## 🏗️ Features

### 1. Custom Data Structures
- **`IList<T>`** – Abstract interface defining common list operations.  
- **`XArrayList<T>`** – Array-based list supporting dynamic resizing, iterator traversal, and exception-safe access.  
- **`DLinkedList<T>`** – Doubly linked list implementation for efficient insertion and removal.

### 2. Application Classes
- **`List1D<T>`** – One-dimensional list wrapper for array-like data.  
- **`List2D<T>`** – Two-dimensional list supporting matrix-like operations (rows × columns).  
- **`InventoryManager`** – Manages inventory data using:
  - `List2D<InventoryAttribute>` for product attributes  
  - `List1D<string>` for product names  
  - `List1D<int>` for quantities  

### 3. Inventory Operations
- Add / remove products  
- Update quantity  
- Query products by attributes (e.g., value ranges or stock levels)  
- Merge and split inventories  
- Detect and remove duplicates

---

## 🧩 Class Structure

```text
/include/
├── list/
│   ├── IList.h         # Abstract list interface
│   ├── XArrayList.h    # Array-based list implementation
│   ├── DLinkedList.h   # Doubly linked list implementation
│
└── inventory.h         # List1D, List2D, InventoryManager, InventoryAttribute

## ▶ How to Build & Run

## **1. Build**
Compile the whole project (adjust paths if needed):

```bash
g++ -std=c++17 -O2 -I./ -o app main.cpp