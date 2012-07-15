/************************************************************************
* Jonathan Canfield
* professor: Wortman
* Project 1 due 2/21/2012
************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdio>
#include <fstream>
using namespace std;

//function declerations 
void ReverseArray ( int *myArray,int n);
void SelectionSort( int *myArray, int n);
void BubbleSort( int *myArray, int n);
int create_array ( int *myArray, int n);
void cpu_run (int *myArray);
void user_run(int *myArray);
int *myArray;
ofstream myfile; 
	int main (){	
	myfile.open ("results.txt");
	int choice =0;
	
	/***********************************************************************
	** user is asked if they would like to run their own N input for each
	** test or you can simply have the computer run the tests for x amount
	** of times at a starting N amount and mulitplied by y
	***********************************************************************/
	cout<<"would you like to set N for each run or allow N to be x with y runs each increasing by n*z (enter 1 for x. y. z option)? ";
	cin>> choice;
	if (choice == 1){
		cpu_run(myArray);}
	if (choice !=1){
		user_run(myArray);}
		system ("pause");
	return 0;

}
// create_array, creates a array of size n filed with random integers from 
// 0-100000
int create_array ( int *myArray, int n){

	for ( int i= 0; i <n; i++){
		myArray[i]=rand()%100000;		
		}
	return *myArray;
}

/*********************************************************************** 
** reverses the array, the function only needs to run through half the *
** array since the left side is awapped with the right. the timer only *
** runs for the actual reverse alg. 
*************************************************************************/
void ReverseArray ( int *myArray, int n){
	
	clock_t start;
    double time_for_run;	
	int left =0;
	int right = n-1;
	int temp;		
	
	start = clock();   //starting timer	
	while (left < right){
		temp =myArray[left];
		myArray[left]=myArray[right];
		myArray[right] = temp;	
		left++;
		right=right -1;}		
	//ending timer once array has been reversed
	time_for_run = ( std::clock() - start ) / (double)CLOCKS_PER_SEC; 
	myfile <<"ReverseArray-> "<< time_for_run <<'\n';	
	cout<<"ReverseArray-> "<< time_for_run <<'\n';			
	
	
}
/**************************************************** 
** standared selection sort alg.  the timer only ****
** runs for the actual alg. 
****************************************************/
void SelectionSort( int *myArray, int n){
	
	clock_t start;
    double time_for_run;	
	int i, j, min, temp;    
	
	start = clock(); //starting timer     
	for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++)
                  if (myArray[j] < myArray[min])
                      min = j;
			      if (min != i) {
                     temp = myArray[i];
                     myArray[i] = myArray[min];
                     myArray[min] = temp;}
      }
	//ending timer once array has been sorted
	  time_for_run = ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
	  myfile <<"SelectionSort-> "<< time_for_run <<'\n';	
	  cout<<"SelectionSort-> "<< time_for_run <<'\n';			
}

/**************************************************** 
** standared bubble sort alg.  the timer only ****
** runs for the actual alg. 
****************************************************/
void BubbleSort( int *myArray, int n){
	
	clock_t start;	
    double time_for_run;	
	bool swap = true;
	int j = 0;
	int temp;
		start = clock(); //starting timer
      while (swap) {
            swap = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (myArray[i] > myArray[i + 1]) {
                        temp = myArray[i];
                        myArray[i] = myArray[i + 1];
                        myArray[i + 1] = temp;
                        swap = true;}
			         }
	          }
	  //ending timer once array has been sorted
	time_for_run = ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
	 myfile <<"BubbleSort-> "<< time_for_run <<endl<<endl;	
	cout<<"BubbleSort-> "<< time_for_run<<endl<<endl;	
}
/**********************************************************************
** The users sets the size of N, the amount N should be increased by **
** then the runs are performed. this was created so the users could  **
** set up the test requirments and walk away since some of the tests **
** could take a long time											 **
**********************************************************************/
void cpu_run(int *myArray){
	int count =1;
	int n=0;
	int run_amount=0;
	float increase_N=0;	
	cout<< "what N value you would like to start with? ";
	cin >> n;
	cout <<"what would you like N to be multiplied by for each run? ";
	cin>> increase_N;
	cout<<"What many runs? ";
	cin>> run_amount;
	while (count != run_amount){
		n = n * increase_N;
		cout<<"N ->"<<n<<endl;
		myfile <<"N ->"<<n<<endl;
		cout<<"count-> "<<count<<endl;
		 myfile <<"count-> "<<count<<endl;
		const int array_size = n;
		myArray = new int[n];
		
		*myArray=create_array (myArray,n);	
		ReverseArray(myArray,n);
		SelectionSort( myArray,n);
		*myArray=create_array (myArray,n);
		BubbleSort( myArray, n);	
		
		count++;
		if (n >100000000){
			count= run_amount;}
	}

}
	/*********************************************************************
	** The user inputs a size N for the three tests. When the           **
	** bubble sort is called the array is recreated because the         **
	** selection sort sorts the array thus the bubble sort is pointless **
	** when the tests are over the user is asked if they would like to  **
	** run another test.                                                **
	*********************************************************************/

	void user_run(int *myArray){
		int n=0;
		int run_more = 0;
		int count = 1;
		while ( run_more !=1){
		cout<<"input array size: ";
		cin>> n;		
		
		cout<<"N ->"<<n<<endl;
		myfile <<"N ->"<<n<<endl;
		cout<<"count-> "<<count<<endl;
		myfile <<"count-> "<<count<<endl;
		
		const int array_size = n;
		myArray = new int[n];
		
		*myArray=create_array (myArray,n);	
		ReverseArray(myArray,n);
		SelectionSort( myArray,n);
		*myArray=create_array (myArray,n);
		BubbleSort( myArray, n);			
		
		count++;
		cout<<"run once more? ";
		cin>> run_more;
		
	}
}