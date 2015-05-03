class Solution {
public:
    int compareVersion(string version1, string version2) {

        int v1,p1=string::npos;
        if(version1.empty())
            v1 = 0;
        else
        {
            p1 = version1.find("."); 
            v1 = stoi(version1.substr(0,p1));
        }

        int v2,p2=string::npos;
        if(version2.empty())
            v2 = 0;
        else
        {
            p2 = version2.find(".");
            v2 = stoi(version2.substr(0,p2));
        }


        if(v1 < v2)
            return -1;
        else if(v1 > v2)
            return 1;
        else if(p1==string::npos && p2==string::npos)
            return 0;
        else
            return compareVersion((p1==string::npos)?string():version1.substr(p1+1), (p2==string::npos)?string():version2.substr(p2+1));

    }
};
