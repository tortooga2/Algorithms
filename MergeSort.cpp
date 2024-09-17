#include <iostream>

using namespace std;


int ARRAYSIZE = 13;
int ARRAY[] = {3, 4, 10, 15, 11, 19, 10, 1, 111, 12, 454, 101, 99};


int* Merge(int sizeOfL, int sizeOfR, int *inLeft, int *inRight){
	
	int length = sizeOfL + sizeOfR;
	int *S = new int[length];
	
	int pL = 0;
	int pR = 0;

	for(int i = 0; i < length; i++){
		if((inLeft[pL] > inRight[pR] || pL >= sizeOfL) && pR < sizeOfR){
			S[i] = inRight[pR];
			pR+=1;
		}
		else{
			S[i] = inLeft[pL];
			pL+=1;
		}
	}
	
	return S;
}

int* MergeSort(int sizeOfA, int *A){
	int length = sizeOfA;
	if(length <= 1){
		return A;
	}
	int overflow = length % 2 == 1;
	int sub_length = floor(length / 2);
	
	int *arrayL = new int[sub_length];
	int *arrayR = new int[sub_length + overflow];

	for(int i = 0; i < sub_length; i++){
		arrayL[i] = A[i];
		arrayR[i] = A[sub_length + i];
	}
	arrayR[sub_length] = A[length - 1];
	arrayL =  MergeSort(sub_length, arrayL);
	arrayR =  MergeSort(sub_length + overflow, arrayR);
	int *out = Merge(sub_length, sub_length + overflow, arrayL, arrayR);

	delete[] arrayL;
	delete[] arrayR;

	return out;
}


int main(){

	int* unsortedArray = new int[ARRAYSIZE];
	for(int i = 0; i < ARRAYSIZE; i++) unsortedArray[i] = ARRAY[i];

	int * sortedArray = new int[ARRAYSIZE];	
	sortedArray = MergeSort(ARRAYSIZE, unsortedArray);


	cout << "Results: " << endl;
	for(int i = 0; i < ARRAYSIZE; i++){
		cout << sortedArray[i] << " ";
	}
	cout << endl;

	delete[] unsortedArray;
	delete[] sortedArray;

	return 0;
}






