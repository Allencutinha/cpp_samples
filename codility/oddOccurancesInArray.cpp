int solution(vector<int>& A)
{
    // Implement your solution here
    int odd = 0;
    if (1 == A.size()) {
        return A[0];
    }
    for (const auto elem: A) {
        odd = odd ^ elem;
    }
    return odd;
}
