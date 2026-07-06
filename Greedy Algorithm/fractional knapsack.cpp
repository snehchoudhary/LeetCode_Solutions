#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    struct Item {
        long long value;
        long long weight;
    };

    // Custom Comparator
    static bool cmp(Item &a, Item &b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {

        int n = val.size();

        vector<Item> items;

        for (int i = 0; i < n; i++) {
            items.push_back({val[i], wt[i]});
        }

        sort(items.begin(), items.end(), cmp);

        double ans = 0.0;

        for (int i = 0; i < n; i++) {

            if (capacity >= items[i].weight) {
                // Take the whole item
                ans += items[i].value;
                capacity -= items[i].weight;
            }
            else {
                // Take only the required fraction
                ans += ((double)items[i].value / items[i].weight) * capacity;
                break;
            }
        }

        return ans;
    }
};