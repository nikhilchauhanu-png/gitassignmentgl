class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> s1Count(26, 0), window(26, 0);

        // Count frequency of s1
        for (char c : s1)
            s1Count[c - 'a']++;

        int k = s1.size();

        for (int i = 0; i < s2.size(); i++) {

            // Add current character
            window[s2[i] - 'a']++;

            // Remove character outside the window
            if (i >= k)
                window[s2[i - k] - 'a']--;

            // Compare frequency arrays
            if (window == s1Count)
                return true;
        }

        return false;
    }
};
