class Allocator {
public:
    vector<int> arr;
    unordered_map<int, int> mp;
    int n;
    Allocator(int n) {
        this->n=n;
        arr.resize(n);
    }
    
    int allocate(int size, int mID) {
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                int k=i, b=0;
                while(i<n and arr[i]==0){
                    i++, b++;
                    if(b==size) break;
                }
                if(b>=size){
                    for(int j=k; j<k+size; j++)
                        arr[j]=mID;
                    mp[mID]=k;
                    
                    return k;
                }
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int i=mp[mID], b=0;
        for(int i=0; i<n; i++){
            if(arr[i]==mID)
                b++, arr[i]=0;
        }
        mp.erase(mID);
        return b;
    }
};
