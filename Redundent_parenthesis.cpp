
/*

Given s string of balaced rxpression ,find if it contains a redundant parenthesis or not.
A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary
or multiple brackets.print 'Yes' if redundant else 'No'

*/



#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkRedundent(string str){

  stack<char>s;
  for(char ch : str){
    if(ch!=')'){
      s.push(ch);  //a,b,+,-,(...
    }
    else{
      //')'
      bool operator_found = false;
      while(!s.empty() and s.top()!='('){
        char top = s.top();
        if(top=='+' or top=='-' or top=='*' or top == '/' or top == '%'){
          operator_found = true;
        }
        s.pop();
      }
      s.pop();

      if(operator_found == false){
        return true;
      }
    }
  }
  return false;
}

int main(){

string str = "((a+b+c) + c)";  //((a+b))
if(checkRedundent(str)){
  cout<<"contain redundant parenthesis";
}
else{
  cout<<"Does't contain Redundent parenthesis";
}

return 0;
}
