class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> count(26, 0);

        // Count characters available in magazine
        for (char c : magazine) {
            count[c - 'a']++;
        }

        // Use characters for ransomNote
        for (char c : ransomNote) {
            count[c - 'a']--;

            // Not enough characters available
            if (count[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};

