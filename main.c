//Philip Wright
//CMP 4280 P0
//this is the main function of the program that takes in the command line argument of the file
//this file pointer is then read and passed to the 3 tree traversal algorithms
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "tree.h"

int main(int argc, char *argv[]){
	
	// make sure the right number of arguments are given
	if (argc > 2) {
		errno = 8;
		perror("Error: Too many arguments, run the program P0 with either zero or 1 argument");
		return 1;
	}
	// allocate buffer and strings to handle input from the file
	char buffer[20];
	char *infile;
	char *outPre;
	char *outInord;
	char *outPost;

	// initiallize the Tree pointer as well as input and output file pointers
	TreeNode * root = NULL;
	FILE * fp = stdin;
	FILE * foutPreorder;
	FILE * foutInorder;
	FILE * foutPostorder;
	char first;

	if (argc == 2){
		
		// concatenates the strings of the first passed argument and extension ".fs182"
		infile = malloc(strlen(argv[1]) + strlen(".fs182") + 1);
		strcpy(infile, argv[1]);
		strcat(infile, ".sp2020");
		fp = fopen(infile, "r");

		// each output file is set up with a different name based on whether it's pre, in, or post order
		outPre = malloc(strlen(argv[1]) + strlen(".preorder") + 1);
		strcpy(outPre, argv[1]);
		strcat(outPre, ".preorder");

		outInord = malloc(strlen(argv[1]) + strlen(".inorder") + 1);
		strcpy(outInord, argv[1]);
		strcat(outInord, ".inorder");

		outPost = malloc(strlen(argv[1]) + strlen(".postorder") + 1);
		strcpy(outPost, argv[1]);
		strcat(outPost, ".postorder");
	} else {
		
		// in the event that input is from stdin, output files are named differently
		outPre = malloc(strlen("out.preorder") + 1);
		outInord = malloc(strlen("out.inorder") + 1);
		outPost = malloc(strlen("out.postorder") + 1);

		strcpy(outPre, "out.preorder");
		strcpy(outInord, "out.inorder");
		strcpy(outPost, "out.postorder");
	}
	
	// gets input from input pointer and feeds one string-token at a time and its length to build a tree
	while (fscanf(fp, "%s", buffer) != EOF) {
		first = buffer[0];
		root = buildTree(root, first, buffer);
	}

	// a tree was made
	if (root != NULL){
		
		// output files are opened for pre, in, and post ordered trees
		foutPreorder = fopen(outPre, "w");
		foutInorder = fopen(outInord, "w");
		foutPostorder = fopen(outPost, "w");

		// trees are traversed in the three orders and output to files
		traversePreorder(0, root, foutPreorder);
		traverseInorder(0, root, foutInorder);
		traversePostorder(0, root, foutPostorder);

		// close all output files
		fclose(foutPreorder);
		fclose(foutInorder);
		fclose(foutPostorder);

	} else {
		// if the file wasn't available or couldn't be read
		errno = 2;
		perror("Error: Input could not be used. No usable file was found!");
		return 1;
	}

	// close the input file
	fclose(fp);
	return 0;
}
