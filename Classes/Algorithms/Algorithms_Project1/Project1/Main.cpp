//Search engines rank webpages based on popularity and relevance, with a low number meaning a page meets these qualifications. 
//This program accepts multiple source files with integers to represent the "score" each webpage receives. Each source file 
//resembles a different search engine with the same query. Each line in the source file represents a different webpage result,
//so for example if you have 3 source files, each representing a different search engine, line 4 of each source file will resemble 
//the same webpage, and each value in line 4 resembles a different score the search engine assigns it. This program sums each 
//line across all source files. This is the webpage total score. After each webpage has a total score, the total scores are sorted
//in ascending order. The webpages with the lowest total score resemble the "most accurate" webpages. The source file values are then
//sorted to the page order calculated from the total scores. The more values that are switched in each source file, the less accurate
//the search engine. The search engine with the fewest inversions is considered the most accurate search engine. 

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

//The number of lines(webpages) in each source file
const int SIZE = 10000;

struct Node
{
	int index; //Page number - 1
	int value; //The value of each page. The lower the number the higher in the list it ranks. 
};

//Read data from source file, place in Node array
Node *readFromFile(char *fileName)
{
	int count = 0;
	ifstream inFile;
	//Store in heap
	Node *list = (Node *)malloc(sizeof(Node)*SIZE);

	inFile.open(fileName);

	//If file is not found, display error message to user
	if(!inFile)
		cout << "Error opening \"" << fileName << "\"\n";

	//Read from file until EOF or until we fill our allocated array
	while(inFile && count < SIZE)
	{
		inFile >> list[count].value;
		list[count].index = count;
		count++;
	}

	inFile.close();

	return list;
}

//Sum across source files and calculate a total score for each webpage
Node *sumData(Node *list1, Node *list2, Node *list3, Node *list4, Node *list5)
{
	Node *listSum = (Node *)malloc(sizeof(Node)*SIZE);

	for(int i = 0; i < SIZE; i++)
	{
		listSum[i].value = list1[i].value + list2[i].value + list3[i].value + list4[i].value + list5[i].value;
		listSum[i].index = i;
	}

	return listSum;
}

//A simple (yet inefficient) bubble sort to sort our total scores in ascending order. We make sure to sort the page index as well
void orderedSumList(Node *sumList)
{
	bool sorted = false;
	int switches = 0;

	//Run until we have an instance where no switches are performed. This signals the array is sorted.
	while(!sorted)
	{
		sorted = true;

		for(int i = 0; i < SIZE - 1; i++)
		{
			//If the sum of i is greater than i+1, switch the sums and the page numbers.
			if(sumList[i].value > sumList[i+1].value)
			{
				Node temp;
				temp.index = sumList[i].index;
				temp.value = sumList[i].value;

				sumList[i].index = sumList[i+1].index;
				sumList[i].value = sumList[i+1].value;
				sumList[i+1].index = temp.index;
				sumList[i+1].value = temp.value;

				sorted = false;
			}
		}
	}
}

//Our source lists are originally sorted in ascending order by page number. Now that we have a list of total sums, 
//we sort our source files to be in the same order as the page numbers in our total sum array. 
int *preSortedOrder(Node *sourceList, Node *sumList)
{
	int *preSortedList = (int *)malloc(sizeof(int)*SIZE);

	for(int i = 0; i < SIZE; i++)
	{
		//sumList is a sorted list of nodes in ascending order with respect to the sum page count of i between all 5 source files,
		//therefore sumList[i].index is the page number of sumList[i].
		//We want to create an array of integers and load it with the page count of each page number of sumList for each source list.
		preSortedList[i] = sourceList[sumList[i].index].value;
	}

	return preSortedList;
}

//Our control function. We can compare our switches in our search algorithms with this bubble sort. 
long bubbleSort(int *list)
{
	bool sorted = false;
	long switches = 0;

	//Run until we have an instance where no switches are performed. This signals the array is sorted.
	while(!sorted)
	{
		sorted = true;

		for(int i = 0; i < SIZE - 1; i++)
		{
			//If the sum of i is greater than i+1, switch the sums and the page numbers.
			if(list[i] > list[i+1])
			{
				int temp;
				temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;

				sorted = false;
				switches++;
			}
		}
	}
	return switches;
}

//Our merge sort function
int mergeSort(int *list, int length)
{
	int switches = 0;
	int *ptrLeft = list;
	int *ptrRight = list+(length/2);

	if(length == 1)
		return 0;
	
	int jumpSize = length/2;

	switches += mergeSort(ptrLeft,length/2);
	switches += mergeSort(ptrRight,ceil(static_cast<double>(length)/2));

	int *leftOutOfBounds = ptrRight;
	int *rightOutOfBounds = list + length;

	int *buffer = (int *)malloc(sizeof(int)*length);

	int i = 0;

	while(i < length)
	{
		if(ptrLeft == leftOutOfBounds)
		{
			buffer[i] = *ptrRight;
			ptrRight++;
		}
		else if(ptrRight == rightOutOfBounds)
		{
			buffer[i] = *ptrLeft;
			ptrLeft++;
			jumpSize--;
		}
		else if(*ptrLeft <= *ptrRight)
		{
			buffer[i] = *ptrLeft;
			ptrLeft++;
			jumpSize--;
		}
		else if(*ptrLeft > *ptrRight)
		{
			buffer[i] = *ptrRight;
			ptrRight++;
			switches += jumpSize;
		}
		i++;
	}

	for(int i = 0; i < length; i++)
		list[i] = buffer[i];
	return switches;
}

