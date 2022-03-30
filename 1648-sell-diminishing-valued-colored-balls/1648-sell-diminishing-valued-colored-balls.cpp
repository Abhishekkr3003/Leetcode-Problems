/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

typedef long long ll;

class Solution {
    ll sumOfNterms(ll n) {
        return (n * (n + 1)) / 2;
    }
public:
    int maxProfit(vector<int>& inventory, int orders) {
        inventory.push_back(0);
        sort(inventory.begin(), inventory.end());
        ll quntity = 1, i = inventory.size() - 1;
        ll res = 0;
        int mod = 1e9 + 7;
        while (orders) {
            while (inventory[i] == inventory[i - 1]) {
                quntity++;
                i--;
                inventory.pop_back();
            }
            int n = inventory.size();
            int size = quntity * (inventory[n - 1] - inventory[n - 2]);
            // cout<<size<<endl;
            if (orders < size) {
                ll div = orders / quntity;
                ll rem = orders % quntity;
                res = (res + quntity * (sumOfNterms(inventory[n - 1]) - sumOfNterms(inventory[n - 1] - div))) % mod;
                res = (res + rem * (inventory[n - 1] - div)) % mod;
                orders = 0;
            }
            else {
                res = (res + quntity * (sumOfNterms(inventory[n - 1]) - sumOfNterms(inventory[n - 2]))) % mod;
                orders -= size;
            }
            inventory.back()=inventory[n-2];
            // cout<<"res "<<res<<endl;
        }
        return res;

    }
};