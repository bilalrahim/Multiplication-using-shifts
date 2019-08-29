#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#include <chrono>
using namespace std::chrono;

/*Converts the values to strings first and selects required "digit" through index, 
then re-converts the selected-digit to int and adds it the number of times its required.
It converts the sum to string for adding "zeros"(this is where shift happens).
Re-converts it to int and addds it to final answer.
*/

int divide_conquer_mul(int v1,int v2)
{

	int counter=1;                //While loop counter.
    int t_sum=0;                //Variable for sum.
    int answer=0;                //VAriable for final answer.
    std::string st_val1= std::to_string(v1);        //converting both values to string.
    std::string st_val2= std::to_string(v2);
    int val1_digit_c=st_val1.size();    //Number of digits in value 1.
    int val2_digit_c=st_val2.size();    //Number of digits in value 2.
	int sum_count=0;                    //Sum Count for adding zeros.
    
    for(int i=0 ; i < val1_digit_c ; i++)
    {
        for(int j=0 ; j < val2_digit_c ; j++)
        {
            char x=st_val1[i];                //moving the required digit to x.
            char y=st_val2[j];               //We need y to know how many times x needs to be added.
			int x1=int(x)-48;               //Converting the digit to int for furthur procces.
            int y2=int(y)-48;
            for(int k=0 ; k < y2 ; k++)   //Adding the number. (the number of times it's required to be added).
            {
               t_sum+=x1;
            }
			std::string str_t_sum=std::to_string(t_sum); //Converting total sum to string so we can add 'zeros'.
			sum_count=val1_digit_c-(i+1);
            sum_count=sum_count+(val2_digit_c-(j+1));

            while(counter<=sum_count)       //This is where shift happens^.
            { 
				str_t_sum=str_t_sum+"0";
				counter++;
            }
			t_sum=atoi(str_t_sum.c_str());
            answer+=t_sum;           //Adding the number to final answer after adding zeros.
			
			//Reseting them both for next itration.
			t_sum=0;
			counter=1;
    
		}
    }
    cout<<answer<<endl;

	return answer;


}


void main()
{


	auto start = high_resolution_clock::now(); 
	
	divide_conquer_mul(981,1234);
    
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; 
  
return ;
}

