class Solution {
  public:
    int lastDigit(int n) {
        // Code here
        return n < 0 ? (n * -1) % 10 :
                       n % 10;
    }
};
