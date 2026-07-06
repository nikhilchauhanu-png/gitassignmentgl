class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> pCount(26, 0), sCount(26, 0);

        // Frequency of characters in p
        for (char c : p)
            pCount[c - 'a']++;

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {
            // Add current character to window
            sCount[s[i] - 'a']++;

            // Remove character that goes out of window
            if (i >= k)
                sCount[s[i - k] - 'a']--;

            // Compare frequencies when window size == k
            if (sCount == pCount)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};
