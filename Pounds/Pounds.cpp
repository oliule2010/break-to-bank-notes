/*
Return the number of notes for one sum
307 = 6* £50 + 1* £5 + 1* £2
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> notes{ 1, 2, 5, 10, 20, 50 };
unordered_map<int, int> money(int input) {
    unordered_map<int, int> output;
    for (int i = notes.size()-1; i >= 0; i--) {
        if (notes[i] <= input) {
            int times = 0;
            int number = 0;
            while (notes[i] * (times+1) <= input) {
                number = notes[i] * times;
                times++;
            }
            output[notes[i]] = times;
            input -= notes[i] * times;
            times = 0;
            number = 0;
        }
    }
    return output;
}
int main()
{
    unordered_map<int, int> input = money(307);
    for (auto it = input.begin(); it != input.end(); ++it)
        cout << " " << it->first << ":" << it->second;
    return 0;
}