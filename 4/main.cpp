#include <iostream>
#include <string>

std::string find_longest_palindrome(std::string str)
{
    int size = str.size();
    bool **dp = new bool *[size];

    // Allocation
    for (int i = 0; i < size; ++i)
    {
        dp[i] = new bool[size];
        for (int j = 0; j < size; ++j)
        {
            dp[i][j] = false;
        }
    }

    // First window is always true (single characters are palindromes)
    for (int i = 0; i < size; ++i)
    {
        dp[0][i] = true;
    }
    // Second window is true for each two equal contigious characters
    for (int i = 0; i < size - 1; ++i)
    {
        dp[1][i] = str[i] == str[i + 1];
    }

    int successive_fails = 0;
    int window = 3;

    while (window <= size)
    {
        bool found = false;
        int w = window - 1;
        for (int i = 0; i < size - w; ++i)
        {
            // If the characters on the borders of the window are equal, check if the inner word is a palindrome
            if (str[i] == str[i + w])
            {
                dp[w][i] = dp[w - 2][i + 1];
                found = found || dp[w][i];
            }
        }
        if (found)
        {
            successive_fails = 0;
        }
        else
        {
            successive_fails++;
        }

        ++window;

        // Can't find a palindrome neither with an odd window nor with an even window
        if (successive_fails == 2)
        {
            break;
        }
    }

    --window;
    int successful_window = window - successive_fails;
    std::string result = "";
    // successful window == 1 means only the single characters are palindromes (no palindromic substrings are found)
    if (successful_window > 1)
    {
        int w = successful_window - 1;
        for (int i = 0; i < size; ++i)
        {
            if (dp[w][i])
            {
                result = str.substr(i, successful_window);
                break;
            }
        }
    }

    // De-allocation
    for (int i = 0; i < size; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main()
{
    std::cout << "Enter a string:\n";
    std::string str;
    std::getline(std::cin, str);
    std::string result = find_longest_palindrome(str);
    if (result == "")
    {
        std::cout << "No palindromes were found\n";
    }
    else
    {
        std::cout << "The longest palindrome is: " << result << '\n';
    }
    return 0;
}
