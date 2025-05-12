# Bank Management System

A basic Bank Management System developed in C++ that allows users to perform fundamental banking operations such as creating accounts, viewing account details, depositing and withdrawing funds. This project demonstrates the use of object-oriented programming principles and file handling in C++.

## Features

- Create a new bank account
- View account details
- Deposit funds into an account
- Withdraw funds from an account
- Modify account information
- Creates log of each operation performed on an account
- Creates log of each account's opening

## Technologies Used

- C++
- File handling using fstream
- Object-Oriented Programming (OOP)

## Getting Started

### Prerequisites

To compile and run this project, ensure you have:

- A C++ compiler (e.g., g++, clang++)
- A terminal or an IDE that supports C++ (e.g., Code::Blocks, Visual Studio Code)

### Compilation

Compile the project using g++:

```bash
g++ main.cpp Account.cpp Bank.cpp -o ./output/BankApp
cd output
./BankApp
