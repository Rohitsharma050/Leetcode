class Solution {
public:
    char nextChar(char ch, int steps) {
        return (ch - 'a' + steps) % 26 + 'a';
    }

    char kthCharacter(int k) {
        int depth = 0;
        int size = 1;

        // Find the depth (or number of operations) such that size >= k
        while (size < k) {
            size *= 2;
            depth++;
        }

        int index = k - 1;
        char ch = 'a';
        while (depth > 0) {
            int half = 1 << (depth - 1);
            if (index >= half) {
                index -= half;
                ch = nextChar(ch, 1); // move to next character in alphabet
            }
            depth--;
        }
        return ch;
    }
};

