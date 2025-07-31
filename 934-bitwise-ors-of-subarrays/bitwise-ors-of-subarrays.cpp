class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> all;    //Stores all unique OR results.
        set<int> prev;             //Stores ORs for subarrays ending at previous index.

        for(int x:arr){
            set<int> cur;          //Stores ORs for subarrays ending at current index.
            cur.insert(x);         //New subarray: only arr[i].

            for(auto it:prev){
                cur.insert(it|x); //Extend each previous subarray to current position.
            }

            all.insert(cur.begin(),cur.end()); //Add all unique ORs for this step to global set.
            prev=move(cur);              //Set up for next iteration.
        }
        return all.size();
    }
};
