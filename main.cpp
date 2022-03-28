#include <iostream>
#include <string>
#include "Notebook.hpp"
using namespace ariel;
using namespace std;

 int main(){
  ariel::Notebook notebook;
  string command;
  cout << "please enter the name of command" << endl;
  cin >> command;
  while (command!="stop"){
  ////////////////////////////////////////////////////////////////
  if (command=="write"){
  int page;
  cout << "please enter the a page number" << endl;
  cin >> page; 
  int row;
  cout << "please enter a row number" << endl;
  cin >> row;
   int column;
  cout << "please enter a column number" << endl;
  cin >> column;
  string s;
  cout << "please enter the a string" << endl;
  cin >> s; 
  string Direction;
  cout << "please enter a Direction" << endl;
  cin >> Direction;
  if(Direction=="Horizontal"){
  notebook.write(page,row,column, Direction::Horizontal,s);
  }
  if(Direction=="Vertical"){
  notebook.write(page,row,column, Direction::Vertical,s);
  }
  }
  ////////////////////////////////////////////////////////////////
  if (command=="read"){
  int page;
  cout << "please enter the a page number" << endl;
  cin >> page;  
  int row;
  cout << "please enter a row number" << endl;
  cin >> row;
   int column;
  cout << "please enter a column number" << endl;
  cin >> column;  
  int len;
  cout << "please enter the a len" << endl;
  cin >> len;  
  string Direction;
  cout << "please enter a Direction" << endl;
  cin >> Direction;
  if(Direction=="Horizontal"){
  cout << notebook.read(page,row,column, Direction::Horizontal,len) << endl;
  }
  if(Direction=="Vertical"){
  cout << notebook.read(page,row,column, Direction::Vertical,len) << endl;
  }
  }
  ///////////////////////////////////////////////////////////////////
  if (command=="erase"){
  int page;
  cout << "please enter the a page number" << endl;
  cin >> page;
  int row;
  cout << "please enter a row number" << endl;
  cin >> row;
  int column;
  cout << "please enter a column number" << endl;
  cin >> column;
  int len;
  cout << "please enter the a len" << endl;
  cin >> len;
  string Direction;
  cout << "please enter a Direction" << endl;
  cin >> Direction;
  if(Direction=="Horizontal"){
  notebook.erase(page,row,column, Direction::Horizontal,len);
  }
  if(Direction=="Vertical"){
  notebook.erase(page,row,column, Direction::Vertical,len);
  }      
  }
  /////////////////////////////////////////////////////////////////////////
  if (command=="show"){
  int page;
  cout << "please enter the a page number" << endl;
  cin >> page;    
  notebook.show(page);
  }
  
 
  cout << "please enter more name of command" << endl;
  cin >> command;

  }
  
  
  
 }