class Solution {
public:
    int gcd(int a, int b)
    {
        if(a % b == 0)
        {
            return b;
        }else{
            return gcd(b, a % b);
        }
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0 || z == x + y) return true;
        if(z > x + y) return false;
        if(x == 0) return z == y;
        if(y == 0) return z == x;
        if(x == y) return z == x;
        int y_in = (y > x)? y : x;
        int x_in = (y > x)? x : y;
        int r = y_in % x_in;
        if (r == 0)
        {
            return z % x_in == 0;
        }else{
            return z % gcd(r, x_in) == 0;
        }
    }
};