//Verify sum array is in ascending order
void verifySumList(Node *list)
{
	for(int i = 0; i < SIZE-1; i++)
	{
		if(list[i].value > list[i+1].value)
		{
			cerr << "Sum list is NOT ordered. Error at line " << i << endl;
			exit(EXIT_FAILURE);
		}
	}
}

//Verify source array is in ascending order
void verifyOrderedList(int *list)
{
	for(int i = 0; i < SIZE-1; i++)
	{
		if(list[i] > list[i+1])
		{
			cerr << "List is NOT ordered. Error at line " << i << endl;
			exit(EXIT_FAILURE);
		}
	}
}

//Output sorted lists to files
void fileOutNode(char *fileName,Node *list)
{
	ofstream outFile; //output sorted sources

	outFile.open(fileName);

	outFile << "Score\tIndex\n";

	for(int i = 0; i < SIZE; i++)
		outFile << list[i].value << "\t" << list[i].index << endl;

	outFile.close();
}

//Output sorted lists to files
void fileOutInt(char *fileName,int *list)
{
	ofstream outFile;

	outFile.open(fileName);

	for(int i = 0; i < SIZE; i++)
		outFile << list[i] << endl;

	outFile.close();
}

//our function to measure accuracy is f(S_measured) = (S_max - S_measured)/S_max
long double accuracyFunction(long S_actual)
{	
	long double S_max = (SIZE*SIZE-SIZE)/2;

	return((S_max-S_actual)/S_max);
}

