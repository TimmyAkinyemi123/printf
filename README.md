PRINTF

An ALX SE Project.
By - Timilehin Akinyemi & Onyedikachi Eze

INTRODUCTION
The 'printf' function is a commonly used one in C programming which allows a formatted output to the consoile or other output streams(viz: standard output).

It takes as an arguement, a format string which specifies the desired format of the output as well as anyadditional arguements that need to be printed according to that format.

DESCRIPTION
This project aims to recreate the functionality of the 'printf' function.
With adept understanding of various concepts in C programming such as; string manipulation, variable arguement lists and formatting techniques we can breakdown the core mechanisms of 'printf' and rebuild from ground up, a simplified version of this classic function.

FEATURES
.Basic Formatting Options:
This project is bult to work with basic formatting options like width and precision modifiers.
This gives users the ability to control the width of printed fields, decimal precision, and other aspects of formatting.

.Format Specifiers:
We have enabled support for commony used format specifiers like '%d' for integers, '%f' for floating-point numbers, '%s' for strings, '%c' for characters and even more.
This enables users to print values of the various data types with appropriate formatting.

.Variable Argument Handling
Out 'printf' implementation handles variable argument lists which allows users to pass a variable number of arguments to be printed in line with specified format.

USAGE
Follow these steps to use the 'printf' implementation in your C program.

1.
Include the 'printf.h' header file in your source file:
	#include "printf"

2.
Call the 'my_printf' function with the desired format string and additional arguments
	my_printf("My name is %s and I'm %d", Bob, 46);

3.
Compile your program. Ensure to include the 'printf.c' and 'printf.h' files in the compilation.
	gcc your_code.c printf.c -o your_code

4.
Run your program
	./your_code

CONTRIBUTIONS
If you encounter any issues, have suggestions for new features you would like us to add and general improvements, please do not hesitate to send a pull request.
We believe in the power of community, hence contributions to the 'printf' project are welcome and appreciated!

LICENSE
--------------
See the LICENSE file for more information.

ACKNOWLEDGEMENTS
It goes without saying that our 'printf' project was inspired by the original 'printf' function in the C standard library.
We are grateful to those who created and continue to maintain the C programming language and the innumerable contributors from the open-source community.
Our heartfelt gratitude also goes to all those at ALX and Holberton School, with special regards to our technical mentors. You are the real MVPs.

You are invited to eplore and experiment with our 'printf' implementation. HAPPY CODING!
