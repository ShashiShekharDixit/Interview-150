class Solution {
public:
    int nextNumber(int n) {
        int newNumber = 0;
        while (n != 0) {
            int digit = n % 10;
            n = n / 10;
            newNumber += digit * digit;
        }
        return newNumber;
    }
    bool isHappy(int n) {
        if(n==1)return true;
        int slowPointer = n;
        int fastPointer = nextNumber(n);
        while (slowPointer != fastPointer) 
        {
            if (slowPointer == 1 || fastPointer==1)
            {
                return true;
            }
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
        }
        return false;
    }
};