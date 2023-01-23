int solution(vector<int> &A) {
    // Implement your solution here
    unsigned long long int n = A.size()+1;
    unsigned long long int esum = (n * (n+1))/2;
    unsigned long long int sum = 0;
    for(const auto& e:A){
        sum+=e;
    }
    return (esum-sum);
}