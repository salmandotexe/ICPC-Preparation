int n;
cin >> n;
vll v(n);
for(int i=0;i<n;i++) cin >> v[i];

vll pref(n+2);
for(int i=1;i<=n;i++){
    pref[i]+=pref[i-1]+v[i-1];
}
ll res=0;
map<ll,int> m;

//for any general k:
int k=0;

for(int i=1;i<=n;i++){
    m[k + pref[i-1]]++;
    res+=m[pref[i]];
}

cout << res <<"\n";   //res is the number of subarrays with sum K.
//It follows from this:
/*
    Sum = pref[r] - pref[l-1] = k
    
    => pref[r] = k + pref[i-1].
       increment frequency of k + pref[i-1] for all i in 1<=i<=n. Does not work if you increment pref[i].
       
       for(int i=1;i<=n;i++) m[ k + pref[i-1] ] ++;
       
       now count for all endpoints:
       ll res=0;
       
       for(int i=1;i<=n;i++) res+=m[pref[i]];
*/
