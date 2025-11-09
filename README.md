# Student Report Card System

A small C++ program that collects a student's name, roll number, and marks for 5 subjects, calculates total, percentage and grade, displays the result, and appends the record to `report_card.txt`.

## Features

- Prompt for student name and roll number
- Input marks for 5 subjects
- Calculate total marks, percentage, and grade (A/B/C/D/F)
- Display a formatted report card on the console
- Append the record to `report_card.txt` in the program directory

## Files

- `main.cpp` — program source (single-file implementation)
- `report_card.txt` — output file created/appended by the program

## Build (Windows / PowerShell)

You can compile with any C++ compiler. Below are common options.

### Using MinGW / MSYS2 g++ (recommended)

If you have `g++` available in PATH or want to call the MSYS2 toolchain directly, run (PowerShell):

```powershell
# If g++ is in PATH
g++ -std=c++17 -O2 -Wall "main.cpp" -o "report_card.exe"
# Or call MSYS2 g++ explicitly (use & in PowerShell for a path string)
& 'C:/msys64/ucrt64/bin/g++.exe' -std=c++17 -O2 -Wall "main.cpp" -o "report_card.exe"
```

### Using Visual Studio Developer Command Prompt (MSVC)

Open "Developer Command Prompt for VS" and run:

```cmd
cl /EHsc /std:c++17 main.cpp /Fe:report_card.exe
```

## Run

From PowerShell or CMD in the project directory:

```powershell
.\report_card.exe
```

The program will prompt for input interactively. After completion, the student's record is appended to `report_card.txt`.

## Example session

User input (example):
```
Enter student name: Alice Johnson
Enter roll number: 12
Enter marks of 5 subjects (out of 100):
Subject 1: 88
Subject 2: 92
Subject 3: 79
Subject 4: 85
Subject 5: 94
```

Console output:
```
----- STUDENT REPORT CARD -----
Name       : Alice Johnson
Roll No.   : 12

Marks in each subject:
Subject 1: 88
Subject 2: 92
Subject 3: 79
Subject 4: 85
Subject 5: 94

Total Marks : 438/500
Percentage  : 87.60%
Grade       : B

Student record saved to file successfully!
```

And `report_card.txt` will contain an appended entry similar to:

```
==============================
Name: Alice Johnson
Roll No: 12
Marks: 88 92 79 85 94 
Total: 438  Percentage: 87.6  Grade: B
```

## Notes & Troubleshooting

- PowerShell: when calling an executable via a full path string, prefix with `&`, e.g. `& 'C:/msys64/ucrt64/bin/g++.exe' ...`.
- If the compiler is not found, install MinGW/MSYS2 or Visual Studio and ensure the chosen compiler is available in PATH or call it by absolute path.
- The program uses standard iostream/fstream; no external libraries required.
- If input behaves unexpectedly when mixing `getline` and `cin >>`, ensure you provide inputs in the order prompted; this program reads the name with `getline` first and then numeric inputs with `cin`.

## License

This project is provided as-is for learning/educational purposes. Feel free to modify and reuse.
