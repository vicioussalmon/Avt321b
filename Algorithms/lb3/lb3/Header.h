#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#include <memory>

using namespace std;



struct BinaryTree
{
	string FullName;
	int birthdate;
	int mark;

	BinaryTree* LeftBranch;
	BinaryTree* RightBranch;

};

int size(BinaryTree*& Root);

void get_data(BinaryTree* Root, BinaryTree* mass, int count);

void CreateNewTree(BinaryTree*& Root, string FullName, int birthdate, short int mark);

void Print(BinaryTree** Root, int l = 0); // print test

bool Empty(BinaryTree* Root);

void CreateTree(BinaryTree*& Root, string FullName, int birthdate, short int mark);

float avarmarkmark(BinaryTree*& Root);

void del(BinaryTree*& Root);


void pr_obh(BinaryTree*& Root);
void zb_obh(BinaryTree*& Root);
void sm_obh(BinaryTree*& Root);

void del_left_tree(BinaryTree*& Root);
void del_right_tree(BinaryTree*& Root);
void del_branch(BinaryTree*& Root, int mark);

void write_trea_in_file(BinaryTree* Root);


void PrintTest(BinaryTree const* node);
