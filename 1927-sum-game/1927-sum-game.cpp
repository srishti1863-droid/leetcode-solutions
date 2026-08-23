class Solution {
public:
    bool sumGame(string num) {
        int mid = num.size() / 2;

        int leftSum = 0, rightSum = 0;

        int leftQuestion = 0, rightQuestion = 0;

        for (int i = 0; i < num.size(); i++) {
            if (i < mid) {
                if (num[i] == '?')
                    leftQuestion++;
                else
                    leftSum += num[i] - '0';
            } else {
                if (num[i] == '?')
                    rightQuestion++;
                else
                    rightSum += num[i] - '0';
            }
        }

        return 2 * (leftSum - rightSum) !=
               9 * (rightQuestion - leftQuestion);
    }
};