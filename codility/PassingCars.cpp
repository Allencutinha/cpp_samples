/*

*/

int solution(vector<int> &A) {
    // Implement your solution here
    unsigned int count = 0;
    int result = 0;
    for(int e:A){
        if(0 == e){count++;}
        if(1 == e && 0!=count){result+=count;}
        if(1000000000 < result){return -1;}
    }
    return result;
}