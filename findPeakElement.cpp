int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        int mid = 0, v1, v2;

        while ( low < high ) {

              // Find the index of middle element
              mid = low + ( high - low ) / 2;

              // Compare middle element with its neighbours (if neighbours exist)
              if ( ( mid == 0 || nums[mid] > nums[mid-1] ) && 
                 ( mid == n - 1 ||  nums[mid] > nums[mid+1] )  ){
                 return mid;
              }

              // If middle element is not peak and its left neighbor is greater than it
              // then left half must have a peak element
              if (mid > 0 && nums[mid-1] > nums[mid]){
                 high = mid - 1;
              // If middle element is not peak and its right neighbor is greater than it
              // then right half must have a peak element
              }
              else{
                   low = mid + 1;
              }

         }

         return high; // return low is also accepted
        
    }
