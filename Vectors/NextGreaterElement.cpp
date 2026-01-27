#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
     {
        int n = letters.size();
        int i =0;
        int j = n-1;
        char ans = letters[0];
        while (i<=j)
        {
         int mid = i+(j-i)/2;
         
         if (letters[mid]>target)
         {
            ans =  letters[mid];
            j = mid - 1;
         }
         else 
         {
            i = mid  + 1;
         }
        }
     
       return ans;
     }
};
int main()
{
    Solution obj;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    char result = obj.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is '" << result << "'" << endl;
    return 0;
}