//User function template for C++

class Solution{   
public:
    int FindSmallerElement(vector<vector<int>> &matrix,int assumedMedian){
        int noOfSmallerElements = 0;
        for(int i=0; i<matrix.size(); i++){
            int start = 0;
            int end = matrix[i].size() -1;
            while(start<=end){
                int mid = start +(end - start)/2;
                if(matrix[i][mid]<= assumedMedian){
                    start = mid +1;
                }
                else
                {
                    end = mid -1;
                }
            }
            noOfSmallerElements = noOfSmallerElements + start;
        }
        return noOfSmallerElements;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here       
        int N = R*C;
        int medianIndex = N/2;
        int start = 1;
        int end = 2000;
        while(start<=end){
            int assumedMedian = start + (end - start)/2;
            int lessarElements = FindSmallerElement(matrix,assumedMedian);
            if(lessarElements <= medianIndex){
                start = assumedMedian +1;
            }
            else
            {
                end = assumedMedian -1;
            }
        }
        return start;
    }
};