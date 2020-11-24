#include<iostream>
using namespace std;

bool isVowel(char ch) 
{ 
    ch = toupper(ch); 
    return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'); 
} 
  

int countVowels(string str, int n) 
{ 
    if (n == 1) 
        return isVowel(str[n-1]); 
  
    return countVowels(str, n-1) + isVowel(str[n-1]); 
} 
  
int main() 
{ 
    
    string str = "Hifza Majeed "; 
  
    
    cout << countVowels(str,str.length()) << endl; 
	system("pause");
    return 0; 
}
