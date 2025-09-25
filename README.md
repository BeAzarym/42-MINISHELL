# MINISHELL - Unix Shell Recreation

A 42 School project implementing a fully functional Unix shell in C, recreating bash-like functionality with parsing, execution, and built-in commands.

**Contributors:** [@BeAzarym](https://github.com/BeAzarym) & [@AnaisTry](https://github.com/AnaisTry)

## Overview

**Minishell** is a minimal Unix shell implementation that handles command parsing, execution, redirections, pipes, environment variable expansion, and built-in commands. Built entirely in C with custom parsing and execution logic, it demonstrates deep understanding of Unix system calls, process management, and shell internals.

## Quick Start

### Prerequisites
- GCC compiler
- GNU Readline library
- Make

### Installation
```bash
git clone https://github.com/BeAzarym/42-MINISHELL.git
cd minishell
make
```

### Usage
```bash
./minishell
```

## Features

### Core Functionality
- **Interactive shell** with readline support and command history
- **Command parsing** with proper tokenization and syntax validation  
- **Process execution** with fork/exec system calls
- **Pipeline support** - Chain commands with pipes (`|`)
- **Input/Output redirection** - `>`, `>>`, `<`, and heredoc `<<`
- **Environment variable expansion** - `$VAR` and `$?` support
- **Quote handling** - Single (`'`) and double (`"`) quotes
- **Signal handling** - Proper Ctrl+C, Ctrl+D, and Ctrl+\ behavior

### Built-in Commands
- **`echo`** - Display text with `-n` option support
- **`cd`** - Change directory with relative/absolute paths, `~`, and `-`
- **`pwd`** - Print working directory
- **`export`** - Set environment variables
- **`unset`** - Remove environment variables  
- **`env`** - Display environment variables
- **`exit`** - Exit shell with optional status code

### Advanced Features
- **Heredoc support** (`<<`) with delimiter-based input
- **Environment variable substitution** in commands and arguments
- **Exit status tracking** with `$?` variable
- **Path resolution** from `$PATH` environment variable
- **Proper error handling** with descriptive error messages

## Architecture

The shell is organized into modular components:

| Component | Description |
|-----------|-------------|
| **Lexing** | Tokenization, quote handling, and environment expansion |
| **Parsing** | Command structure creation and redirection parsing |
| **Execution** | Process creation, pipe management, and built-ins |
| **Signals** | Signal handling for interactive behavior |
| **Built-ins** | Implementation of shell built-in commands |

## Project Structure

```
minishell/
├── Makefile                    # Build configuration
├── includes/                   # Header files
│   ├── minishell.h            # Main definitions and structures
│   ├── builtins.h             # Built-in command declarations
│   ├── execute.h              # Execution engine declarations
│   └── signals.h              # Signal handling definitions
├── src/                       # Source code
│   ├── minishell.c            # Main program and prompt loop
│   ├── builtins/              # Built-in command implementations
│   │   ├── builtin.c          # env, pwd commands
│   │   ├── cd.c               # Directory navigation
│   │   ├── echo.c             # Text output with options
│   │   ├── exit.c             # Shell termination
│   │   ├── export.c           # Environment variable management
│   │   └── unset.c            # Environment variable removal
│   ├── execution/             # Command execution engine
│   │   ├── execution.c        # Main execution logic
│   │   ├── execute.c          # Process creation and path resolution
│   │   ├── pipex.c            # Pipeline management
│   │   ├── redir.c            # Input/output redirection
│   │   ├── here_doc.c         # Heredoc implementation
│   │   └── wait.c             # Process synchronization
│   ├── lexing/                # Parsing and tokenization
│   │   ├── lexer.c            # Main lexical analysis
│   │   ├── parser.c           # Command structure creation
│   │   ├── expander.c         # Environment variable expansion
│   │   ├── quote_handler.c    # Quote processing
│   │   └── token.c            # Token management
│   └── signals/               # Signal handling
│       ├── signals.c          # Signal setup and management
│       └── signal_functions.c # Signal handler implementations
├── utils/                     # Utility functions
├── libft/                     # Custom C library
└── README.md                  # Project documentation
```

## Technical Implementation

### Data Structures

#### Token System
```c
typedef struct s_token {
    char type;              // Token type (command, pipe, redirect, etc.)
    char *value;           // Token content
    struct s_token *next;  // Linked list structure
} t_token;
```

#### Command Structure
```c
typedef struct s_cmd {
    char **cmd;            // Command and arguments array
    int type_in;           // Input redirection type
    int type_out;          // Output redirection type
    t_redir_lst *redir_in; // Input redirections
    t_redir_lst *redir_out;// Output redirections
    struct s_cmd *next;    // Pipeline chain
} t_cmd;
```

#### Environment Management
```c
typedef struct s_env {
    char *key;             // Variable name
    char *value;           // Variable value
    struct s_env *next;    // Environment chain
} t_env;
```

### Execution Flow

1. **Input Processing** - Read user input with readline
2. **Lexical Analysis** - Tokenize input handling quotes and expansions
3. **Parsing** - Build command structures from tokens
4. **Environment Expansion** - Process `$VAR` substitutions
5. **Execution** - Create processes and handle redirections
6. **Cleanup** - Free allocated memory and reset state

### Memory Management

- **Dynamic allocation** for all data structures
- **Proper cleanup** on exit and error conditions  
- **Memory leak prevention** with comprehensive freeing
- **Safe string handling** with bounds checking

## Build System

### Available Commands
```bash
make        # Build the minishell executable
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```

### Compilation Flags
- **`-Wall -Wextra -Werror`** - Strict error checking
- **Readline linking** - Platform-specific readline paths
- **Debug mode** - Optional debugging symbols and sanitizers

## Error Handling

- **Syntax validation** - Detect malformed commands
- **File access checks** - Verify redirections before execution
- **Process error handling** - Manage fork/exec failures
- **Signal safety** - Proper cleanup on interruptions
- **Memory safety** - Prevent leaks and segmentation faults

## Testing

The shell handles various test cases:
- **Basic commands** - `ls`, `cat`, `grep`, etc.
- **Complex pipelines** - `ls -la | grep mini | wc -l`
- **Redirections** - `echo "test" > file < input`
- **Environment variables** - `echo $HOME $USER $?`
- **Edge cases** - Empty input, invalid syntax, signal handling

---
