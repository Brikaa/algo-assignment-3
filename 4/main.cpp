#include <iostream>
#include <string>

std::string find_longest_palindrome(std::string str)
{
    int size = str.size();
    if (size == 1)
    {
        return str;
    }
    bool **dp = new bool *[3];

    // Allocation
    for (int i = 0; i < 3; ++i)
    {
        dp[i] = new bool[size];
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
            // The substring is a palindrome if the characters on the borders of the window are equal
            // and the inner word is a palindrome
            dp[w % 3][i] = str[i] == str[i + w] && dp[(w + 1) % 3][i + 1];
            found = found || dp[w % 3][i];
        }
        successive_fails = found ? 0 : successive_fails + 1;
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
    int w = successful_window - 1;
    for (int i = 0; i < size; ++i)
    {
        if (dp[w % 3][i])
        {
            result = str.substr(i, successful_window);
            break;
        }
    }
    if (result == "")
    {
        result = str[0];
    }

    // De-allocation
    for (int i = 0; i < 3; ++i)
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
