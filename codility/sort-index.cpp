#include<algorithm>
#include <vector>
#include<iostream>
    using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return (a.first > b.first);
}

vector<int> solution(vector<int>& A)
{
    vector<pair<int, int>> pairs;

    for (int i = 0; i < (int)A.size(); ++i)
        pairs.push_back({A[i], i});

    std::sort(pairs.begin(), pairs.end(), cmp);

    vector<int> result;
    for (auto p: pairs)
        result.push_back(p.second);

    return result;
}

int main()
{
    std::vector<int> A = {1,99,4,56,78};
    for (int i = 0; i < A.size(); ++i) {
        std::cout << A[i] << "-" << i << "\n";
    }

    std::vector<int> indi = solution(A);
    
    //std::sort(A.begin(),A.end(), greater<>());
    std::cout << std::endl;
    for (int i = 0; i < A.size(); ++i) {
        std::cout << A[indi[i]] << "-" << indi[i] << "\n";
    }

}