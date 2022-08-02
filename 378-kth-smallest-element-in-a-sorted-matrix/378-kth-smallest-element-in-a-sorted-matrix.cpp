class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>heap;
        int size=matrix.size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<size;j++){
                if(heap.size()==k){
                    if(matrix[i][j]>=heap.top())
                        size=j;
                    else{
                        heap.pop();
                        heap.push(matrix[i][j]);
                    }
                }
                else{
                    heap.push(matrix[i][j]);
                }
            }
            if(size==0) break;
        }
        return heap.top();
    }
};