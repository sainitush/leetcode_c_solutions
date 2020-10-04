#define SIZE 100000

typedef struct node_
{
    int idx;
    int val;
} node_t;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{ 
    node_t hash[SIZE] = {0,};

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int j = search(hash, complement);

        if (j)
        {
            int *ret = (int *)malloc(sizeof(int)*2);
            ret[0] = i;
            ret[1] = j-1;

            *returnSize = 2;
            return ret;
        }

        insert(hash, i+1, nums[i]);
    }

    *returnSize = 0;
    return NULL;
}

void insert(node_t *hash, int idx, int val)
{
    int tmp = val % SIZE;
    int key = (tmp < 0)? tmp+SIZE : tmp;

    while (1)
    {
        if (hash[key].idx == 0)
        {
            hash[key].idx = idx;
            hash[key].val = val;
            return;
        }
        key = (key+1)%SIZE;
    }
}

int search(node_t *hash, int val)
{
    int tmp = val % SIZE;
    int key = (tmp < 0)? tmp+SIZE : tmp;

    while (1)
    {
        if (hash[key].idx == 0)
        {
            return 0;
        }
        if (hash[key].val == val)
        {
            return hash[key].idx;
        }
        key = (key+1)%SIZE;
    }
}
