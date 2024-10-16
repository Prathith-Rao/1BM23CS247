int majorityElement(int* nums, int numsSize) {
    int ele=0;
    int c=0;
    for(int i=0;i<numsSize;i++)
    {
        if(c==0)
        {
            ele=nums[i];
            c++;
        }
        else if(nums[i]==ele)
            c++;
        else
            c--;
    }
    return ele;
}
