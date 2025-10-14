# Minishell

<div align="center">
  <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/minishellm.png" alt="Minishell Logo" width="200"/>
</div>

<h4 align="center">
    A simplified Bash-like shell written in C as a 42 Lisboa project.
</h4>

<p align="center">
  <a href="#about">About</a> •
  <a href="#features">Features</a> •
  <a href="#installation">Installation</a> •
  <a href="#usage">Usage</a>
</p>

---

## About

**Minishell** is a collaborative project from **42 Lisboa** that involves creating a simple, yet functional, Unix shell. This project is a deep dive into process creation, synchronization, and input/output management, reinforcing core systems programming concepts.

The shell handles command execution, environment variables, signals, and built-in commands, providing a hands-on understanding of how tools like **Bash** or **Zsh** work under the hood.

**Key Learning Objectives:**
*   Process creation and management using `fork()`, `execve()`, and `waitpid()`.
*   Input parsing, tokenization, and handling of quoting and escaping.
*   Redirections (`>`, `>>`, `<`, `<<`) and pipes (`|`).
*   Signal handling (e.g., `Ctrl-C`, `Ctrl-D`, `Ctrl-\`).
*   Environment variable expansion (`$VAR`).

## Features

| Category | Implemented Features |
| :--- | :--- |
| **Command Execution** | Executes commands found in the `PATH` (e.g., `ls`, `grep`, `cat`). |
| **Built-ins** | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`. |
| **Redirections** | Input (`<`), Output (`>`), Append (`>>`), Heredoc (`<<`). |
| **Pipes** | Multiple pipes in a single command line (e.g., `ls │ grep .c │ cat -e`). |
| **Variables** | Expands `$USER` and `$?` (exit status of the last command). |
| **Quotes & Escapes** | Handles single quotes `' '`, double quotes `" "`, and the backslash `\`. |
| **Signals** | `Ctrl-C` displays a new prompt, `Ctrl-D` exits the shell, `Ctrl-\` does nothing. |

## Installation

1.  **Clone the repository**
    ```bash
    git clone https://github.com/duarteagostinho/minishell.git
    cd minishell
    ```
2.  **Compile the program**
    ```bash
    make
    ```
    This will generate the `minishell` executable.

## Usage

Run the shell by executing the generated binary:

```bash
./minishell
