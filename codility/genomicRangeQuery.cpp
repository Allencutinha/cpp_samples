/*
A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
Write a function:

vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P and Q is an integer within the range [0..N - 1];
P[K] ≤ Q[K], where 0 ≤ K < M;
string S consists only of upper-case English letters A, C, G, T
*/

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
// write your code in Java SE 8
        int N = S.size();
        int M = P.size();
        std::vector<int> result(M);
        // store the position of A in the String S
        std::vector<int> posOfA(N+1);
        std::vector<int> posOfC(N+1);
        std::vector<int> posOfG(N+1);
        std::vector<int> posOfT(N+1);
        
        for (int i = 0; i < N; i++) {
            // when A appears, assign 1 to the value of posOfA with the same index.
            if (S[i] == 'A')
                posOfA[i+1] = 1;
            if (S[i] == 'C')
                posOfC[i+1] = 1;
            if (S[i] == 'G')
                posOfG[i+1] = 1;
            if (S[i] == 'T')
                posOfT[i+1] = 1;
        }
        for (int i = 1; i <= N; i++) {
            // prefix sum of the array
            posOfA[i] += posOfA[i-1];
            posOfC[i] += posOfC[i-1];
            posOfG[i] += posOfG[i-1];
            posOfT[i] += posOfT[i-1];
        }
        for (int i = 0; i < M; i++) {
            // calculate the sum between P[i] and Q[i] in O(1) time complexity
            // if the value is not zero, then A has appeared in the slice.
            if ((posOfA[Q[i]+1] - posOfA[P[i]]) != 0)
                result[i] = 1;
            else if ((posOfC[Q[i]+1] - posOfC[P[i]]) != 0)
                result[i] = 2;
            else if ((posOfG[Q[i]+1] - posOfG[P[i]]) != 0)
                result[i] = 3;
            else if ((posOfT[Q[i]+1] - posOfT[P[i]]) != 0)
                result[i] = 4;
        }
        return result;
    }