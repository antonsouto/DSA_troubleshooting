# DSA_troubleshooting
Repository for practicing data structures and algorithms in C++ (GeeksforGeeks style). Organized by topics like hashing, two pointers, arrays, etc. Includes custom testing setup with CMake and VS Code debugging for efficient problem solving and learning.

# DSA_troubleshooting

Repository for practicing data structures and algorithms in C++, organized by topic (hashing, two pointers, arrays, etc.).

## Structure

All problems are inside `src/`, grouped by topic (e.g. `hashing`, `two_pointers`).  
Each `.cpp` file represents one problem and contains the statement (as comments) and its solution.

## Running problems

The entry point is `src/main.cpp`.

To test a problem, include its file manually in `main.cpp` and run it from there.  
You need to modify `main.cpp` each time to execute a different problem.

## Build and Debug

From the `build/` directory:

```
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
```

Then in VS Code:
- set breakpoints if needed
- run using the debug button (bottom only, where there are debug and run buttons, not automatic configuration)

Do not use the top "Run" button, as it may ignore the debug configuration.
