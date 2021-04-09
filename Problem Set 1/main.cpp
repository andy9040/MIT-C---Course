//  main.cpp
//  Problem Set 1

#include <iostream>
using namespace std;
void indent();

#define INDENT "\n\n";

int main() {

//2.1
    const char* greeting = "Hello, World!";
    cout << greeting<<INDENT;
    
//2.2
    cout<<"Input repetitions n: ";
    int input;
    cin>>input;
    
    //for loop
    for(int i=0;i<input;i++){
        cout<<greeting<<endl;
    }
    indent();
    
    //while loop
    int t=0;
    while(t<input){
        cout<<greeting<<endl;
        t++;
    }
    indent();
    //do while loop
    do{
        cout<<greeting<<endl;
        t++;
    } while(t<input*2);
    
    indent();
 
//3.1
    /*1. The code will not compile because we are redefining arg1 with a different varialbe type. I got the error message: Redefinition of 'arg1' with a different type: 'char' vs 'int'"
    2. The code runs/compiles becauase even though we are defining varaibles with the saem identifier, they have different scopes.
    3. The inner declaration will be used.
    4. The outer declaration will be used
    5. The code will not compile because we the preproccesor commands are defined before the code. Therefore, the compiler will not know what file to get procedures from. Move #include <iostream> to top to fix.*/

//3.2 Basic Stats
    cout<<"How many numbers followed by the numbers."<<endl;
    
    int number;
    cin>>number;
    
    int i=0;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum=0;
    
    while(i<number){
        int newNumber;
        cin>>newNumber;
        if(newNumber>max){
            max=newNumber;
        }
        if(newNumber<min){
            min=newNumber;
        }
        
        sum+=newNumber;
        i++;
    }
    indent();
    cout<<"Mean: "<<(sum/number)<<endl;
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
    cout<<"Range: "<<max-min<<endl;
 
//3.3 Primes
    cout<<"How many primes?"<<endl;
    int numberOfPrimesDesired;
    cin>>numberOfPrimesDesired;
    
    int primesFound=0;
    int check=2;
    while(primesFound<numberOfPrimesDesired){
        bool isPrime=true;
        for(int j=2;j<check;j++){
            if(check%j==0){isPrime=false;}
        }
        
        if(isPrime==true){
            primesFound++;
            cout<<check<<endl;
        }
        check++;
    }
    indent();
//3.4.1 --> will not loop indefinitely because then program will never end and rest of modules won't work
    cout<<"3.4.1"<<endl;
    for(int j=0; j<3;j++){
        int userInput;
        cin>>userInput;
        
        cout<< ((userInput%5==0 && userInput>=0) ? userInput/5:-1)<<endl;
    }
    indent();
    
//3.4.2
    cout<<"3.4.2"<<endl;
    for(int j=0; j<3;j++){
        int userInput;
        cin>>userInput;
        
        int output =((userInput%5==0 && userInput>=0) ? userInput/5:-1);
        if (output==-1){continue;}
        cout<<output<<endl;
    }
    indent();
//3.4.3
    cout<<"3.4.3"<<endl;
    while(true){
        int userInput;
        cin>>userInput;
        if(userInput==-1){
            cout<<"Goodbye!";
            break;
        }
        cout<< ((userInput%5==0 && userInput>=0) ? userInput/5:-1)<<endl;
    }
 
//3.5
    /*1. Finds the proudct of bob and dole. REVISE: Russian peasant multiplication
     2. Return 1. Would not compile and error would form.
     3. Alternating sum of 1/n^2 (goes from + + to - -)*/
//4
    /*
     1. 0: 1, 1: 1, 2: 2, 9: 362880, 10: 3628800
     2. You get 1. This is incorrect cause you can't take factorails of negatives so I would add an if statement to ensure inputted number is positive.
     3. 13 factorial because we are exceeding the storage potential of the 32-bit algorithm.
     */
    int number;
    cout << " Enter a number : ";
    cin >> number ;
    
    while(number<0){
        cout<<"No negatives!";
        cin >> number ;
    }
    
    cout << "The factorial of " << number << " is ";
    long accumulator = 1;
    for (; number > 0; accumulator *= number --);
    cout << accumulator << ".\n";
    
    

    
    int number;
    cout << " Enter a number : ";
    cin >> number ;
    
    while(number<0){
        cout<<"No negatives!";
        cin >> number ;
    }
    
    cout << "The factorial of " << number << " is ";
    switch(number){
        case 0:
            cout<<"1\n";
            break;
        case 1:
            cout<<"1\n";
            break;
        case 2:
            cout << "2\n";
            break ;
        case 3:
            cout << "6\n";
            break ;
        case 4:
            cout << "24\n";
            break ;
        case 5:
            cout << " 120\n";
            break ;
        case 6:
            cout << " 720\n";
            break ;
        case 7:
            cout << " 5040\n";
            break ;
        case 8:
            cout << " 40320\n";
            break ;
        case 9:
            cout << " 362880\n";
            break ;
        case 10:
            cout << " 3628800\n";
            break ;
    }
        
    
    indent();
    return 0;
}

void indent(){
    cout<<INDENT;
}
