#include <iostream>

/*
                    Q. count inversions
                                algorithm used from merge sort

                explanation -  we will be given an array - arr[] = {5, 3, 2, 4, 1}
                                and we have to find pairs in which left element is greater than right elememnt
                                        i.e, a[i] > a[j]        where  i < j

                                    desired pairs are -  (5, 3)  (5, 2)  (5, 4)  (5, 1)
                                                         (3, 2)  (3, 1)
                                                         (2, 1)
                                                         (4, 1)
                                        desired o/p   -  8      count of pairs

            
            Brute force -  'i' at any index and 'j' will iterate through the array

        pseudo code
cnt = 0
for(i=0->n-1)
{
    for(j=i+1->n)
    {
        if(a[i] > a[j])
            cnt++;
    }
}
return cnt;

            TC - O(N^2)
            SC - O(1)


            Optimal sol -  lets take 2 arrays as examples   arr1[] = {2, 3, 5, 6}
                                                            arr2[] = {2, 2, 4, 4, 8}    they both are sorted

                            now we have to create pairs where left element is from arr1[] and right element is from arr2[]
                            left element should be greater than right element

                            methd 1)    we pick first element from arr1[] and iterate through arr2[]
                                        then we pick another elelemnt from arr1[] and iterate through arr2[]

                            method 2)   we pick first element from arr1[] and iterate through arr2[] -  (2, 2)  which is not
                                        the pair we required
                                        take 3 from arr1[], create (3, 2) which is desired pair. we also know that the both 
                                        of the entire arrays are sorted, so we can say that in arr1[] the elements in the right
                                        of the element '3' are greater than 3(elements are 5, 6), which means that they can give 
                                        us the desired o/p with 2
                                                    which are -     (3, 2),  (5, 2),  (6, 2)

                                        similarly if we take '5' and pair it with 2, 2, 4, 4    
                                        then 6 can also make pair with them

                                        in this similar concept we will do a dry run

            dry run -  given array -  arr[] = {5, 3, 2, 4, 1}   lets split it into 2                (as we have done in merge sort)

                                        {5, 3, 2}           {4, 1}              .. (b

                                    {5, 3}      {2}       {4}     {1}           .. (c

                                  {5}    {3}                                    .. (d

                       we can see that {5} is an array on its own, similarly {3} is also an array
                       let them pair-up     {3, 5}      and increase our counter to  +1
                       {5, 3} from  (c  will become  {3, 5}

                       lets pair {3, 5} with {2},       here 2 is smaller than 3 so they can form a pair, which also means all the 
                       elements in the right of the 3 can form pair with '2'        and increase our counter to +2, now it become -  +1 +2
                       {5, 3, 2} from  (b  will become {2, 3, 5}

                       lets also pair {4} with {1}      and increase our counter to  +1,  now it will become -  +1 +2 +1
                        {4, 1} from  (b  will become {1, 4}

                        now the step is to merge the sorted arrays from  (b  -  
                                            i.e,  {2, 3, 5}  and  {1, 4}            .. (e

                                from  (e,  lets pair {2, 3, 5} with {1, 4},     here 1 is smaller than 2 so they can form a pair, which
                                also means all the elements right of the 2 can form pair with '1'       so we increase our counter to +3
                                it becomes -  +1 +2 +1 +3
                                                                            array will be {1, ...}

                                now pair {2, 3, 5} with {4}     here 4 is greater than 2 and 3 
                                                so the array will become -  {1, 2, 3, ..}

                                now moving fwd we have 5    here 4 is smaller than 5 so it can become a pair
                                we increase our counter -  +1,      it becomes -  +1 +2 +1 +3 +1

                                                        array will be - {1, 2, 3, 4}
                                                        there is no elelemnts on the right of the 4 so we take 5 at the end
                                                        array will be -  {1, 2, 3, 4, 5}

                                                we will get our counter as -  +1 +2 +1 +3 +1
                                                                            = 8     whih is our desired o/p

        Actual code

int merge(vector<int> &arr, int low, int, mid, int high)
{
    vector<int> temp;
    int left = low;             // low to mid
    int right = mid + 1;        // mid+1 to high

    // storing elements in the temporary array in a sorted manner
    int cnt = 0;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid)                  //if there is still elements left then feed it to left
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mS(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if(low == high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mS(arr, low, mid);
    cnt += mS(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}


//void mergeSort(vector<int> &arr, int n)
//{
//    ms(arr, 0, n - 1);          // <-original starting and end position of the array
//}


int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n-1);
}

            TC - O(N logN)
            SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}