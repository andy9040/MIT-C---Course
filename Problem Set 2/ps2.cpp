//Problem Set 2

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

    /*Question 2 -
         2
         246
         6
         8
         10
     
     Q3.1
        1) put a void printNum(int); at the top (prototype @ top) or 2) place the definition at top
     Q3.2
        Remove additional semicolon at the end of line 3. 1) Replace w/ printNum(number) or replace number with 35 on line 3 and remove number from printNum(); on line 7.
     Q3.3
     */
    
void doubleNumber (int *num ) {*num = *num * 2;}

int sum(const int a, const int b){
    return a+b;
}
double sum(const double a, const double b){return a+b;}

int sum(const int a, const int b, const int c){
    return a+b+c;
}

int sum(const int a, const int b, const int c, const int d){
    return a+b+c+d;
}

int SUM(const int a, const int b, const int c=0, const int d=0){
    return a+b+c+d;
}

int sum(const int array[], const int num){
    int sum=0;
    for(int i=0;i<num;i++){
        sum+=array[i];
    }
    return sum;
}

int mySum(const int array[], const int length){
    if(length==0){
        return 0;
    }else{
        //(array+1)[0] represents the 0th of an array that has all the elements of 'array' except the first one (due to the +1)
        return array[0]+mySum(array+1, length-1);
    }
}

double piCalc(const int reps){
    srand((unsigned)time(NULL));
    
    int count=0;
    for(int i=0; i<reps; i++){
        double xRand=rand()/(double)RAND_MAX;
        double yRand=rand()/(double)RAND_MAX;
        
        double d=sqrt(pow(xRand,2)+pow(yRand,2));
        if(d<1){
            count++;
        }
    }
    
    cout<<count<<" "<<reps<<endl;
    return (double)4*count/reps;
}

//function 6.1
void printArray(const int list[], const int len){
    cout<<endl<<"------"<<endl;
    int length =len;
    for(int i=0; i<length-1; i++){
        cout<<list[i]<<", ";
    }
    cout<<list[length-1]<<endl;
}
//function 6.2
void reverse(int list[], const int len){
    for(int i=0; i<len/2; i++){
        int store = list[i];
        list[i]=list[len-1-i];
        list[len-1-i]=store;
    }
}
//function 6.3
int LENGTH = 4;
int WIDTH = 5;

void transpose ( const int input[][LENGTH], int output[][WIDTH]){
    for(int i=0; i<LENGTH; i++){
        for(int j=0; j<WIDTH; j++){
            output[i][j]=input[j][i];
        }
    }
}

void alsoReverse(int list[], const int len){
    for(int i=0; i<len/2; i++){
        int store = *(list+i);
        *(list+i)=*(list+len-1-i);
        *(list+len-1-i)=store;
    }
}

int lengthString(const char* string){
    int counter=0;
    while(true){
        if(*(string+counter)!='\0'){
            counter++;
        } else {
            return counter;
        }
    }
    
    return counter;
}
//7.2
void swap(int &a, int &b){
    int c=a;
    a=b;
    b=c;
}
//7.3
void SWAP(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

//7.4

void SWAPtwo(int **a, int **b){
    int* c=*a;
    *a=*b;
    *b=c;
}



int main () {
    int num = 35;
    doubleNumber (&num);
    cout << num << endl ; // Should print 70
    
    /*
     3.4 - add a return diff
     3.5 - add a 3rd int arguement to function
     3.6 - turn yPtr into *yPtr
     */
    
    cout<<endl<<"Question 4.1"<<endl<<sum(23,56)<<endl<<sum(2.4,5.92)<<endl<<endl;
    
    //Question 4.2 - Because we have 2 function, using both int and a double as inputs would ensure the neither could be used because both could be equally likely to be used, causing the computer to error
    
    //Q 4.4 - The compiler wouldnt be able to distinguish calls from eacher other because it's either the function with defaults or one of rge functions without defaults
    cout<<SUM(4,9,5)<<endl<<endl;
    
    //Q4.5
    int numbers[]={5,9,8,4,7,7};
    int NUMBERS[]={5,9,8,4,7,7};
    cout<<"-----------"<<(NUMBERS+1)[0]<<endl;
    for(int i=0; i<(sizeof(numbers)/sizeof(numbers[0]));i++){
        cout<<numbers[i]<<endl;
    }
    cout<<"-----------"<<endl;
    cout<<*numbers<<endl;
    cout<<*(numbers+1)<<endl;
    cout<<"Sum:"<<mySum(numbers,6) <<endl<<endl;
    
    //Q5 Calculating PI
    cout<<piCalc(5000000)<<endl;
    //Q6.1
    int newArray[]={1,2,3,4,5};
    printArray(newArray,5);
    
    //Q6.2
    reverse(newArray,5);
    printArray(newArray,5);
    
    //Q6.3 --> function above
    //6.4 There will be a scope error
    //6.5 --> function above
    alsoReverse(newArray,5);
    printArray(newArray,5);
    
    //7.1 Pointers and Strings
    cout<<lengthString("123456789")<<endl;
    
    //7.2
    int alpha =2;
    int beta = 3;
    cout<<"alpha:"<<alpha<<" beta:"<<beta<<endl;
    SWAP(&alpha,&beta);
    cout<<"alpha:"<<alpha<<" beta:"<<beta<<endl;
    
    //7.5
    /*char *nthCharPtr = &oddOrEven[5];
    nthCharPtr -= 2; or nthCharPtr = oddOrEven + 3;
    cout << *nthCharPtr;
    char **pointerPtr = &nthCharPtr;
    cout << pointerPtr;
    cout << **pointerPtr;
    nthCharPtr++;
    cout << nthCharPtr - oddOrEven;*/
    
    cout<<"-----------"<<endl;
    return 0;
}
