//source: https://codeforces.com/blog/entry/11080?#comment-722830
/*Here's a quick way using Policy-Based Data Structures in C++:
There exists something called as an Ordered Set, which lets you insert/remove elements in O(log n) time (and pretty much all other functions that std::set has to offer). It also gives 2 more features: find the Kth element and find the rank of the Xth element. The problem is that this doesn't allow duplicates :(

No Worries though! We will map duplicates with a separate index/priority, and define a new structure (call it Ordered Multiset)! I've attached my implementation below for reference.

Finally, every time you want to find the no of elements greater than say x, call the function upper_bound (No of elements less than or equal to x) and subtract this number from the size of your Ordered Multiset!

Note: PBDS use a lot of memory, so that is a constraint, I'd suggest using a Binary Search Tree or a Fenwick Tree.

Code*/

    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace std;
    using namespace __gnu_pbds;

    struct ordered_multiset { // multiset supporting duplicating values in set
        int len = 0;
        const int ADD = 1000010;
        const int MAXVAL = 1000000010;
        unordered_map<int, int> mp; // hash = 96814
        tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
    
        ordered_multiset() { len = 0; T.clear(), mp.clear(); }
    
        inline void insert(int x){
            len++, x += MAXVAL;
            int c = mp[x]++;
            T.insert((x * ADD) + c); }
    
        inline void erase(int x){
            x += MAXVAL;
            int c = mp[x];
            if(c) {
                c--, mp[x]--, len--;
                T.erase((x*ADD) + c); } }
    
        inline int kth(int k){        // 1-based index,  returns the
            if(k<1 || k>len) return -1;     // K'th element in the treap,
            auto it = T.find_by_order(--k); // -1 if none exists
            return ((*it)/ADD) - MAXVAL; } 
    
        inline int lower_bound(int x){      // Count of value <x in treap
            x += MAXVAL;
            int c = mp[x];
            return (T.order_of_key((x*ADD)+c)); }
    
        inline int upper_bound(int x){      // Count of value <=x in treap
            x += MAXVAL;
            int c = mp[x];
            return (T.order_of_key((x*ADD)+c)); }
    
        inline int size() { return len; }   // Number of elements in treap
    };
//Usage:
    int n; cin>>n;
    ordered_multiset s;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        s.insert(x);
        int ctr = s.size() - s.upper_bound(x);
        cout<<ctr<<" ";
    }
//Test Case: Input : 6 10 1 3 3 2
//Output : 0 1 1 1 3
/*
References
mochow13's GitHub

Time Complexity : O(log n) per insert/query*/

