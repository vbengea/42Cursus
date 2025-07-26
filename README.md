# 42 Cursus - Introduction to Programming

[![42 Badge](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)](https://42.fr/)
[![C Badge](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))

Welcome to my collection of introductory projects from **42 School**! This repository contains a series of carefully crafted projects that build foundational programming skills in C, covering everything from basic string manipulation to complex system programming concepts.

## 🎯 About 42 School

42 is an innovative programming school with a peer-to-peer learning methodology. Students learn by working on practical projects without traditional courses or teachers, fostering self-reliance, collaboration, and problem-solving skills.

## 📚 Projects Overview

### 🔧 Core Library Projects

#### [**libft**](./libft/) - Your First Library
- **Objective**: Create a personal C library with essential functions
- **Skills**: Memory management, string manipulation, linked lists
- **Functions**: 70+ functions including custom implementations of `strlen`, `strcpy`, `malloc`, etc.
- **Bonus**: Linked list manipulation functions

#### [**ft_printf**](./ft_printf/) - Variadic Functions Master
- **Objective**: Recreate the famous `printf` function
- **Skills**: Variadic functions, format specifiers, string parsing
- **Supported formats**: `%c %s %d %i %u %x %X %p %%`
- **Key Concepts**: `va_list`, `va_start`, `va_arg`, `va_end`

#### [**get_next_line**](./get_next_line/) - File Reading Utility
- **Objective**: Read files line by line efficiently
- **Skills**: File I/O, static variables, buffer management
- **Features**: Handles multiple file descriptors simultaneously
- **Buffer size**: Configurable via compilation flags

### 🧮 Algorithm & Data Structure Projects

#### [**push_swap**](./push_swap/) - Sorting Algorithm Challenge
- **Objective**: Sort numbers using two stacks with minimal operations
- **Skills**: Algorithm optimization, stack operations, complexity analysis
- **Operations**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Algorithm**: Turkish algorithm implementation for optimal sorting
- **Challenge**: Sort 500 numbers in under 5500 operations

### 🔄 System Programming Projects

#### [**pipex**](./pipex/) - Unix Pipes Recreation
- **Objective**: Recreate shell pipe functionality (`|`)
- **Skills**: Process management, file descriptors, system calls
- **Usage**: `./pipex file1 cmd1 cmd2 file2` → equivalent to `< file1 cmd1 | cmd2 > file2`
- **Bonus**: Support for multiple pipes (here_doc functionality)
- **System calls**: `pipe()`, `fork()`, `execve()`, `dup2()`

#### [**philosophers**](./philosophers/) - Threading & Synchronization
- **Objective**: Solve the classic dining philosophers problem
- **Skills**: Multithreading, mutexes, deadlock prevention, race conditions
- **Concepts**: Thread synchronization, resource sharing, concurrent programming
- **Challenge**: Prevent starvation and deadlock while maintaining performance
- **Thread safety**: Mutex-protected shared resources

### 🎮 Graphics Programming Project

#### [**so_long**](./so_long/) - 2D Game Development
- **Objective**: Create a simple 2D game using MiniLibX
- **Skills**: Graphics programming, event handling, game loops
- **Features**: Player movement, collectibles, win/lose conditions
- **Graphics**: Sprite rendering, keyboard input handling
- **Map format**: Custom `.ber` format with validation

## 🛠️ Technical Skills Developed

### **Programming Fundamentals**
- ✅ Memory management (`malloc`, `free`, leak prevention)
- ✅ Pointer manipulation and pointer arithmetic
- ✅ String processing and manipulation
- ✅ Error handling and edge case management
- ✅ Code organization and modular programming

### **System Programming**
- ✅ File I/O operations and file descriptor management
- ✅ Process creation and management (`fork`, `execve`)
- ✅ Inter-process communication (pipes)
- ✅ Signal handling and process synchronization

### **Concurrent Programming**
- ✅ Thread creation and management (`pthread`)
- ✅ Mutex synchronization and deadlock prevention
- ✅ Race condition identification and resolution
- ✅ Resource sharing in multi-threaded environments

### **Algorithm Design**
- ✅ Sorting algorithms and optimization techniques
- ✅ Data structure implementation (stacks, linked lists)
- ✅ Time and space complexity analysis
- ✅ Problem-solving and logical thinking

### **Graphics Programming**
- ✅ Event-driven programming
- ✅ 2D graphics rendering
- ✅ Game loop implementation
- ✅ User input handling

## 🏗️ Project Structure

Each project follows the 42 School standards:

```
project_name/
├── src/                    # Source files
├── incl/                   # Header files
├── Makefile               # Build automation
├── *.c                    # Implementation files
├── *.h                    # Header files
└── additional_files/      # Project-specific files
```

## 🚀 Compilation & Usage

Each project includes a **Makefile** with standard rules:

```bash
make                # Compile the project
make clean          # Remove object files
make fclean         # Remove object files and executable
make re             # Recompile everything
make bonus          # Compile with bonus features (where applicable)
```

### Quick Start Examples:

```bash
# ft_printf
make && ./test_printf

# get_next_line
make && ./test_gnl filename.txt

# push_swap
make && ./push_swap 4 67 3 87 23

# pipex
make && ./pipex infile "ls -l" "wc -l" outfile

# philosophers
make && ./philo 5 800 200 200 7

# so_long
make && ./so_long maps/map.ber
```

## 📏 Coding Standards

All projects adhere to the **42 Norm**, which enforces:
- ✅ Maximum 25 lines per function
- ✅ Maximum 80 characters per line
- ✅ Maximum 5 functions per file
- ✅ Specific naming conventions
- ✅ Forbidden functions list compliance
- ✅ Memory leak prevention
- ✅ Proper error handling

## 🎓 Learning Outcomes

Through these projects, I have developed:

1. **Strong C Programming Skills**: Deep understanding of memory management, pointers, and system calls
2. **Problem-Solving Abilities**: Breaking down complex problems into manageable components
3. **System Understanding**: How operating systems handle processes, files, and memory
4. **Debugging Skills**: Using tools like `valgrind`, `gdb`, and manual debugging techniques
5. **Code Quality**: Writing clean, efficient, and maintainable code
6. **Project Management**: Following specifications, meeting deadlines, and iterative development

## 🤝 Peer Learning

These projects were completed following 42's peer-to-peer methodology:
- Code reviews with fellow students
- Collaborative problem-solving sessions
- Knowledge sharing and mentoring
- Defense presentations explaining code implementation

## 📈 Evaluation

Each project is evaluated through:
- **Automated tests**: Moulinette (42's testing system)
- **Peer evaluations**: Code review sessions with other students
- **Defense**: Oral presentation explaining implementation choices
- **Code quality**: Adherence to 42 Norm and best practices

## 🏆 Skills Progression

```
libft → ft_printf → get_next_line → push_swap → pipex → philosophers → so_long
  ↓         ↓            ↓             ↓         ↓          ↓            ↓
Basic    Variadic    File I/O     Algorithms  Process   Threading   Graphics
 C       Functions                             Control
```

---

**Author**: vbengea  
**School**: 42 Madrid  
**Curriculum**: 42 Cursus  
**Start Date**: September 2024  

*"The important thing is not to stop questioning."* - Albert Einstein

---

*This repository represents the beginning of my journey in computer science and software engineering. Each project builds upon the previous one, creating a solid foundation for more advanced programming challenges.*
