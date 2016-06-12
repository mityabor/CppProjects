#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        vector<vector<std::pair<long long, long long> > > preprocessed = preprocess(matrix);

        std::cout << "Prep" << std::endl;
        long long  maxSquare = 0;
        for (int i = 0; i < preprocessed.size(); i++)
        {
            for (int j = 0; j < preprocessed[i].size(); j++)
            {
                std::cout<< "(" << preprocessed[i][j].first<<", " << preprocessed[i][j].second<< ")  ";
                long long min = preprocessed[i][j].first > preprocessed[i][j].second ? preprocessed[i][j].second : preprocessed[i][j].first;
                if (min * min>  maxSquare)
                {
                    maxSquare = preprocessed[i][j].first * preprocessed[i][j].second;
                }
            }
            std::cout << std::endl;
        }
        std::cout <<"Return";
        return maxSquare;

     }

private:
    vector<vector<std::pair<long long, long long> > > preprocess(vector<vector<char>>& matrix) {
        vector<vector<std::pair<long long, long long> > > result;
        for (int i = 0; i < matrix.size(); i++)
        {
            std::vector<pair<long long, long long> > row;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                row.push_back(pair<long long, long long>(0, 0));
            }
            result.push_back(row);
        }

        std::cout << "Prep size = " << result.size()<<" " << result[0].size()<< std::endl;

        for (int i = matrix.size() - 1; i >=0; i--)
        {
            for (int j = matrix[i].size(); j>=0; j--)
            {
                if(matrix[i][j] > 0)
                {
                    if(i < matrix.size() - 1)
                    {
                        result[i][j].first = result[i + 1][j].first + 1;
                    }
                    else
                    {
                        result[i][j].first = (long long)matrix[i][j];
                    }

                    if(j < matrix.size() - 1)
                    {
                        result[i][j].second = result[i][j + 1].second + 1;
                    }
                    else
                    {
                        result[i][j].second = (long long)matrix[i][j];
                    }
                }
            }
        }

        return result;
    }

};

int main(int argc, char *argv[])
{

    vector<vector<char> > matrix;
    matrix.push_back({1, 0, 1, 0, 0});
    matrix.push_back({1, 0, 1, 1, 1});
    matrix.push_back({1, 1, 1, 1, 1});
    matrix.push_back({1, 0, 0, 1, 0});
    std::cout << matrix.size();
    std::cout << matrix[0].size();
    Solution sol;
    std::cout << sol.maximalSquare(matrix);

    return 0;
}
