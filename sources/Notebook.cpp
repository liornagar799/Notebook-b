#include <iostream>
#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iterator>
#include <map>
#include <bits/stdc++.h>
using namespace ariel;
using namespace std;

const int MAX=100;
const int min_ch=32;
const int max_ch=126;


      void ariel::Notebook::write( int page, int row, int column,Direction x,const string &s){
         if(page < 0 || row < 0 || column< 0 || column>=MAX|| (s.length() > MAX && x==Direction::Horizontal) || ((column +int(s.length())) > MAX && x==Direction::Horizontal)){
           throw invalid_argument ("invalid argument");
          // return "invalid argument";       
         }
      
         for (const auto &ch : s) {
            if(ch =='~' || ch=='\n' || (ch < min_ch || ch > max_ch)){
            throw invalid_argument ("invalid argument");        
            }
         }

        /////////////////////////////
        if(x==Direction::Horizontal){
           // if the page./ the row not Exists
           if(pages.find(page)==pages.end() ||pages[page].find(row)==pages[page].end() ){  
               int i=0;    
               for (const auto &ch : s) { 
                  if(ch=='_'){
                   i++ ; 
                  } else{
               pages[page][row][column+i]=ch; 
               i++;}
               }
         
          // if the page and the row are Exists 
           }else{
               for(int i=column; i<column+int(s.length()); i++){ 
                 // if all the place is not _ return throw           
                if (!pages[page][row][i].empty()){
                 throw invalid_argument ("invalid argument");
                 break;
                } 
                }
               int i=0;    
               for (const auto &ch : s) {  
                if(ch=='_'){
                   i++;  
                  } else{
               pages[page][row][column+i]=ch; 
               i++;}
               }       
           
           }
        }
      
        
        /////////////////////////////
        if (x==Direction::Vertical){
                //if the page not Exists
             if(pages.find(page)==pages.end()){  
               int i=0;    
               for (const auto &ch : s) {  
                if(ch=='_'){
                   i++ ; 
                  } else{
               pages[page][row+i][column]=ch; 
               i++;}
               }      
                
           }else{
                // // if the page Exists check if the rows are Exists and without  _
                for (int z=row; z< row +int(s.length()); z++){
                 if(pages[page].find(z)!=pages[page].end()){
                  if (!pages[page][z][column].empty()){
                  throw invalid_argument ("invalid argument");
                  break;
                }}}        
               // if the place is good
               int i=0;    
               for (const auto &ch : s) {  
                if(ch=='_'){
                   i++;  
                  } else{
               pages[page][row+i][column]=ch; 
               i++;}
               } 
                   
           }


        }
        }
        
        string ariel::Notebook::read(int page, int row, int column,Direction x, int len){
         if(len<0 || page < 0 || row < 0 || column< 0 || column>=MAX|| (len > MAX &&  x==Direction::Horizontal) || (column + len > MAX && x==Direction::Horizontal) ){
           throw invalid_argument ("invalid argument");
          // return "invalid argument";       
           }
           string ans;
           if (x==Direction::Horizontal){
           for( int i=column; i< column+len ; i++){
            if(pages[page][row][i].empty()){
            ans+= '_';
            }else{               
            ans+= pages[page][row][i];        
           }}}
                

           if (x==Direction::Vertical){
           for(int i=row; i< row+len; i++){        
            if( pages[page][i][column].empty()){
            ans+= '_';
            }else{       
            ans+=pages[page][i][column];        
           }}}
           return ans;       
           
        
        }

        void ariel::Notebook::erase( int page, int row, int column,Direction x, int len){
          if(len<0 || page < 0 || row < 0 || column< 0 ||column>=MAX|| (len > MAX &&  x==Direction::Horizontal) || (column + len > MAX && x==Direction::Horizontal) ){
           throw invalid_argument ("invalid argument");
          // return "invalid argument";       
           }   

        /////////////////////////////
        if(x==Direction::Horizontal){
               for(int i=column; i< column+ len; i++){  
               pages[page][row][i]= '~';
               
        }}
        
        /////////////////////////////
        if (x==Direction::Vertical){
                for(int i=row; i< row +len; i++){
                   pages[page][i][column]='~';
               

        }}
        }


//////////////////////////////////////////////////////////////////////

 void ariel::Notebook::show(int page){
          if(page < 0){
           throw invalid_argument ("invalid argument");}
         if (pages.find(page)==pages.end()){
            cout << " the page is empty" << endl;
         }else{
            int last = pages[page].rbegin()->first;
            int first = pages[page].begin()->first;
            for(int i=first; i<=last; i++){
              cout << i << " ) "; 
              cout << read(page,i,0,Direction::Horizontal,MAX) << endl ;
             }
         }}



         
         

      

