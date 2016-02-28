int binary_search(vector<int> A, int low, int high, int key){

        while (low <= high) {
              int mid = low + (high-low)/2;
              if (A[mid] == key) {
                 return mid;
              }
              if (key > A[mid]) {
                 low = mid + 1;
              }
              if (key < A[mid]) {
                 high = mid - 1;
              }
        }
         
        return -1;
    }



    vector<int> searchRange(vector<int>& nums, int target) {
        
/*
 *   O(log n) solution must be something like binary search.
 *
 *   So, we can use the binary search to find the one postion - `pos`
 *   
 *   then, we can keep using the binary search find the target in A[0..pos-1] and A[pos+1..n]
 *
 */
    int n = nums.size();
 
     int pos = binary_search(nums, 0, n-1, target);

    vector<int> v;
    int low = -1, high = -1;
    if (pos >= 0){
        low = high = pos;
        int l = low;
        do {
            low = l;
            l = binary_search(nums, 0, low - 1, target);
        }while (l >= 0);

        int h = high;
        do {
            high = h;
            h = binary_search(nums, high + 1, n-1, target);
        }while (h >= 0);
    }

    v.push_back(low);
    v.push_back(high);
    return v;
        
 
 
        
    }
