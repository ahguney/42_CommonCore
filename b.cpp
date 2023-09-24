#include <iostream>
#include <vector>

class Pmerge
{
  public:
  Pmerge()
  {
    _subarrsize = 2;
  }
  void insertionSortV(int left, int right);
  void mergeV(int left, int middle, int right);
  void mergeInsertionSortV(int left, int right);

  int _subarrsize;
  std::vector<int> _sortedVector;
};

void Pmerge::insertionSortV(int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = _sortedVector[i];
        int j = i - 1;

        while (j >= left && _sortedVector[j] > key) 
        {
            _sortedVector[j + 1] = _sortedVector[j]; 
            --j;
        }

        _sortedVector[j + 1] = key;
    }
}

void Pmerge::mergeV(int left, int middle, int right) 
{
    int n1 = middle - left + 1; 
    int n2 = right - middle;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = _sortedVector[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = _sortedVector[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (leftArray[i] <= rightArray[j]) 
        {
            _sortedVector[k] = leftArray[i];
            ++i;
        } 
        else 
        {
            _sortedVector[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) 
    {
        _sortedVector[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) 
    {
        _sortedVector[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void Pmerge::mergeInsertionSortV(int left, int right) 
{
    if (right - left + 1 <= _subarrsize)
        insertionSortV(left, right);
    else 
    {
        int middle = left + (right - left) / 2; 
        mergeInsertionSortV(left, middle); 
        mergeInsertionSortV(middle + 1, right);
        mergeV(left, middle, right); 
    }
}

int main() {
  Pmerge a;
  
  a._sortedVector.push_back(121);
  a._sortedVector.push_back(1);
  a._sortedVector.push_back(29);
  a._sortedVector.push_back(2);
  a.mergeInsertionSortV(0,a._sortedVector.size() - 1);

  for(size_t i = 0 ; i < a._sortedVector.size(); i++)
  {
    std::cout << a._sortedVector[i] << std::endl;
  }
  
}