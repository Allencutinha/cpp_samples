int solution(std::vector<int>& A)
{
    unsigned int N = A.size();

    std::vector<int> track(N, 0);
    unsigned int n = 0 for (unsigned int i = 0; i < N; i++)
    {
        if (((unsigned int)A[i]) > N) {
            return 0;
        } else if (track[A[i] - 1]) {
            return 0;
        } else {
            n++;
            track[A[i] - 1] = 1;
        }
    }

    if (n != N) {
        return 0;
    }

    return 1;
}