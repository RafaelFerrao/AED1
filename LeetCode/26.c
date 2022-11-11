int removeDuplicates(int* nums, int numsSize){
    int lastIndex = 1;
    
    for(int i = 1; i < numsSize; i++){

        if(nums[lastIndex-1] < nums[i]){
            nums[lastIndex] = nums[i];
            lastIndex++;
        }

    }
    return lastIndex;
}