/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()<3)  
            return points.size();

        int i = 0;
        int size = points.size();
        int mp = 2;
        while(i<size-1)
        {
            unordered_map<double, int> m; // slope->number of points
            int n_vertical = 0; // number of points on vertical line
            int j = i+1;  
            double xi = points[i].x;
            double yi = points[i].y;
            int n_nonvert = 0;
            int n_self = 1;
            while(j<size)
            {
                double xj = points[j].x; 
                double yj = points[j].y; 

                if(xj==xi && yj==yi)
                {
                    n_self++;     
                }
                else if(xj==xi)
                {
                    n_vertical++;    
                }
                else
                {
                    double slope = (yj-yi)/(xj-xi);
                    m[slope]++; 
                    if(m[slope]>n_nonvert)
                        n_nonvert = m[slope];
                }
                j++;  
            }
            mp = max(mp,max(n_vertical,n_nonvert)+n_self);
            i++; 
        }

        return mp;
        
    }
};
