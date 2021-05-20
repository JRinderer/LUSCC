# Notes: 5/15/2021 - JRinderer

## Summary: 
Using a few books, and open source resources I'm going to build a simple C compiler. The language will be C,
but with some features removed. There will be no structs, pointers, enum, and no header files can be imported as in
standard C. It will be a very primitive C programming langage I'll call SC; or Simple C.

The idea is to build a course around this language to teach students the basics of hand written compilers. The end code
will be X86_64 Assembly. There will be three primary programs written: scanner, parser, code_gen. The course will use
nasm for Assembly, and CLANG or GCC for C compiling. While I'm building mine in FreeBSD I will have an Ubuntu Virtual
Machine to run students code.

## Steps to get started

1. Define the language
2. Examine the language definition
3. Build the scanner
4. Build the parser
5. Build the code_gen

## General Rules
Our Simple C language will require a main funciton. This function must be declared VOID. It's position must be the last
function in our file.

## The Scanner
The scanner is one of the most important parts of the programming; it runs through our source code and generates tokens
for us. There are a variety of approaches to building the scanner, the one I'll use will create a .scn file. This .scn
file will then be passed to the parser to validate that it's correct. This isn't the ideal way, but it my opinion for
the sake of teaching it makes it easier for students to follow this method. The reason is when you can see the output
and confirm it's correct it makes debugging better. 

The scanner will use the global_defs token_types to check that each "string" (a combination of chars to create a unique
token or lexeme) is either a keyword, or a lexem. Think of this as a key value pair.

###Working scanner notes:
What's the best way to approach building Token Lexeme? Step 1 is to loop through every character. This has been completed.
The next step is to build each character into a string pointer. Currently I'm comparing characters to characters for some things,
but the best approach may be to build each character into a string and then compare to another string.

The question becomes when we de stop adding to the buffer?
1. When the buffer contains a token, and the look ahead identifies the next character won't change that.
2. When the buffer contains an identifier and the look ahead identifies the next character is:
    * space
    * a reserved character
    * a tab
    * a line ender
   
####How best to handle functions:
In short how do we write our scanner to effectively identify a fuction vs a variable? 

A variable is declared like this:
int x; 

Optionally it can also look like this
int x=0;

A funciton on the other hand will look like this:

int func(){

An interesting challenge is, do we want the scanner to identify in some way that we have a function.
Something like the following:

func     func
int      int
gcd      gcd
(        (
int      int
identif  x
)        )
{        {

And if that's the case, how far down do we want to track that?