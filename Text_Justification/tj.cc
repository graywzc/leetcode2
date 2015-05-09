// this doesn't pass because I get rid of empty word
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        if(maxWidth==0)
            return vector<string>(1,"");
        vector<string> res;
        int i = 0;
        while(i<words.size())
        {
            if(words[i].empty())
            {
                i++;
                continue;
            }
            else
            {
                string line;
                int count = words[i].size();
                vector<int> idx(1,i);
                assert(count<=maxWidth);
                line+=words[idx[0]]; 
                int j = i+1;
                while(j<words.size())
                {
                    if(!words[j].empty()) 
                    {
                        if((count+1+words[j].size())>maxWidth)
                            break;
                        else
                        {
                            idx.push_back(j);
                            count += 1+words[j].size();
                        }
                    }
                        
                    j++; 
                }
                if(j == words.size())
                {
                    for(int k = 1; k < idx.size(); k++)
                    {
                        line+=' '; 
                        line+=words[k];
                    }
                    while(line.size()<maxWidth)
                    {
                        line+=' '; 
                    }
                }
                else if(idx.size()!=1)
                {
                    int space = maxWidth - count; 
                    int ns = idx.size()-1;
                    int space_between = space/ns;
                    int residue = space%ns;
                    int k = 1;
                    while(k<=residue)
                    {
                        line+=string(space_between+1,' ');
                        line+=words[idx[k]];
                        k++; 
                    }
                    while(k<=ns)
                    {
                        line+=string(space_between,' ');
                        line+=words[idx[k]];
                        k++;  
                    }
                }
                res.push_back(line);
                i = j;
            }
        }
        return res;
    }
};
