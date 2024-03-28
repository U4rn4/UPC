#include <iostream>
#include <string>
#include <list>
// Add more includes if you wish.
// ...

using namespace std;

// Add auxiliary functions if you wish.
// ...

int main()
{
  // Declare and initialise more data if you wish.
  // ...
  
  list<int> v;
  

  string command;
  while (cin >> command) {

    list<int>::iterator it = v.begin();

    if (command == "v.push_back(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ");"
      v.push_back(val);
      
    } else if (command == "v.push_front(") {
        int val;
        cin >> val;
        string ending;
        cin >> ending; // Això consumeix el ");"
        v.push_front(val);
    } else if (command == "v.pop_front();") {
        v.pop_front();
    } else if (command == "v.pop_back();") {
        v.pop_back();
    } else if (command == "v.resize(") {
        int newsize;
        cin >> newsize;
        string ending;
        cin >> ending; // Això consumeix el ");"
        if (v.size()<newsize)
        {
          while (v.size()<newsize)
          {
            v.push_back(0);
          }
        }
        else{
          while (v.size()>newsize)
          {
            v.pop_back();
          }
          
        }
        
    } else if (command == "cout<<v[") {
        int index;
        cin >> index;
        string ending;
        cin >> ending; // Això consumeix el "];"
        for (int i = 0; i < index; i++)
        {
          it++;
        }
        cout << *it << endl;
    } else if (command == "cout<<v;") {
      int vsiz = v.size()-1;
        for (int i = 0; i < vsiz; i++)
        {
          cout << *it << ',';
          it++;
        }
        cout << *it << endl;
    } else if (command == "v[") {
        int index;
        cin >> index;
        string mid;
        cin >> mid; // Això consumeix el "]="
        int val;
        cin >> val;
        string ending;
        cin >> ending; // Això consumeix el ";"
        for (int i = 0; i < index; i++)
        {
          it++;
        }
        *it = val;
        // ...
    } else if (command == "//") {
        string comment;
        getline(cin, comment);
        cout << "//" << comment << endl;
    } else {
        cout << "Wrong command '" << command << "'" << endl;
        string discard;
        getline(cin, discard);
    }
  }
}