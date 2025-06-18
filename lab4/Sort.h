#include <cstdarg>

class Sort
{ 
    int* v;
    int count;
    int partitie(int high, int low);
    void quicksortcorect(int low, int high);
    public:
        Sort(int count, int min, int max);
        Sort(std::initializer_list<int>);
        Sort(const int* vec2, int countv2);
        Sort(int count, ...);
        Sort(const char* str);
        void InsertSort(bool ascendent);
        void QuickSort(bool ascendent);
        void BubbleSort(bool ascendent);
        void Print();
        int  GetElementsCount();
        int  GetElementFromIndex(int index);
};

