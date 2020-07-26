MIN-MAX HEAP
====================

This repository has a project with the implementation of a MIN-MAX HEAP.

It is written in C++.

The code of the MIN-MAX HEAP is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the MIN-MAX HEAP (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the MIN-MAX HEAP, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Remove minimum number;](#markdown-header-emphasis)
	* [Remove maximum number;](#markdown-header-emphasis)
	
- - -

Sample images: 
====================

## This is the sample without colors.

![Alt text](images/sample1.png)

## This is the sample with colors. The blue color represents a min level. The red color represents a max level.

![Alt text](images/sample2.png)



Insertion steps (without colors): 
====================

## Initial
![Alt text](images/insertingwithoutcolors/1.png)

## Inserting 40
![Alt text](images/insertingwithoutcolors/2.png)

## Inserting 50
![Alt text](images/insertingwithoutcolors/3.png)

## Inserting 75
![Alt text](images/insertingwithoutcolors/4.png)

## Inserting 35
![Alt text](images/insertingwithoutcolors/5.png)

## Inserting 20
![Alt text](images/insertingwithoutcolors/6.png)

## Inserting 60
![Alt text](images/insertingwithoutcolors/7.png)

## Inserting 4
![Alt text](images/insertingwithoutcolors/8.png)

## Inserting 2
![Alt text](images/insertingwithoutcolors/9.png)



Insertion steps (with colors): 
====================

## Initial
![Alt text](images/insertingwithcolors/1.png)

## Inserting 40
![Alt text](images/insertingwithcolors/2.png)

## Inserting 50
![Alt text](images/insertingwithcolors/3.png)

## Inserting 75
![Alt text](images/insertingwithcolors/4.png)

## Inserting 35
![Alt text](images/insertingwithcolors/5.png)

## Inserting 20
![Alt text](images/insertingwithcolors/6.png)

## Inserting 60
![Alt text](images/insertingwithcolors/7.png)

## Inserting 4
![Alt text](images/insertingwithcolors/8.png)

## Inserting 2
![Alt text](images/insertingwithcolors/9.png)





Remove min steps (without colors, for instance): 
====================

## Initial
![Alt text](images/removingminwithoutcolors/1.png)

## Removing min
![Alt text](images/removingminwithoutcolors/2.png)

## Removing min
![Alt text](images/removingminwithoutcolors/3.png)

## Removing min
![Alt text](images/removingminwithoutcolors/4.png)

## Removing min
![Alt text](images/removingminwithoutcolors/5.png)

## Removing min
![Alt text](images/removingminwithoutcolors/6.png)

## Removing min
![Alt text](images/removingminwithoutcolors/7.png)

## Removing min
![Alt text](images/removingminwithoutcolors/8.png)

## Removing min
![Alt text](images/removingminwithoutcolors/9.png)



Remove max steps (with colors, for instance): 
====================

## Initial
![Alt text](images/removingmaxwithcolors/1.png)

## Removing min
![Alt text](images/removingmaxwithcolors/2.png)

## Removing min
![Alt text](images/removingmaxwithcolors/3.png)

## Removing min
![Alt text](images/removingmaxwithcolors/4.png)

## Removing min
![Alt text](images/removingmaxwithcolors/5.png)

## Removing min
![Alt text](images/removingmaxwithcolors/6.png)

## Removing min
![Alt text](images/removingmaxwithcolors/7.png)

## Removing min
![Alt text](images/removingmaxwithcolors/8.png)

## Removing min
![Alt text](images/removingmaxwithcolors/9.png)


Qt gui project: 
====================
The qt gui application gui is shown below:

## This is the sample with colors. 

![Alt text](images/guisample1.png)

##  This is the sample without colors. The blue color represents a min level. The red color represents a max level.


![Alt text](images/guisample2.png)





