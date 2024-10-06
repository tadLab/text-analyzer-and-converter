# text-analyzer-and-converter

is a C-based project designed to perform various operations on strings. The project offers functionalities such as counting characters, digits, words, converting text case, applying Caesar cipher, comparing strings, and more. It allows users to interact with the program via command-line arguments for flexible text processing.

### Features:
- **Calculate string length** (max 100 characters)
- **Count digits and letters** in a given string
- **Convert uppercase letters to lowercase**
- **Replace a specific character** in the string with an underscore ('_')
- **Apply Caesar cipher** with a user-defined shift value
- **Compare two strings** for equality
- **Count the number of words** in a string

### Usage:
1. **Compile the program**:
    ```
    gcc -o proj proj.c
    ```

2. **Run the program**:
    ```
    ./proj
    ```

3. **Available options**:
    - **1**: Find the length of a string
    - **2**: Count digits and letters in a string
    - **3**: Convert uppercase letters to lowercase
    - **4**: Replace a specified character with '_'
    - **5**: Apply Caesar cipher with a shift value
    - **6**: Compare two strings for equality
    - **7**: Count words in a string
