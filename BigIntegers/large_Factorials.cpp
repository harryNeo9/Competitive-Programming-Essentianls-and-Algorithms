
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

    void  bigIntegerMultiplicaion(vector<int>& a, int num, int& size){
        int carry = 0;

        for(int i=0; i<size; i++){
            int product = a[i] * num + carry;
            a[i] = product % 10;
            carry = product / 10;
        }

        while(carry){
            a[size] = carry % 10;
            carry = carry/10;
            size += 1;
        }
    }

    void factorial(int n){
        //set size of factorial array as 1000
        //size can be inferred from problem constraints
        vector<int> a(1000, 0);

        // Initialise 1! as 1
        a[0] = 1;

        //keeps track of the no of digits of factorial computed
        int size_of_fac = 1;

        for(int i=2; i<=n; i++){
            bigIntegerMultiplicaion(a, i, size_of_fac);
        }

        //print the output in the reverse order
        for(int i=size_of_fac-1; i>=0; i--){
            cout<<a[i];
        }
        cout<<endl;
    }

    int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

       factorial(5);

        return 0;
    }

    /*
    2
    5
    1 3 5 7 9
    6
    16 11 34 23 12  45
    */