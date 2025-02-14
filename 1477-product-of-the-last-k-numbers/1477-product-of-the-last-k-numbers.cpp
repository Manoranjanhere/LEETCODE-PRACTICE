class ProductOfNumbers {
public:
    vector<int> store;
    int i;
    ProductOfNumbers() {
        i=0;
    }
    
    void add(int num) {
        store.push_back(num);
        i++;
    }
    
    int getProduct(int k) {
        long long p=1;
        int c=i;
        while(k)
        {
            int ele=store[i-1];
            p*=ele;
            k--;
            i--;
        }
        i=c;
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */