int solution(int X, int Y, int D)
{
    // Implement your solution here
    int add = ((Y - X) % D != 0) ? 1 : 0;
    return (Y - X) / D + add;
}