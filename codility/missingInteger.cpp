/*
Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

int solution(vector<int> &A) {
    // Implement your solution here
    unsigned int N = A.size();
    long long int maxe = *std::max_element(A.begin(), A.end());
    if(maxe<1){return 1;}
    std::vector<long long int > flag(maxe,0);
    for(const auto & e:A){
        if(e>0){
            if(e<=maxe){
                flag[e-1] = 1;
            }
        }
    }
    for(long long int i = 0;i<maxe;++i){
        if(0 == flag[i]){return i+1;}
    }
    return maxe+1;
}