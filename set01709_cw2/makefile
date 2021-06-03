test:
	cl /c test.cpp BinarySearchTree.cpp
	lib BinarySearchTree.obj
	link test.obj BinarySearchTree.lib
	test

singlewords:
	cl /c wordcount1.cpp BinarySearchTree.cpp
	lib BinarySearchTree.obj
	link wordcount1.obj BinarySearchTree.lib
	wordcount1

sentences:
    cl /c wordcount2.cpp BinarySearchTree.cpp
	lib BinarySearchTree.obj
	link wordcount2.obj BinarySearchTree.lib
	wordcount2

erase:
	del *.lib
	del *.exe
	del *.obj