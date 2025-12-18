# C867 – Class Roster (C++)

This project was completed for **WGU C867: Scripting and Programming – Applications**.  
It implements a simplified student roster system in **C++**, simulating part of a university’s migration to a new student management platform.

## Overview

The program maintains a roster of students for a single course.  
It reads a predefined dataset, parses student records, stores them in memory, and provides functions to query and manipulate the data.

The system is built around two core classes:

- **Student** – represents an individual student and their attributes  
- **Roster** – manages a collection of students and performs required operations

All output is displayed via the console.

## Features

- Parses raw student data and creates `Student` objects
- Stores students in a `classRosterArray`
- Displays all students with formatted output
- Validates and reports invalid email addresses
- Calculates average days-in-course per student
- Filters students by degree program
- Removes students by ID with proper error handling

## Data Model

Each student record includes:
- Student ID
- First name
- Last name
- Email address
- Age
- Days to complete each course (array of 3 integers)
- Degree program

## Technologies Used

- **C++**
- Object-Oriented Programming (classes, encapsulation)
- Arrays and basic memory management
- Console-based I/O

## Purpose

This project demonstrates:
- Core C++ syntax and structure
- Object-oriented design fundamentals
- Data parsing and validation
- Basic collection management and control flow

## Notes

This project was developed and intended as an academic and foundational C++ example rather than a production system.
