class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<>> right;
    int l=0,r=0;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.empty()){
            right.push(num);
            r++;
        }
        else if(num<right.top()){
            left.push(num);
            l++;
        }
        else{
            right.push(num);
            r++;
        }
        if(l>r){
            int x=left.top();
            left.pop();
            right.push(x);
            l--,r++;
        }
        if(r-l>1){
            int x=right.top();
            right.pop();
            left.push(x);
            l++,r--;
        }
    }
    
    double findMedian() {
        if((l+r)%2==0){
            double x=left.top(),y=right.top();
            return (x+y)/2.0;
        }
        else{
            return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */