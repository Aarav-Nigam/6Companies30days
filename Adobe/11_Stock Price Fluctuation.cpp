/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/stock-price-fluctuation/
*/
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
class StockPrice {
public:
   map<int, int> m;
multiset<int> prices;
void update(int timestamp, int price) {
    auto it = m.find(timestamp);
    if (it != end(m))
        prices.erase(prices.find(it->second));
    prices.insert(price);
    m[timestamp] = price;
}
int current() { return rbegin(m)->second; }
int maximum() { return *rbegin(prices); }
int minimum() { return *begin(prices); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */