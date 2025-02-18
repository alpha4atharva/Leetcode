class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq; // Min-heap
        unordered_set<long> seen; // To avoid duplicates

        pq.push(1);
        seen.insert(1);
        
        long ugly = 1; // Stores the nth ugly number

        for (int i = 0; i < n; i++) {
            ugly = pq.top();
            pq.pop();
            
            // Generate next ugly numbers
            if (seen.find(ugly * 2) == seen.end()) {
                pq.push(ugly * 2);
                seen.insert(ugly * 2);
            }
            if (seen.find(ugly * 3) == seen.end()) {
                pq.push(ugly * 3);
                seen.insert(ugly * 3);
            }
            if (seen.find(ugly * 5) == seen.end()) {
                pq.push(ugly * 5);
                seen.insert(ugly * 5);
            }
        }

        return ugly;
    }
};
