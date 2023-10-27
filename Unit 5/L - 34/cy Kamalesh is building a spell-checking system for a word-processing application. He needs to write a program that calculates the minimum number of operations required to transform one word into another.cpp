




#include <iostream>
#include <string>
#include <vector>

class EditDistanceCalculator {
public:
    virtual int min(int x, int y, int z) = 0;
    virtual int calculateDistance(const std::string& s1, const std::string& s2) = 0;
    virtual ~EditDistanceCalculator() = default;
};

class MinEditDistanceCalculator : public EditDistanceCalculator {
public:
    int min(int x, int y, int z) override {
        if (x <= y && x <= z) return x;
        if (y <= x && y <= z) return y;
        return z;
    }

    int calculateDistance(const std::string& s1, const std::string& s2) override {
        int m = s1.length();
        int n = s2.length();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    MinEditDistanceCalculator calculator;
    int distance = calculator.calculateDistance(s1, s2);
    
    std::cout << "Edit distance between " << s1 << " and " << s2 << " is " << distance << std::endl;

    return 0;
}


