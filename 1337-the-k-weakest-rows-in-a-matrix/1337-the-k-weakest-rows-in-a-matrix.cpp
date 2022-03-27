class Solution {
    int binSearch(vector<int>v)
    {
        if(!v[0])
            return 0;
        if(v[v.size()-1])
            return v.size();
        int l=0,h=v.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(v[l]==v[mid] && v[mid]==1)
            {
                l=mid+1;
                if(!v[l])
                    break;
            }
            else if(v[mid]<v[l])
                h=mid;
        }
        return l;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>>fauji;
        int sizeN=mat.size();
        int sizeM=mat[0].size();
        int counter=0;
        for(int i=0;i<sizeN;i++)
        {
            fauji.insert({binSearch(mat[i]), i});
        }
        set<pair<int, int>>::iterator it;
        vector<int> res(k);
        counter=0;
        for(it=fauji.begin(); it!=fauji.end() && k>0; it++, k--)
        {
            res[counter++]=it->second;
        }
        return res;
    }
};