int main()
{
	//Our 5 source file array pointers
	Node *list1;
	Node *list2;
	Node *list3;
	Node *list4;
	Node *list5;

	//Holds the webpage sums
	Node *sumOfLists;

	char fileName1[100] = "Project1_source1.txt";
	char fileName2[100] = "Project1_source2.txt";
	char fileName3[100] = "Project1_source3.txt";
	char fileName4[100] = "Project1_source4.txt";
	char fileName5[100] = "Project1_source5.txt";

	//arrays are loaded with data from files
	list1 = readFromFile(fileName1);
	list2 = readFromFile(fileName2);
	list3 = readFromFile(fileName3);
	list4 = readFromFile(fileName4);
	list5 = readFromFile(fileName5);

	//Calculate sum for each page
	sumOfLists = sumData(list1,list2,list3,list4,list5);

	//Sort our total sum array by score in ascending order. We also sort the page number that
	//corresponds to that webpage
	orderedSumList(sumOfLists);

	//Verify sumList is ordered ascending
	verifySumList(sumOfLists);

	//We now sort our source file values to match the same order as the page numbers in our total sum array
	int *preSortedList1 = preSortedOrder(list1,sumOfLists);
	int *preSortedList2 = preSortedOrder(list2,sumOfLists);
	int *preSortedList3 = preSortedOrder(list3,sumOfLists);
	int *preSortedList4 = preSortedOrder(list4,sumOfLists);
	int *preSortedList5 = preSortedOrder(list5,sumOfLists);

	//We no longer need our original source file arrays 
	free(list1);
	free(list2);
	free(list3);
	free(list4);
	free(list5);

	//Set pointers to 0
	list1 = 0;
	list2 = 0;
	list3 = 0;
	list4 = 0;
	list5 = 0;

	/*----------------------------------------------------------------------------------------------
		Everything prior to this point is set up code for us to be able to perform sort functions. 
	----------------------------------------------------------------------------------------------*/

	int *mergeSortList1 = (int *)malloc(sizeof(int)*SIZE);
	int *mergeSortList2 = (int *)malloc(sizeof(int)*SIZE);
	int *mergeSortList3 = (int *)malloc(sizeof(int)*SIZE);
	int *mergeSortList4 = (int *)malloc(sizeof(int)*SIZE);
	int *mergeSortList5 = (int *)malloc(sizeof(int)*SIZE);

	int *bubbleSortList1 = (int *)malloc(sizeof(int)*SIZE);
	int *bubbleSortList2 = (int *)malloc(sizeof(int)*SIZE);
	int *bubbleSortList3 = (int *)malloc(sizeof(int)*SIZE);
	int *bubbleSortList4 = (int *)malloc(sizeof(int)*SIZE);
	int *bubbleSortList5 = (int *)malloc(sizeof(int)*SIZE);

	//Create a copy of our preSortedLists for our bubble sort functions
	for(int i = 0; i < SIZE; i++)
	{
		bubbleSortList1[i] = preSortedList1[i];
		bubbleSortList2[i] = preSortedList2[i];
		bubbleSortList3[i] = preSortedList3[i];
		bubbleSortList4[i] = preSortedList4[i];
		bubbleSortList5[i] = preSortedList5[i];
	}

	long switches;
	
	//Use bubble sort to sort our sorce lists as a control
	cout <<  "---Bubble sort switch results---" << endl;	
	switches = bubbleSort(bubbleSortList1);
	cout << "Source 1: " << switches << endl;
	switches = bubbleSort(bubbleSortList2);
	cout << "Source 2: " << switches << endl;
	switches = bubbleSort(bubbleSortList3);
	cout << "Source 3: " << switches << endl;
	switches = bubbleSort(bubbleSortList4);
	cout << "Source 4: " << switches << endl;
	switches = bubbleSort(bubbleSortList5);
	cout << "Source 5: " << switches << endl << endl;

	//Create a copy of our preSortedLists for our merge sort functions
	for(int i = 0; i < SIZE; i++)
	{
		mergeSortList1[i] = preSortedList1[i];
		mergeSortList2[i] = preSortedList2[i];
		mergeSortList3[i] = preSortedList3[i];
		mergeSortList4[i] = preSortedList4[i];
		mergeSortList5[i] = preSortedList5[i];
	}

	//Use merge sort to sort our source lists
	cout <<  "---Merge sort switch results---" << endl;	
	long switches1 = mergeSort(mergeSortList1,SIZE);
	cout << "Source 1: " << switches << endl;
	long switches2 = mergeSort(mergeSortList2,SIZE);
	cout << "Source 2: " << switches << endl;
	long switches3 = mergeSort(mergeSortList3,SIZE);
	cout << "Source 3: " << switches << endl;
	long switches4 = mergeSort(mergeSortList4,SIZE);
	cout << "Source 4: " << switches << endl;
	long switches5 = mergeSort(mergeSortList5,SIZE);
	cout << "Source 5: " << switches << endl << endl;

	/*----------------------------------------------------------------------------------------------
	------------------------------------Verify results---------------------------------------------- 
	----------------------------------------------------------------------------------------------*/

	verifyOrderedList(bubbleSortList1);
	verifyOrderedList(bubbleSortList2);
	verifyOrderedList(bubbleSortList3);
	verifyOrderedList(bubbleSortList4);
	verifyOrderedList(bubbleSortList5);

	verifyOrderedList(mergeSortList1);
	verifyOrderedList(mergeSortList2);
	verifyOrderedList(mergeSortList3);
	verifyOrderedList(mergeSortList4);
	verifyOrderedList(mergeSortList5);

	/*----------------------------------------------------------------------------------------------
	------------------------------------Print results to file--------------------------------------- 
	----------------------------------------------------------------------------------------------*/

	char sumList[100] = "SumList.txt";

	char bubble1[100] = "bubble1.txt";
	char bubble2[100] = "bubble2.txt";
	char bubble3[100] = "bubble3.txt";
	char bubble4[100] = "bubble4.txt";
	char bubble5[100] = "bubble5.txt";

	char merge1[100] = "merge1.txt";
	char merge2[100] = "merge2.txt";
	char merge3[100] = "merge3.txt";
	char merge4[100] = "merge4.txt";
	char merge5[100] = "merge5.txt";

	fileOutNode(sumList,sumOfLists);

	fileOutInt(bubble1,bubbleSortList1);
	fileOutInt(bubble2,bubbleSortList2);
	fileOutInt(bubble3,bubbleSortList3);
	fileOutInt(bubble4,bubbleSortList4);
	fileOutInt(bubble5,bubbleSortList5);

	fileOutInt(merge1,mergeSortList1);
	fileOutInt(merge2,mergeSortList2);
	fileOutInt(merge3,mergeSortList3);
	fileOutInt(merge4,mergeSortList4);
	fileOutInt(merge5,mergeSortList5);	

	/*----------------------------------------------------------------------------------------------
	------------------------------------Rank each search engine------------------------------------- 
	----------------------------------------------------------------------------------------------*/

	//Our method of scoring is a simple linear scale ranging from 0 to 1, with 1 meaning the search engine agrees with the sum of the search engines
	//and 0 meaning the results were completely opposite the sum of the search engines. The maximum amount of switches (which occurs when the results
	//are backwards, as mentioned), is calculated to be (n^2-n)/2. We can show this to be true in practice as well, which is below.

	int test[10000];

	for(int i = 10000; i > 0; i--)
	{
		test[10000-i] = i;
	}

	//We will call this max value S_max. Therefore our function to measure accuracy is f(S_measured) = (S_max - S_measured)/S_max.

	double source1Accuracy = accuracyFunction(switches1);
	double source2Accuracy = accuracyFunction(switches2);
	double source3Accuracy = accuracyFunction(switches3);
	double source4Accuracy = accuracyFunction(switches4);
	double source5Accuracy = accuracyFunction(switches5);

	cout << "---Accuracy---\n";
	cout << "Source 1: " << source1Accuracy << endl;
	cout << "Source 2: " << source2Accuracy << endl;
	cout << "Source 3: " << source3Accuracy << endl;
	cout << "Source 4: " << source4Accuracy << endl;
	cout << "Source 5: " << source5Accuracy << endl << endl;

	return 0;
}