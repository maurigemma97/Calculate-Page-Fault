#include <string>
#include <iostream>
using namespace std;
#define NUM_REF

void FIFO(int);
void LRU(int);

int pages[NUM_REF] = {1, 2, 7, 4, 5, 2, 7, 2, 3, 2, 1, 7, 6, 3, 7, 6, 3, 4, 3, 4, 3, 4, 7, 2, 1, 7, 6, 7, 8, 7, 8, 9, 7, 8, 2, 7, 8, 3, 5, 3, 5, 7};

int resultsAr[0][0] = {};
int FIFOmin = 10000, LRUmin = 10000;
int FIFOMin = 0, LRUMin = 0;
//int totalmin = 0;

void FIFO(int);
void LRU(int);
 /*------------------------------------------------*/
int main ()
{

	cout << "Page Replacement Algorithm Evaluation Result" << endl;
	cout << " " << endl;

	cout << "FIFO RESULTS:" << endl;
	for(int fifocap = 3; fifocap <= 7; fifocap++)
	{	
		//cout << cap << endl;	
		FIFO(fifocap);
	}
	cout << " " << endl;
	
	
	cout << "LRU RESULTS:" << endl;
	for(int lrucap = 3; lrucap <= 7; lrucap++)
	{
		//cout << newCap << endl;
		LRU(lrucap);
	}
	cout << " " << endl;
	if(FIFOmin == LRUmin)
	{
		cout<< "both have same page fault minimum of:" << " " << FIFOmin << endl;
	}
	if(FIFOmin < LRUmin)
	{
		cout << "FIFO minimum is smaller than LRU minimum with:" << " " << FIFOmin << endl;
	}
	if(FIFOmin > LRUmin)
	{
		cout << "LRU minimum is smaller than FIFO minimum with:" << " " << LRUmin << endl;
	}
	

cout << endl << "MIN Number of FIFO Page Replacement Faults: " << FIFOmin << endl << "Frame Number: " << FIFOMin << endl;
cout << endl << "MIN Number of LRU Page Replacement Faults: " << LRUmin << endl << "Frame Number: " << LRUMin << endl;

return 0;
}
/*------------------------------------------------*/

void FIFO(int frames)
{
 // int ref = pages[NUM_REF];	
  int FIFOar[  7 ] = {}; 
  int pageF =  0 ; 
  int counter =  0 ; 

	for ( int i =  0 ; i < 42 ; i++) 
	{ 
		if (i ==  0 ) 
		{ 
			for ( int j =  0 ; j < frames; j++) 
			{ 
				if(FIFOar[j] == frames)
				{
					FIFOar[j] = pages[j]; 
					pageF++; 
					i++;
				} 
			} 
		} 
		if (pages[i] != FIFOar[  0 ] && pages[i] != FIFOar[  1 ] && pages[i] != FIFOar[  2 ] && pages[i] != FIFOar[  3 ] && pages[i] != FIFOar[  4 ]  && pages[i] != FIFOar[  5 ] && pages[i] != FIFOar[  6 ]) 
		{ 
			pageF++; 
			FIFOar[counter] = pages[i]; 
			counter++; 
		
			if (counter == frames)
			{ 
				counter =  0 ; 
			}
		}
		
 
		if (frames ==  3 ) 
		{
			resultsAr[  0 ][  0 ] = pageF;
		}
 
		if ( frames ==  4 )
		{ 
			resultsAr[  1 ][  0 ] = pageF;
		} 
		if (frames ==  5 )
		{ 
			resultsAr[  2 ][  0 ] = pageF;
		} 
		if (frames ==  6 )
		{ 
			resultsAr[  3 ][  0 ] = pageF;
		} 
		if(frames ==  7 )
		{	
			resultsAr[  4 ][  0 ] = pageF;
		}
	//}
		
   	
		FIFOmin = resultsAr[  0 ][  0 ]; 
		for ( int f =  1 ; f <  5 ; f++) 
		{ 
			if (resultsAr[f][  0 ] < resultsAr[f-  1 ][  0 ]) 
			{ 
				FIFOmin = resultsAr[f][  0 ]; 
				FIFOMin = f +  3 ; 
			} 
			else 
    				FIFOMin =  3 ; 
  		}
	
	} 
  	cout << "Frame Number " << frames << ": " << pageF << " Page Faults" << endl; 
} 
  /*---------------------------------------------------------------------------------------------------*/


