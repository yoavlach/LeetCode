class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> counter;
        if(s.size() != t.size())
            return false;
        for(char i : s)
        {
            if(counter.find(i) != counter.end())
                counter.find(i)->second++;
            else
                counter[i] = 1;
        }
        for(char i : t)
        {
            auto curr = counter.find(i);
            if(curr == counter.end() || curr->second == 0)
                return false;
            curr->second--;
        }
        for(auto i : counter)
        {
            if(i.second != 0)
                return false;
        }
        return true;
    }
};