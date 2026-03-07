class Solution {
public:
    string predictPartyVictory(string senate)
    {
        int radiantCantVote = 0, direCantVote = 0;
        int radiantCounter = 0, direCounter = 0;
        string winner = "";
        bool needToRemoveNextRadiant = false, needToRemoveNextDire = false;
        while (winner == "")
        {
            radiantCounter = 0;
            direCounter = 0;
            for (int i = 0; i < senate.length(); i++)
            {
                if (senate[i] == 'D')
                {
                    if(direCantVote >= 1)
                        direCantVote--;
                    if (needToRemoveNextDire)
                    {
                        senate.erase(senate.begin() + i);
                        i--;
                    }
                    else
                    {
                        needToRemoveNextRadiant = true;
                        radiantCantVote++;
                        direCounter++;
                    }
                    needToRemoveNextDire = direCantVote > 0;
                }
                else
                {
                    if(radiantCantVote >= 1)
                        radiantCantVote--;
                    if (needToRemoveNextRadiant)
                    {
                        senate.erase(senate.begin() + i);
                        i--;
                    }
                    else
                    {
                        needToRemoveNextDire = true;
                        direCantVote++;
                        radiantCounter++;
                    }
                    needToRemoveNextRadiant = radiantCantVote > 0;

                }
            }
            if (radiantCounter == 0)
                winner = "Dire";
            else if (direCounter == 0)
                winner = "Radiant";
        }
        return winner;
    }
};
