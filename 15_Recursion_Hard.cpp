#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void createPartition(string s, vector<vector<string>> &result, vector<string> curr, int idx)
{
    if (idx == s.size())
    {
        result.push_back(curr);
        return;
    }
    // starting index is idx
    // ending index is i

    // looping to all starting indexes
    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(idx, i, s))
        {
            string a = s.substr(idx, i - idx + 1);
            curr.push_back(a);
            createPartition(s, result, curr, i + 1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> curr;
    createPartition(s, result, curr, 0);
    return result;
}

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

// DFS function to search for the word
bool dfs(vector<vector<char>> &board, string &word, int i, int j, int idx)
{
    if (idx == word.size())
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';
    bool found = 0;
    for (int k = 0; k < 4; k++)
    {
        found = found || dfs(board, word, i + x[k], j + y[k], idx + 1);
    }

    // Restore the character (backtracking)
    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Start DFS if first letter matches
            if (dfs(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    // If no path found, return false
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word;
    cin >> word;
    bool ans = exist(board, word);
    cout << ans;
}