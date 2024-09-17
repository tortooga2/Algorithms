#include <iostream>


using namespace std;

int main(int argc, char **argv ){
	int arraySize = 6;
	int array[] = {2,5,10,99,6,13, 256};




	
	
	
	
	for(int i = 1; i < arraySize; i++){
		for(int j = i; j > 0 && array[j] < array[j - 1]; j--){
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
		}
		for(int j = 0; j < i + 1; j++){
			cout << array[j] << ";";
		}
		cout << endl;
	}

	
	return 0;
}
