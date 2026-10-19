class Solution {
public:

    bool checkAnagram(string a, string b){
        unordered_map<char,int> m1,m2;
        int x=a.size(),y=b.size();
        for(int i=0; i<x;i++){
         m1[a[i]]++;
        }

        for(int i=0; i<y;i++){
         m2[b[i]]++;
        }
      return m1==m2;
    }
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
     vector<vector<string>> ans;
     unordered_map<string,bool> reference;
    for(int i=0; i<arr.size(); i++){
        if(reference[arr[i]]==true){
            continue;
        }

       vector<string> storeResult;

       reference[arr[i]]=true;
       storeResult.push_back(arr[i]);
        for(int j=i+1; j<arr.size(); j++){
        //if(reference[arr[j]]!=true){
         if(checkAnagram(arr[i],arr[j])){
            reference[arr[j]]=true;
            storeResult.push_back(arr[j]);            
         //}
        }
        }
        ans.push_back(storeResult);
    }
        
   return ans;

    }
};
