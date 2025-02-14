class ProductOfNumbers {
private:
    vector<int> prefix;
    int n=0;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            prefix=vector<int>();
            n=0;
            return;
        }
        if(n==0)    prefix.push_back(num);
        else prefix.push_back(num*prefix[n-1]);
        n++;
    }
    
    int getProduct(int k) {
        if(k>n) return 0;
        if(n==k)    return prefix[n-1];
        else return prefix[n-1]/prefix[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */