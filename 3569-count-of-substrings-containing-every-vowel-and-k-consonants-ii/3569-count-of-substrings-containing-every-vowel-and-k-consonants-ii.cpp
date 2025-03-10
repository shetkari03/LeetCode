
class Solution {
public:
    const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    inline int getVowelIndex(const char c) {
        for (int i = 0; i < 5; i++) {
            if (c == vowels[i]) {
                return i;
            }
        }
        return 5;
    }
    static inline bool isValid(const int counts[], int k) {
        for (int i = 0; i < 5; i++) {
            if (counts[i] == 0) {
                return false;
            }
        }
        if (counts[5] != k) {
            return false;
        }
        return true;
    }
    long long countOfSubstrings(const std::string& word, int k) {
        long long result = 0;
        int counts[6] = {0}; 
        int left = 0, lastConsonantIndex = -1;
        for (int right = 0; right < word.size(); right++) {
            counts[getVowelIndex(word[right])]++;
            while (counts[5] > k) {
                int vowelIndex = getVowelIndex(word[left]);
                counts[vowelIndex]--;
                if (vowelIndex == 5) {
                    lastConsonantIndex = left; 
                }
                left++;
            }
            if (isValid(counts, k)) {
                while (isValid(counts, k)) {
                    counts[getVowelIndex(word[left])]--;
                    left++;
                }
                left--;
                counts[getVowelIndex(word[left])]++;
                result += (left - lastConsonantIndex);
            }
        }

        return result;
    }
};