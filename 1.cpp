10. Regular Expression Matching

Approach : Recursion with Memoization

we have to check if str[1] == '*' means we can make the (a*) part empty or we can take multiple occurrences of the character before '*'.
if(str[1] == '*') then treat * and char before it as a single entity and check if the rest of the string matches.

if str[1] != '*' then we have to check if the current character matches with the pattern character or not.

and baaki solution dekhlo smjh ajayega
 


class Solution {
public:
    int dp[21][21];
    bool solve(int i, int j, string& s, string& p) {
        if (j == p.length()) {
            if (i == s.length())
                return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool f_c_m =
            (s.length() > i && (s[i] == p[j] || p[j] == '.')) ? true : false;

        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool take = f_c_m && solve(i + 1, j, s, p);
            bool notake = solve(i, j + 2, s, p);
            
            return dp[i][j] = take || notake;
        }

        return dp[i][j] = f_c_m && solve(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};


# Open a terminal and navigate to your project directory
cd "/C:/Users/8yi/Desktop/155 LeetCode"

# Initialize git if you haven't already
git init

# Add your file to the staging area
git add 1.cpp

# Commit your changes
git commit -m "Add solution for Regular Expression Matching"

# Add your GitHub repository as a remote (replace the URL with your repo's URL)
git remote add origin https://github.com/your-username/your-repo-name.git

# Push your code to GitHub
git push -u origin master