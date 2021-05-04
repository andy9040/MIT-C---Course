#include <string>
#include <iostream>

using namespace std;

const string vowels = "aeiouAEIOU";
string PigLatinify(const string input){
    if(input.size()==0){
        return input;
    }
    
    if(input.find("qu")==0){
        return input.substr(2,input.size()-1)+"-"+"quay";
    }
    
    string checker=input.substr(0,1);
    if(vowels.find(checker)!=-1){
        return input.substr(0,input.size())+"-"+"way";
    } else {
        
        return input.substr(1,input.size()-1)+"-"+input.substr(0,1)+"ay";
    }
    
    return "hi";
}

int main() {
    // insert code here...
    int i=0;
    while(i<5){
    cout<<"Give a word:"<<endl;
    string word;
    cin>>word;
    cout<<PigLatinify(word)<<endl;
        i++;
    }
    std::cout << "\n";
    return 0;
}