void LRU( int moreFrame) 
{ 
	int LRUar[ 7 ] = {}; 
	int counter[ 7 ] = {}; 
 	int pF =  0 , oP =  0 , max =  0 ;
	const int ref = 42; 

	for ( int t =  0 ; t <  ref ; t++) 
	{
		//cout << "outer loop" << endl;
		if (t ==  0 )
		{ 
   
			for ( int j =  0 ; j < moreFrame; j++) 
			{
				if(LRUar[j] == moreFrame)
				{ 
					LRUar[j] = pages[j]; 
					pF++; 
					t++;
				} 
			} 
		//}
			if (moreFrame ==  3 ) 
			{ 
				counter[  0 ] =  3 ; 
				counter[  1 ] =  2 ; 
				counter[  2 ] =  1 ; 
			} 
			else  if (moreFrame ==  4 ) 
			{ 
				counter[  0 ] =  4 ; 
				counter[  1 ] =  3 ; 
				counter[  2 ] =  2 ; 
				counter[  3 ] =  1 ; 
			} 
			else  if (moreFrame ==  5 ) 
			{ 
				counter[  0 ] =  5 ; 
				counter[  1 ] =  4 ; 
				counter[  2 ] =  3 ; 
				counter[  3 ] =  2 ; 
				counter[  4 ] =  1 ; 
			} 
			else  if (moreFrame ==  6 ) 
			{ 
				counter[  0 ] =  6 ; 
				counter[  1 ] =  5 ; 
				counter[  2 ] =  4 ; 
				counter[  3 ] =  3 ; 
				counter[  4 ] =  2 ; 
				counter[  5 ] =  1 ; 
			} 
			else  if (moreFrame ==  7 ) 
			{ 
				counter[  0 ] =  7 ; 
				counter[  1 ] =  6 ; 
				counter[  2 ] =  5 ; 
				counter[  3 ] =  4 ; 
				counter[  4 ] =  3 ; 
				counter[  5 ] =  2 ; 
				counter[  6 ] =  1 ; 
			} 
		} 
 
		if (pages[t] != LRUar[  0 ] && pages[t] != LRUar[  1 ] && pages[t] != LRUar[  2 ] && pages[t] != LRUar[  3 ] && pages[t] != LRUar[  4 ] && pages[t] != LRUar[  5 ] && pages[t] != LRUar[  6 ]) 
		{ 
			pF++; 
			max =  0 ; 

			for ( int z =  0 ; z < moreFrame; z++) 
			{ 
				if (counter[z] > max) 
				{ 
					max = counter[z]; 
					oP = z; 
				} 
			} 

			LRUar[oP] = pages[t]; 
			counter[oP] =  0 ; 
		} 

		else  if (LRUar[  0 ] == pages[t]) 
			counter[  0 ] =  0 ; 
		else  if (LRUar[  1 ] == pages[t]) 
			counter[  1 ] =  0 ; 
		else  if (LRUar[  2 ] == pages[t]) 
			counter[  2 ] =  0 ; 
		else  if (LRUar[  3 ] == pages[t]) 
			counter[  3 ] =  0 ; 
		else  if (LRUar[  4 ] == pages[t]) 
			counter[  4 ] =  0 ; 
		else  if (LRUar[  5 ] == pages[t]) 
			counter[  5 ] =  0 ; 
		else  if (LRUar[  6 ] == pages[t]) 
			counter[  6 ] =  0 ; 
		for ( int q =  0 ; q < moreFrame; q++)
		{ 
			counter[q]++; 
		} 

		if (moreFrame ==  3 ) 
			resultsAr[  0 ][  1 ] = pF; 
		else  if (moreFrame ==  4 ) 
			resultsAr[  1 ][  1 ] = pF; 
		else  if (moreFrame ==  5 ) 
			resultsAr[  2 ][  1 ] = pF; 
		else  if (moreFrame ==  6 ) 
			resultsAr[  3 ][  1 ] = pF; 
		else  if (moreFrame ==  7 ) 
			resultsAr[  4 ][  1 ] = pF; 

		//cout << "Frame number " << moreFrame << ": " << pF << " Page Faults" << endl; 

		LRUmin = resultsAr[  0 ][  1 ]; 
		for ( int l =  1 ; l <  5 ; l++) 
		{ 
			if (resultsAr[l][  1 ] < resultsAr[l-  1 ][  1 ]) 
			{ 
				LRUmin = resultsAr[l][  1 ]; 
				LRUMin = l +  3 ; 
			} 
			else 
				LRUMin =  3 ; 
		} 

	} 
	cout << "Frame number " << moreFrame << ":" << " " <<  pF << " " <<  "Page Faults" << endl;

}
