class TrieNode{
    public:
    unordered_set<string>names;
    TrieNode*children[27];
    TrieNode(){
        for(int i=0;i<27;i++) children[i]=NULL;
    }
};


class AutoCompleteSystem {
private:
    TrieNode*root=new TrieNode();
    /* unordered_*/map<string,int>freq;
public:
    static bool compare(const pair<string,int>&a,const pair<string,int>&b){
        if(a.second!=b.second){
            // if frequency of a is greater than b then return true
            return a.second>b.second;
        }
        else{
            // if frequency is same and a is smaller lexographically return true
            return a.first<b.first;
        }
    }
    vector<string> preprocessing(unordered_set<string>&nums){
        vector<pair<string,int>>freqWstr;
        for(auto it:nums){
            freqWstr.push_back({it,freq[it]});
        }
        // sort using custom compare function
        sort(freqWstr.begin(),freqWstr.end(),compare);
        vector<string>final;
        // convert the frequency and string pair vector to returnable vector
        for(int i=0;i<freqWstr.size();i++){
            final.push_back(freqWstr[i].first);
            if(i==2) break;
        }
        return final;
    }
    void insertIntoTries(TrieNode*& curr,string sentence,int times){
        TrieNode*r=curr;
        // update the frequency of the element in the map
        freq[sentence]=times;
        
        int n=sentence.size();
        // insert the element
        for(int i=0;i<n;i++){
            int idx=26;
            if(sentence[i]!=' ') idx=sentence[i]-'a';
            if(r->children[idx]==NULL){
                TrieNode*child=new TrieNode();
                r->children[idx]=child;
            }
            r->children[idx]->names.insert(sentence);
            r=r->children[idx];
        }
    }
    vector<string>solver(TrieNode*& root,string word){
        int n=word.size();

        TrieNode*r=root;
        for(int i=0;i<n;i++){
            int idx=26;
            if(word[i]!=' ') idx=word[i]-'a';
            if(r->children[idx]==NULL){
                return {};
            }
            r=r->children[idx];
        }
        return preprocessing(r->names);
    }
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        // write code for constructor
        int n=times.size();
        for(int i=0;i<n;i++){
            insertIntoTries(root,sentences[i],times[i]);
        }
        
    }
    string str="";
    vector<string> input(char c) {
        
        if(c=='#'){
            if(freq.find(str)==freq.end()){
                
                insertIntoTries(root,str,1);
            }
            else{
                freq[str]++;
            }
            str="";
            return {};
        }
        else{
            str+=c;
        }
        
        return solver(root,str);
    }
};