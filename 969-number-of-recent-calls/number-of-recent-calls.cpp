class RecentCounter 
{
public:
    RecentCounter() 
    {
        counter = 0;
    }

    int ping(int t) 
    {
        counter = 0;
        calls.push(t);
        stack<int> tmp = calls;
        int start = t - 3000;
        bool inRange = true;
        while (inRange)
        {
            if (tmp.size() > 0)
            {
                if (tmp.top() >= start)
                {
                    counter++;
                    tmp.pop();
                }
                else
                    inRange = false;
            }
            else
                inRange = false;
        }
        return counter;
    }
private:
    int counter;
    stack<int> calls;
};
