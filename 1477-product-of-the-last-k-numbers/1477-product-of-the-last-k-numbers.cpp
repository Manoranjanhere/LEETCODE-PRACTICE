class ProductOfNumbers {
public:
    vector<int> store;
    int s=0;
    ProductOfNumbers() {
       store ={1};
       s=0;
    }
    
    void add(int num) {
        
        if(num==0)
        {
            store={1};
            s=0;
        }
        else
        {
            store.push_back(store.back()*num);
            s++;
        }
    }
    
    int getProduct(int k) {
        if(k>s)return 0;
        return store[s]/store[s-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */