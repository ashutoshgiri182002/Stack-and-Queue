/*

You are given a running stream of characters,output the
first non repeating characters in the string formed so far
after every new characters you get in input . Output -1 if such
a characters does't exist.

*/

#include<iostream>
#include<queue>
using namespace std;

int main(){

  queue<char>q;
  int freq[27] = {0};

char ch;
cin>>ch;

while(ch!='.'){
//letter
q.push(ch);
freq[ch-'a']++;
//query->remoce all characters from front of queue will you get a char with freq 1
while(!q.empty()){
  int idx = q.front()-'a';
  if(freq[idx] > 1){
    q.pop();
  }
  else{
    cout<<q.front()<<endl;
    break;
  }
}


if(q.empty()){
  cout<<"-1"<<endl;
}
cin>>ch;

}

return 0;
}
