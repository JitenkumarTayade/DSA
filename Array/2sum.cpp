//Brutforce - o(n^2) , o(1)
  vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return{i,j};
                }
            }
        }

        
        
        return {-1,-1};
        
    }


//optimized   -o(nlogn) , o(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});     //storing values with its first original indices(before sorting)
        }  
        
        sort(v.begin(),v.end());   //only elemts will sorted not indices(indices for indiviual ele reamins same)
        
        //two pointer approach
        int i=0;
        int j=n-1;
        int ans1=0;int ans2=0;    //for answer returning indices
        while(i<j){
           if(v[i].first+v[j].first==target)     //fiest stores the element and second stores indices
           {
               ans1=v[i].second;
               ans2=v[j].second;
               break;                //as we want eaxtly one solution
           }
            else if(v[i].first+v[j].first<target){
                i++;
            }
            else{
                j--;
            }
           
        }        
        
         return {ans1,ans2};
        
    }
