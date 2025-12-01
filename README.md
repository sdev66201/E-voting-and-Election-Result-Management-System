# E-Voting and Election Result Management System

A simple digital voting platform written in C for conducting transparent elections in colleges and organizations.

## About This Project
This project demonstrates voter & candidate management, secure vote casting, result calculation, and persistent data storage using C structures, pointers, linked lists, and file handling.

## Features
- Register voters and candidates  
- Cast votes (one vote per voter)  
- Prevent duplicate/invalid voting  
- Compute winner & percentages  
- Export results to text file  
- Save/load data across sessions  

## Compilation
Compile all files together:

```bash
gcc evoting_main.c evoting_management.c evoting_voting.c -o evoting
./evoting
```

Windows (MinGW):
```cmd
gcc evoting_main.c evoting_management.c evoting_voting.c -o evoting.exe
evoting.exe
```

## Project Structure
```
evoting_main.c        # main menu + navigation  
evoting_management.c  # voter/candidate management  
evoting_voting.c      # voting system + results + files  
evoting.h             # shared structs, globals, prototypes  
README.md             # documentation  
```

## How to Use
1. Register voters  
2. Register candidates  
3. Cast votes  
4. View results  
5. Save results to file  
6. Save data or exit  

## Generated Files
- `election_results.txt`  
- `voters.dat`, `candidates.dat`, `votes.dat` (if implemented)


Made for educational project use.
