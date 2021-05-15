#Notes: 5/15/2021 - JRinderer

##Summary: 
Using a few books, and open source resources I'm going to build a simple C compiler. The language will be C,
but with some features removed. There will be no structs, pointers, enum, and no header files can be imported as in
standard C. It will be a very primitive C programming langage I'll call SC; or Simple C.

The idea is to build a course around this language to teach students the basics of hand written compilers. The end code
will be X86_64 Assembly. There will be three primary programs written: scanner, parser, code_gen. The course will use
nasm for Assembly, and CLANG or GCC for C compiling. While I'm building mine in FreeBSD I will have an Ubuntu Virtual
Machine to run students code.

##Steps to get started

1. Define the language
2. Examine the language definition
3. Build the scanner
4. Build the parser
5. Build the code_gen

##The Scanner
The scanner is one of the most important parts of the programming; it runs through our source code and generates tokens
for us. There are a variety of approaches to building the scanner, the one I'll use will create a .scn file. This .scn
file will then be passed to the parser to validate that it's correct. This isn't the ideal way, but it my opinion for
the sake of teaching it makes it easier for students to follow this method. The reason is when you can see the output
and confirm it's correct it makes debugging better. 

The scanner will use the global_defs token_types to check that each "string" (a combination of chars to create a unique
token or lexeme) is either a keyword, or a lexem. Think of this as a key value pair.