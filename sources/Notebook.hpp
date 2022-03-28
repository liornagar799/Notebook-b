#include <string>
#include "Direction.hpp"
#include <map>
using namespace std;

namespace ariel{
    class Notebook{   
     private:
     
    //  struct arr
    //  {
    //  char a[100];
    //  }; 
    //  map<int, map<int, arr>> pages;

    //map of pages , for every page < row, array>
     map<int, map<int, string[100]>> pages;
    
     
     public:
        void write( int page, int row, int column,Direction x, const string &s);
        string read(int page, int row, int column,Direction x, int len);
        void erase( int page, int row, int column,Direction x, int len);
        void show(int page);
    };
    
}

