class WordDictionary {
public:
  unordered_set<string>st;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        st.insert(word);
    }
    
    bool search(string word) {
        int a=-1,b=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.' && a==-1)a=i;
            else if(word[i]=='.' && b==-1 )b=i;
        }
        // if(a==-1){
        //     if(st.find(word)!=st.end())return true;
        //     else return false;
        // }
        //cout<<word<<" "<<a<<" "<<b<<endl;
        for(int i=0;i<26;i++){
           if(a!=-1) word[a]='a'+i;
            for(int j=0;j<26;j++){
                if(b!=-1)word[b]='a'+j;
            if(st.find(word)!=st.end())return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */