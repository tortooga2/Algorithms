#include <iostream>



using namespace std;



int BSearch(int Array[], int start, int end, int value){
	if (end < start) return -1;	
	
	int i = floor((start + end)/2);
	if(Array[i] == value){
		return i;
	}
	else if(Array[i] > value){
		return BSearch(Array, start, i - 1, value);
	}
	else{
		return BSearch(Array, i + 1, end, value);
	}
}




int main(){

	int sizeOfArray = 10;

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << BSearch(array, 0, 6, 5) << endl;

	return 0;
}
