#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<string> VecString;

struct Slot
{
    VecString listsubjects;
    VecString listteachers;
};
typedef vector<vector<Slot>> TableSlots;

void Slots(Slot& slot, const string& subject, const string& teacher)
{
    slot.listsubjects.push_back(subject);
    slot.listteachers.push_back(teacher);
}

int Weekdayc(const string& weekday)
{
    int day;
    if      (weekday == "monday")       day = 0;
    else if (weekday == "tuesday")      day = 1;
    else if (weekday == "wednesday")    day = 2;
    else if (weekday == "thursday")     day = 3;
    else                                day = 4;

    return day;
}

void WriteJRS(const string text, const int width)
{
    int text_width = text.size();
    for(int i = 0; i < width-text_width; ++i)
        cout << ' ';
    cout << text;
}

void ConflictsCalculator(VecString& vec, int& conflicts)
{
    int size = vec.size();
    if (size == 0) return;

    sort(vec.begin(), vec.end());
    
    VecString vec_new;

    string entry_before = "-1";
    string entry;

    for(int i = 0; i < size; ++i)
    {
        entry = vec[i];
        if (entry == entry_before) conflicts++;
        else vec_new.push_back(entry);
        entry_before = entry;
    }

    vec = vec_new;
}

void WriteJRI(const int text, const int width)
{
    int text_width = 0;
    int text_aux = text;
    if (text == 0) text_width = 1;
    while(text_aux != 0)
    {
        text_aux /= 10;
        text_width++;
    }
    for(int i = 0; i < width-text_width; ++i)
        cout << ' ';
    cout << text;
}

void Write(const TableSlots& table, const int& bottom_h, const int& top_h, const int& conflicts)
{
    cout << "number of subjects per slot:" << endl;
    WriteJRS("h", 2);
    WriteJRS("monday", 10);
    WriteJRS("tuesday", 10);
    WriteJRS("wednesday", 10);
    WriteJRS("thursday", 10);
    WriteJRS("friday", 10);
    cout << endl;

    for(int i = bottom_h; i < top_h; ++i)
    {
        WriteJRI(i, 2);
        for(int j = 0; j < 5; ++j)
        {
            WriteJRI(table[j][i].listsubjects.size(), 10);
        }
        cout << endl;
    }

    cout << "number of teachers per slot:" << endl;
    WriteJRS("h", 2);
    WriteJRS("monday", 10);
    WriteJRS("tuesday", 10);
    WriteJRS("wednesday", 10);
    WriteJRS("thursday", 10);
    WriteJRS("friday", 10);
    cout << endl;

    for(int i = bottom_h; i < top_h; ++i)
    {
        WriteJRI(i, 2);
        for(int j = 0; j < 5; ++j)
        {
            WriteJRI(table[j][i].listteachers.size(), 10);
        }
        cout << endl;
    }

    cout << "number of replacements needed to avoid conflicts:" << endl;
    cout << conflicts << endl;
}

int main()
{
    Slot emptySlot;
    TableSlots table(5, vector<Slot>(24, emptySlot)); 
    
    int bottom_h = 24;
    int top_h = -1;

    string subject, teacher, weekday;
    int h1, h2;
    while(cin >> subject >> teacher >> weekday >> h1 >> h2)
    {
        if (h1 < bottom_h) bottom_h = h1;
        if (h2 > top_h) top_h = h2;
        
        int day = Weekdayc(weekday);
        for(int i = h1; i < h2; ++i)
            Slots(table[day][i], subject, teacher);
    }

    int conflicts = 0;
    for(int i = bottom_h; i < top_h; ++i)
    {
        for(int j = 0; j < 5; ++j)
            ConflictsCalculator(table[j][i].listteachers, conflicts);
    }

    Write(table, bottom_h, top_h, conflicts);
}