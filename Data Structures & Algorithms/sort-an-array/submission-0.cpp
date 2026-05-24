class Solution {
private:
    void mergeSort(vector<int>&nums,int left,int right,vector<int>& temp){
        if(left>=right) return; //base case
        
        int mid = left + (right-left)/2;
        //divide
        mergeSort(nums,left,mid,temp); //sort the left
        mergeSort(nums,mid+1,right,temp); //right wala

        //conquer
        merge(nums,left,mid,right,temp);

    }

    void merge(vector<int>& nums,int left,int mid, int right, vector<int>& temp){
        //copy current selction into our temporaroy scratchpad array
        for(int i =left;i<=right; ++i){
            temp[i]=nums[i];
        }

        int p1=left;
        int p2=mid +1;
        int orig=left;

        //walk  through both subarrays and copy the smaller value back into nums
        while(p1 <= mid  && p2<=right){
            if(temp[p1] <=temp[p2]){
                nums[orig] = temp[p1];
                p1++;
            }
            else{
                nums[orig]=temp[p2];
                p2++;
            }
            orig++;
        }
        //if anything remaining in left half,cover them
        while(p1<=mid){
            nums[orig]=temp[p1];
            p1++;
            orig++;
        }

        //if some in right half they  are already in their correct order

    }

public:
    vector<int> sortArray(vector<int>& nums) {

        //allocate  a single 
        vector<int> temp(nums.size());

        mergeSort(nums,0,nums.size()-1,temp);

        return nums;
        
    }
};