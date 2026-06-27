class Solution {
public:
    int maxDistance(string moves) {
        int x=0;
        int y=0;
        int wildcards=0;
        for(char ch:moves){
            if(ch=='U') y++;
            else if(ch=='R') x++;
            else if(ch=='D') y--;
            else if(ch=='L') x--;
            else  wildcards++;
        }
        return abs(x)+abs(y)+wildcards;
    }
};