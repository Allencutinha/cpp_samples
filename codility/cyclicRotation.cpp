// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int>& A, int K)
{
    // Implement your solution her
    int n = A.size();
    if (n == 0) {
        return A;
    }
    std::vector<int> B = A;
    if (0 == K % n) {
        return B;
    } else {
        K = K % n;
    }
    for (int i = 0; i < n; ++i) {
        B[(i + K) % n] = A[i];
    }
    return B;
}