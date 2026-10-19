class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
     int n=arr.size();
    int i=0, j=0;
    while(j<n){
    if(arr[j]!=val){
        if(arr[i]==val){
            swap(arr[i],arr[j]);
        }
        j++;
        i++;
    }
    else{
        j++;

    }
    }
    return i;
    }
};