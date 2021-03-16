# 4280-P0

This program takes in a file of string-tokens seperated by whitespace and sorts them into a BST of linked list, sorted by their first letter. All tokens beginning with the same letter are put into the same node (linked list) within the BST.

It will output three seperate files, one for each of the types preorder, inorder, and postorder traversal of the BST. As each traversal goes down the levels of the tree, it is parsed in the output file two tabs for every level down the tree.

Build the program by typing "make" on the command line.

To run the program type "./P0 yourfile" where "yourfile" is a file without the extension. ".sp2020" will be added as the extension for you. 

If you have another file that you'd like to run without the extension ".fs182" then pipe it into the the program upon execution by typing the command: "./P0 < yourfile" 

This will cause the output files to have the names: "out.preorder" "out.inorder" "out.postorder"

To clean all executables and output files, type "make clean"
