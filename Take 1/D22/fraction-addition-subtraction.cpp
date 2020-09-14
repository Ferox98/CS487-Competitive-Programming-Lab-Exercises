class Solution {
public:
    int toInt(string str) {
        stringstream ss(str);
        int val;
        ss >> val;
        return val;
    }
    
    int gcd(int a, int b) {
	    if (a == 0)
		    return b;
	    return gcd(b % a, a);
    }
 
    int lcm(int a, int b)
    {
        return (a * b) / gcd(a, b);
    }

    
    string fractionAddition(string expression) {
        int num, denum, idx = 0; // define numerator, denumerator and string index
        int res_num = 0, res_denum = 1; // result numerators and denominators
        char op; // operation to be performed
        while(idx < expression.size()) {
            int division_idx = expression.find('/', idx);
            num = toInt(expression.substr(idx, division_idx));
            string str_denum = "";
            for(idx = division_idx + 1; idx < expression.size(); idx++) {
                if (expression[idx] == '+' || expression[idx] == '-') break;
                str_denum += expression[idx];
            }
            denum = toInt(str_denum);
            // find the lcm of the denominators
            int new_denum = lcm(denum, res_denum);
            res_num = (new_denum / denum) * num + (new_denum / res_denum) * res_num;
            res_denum = new_denum;
            // divide both resulting numerators and denumerators by their gcds
            int gcd_fraction = gcd(res_num, res_denum);
            res_num /= gcd_fraction, res_denum /= gcd_fraction;
        }
        if ((res_num < 0 && res_denum < 0) || (res_num >= 0 && res_denum > 0))
            return to_string(res_num) + "/" + to_string(res_denum);
        return "-" + to_string(abs(res_num)) + "/" + to_string(abs(res_denum));
    }
};