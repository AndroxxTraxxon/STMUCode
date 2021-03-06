/*
 * my_string.h
 *
 *  Created on: Jan 22, 2016
 *      Author: david
 */

#ifndef MY_STRING_H_
#define MY_STRING_H_

typedef struct {
 char *element ;
 unsigned int length;
 unsigned int capacity;
} string_type;

/* function prototypes */
string_type Create( char *ary, int length);
string_type CreateStr(char *ary);
string_type Clone(string_type original);
void Destroy(string_type str);
void Print(string_type str);
string_type Concatenate( string_type str1, string_type str2);
void Copy(string_type src, string_type dest);
int Compare(string_type str1, string_type str2);
int Length(string_type str);
int Capacity(string_type str);
int max(int a, int b);
int min(int a, int b);
void quickSort(string_type arr[], int left, int right);
void copyString(char* dest, char* src, int length);

#endif /* MY_STRING_H_ */
