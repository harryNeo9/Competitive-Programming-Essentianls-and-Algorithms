
    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long int
    #define ld long double
    #define p 1000000007
    #define inf 1e18
    #define endl "\n"
    #define pb emplace_back
    #define vi vector<int>
    #define vll vector<ll>
    #define vs vector<string>
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define ump unordered_map
    #define mp map
    #define pq_max priority_queue<ll>
    #define pq_min priority_queue<ll, vll, greater<ll>>
    #define ff first
    #define ss second
    #define mid(l, r) (l + (r - l) / 2)
    #define loop(i, a, b) for (int i = (a); i <= (b); i++)
    #define looprev(i, a, b) for (int i = (a); i >= (b); i--)

    int charToDigit(char ch){
        return ch - '0';
    }

    char digitToChar(int digit){
        return digit + '0';
    }

    string bigAddition(string n1, string n2){
        string result = "";

        //1. Make sure n2 is greater than n1
        if(n1.length() > n2.length())
            swap(n1, n2);
        
        //2. Reverse both numbers(Strings)
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());

        //3. Add digits upto n1.lenght() ->smaller number
        int carry = 0;

        for(int i=0; i<n1.length(); i++){
            int d1 = charToDigit(n1[i]);
            int d2 = charToDigit(n2[i]);
            int sum = d1 + d2 + carry;
            int output_digit = sum % 10;
            carry = sum / 10;

            result.push_back(digitToChar(output_digit));
        }

        //4. handle left out digits of n2 and carry
        for(int i=n1.length(); i<n2.length(); i++){
            int d2 = charToDigit(n2[i]);
            int sum = d2 + carry;
            int output_digit = sum % 10;
            carry = sum / 10;

            result.push_back(digitToChar(output_digit));
        }

        //5. If carry is generated
        if(carry)
            result.push_back('1');
        
        //6. Reverse to get finial result
        reverse(result.begin(), result.end());

        //7. Return the result
        return result;
    }

    int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string s1, s2;
        cin>>s1>>s2;
        // string s1 = "123478";
        // string s2 = "3444";
        string res = bigAddition(s1, s2);
        cout<<res<<"\n";


        return 0;
    }

 