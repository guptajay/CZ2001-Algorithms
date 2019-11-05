package project3B;

import java.util.Random;

public class Lab3 {
    static int comp = 0;// number of key comparisons for merge and insertion sort
  
    static int comparisons = 0;
    
    static int kc_min, kc_merge, s_min1, s_min2, s_merge, m_flag =0; 

    public static void main(String[] args)
    {
        double timeforsisone;
        double mainSmaxtime;
        int a[] = new int[1000];
        Random r = new Random();//generating random numbers
        for(int i=0; i<a.length; i++)
        {
            a[i] = r.nextInt(100);
        }        
        int c[] = copy(a);
        timeforsisone = sisone(a);
        for(int i =10; i<=a.length;)
        {
            int b[] = copy(c);           
            implementation(b,i);//varying the value of i in order to find s
            i+=1;  
            /*
            if(m_flag ==1)
            	break;
            	*/            // for array sizes the run time may be a lot so to break
        }
        s_min2--;
        System.out.println("----------------------------");   
        System.out.println("Values of S where key comparisons are minumum: " + s_min1); 
        System.out.println("Value of S where pure merge sort is more efficient: " + s_merge); 
        //System.out.println(kc_min); 
    }

    private static int[] copy(int arr[])
    {
        int a[] = new int[arr.length];
        for(int i =0 ;i<arr.length;i++)
        {
            a[i] = arr[i];//copying the array elements.
        }
        return a;
    }

    static double sisone(int arr[])
    {
        int n = 0;
        int m = arr.length-1;
        int c[] = copy(arr);
        double start = System.nanoTime();
        mergeSort(arr,n,m,1);//sorting using pure merge sort;
        double times1 = System.nanoTime() - start;
        System.out.println("----------------------------");
        System.out.println("The CPU Execution Time for pure MERGE SORT: " + times1 + " ns");
        double start2 = System.nanoTime();
        System.out.println("Key Comparisons: "+ comparisons);
        kc_merge = comparisons;
        kc_min = kc_merge + 100000;      //initializing kc_min and kc_merge
        System.out.println("----------------------------"); 
        comparisons= 0;
        int b[] = copy(c);   
        sort(b,n,m);//sorting using insertion sort
        double times12 = System.nanoTime() - start2;
        System.out.println("The CPU Execution Time for pure INSERTION SORT: " + times12 + " ns");
        System.out.println("Key Comparisons: "+ comp);
        System.out.println("----------------------------"); 
        System.out.println("");
        comp=0;
        return times1;
    }

    static double implementation(int arr[], int s)
    {
        int n = 0;
        int m = arr.length-1;
        double start = System.nanoTime();
        mergeSort(arr,n,m,s);//passing the array using in the merge sort where s denotes the threshold value.
        double times1 = System.nanoTime() - start;
        System.out.println("The CPU Execution Time for s = " + s + ": " + times1 + " ns");
        System.out.println("Key Comparisons: "+ (comparisons+comp));//total comparisons through merge sort and insertion sort
        if((comparisons+comp)< kc_min) {
        	kc_min = (comparisons+comp);
        	s_min1= s; 
        	s_min2= s;
        }
        if((comparisons+comp) == kc_min)
        	s_min2+=1;
        
        if((comparisons+comp) > kc_merge && m_flag ==0) {
        	s_merge = s;
        	m_flag = 1;
        }
        
        System.out.println("");
        comp=0;
        comparisons = 0;
        return times1;
    }

    static void mergeSort(int a[],int n ,int m, int s)
    {

        if(m-n>=s)//if the array size is above the threshold value
        {
            int mid = (n+m)/2;
            mergeSort(a,n,mid,s);
            mergeSort(a,mid+1,m,s);   
            merge(a,n,mid,m);
        }
        else // sorting through insertion sort
            sort(a,n,m);

    }

    static void merge(int arr[], int start, int mid, int end) 
    { 
        int first1 = start, last1 = mid; 
        int first2 = mid + 1, last2 = end; 
        int temp[] = new int[arr.length]; 
        int index = first1;
        while(first1 <= last1 && first2 <= last2) {
            if(arr[first1] < arr[first2]) {//comparing the first elements in the partitioned array
                temp[index] = arr[first1++];
                comparisons++;
            }
            else
                temp[index] = arr[first2++];
            index++;
            comparisons++;
        }

        while(first1 <= last1)//copying the elements left in the array
            temp[index++] = arr[first1++];

        while(first2 <= last2)
            temp[index++] = arr[first2++];

        for(index = start; index <= end; index++)
            arr[index] = temp[index];

    }

    static void sort(int a[],int s , int e) //insertion sort
    { 
        int n = e-s+1; 
        int arr[] = new int[e-s+1];
        for (int i = 1; i < n; ++i)
        {
            arr[i] = a[i];//copying the subarray to be sorted
        }        
        for (int i = 1; i < n; ++i) { 
            int key = arr[i]; 
            int j = i - 1;            
            while (j >= 0 && arr[j] > key) { //swaping till the smaller value for inserting the key
                arr[j + 1] = arr[j]; 
                j = j - 1; 
                comp++;
            }    
            arr[j + 1] = key; 
        } 
        for (int i = 1; i < n; ++i)
        {
            a[i] = arr[i];
        }
    } 

}