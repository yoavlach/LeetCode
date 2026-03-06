class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> remaining;
        vector<int> res;
        for (auto i : asteroids)
        {
            if (remaining.size() > 0)
            {
                if (remaining.top() > 0)
                {
                    if (i > 0)
                        remaining.push(i);
                    else
                    {
                        while (remaining.size() > 0)
                        {
                            if (remaining.top() > 0)
                            {
                                if (abs(i) > remaining.top())
                                    remaining.pop();
                                else
                                    break;
                            }
                            else
                            {
                                remaining.push(i);
                                break;
                            }
                        }
                        if (remaining.size() > 0)
                        {
                            if (remaining.top() == i * (-1))
                                remaining.pop();
                        }
                        else
                            remaining.push(i);
                    }
                }
                else
                    remaining.push(i);
            }
            else
                remaining.push(i);
        }
        while (remaining.size() > 0)
        {
            res.insert(res.begin(), remaining.top());
            remaining.pop();
        }
        return res;
    }
};
