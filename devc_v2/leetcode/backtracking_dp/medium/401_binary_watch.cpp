/*

401. Binary Watch (Solution is not a backtrscking one)

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bit_count(h) + bit_count(m) == num) {
                    const auto hour = to_string(h);
                    const auto minute = m < 10 ? "0" + to_string(m) : to_string(m);
                    result.emplace_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }
    int bit_count(int bits) {
        int count = 0;
        for (; bits; bits &= bits - 1) {
            ++count;
        }
        return count;
    }
};
