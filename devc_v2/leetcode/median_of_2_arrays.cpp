#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int nums1_size = (int)nums1.size();
        int nums2_size = (int)nums2.size();
        
        if(nums1_size == 0){
        	
            if(nums2_size%2==0){
                return nums2[nums2_size/2] + nums2[nums2_size/2 + 1];
            }
            else{
                return nums2[nums2_size/2];
            }
        }
        else if (nums2_size == 0)
            {
            	
            if(nums1_size%2==0){
            	
                return nums1[nums1_size/2] + nums1[nums1_size/2 + 1];
            }
            else{
                return nums1[nums1_size/2];
            }    
        }
        
        int total_size =  nums1_size + nums2_size;
        vector<int> med_ind;
        vector<int> new_array;
        int med = total_size / 2;
        int end_counter = 0;
        if((total_size % 2)==0){
            med_ind.push_back(med);
            med_ind.push_back(med+1);
            end_counter = med+1;
        }
        else{
            med_ind.push_back(med);
            end_counter = med;
        }
        
        int i=0, j=0, k=0;
        
        
        while(k!=end_counter && i< nums1_size && j< nums2_size){
            if(nums1[i]<nums2[j]){
                new_array.push_back(nums1[i++]);
                // k++;
                
            }
            else{
                new_array.push_back(nums2[j++]);
                // k++;
                
            }
            
            while((int)i<nums1_size && i<end_counter){
                new_array.push_back(nums1[i++]);
                // k++;
            }
            while((int)j<nums2_size && j<end_counter){
                new_array.push_back(nums2[j++]);
                // k++;
            }
        }
        
        
        if((int)med_ind.size()==1){
        	
            return new_array[end_counter];
        }
        
        return new_array[end_counter]+new_array[end_counter+1];
    }
};

int main()
{
	Solution s;
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(2);
	vector<int> num2;
	num2.push_back(3);
	num2.push_back(4);
	cout<<s.findMedianSortedArrays(num1, num2);
	}
