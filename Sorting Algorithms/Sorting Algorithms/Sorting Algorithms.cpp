#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

void print(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) cout << vec[i];
}

vector<int> insertion_sort(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (vec[j - 1] > vec[j]) {
				swap(vec, j - 1, j);
				print(vec);
				cout << endl;
			}
		}
	}
	return vec;
}

vector<int> selection_sort(vector<int> vec) {
	int min;
	for (int i = 0; i < vec.size(); i++) {
		min = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		if (vec[min] < vec[i]) {
			swap(vec, min, i);
			print(vec);
			cout << endl;
		}
	}
	return vec;
}

vector<int> bubble_sort(vector<int> vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = 0; j < vec.size() - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				swap(vec, j, j + 1);
			}
		}
		print(vec);
		cout << endl;
	}
	return vec;
}

vector<int> merge(vector<int> left, vector<int> right) {
	int i = 0, j = 0;

	vector<int> temp;

	while (i < left.size() && j < right.size())
		if (left[i] < right[j]) temp.push_back(left[i++]);
		else temp.push_back(right[j++]);

	while (i < left.size()) temp.push_back(left[i++]);
	while (j < right.size()) temp.push_back(right[j++]);
	return temp;
}

vector<int> merge_sort(vector<int>& vec) {
	if (vec.size() <= 1) return vec;

	int mid = vec.size() / 2;

	vector<int> left(vec.begin(), vec.begin() + mid);
	vector<int> right(vec.begin() + mid, vec.end());

	cout << "left: ";
	print(left);
	cout << "   /   ";
	cout << "right: ";
	print(right);
	cout << endl;

	return merge(merge_sort(left), merge_sort(right));
}

vector<int> quick_sort(vector<int> vec) {
	return vec;
}

int main()
{
	vector<int> vec = { 4, 2, 6, 9, 7, 8, 5, 1, 3 };
	print(vec);
	cout << endl << endl;

	cout << "Insertion Sort:" << endl;
	vector<int> insertion = insertion_sort(vec);
	print(insertion);
	cout << endl << endl;

	cout << "Selection Sort:" << endl;
	vector<int> selection = selection_sort(vec);
	print(selection);
	cout << endl << endl;

	cout << "Bubble Sort:" << endl;
	vector<int> bubble = bubble_sort(vec);
	print(bubble);
	cout << endl << endl;

	cout << "Merge Sort:" << endl;
	vector<int> merge = merge_sort(vec);
	print(merge);
	cout << endl << endl;

	cout << "Quick Sort:" << endl;
	vector<int> quick = quick_sort(vec);
	print(quick);
	cout << endl;
}