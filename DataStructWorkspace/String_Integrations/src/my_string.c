/*
 * my_string.c
 *
 *  Created on: Jan 22, 2016
 *      Author: david
 */
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



string_type Create( char *ary, int length){
	string_type str;
	str.length = length;
	str.capacity = length;
	str.element = malloc(sizeof(char) * length);
	copyString(str.element, ary, length);
	return str;
}

string_type CreateStr(char *ary){
	string_type str;
	int i = 0;
	while(ary[i++] != '\0');
	str.length = i;
	str.capacity = i;
	str.element = malloc(sizeof(char) * str.length);
	copyString(str.element, ary, str.length);
	return str;
}

string_type Clone(string_type original){
	string_type str;
	str.length = original.length;
	str.capacity = original.capacity;
	str.element = malloc(sizeof(char) * str.capacity);
	copyString(str.element, original.element, original.length);
	return str;
}

void Destroy(string_type str){
	free(str.element);
}

void Print(string_type str){
	printf("%s%s", str.element, "");
}

string_type Concatenate(string_type str1, string_type str2){
	string_type out = Create("", str1.capacity + str2.capacity);
	copyString(out.element, str1.element, str1.length-1);
	copyString(&out.element[str1.length-1], str2.element,str2.length);
	return out;
}

int Compare(string_type str1, string_type str2)
//Compares two strings, and returns + if the second is larger, and - if the first is larger.
//think 'ascending value is +' and 'descending value is -'
{
	int i, comp = 0;
	for(i = 0; i < min(str1.length, str2.length); i++){
		comp = tolower(str1.element[i])-tolower(str2.element[i]);
		if(comp != 0) break;
	}
	if(comp == 0 && !(str1.length == str2.length)){
		if(str1.length < str2.length){
			return 1;
		}
		return -1;
	}
	return comp;
}


//These functions really are kinda pointless.
int Length(string_type str){
	return str.length;
}

int Capacity(string_type str){
	return str.capacity;
}

int max(int a, int b){
	return(a > b)? a : b;
}

int min(int a, int b){
	return(a < b)? a : b;
}

void quickSort(string_type *arr, int left, int right)
//Returns + if second is lexographically greater,
//and returns - if second is lexographically lesser.
{
	int i = left, j = right;
	      string_type tmp;
	      string_type pivot = arr[(left + right) / 2];
	      while (i <= j) {
	            while (Compare(arr[i], pivot) < 0)
	                  i++;
	            while (Compare(arr[j], pivot) > 0)
	                  j--;
	            if (i <= j) {
	                  tmp = arr[i];
	                  arr[i] = arr[j];
	                  arr[j] = tmp;
	                  i++;
	                  j--;
	            }
	      };
	      /* recursion */
	      if (left < j)
	            quickSort(arr, left, j);
	      if (i < right)
	            quickSort(arr, i, right);
}

void copyString(char* dest, char* src, int length){
	int i;
	for(i = 0; i < length; i ++){
		dest[i] = src[i];
	}
}
